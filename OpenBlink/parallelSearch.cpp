#include "processCore.h"

//Thread includes, maybe worth putting into process core.
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

#include <Windows.h>
#include <conio.h>

enum games {COLO, XD};

struct pool {
    int blink = 0;
    u32 seed = 0;
};

struct blinkVars{
    //expand to class?
    int break_time = 0;
    int sinceLastBlink = 0;
    int interval = 0;
};
struct incBlinkMsg{
    int targetIdx = 0;
    float framerate = 0;
    std::vector<int> blinksMS; //This is already in MS to save on timer computing resources. 
    std::vector<int> blinksF; //may morph into pool if desired.
};

class platform{
    private:
    bool m_is_xd = 0, m_is_emu5;
    region m_gameRegion = NTSCU;
    float m_framerate = 33.373;
    public:
    platform(bool is_xd, bool is_emu5, region gameRegion){
        m_is_xd = is_xd;
        m_is_emu5 = is_emu5;
        m_gameRegion = gameRegion;
        m_framesPer60 = is_xd ? 1 : 2; //used for SLB purposes. at 30fps its 2, at 60 is 1, and for xd it is slightly less than 60. DOES THIS BREAK XD?    
        m_framerate = (gameRegion == PAL50) ? 40 : 33.373; //as used by CoTool, other sites report 33.375 but this is closer. 
        m_framerate = is_xd ? m_framerate / 2 : m_framerate;
    }
    int m_framesPer60 = 0; //The only variable that could change. 
    //Getters
    bool checkXD(){return m_is_xd;}
    bool checkEmu5(){return m_is_emu5;}
    region getRegion(){return m_gameRegion;}
    float getFramerate(){return m_framerate;}
    //can add a getter/setter function for framesPer60 if I really wanted to keep all vars private.
    //Others don't need any yet, will add with QT gui. 
};


struct searchParameters {
    u32 inputSeed = 0;
    int maxSearch = 0; //Have different units possible like frames, seconds, advances, and blinks.
    int minSearch = 0; // must be < max search, handle later. 
    int flexValue = 0;
    int maxCalibrate = 0;
    int arbitrary_Target = 0; //Probably remove for Qt, as target may get chosen at runtime.
};

typedef std::vector<pool>::iterator iterP;
typedef std::vector<int>::iterator iterI;
//~~~~~~~~~~~~GLOBALS~~~~~~~~~~~~~~~~~
//can I avoid these globals? -- threading related. -- could passing by ref(var) be a solution? 
std::condition_variable cv;
std::mutex m;
std::queue<int> intMsg_queue; //only the vframe is passed to the other thread for simplicity sake.
std::queue<incBlinkMsg> incMsg_queue; //Technically this is only used once, maybe doesn't need to be a queue or a msg.
bool stopFlag = false;
bool errorFlag = false;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//can expand using struct but careful not to cause the timer thread to lag.
//Gondor calls for aid. 
void sendMessage(const int& message) { //modify for later blink output queue?
    std::lock_guard<std::mutex> lk(m); //acquires the mutex variable. lk is popped at end of function.
    intMsg_queue.push(message); //adds message to global message queue. first in, first out.
    cv.notify_one(); //wakes up any threads that are waiting. can also notify_all.
}
void sendBlinkSet(const incBlinkMsg& message){
    std::lock_guard<std::mutex> lk(m);
    incMsg_queue.push(message);
    cv.notify_one();
}

//And Rohan will answer.
int getIntMessage() {
    int message; //define incoming
    std::unique_lock<std::mutex> lock(m); //aquire mutex, lock is popped at the end of function.
    cv.wait(lock, [](){return !intMsg_queue.empty();}); //holds thread until the queue isn't empty. 
    //Releases mutex to suspend thread. Upon wakeup,  mutex is automatically re-acquired. Condition is then checked after getting the mutex. 
    message = intMsg_queue.front(); //takes msg from queue. 
    intMsg_queue.pop(); //first-in, first-out.
    return message;
}
incBlinkMsg getIncoming(){
    incBlinkMsg message; //define incoming
    std::unique_lock<std::mutex> lock(m); //aquire mutex, lock is popped at the end of function.
    cv.wait(lock, [](){return !incMsg_queue.empty();}); //holds thread until the queue isn't empty. 
    //Releases mutex to suspend thread. Upon wakeup,  mutex is automatically re-acquired. Condition is then checked after getting the mutex. 
    message = incMsg_queue.front(); //takes msg from queue. 
    incMsg_queue.pop(); //first-in, first-out.
    return message;
}

//Blink functions
float getThreshold(int SLB){
    return static_cast<float>((-SLB+110)*(SLB-10))/150000;
}
float blinkLogic(int SLB){
    //This holds true for colo, but the constants may need updating for gales. 
    if (SLB < 60){
        return getThreshold(SLB);
    }   
    else if (SLB < 180){
        return 1.0/60;
    } else {
        return 1;
    }
}
int nextB (u32 &seed, blinkVars &b, int framesPer60){
    if (b.break_time > 0){
        b.break_time--;
        return false;
    }       
    b.sinceLastBlink += framesPer60;
    if (b.sinceLastBlink < 10){
        return false;
    }
    if (LCGPercentage(seed) <= blinkLogic(b.sinceLastBlink)){
        b.break_time = b.interval;
        int result = b.sinceLastBlink;
        b.sinceLastBlink = 0;
        return result;
    }     
    return true; //I don't think this triggers in normal operation
}
//Search Algo
iterP flexSearch ( iterP first1, iterP last1, iterI first2, iterI last2, bool (*pred)(int,int,int),int flex){
  if (first2==last2) return first1; 
  while (first1!=last1){
    iterP it1 = first1;
    iterI it2 = first2;
    while (pred(it1->blink,*it2,flex)) { //this is where the "iterate over a struct" comes in
        ++it1; ++it2;
        if (it2==last2) return first1;
        if (it1==last1) return last1;
    }
    ++first1;
    //function courtesy of the STL search algorithm. 
  }
  return last1;
}
bool flexPredicate (int a, int b, int flex){
    return (a >= b-flex && a <= b+flex);
}

std::vector<int> searchPool(std::vector<pool> pool, std::vector<int>inputs, int flexValue){
    std::vector<int> resultsIdx; //If you wanted to change this func to return a specific pool object, then need to rename the parameter to something else.
    iterP it;  
    int updateIdx = 0;
    while (it != pool.end())
    { 
        it = flexSearch(pool.begin()+updateIdx,pool.end(),inputs.begin(),inputs.end(),flexPredicate,flexValue); //search algorithm
        updateIdx = it-pool.begin(); //position of result

        if (it != pool.end()){ //rememeber the result seed is located at index + numBlinks - 1
            resultsIdx.push_back(updateIdx); //position of first blink. 
            updateIdx++; //To make sure new comparison doesn't return immediately.
        }
    }
    return resultsIdx; //Index is found, it's up to the caller to find the appropriate pool struct in the mainPool.
};
std::vector<pool> generateBlinks(u32 seed,blinkVars blinkState, platform &userPlatform, int limit){
    const int HEURISTIC = 69; //XD, rate of Time Compensation failures. ~68.138 or until a better number is found.
    std::vector<pool>outPool;
    int vFrames = 0, prev_blink = 0;
    for (int i = 0; i < limit; i++)
        {
            int flag = nextB(seed,blinkState,userPlatform.m_framesPer60); //trying to resist the urge to make a full blink class because it'll get ambiguous quickly.
            if (userPlatform.checkXD()){ //Do I internalize this function inside the class? Passing in vframes and heuristic?
                userPlatform.m_framesPer60 = userPlatform.checkEmu5() ? vFrames % 2 : (vFrames % HEURISTIC); //I feel like heuristic is most visible/editable in the platform class.
            } //If I internalize this then I can avoid passing the whole userPlatform class into this function.
            vFrames++;
            if (flag > 1){ //meaning we blinked.
                int blink = vFrames - prev_blink;
                outPool.push_back({blink,seed});
                prev_blink = vFrames;         
            }
            if (!flag){
                limit++;
            }
        }
    return outPool;
}

int setTarget(incBlinkMsg set, int limiter){
    int timerLimit = 0;
    for (int i = 0; i < limiter;i++){
        timerLimit += set.blinksMS[i];
    }
return timerLimit;
}

void printResults(int resultIdx,std::vector<int> inputBlinks,std::vector<pool>mainPool, u32 inputSeed){
    //Results printing:
    if (resultIdx == -1){
        std::cout << "NOT FOUND!";
    } else {
        std::cout << "Found subsquence at position: " << resultIdx << "\n"; 
        std::cout <<"\nSeed\t : total rng advances" << std::endl;
        u32 resultSeed = mainPool[resultIdx+inputBlinks.size()-1].seed; //IMPORTANT
        std::cout  << std::hex << resultSeed << "\t : " << std::dec << findGap(inputSeed,resultSeed,true) << std::endl;
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        std::cout << "Blinks:\n";
        Sleep(200);
    }

}
void debugPool(std::vector<pool> pool){
    for (unsigned int i = 0; i < pool.size(); i++)
        {
            std::cout << pool.at(i).blink << ", ";
            if (i % 20 == 19){
                std::cout << std::endl;
            }
        }
}

//Application thread functions
void runTimer(int DEFAULT_MS_ADJUST){
    //framerate = 33.373; //I guess I pass this in? Safe and not changing? Apparently its framesPer60 which changes? Does framerate not need to change with it?
    getchar();
    auto start = std::chrono::high_resolution_clock::now();
    std::chrono::milliseconds duration;
    std::chrono::milliseconds previousDur;
    while (!stopFlag){
        m.lock();
        if (stopFlag){
            break;
        }
        m.unlock();
        if (kbhit()){ //This checks for input constantly, needed so that the flag can interrupt.
            auto stop = std::chrono::high_resolution_clock::now();  
            duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start); //milliseconds cast.
            sendMessage(duration.count()); //send blink, process later.
            getch(); //It WORKS -- takes char from input buf, clears kbhit
            start = std::chrono::high_resolution_clock::now();
        }
        // //Backup
        // auto start = std::chrono::high_resolution_clock::now();
        // getchar();
        // auto stop = std::chrono::high_resolution_clock::now();  
        // auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start); //milliseconds cast.
        // sendMessage(duration.count()); //send blink, process later.    
    }
    if (!errorFlag){
        duration = std::chrono::milliseconds::zero();
        std::chrono::milliseconds totalDuration = std::chrono::milliseconds::zero();
        
        incBlinkMsg incoming = getIncoming(); //THESE BLINKS ARE IN MILLISECONDS!!
        iterI nextBlinkIter = incoming.blinksMS.begin();
        iterI nextBlinkF = incoming.blinksF.begin();
        int timerLimit = 0;
        if (incoming.targetIdx < incoming.blinksMS.size()){
            timerLimit = setTarget(incoming,incoming.targetIdx); //Goes to target, assuming target is valid and within the list.
        } else {
            timerLimit = setTarget(incoming,incoming.blinksMS.size()-1); //Goes to end of blink list
        }

        //These values work for ntscu/pal60 but not jpn or pal50 for obv reasons.
        int userInputOffset = -215; //always subtracting from time remaining.
        int userInputOffsetInterval = 5;
        userInputOffset += userInputOffsetInterval * 1000; //in this case: 5000 + previous value.
        //this number is the most heuristic-y of the heuristics. I hate how this is set up but we will fix in QT.



        //debugPrintVec(incoming.blinksMS);
        auto calibrationStart = std::chrono::high_resolution_clock::now() - std::chrono::milliseconds(DEFAULT_MS_ADJUST);
        while (totalDuration.count() < timerLimit - userInputOffset){
            auto stop = std::chrono::high_resolution_clock::now();
            duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
            totalDuration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - calibrationStart);
            if (totalDuration.count() > previousDur.count()){
                if (duration.count() >= *nextBlinkIter){
                    if (nextBlinkIter != incoming.blinksMS.end()){
                        nextBlinkIter++;
                        nextBlinkF++;
                        std::cout << nextBlinkIter - incoming.blinksMS.begin() << ": " << *nextBlinkF << "f | " << *nextBlinkIter << "ms" << "\n";
                    }
                    std::cout << "BLINK!\r";
                    start = std::chrono::high_resolution_clock::now(); //Where should this go honestly. Where should this be so that the timer remains accurate. 
                    Beep(1000,333); //This holds the thread up, maybe should send to other thread.
                    
                } else {
                    std::cout << "~~~~~~\r";
                }
            }
            previousDur = totalDuration;
        }
        //Not the *most* accurate thing in the world, will have to do for now.
        std::cout << "Starting countdown! (" << incoming.targetIdx - (nextBlinkIter - incoming.blinksMS.begin()) << ") blinks occur during countdown.\n"; 
        for (int i = 0; i < userInputOffsetInterval; i++){
            Sleep(700); //300 + 700 = units of 1000.
            Beep(1500, 300); //Determined by userSettings, like in flowtimer.
        }
 
        std::cout << "FINAL BLINK REACHED!";
    }
}
void handleSearch(platform &userPlatform, searchParameters userSearchParams, u32 &resultSeed){
    //SETUP
    u32 seed = userSearchParams.inputSeed; // == input seed
    LCGn(seed,userSearchParams.minSearch);
    blinkVars blinkState;
    std::vector<int> blinkList; //as vector for simplicity of flexSearch().
    std::vector<int> resultIndexes;
    const int lagReduction = 10; //Heuristic, based on CoTool's performance.
    blinkState.interval = (userPlatform.getRegion() == NTSCJ) ? 4 : 5; //make blinkState a class and add this to constructor?
    //generates pool of possible seeds in search range. Could later alter i and maxSearch to re-generate pool of possible seeds.
    std::vector<pool>mainPool = generateBlinks(seed,blinkState,userPlatform,userSearchParams.maxSearch-userSearchParams.minSearch); //SEED IS NOT MODIFIED
    std::cout << "Search pool generated!\n";
    //debug
    //debugPool(mainPool);
    std::cout << "\n\n";
    Beep(900,300);
    //TIME TO GET INPUTS BITCHES.
    std::cout << "Press \"Enter\" to record Blinks: \n";
    std::vector<int> inputBlinks = {89,12,78,60,45}; //for debug
    while (resultIndexes.size() != 1){
        blinkList.push_back((getIntMessage()-lagReduction)/userPlatform.getFramerate());
        resultIndexes = searchPool(mainPool,blinkList,userSearchParams.flexValue);
        std::cout << blinkList.back() << " : " << resultIndexes.size() << " result(s) found!\n"; //Locking this behind mutex seems to cause problems
        if (resultIndexes.size() == 0){
            std::cout << "\nSEED NOT FOUND OR ERROR!\n";
            stopFlag = true;
            errorFlag = true;
            Beep(700,200);
            Beep(700,200);
            Beep(700,200);
            Beep(700,200);
            return;
        }
    }
    stopFlag = true;
    if (resultIndexes.size() > 1){
        errorFlag = true;
        return;
    }  
    seed = mainPool[resultIndexes[0]+blinkList.size()-1].seed;


    int resultIdx = 0;
    //m.lock(); //does this do anything?
    if (resultIndexes.empty()){
        resultIdx = -1;
    } else {
        resultIdx = resultIndexes[0];
    }
    printResults(resultIdx,blinkList,mainPool,userSearchParams.inputSeed);





    incBlinkMsg outMsg;
    std::vector<pool> exitPool = generateBlinks(seed,blinkState,userPlatform,userSearchParams.maxCalibrate);
    
    //CONVERT EXIT POOL TO MS THEN SEND.
    for (unsigned int i = 0; i < exitPool.size(); i++){
        outMsg.blinksMS.push_back(round(exitPool[i].blink * userPlatform.getFramerate())); //If desiring the same results as CoTool, then remove round(). CoTool Floors everything.
        outMsg.blinksF.push_back(exitPool[i].blink);
    }
    //SEND:
    outMsg.framerate = userPlatform.getFramerate(); //Doesn't change, that's fp60, which is already accounted for in the process of generating a blink list.
    outMsg.targetIdx = userSearchParams.arbitrary_Target; //Is this right?
    resultSeed = exitPool[userSearchParams.arbitrary_Target-1].seed;
    sendBlinkSet(outMsg);
    Beep(1200,100);
    Beep(1200,100);
    Beep(1200,100);

    //DONE??????

    // sendMessage(stopFlag); //bool convertible to int here. 
    
    //m.unlock();
    //NOW SEND incBlinkSet to timer
}

int main (){

    //OPENBLINK Originally developed by Kapital
    //With help from Lincoln and others
    //2021-2022.

    //This code works on all regions!
    //Units: Frames = Visual frames at a certain framerate
    //Advances = LCG calls to rng
    //Blinks = Successful blinks

    std::cout << "Tool launched! Reading input file:\n";
    std::vector<std::string>setupL = readStringFromFile("input.txt");
    for (unsigned int i = 0; i < 5; i++)
    {
        setupL[i] = setupL[i].substr(0,setupL[i].find(":")); //Does the space screw things up?
    }
    searchParameters userInputs;
    std::stringstream hexConvert;
    hexConvert << std::hex << setupL[0]; 
    hexConvert >> userInputs.inputSeed;
    hexConvert.clear();
    hexConvert.str("");
    userInputs.minSearch = stoi(setupL[1]);
    userInputs.maxSearch = stoi(setupL[2]);
    userInputs.flexValue = stoi(setupL[3]);
    userInputs.arbitrary_Target = stoi(setupL[4]);
    platform userPlatform = platform(false,false,region(stoi(setupL[5])));
    int msAdjust = stoi(setupL[6]);
    userInputs.maxCalibrate = 200*userInputs.arbitrary_Target; //Will need to change with QT.
    u32 resultSeed = 0;
    std::thread timerT(&runTimer,msAdjust);
    std::thread searchT(&handleSearch,std::ref(userPlatform),userInputs,std::ref(resultSeed));

    timerT.join();
    searchT.join();

    std::cout << "\nYOUR CURRENT SEED IS: " << std::hex << resultSeed << "\n";

    system("Pause");

    return 0;
}
       /*

        Now for blinkTimer

        Functionality:
        User specifies which blink they want to exit on. (last blink is default)
        At any time before the blink occurs the user may alter their choice
        User may hit a button to expand the list of blinks further if needed. -- specify setting?
        User may use two hotkeys/buttons to adjust the alignment of the blinking to fit what is on screen. 
        At Center of Blink - Frames taken to exit blink - Offset (specified buffer by user, probably 5 or 10)
        Flowtimer style beeps occur before input is to be pressed. User defined interval and frequency.
        Progress bar/visual indicator is updated alongside timer. 

        Todo order:
        Display time to target and time to blink
        Allow target changing.
        Allow resync via hotkeys. 
        
        Some of this may need to wait until QT implementation. Almost there!
        

        Not sure what to do about variable framerates like in XD.
        */