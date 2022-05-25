#include "../../processCore.h"



struct pool {
    int blink = 0;
    u32 seed = 0;
};
typedef std::vector<pool>::iterator iterP;
typedef std::vector<int>::iterator iterI;

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
    //If there's a need to make search more forgiving, that goes here.
}

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
int next(u32 &seed,int& break_time, int &sinceLastBlink, int interval, int framesPer60){
    if (break_time > 0){
        break_time -= 1;
        return false;
    }       
    sinceLastBlink += framesPer60;
    if (sinceLastBlink < 10){
        return false;
    }
    if (LCGPercentage(seed) <= blinkLogic(sinceLastBlink)){
        break_time = interval;
        int result = sinceLastBlink;
        sinceLastBlink = 0;
        return result;
    }     
    return true;
}

std::vector<int> getInputBlinks(int numBlinks, int framerate){
    std::vector<int> observed;
    std::string empt = ""; //required buffer for getline. replace with hotkey.
    std::chrono::milliseconds duration;
    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point stop;
    const int lagReduction = 10; //Estimated, for some reason CoTool either runs faster than my code or does some kind of math to reduce the frames slightly.
    for(int i = 0; i < numBlinks; i++){
        
        start = std::chrono::high_resolution_clock::now(); //should I be declaring each run or is it better to declare beforehand?
        std::getline(std::cin,empt); //Will eventually need to add a way to use different keys besides enter. Maybe replace with getChar?
        stop = std::chrono::high_resolution_clock::now();

        duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start); //milliseconds cast.
        observed.push_back((duration.count()-lagReduction)/framerate); //this framerate is dependent on region. At least, that's how CoTool does it.
        //This is where observed would be used to search the pool.

        std::cout << "blink: " << i << ": " << observed.back(); //debug
    }
    return observed;
}


std::vector<int> searchPool(std::vector<pool> pool,std::vector<int>inputs, int flexValue){
    std::vector<int> results;
    iterP it;  
    int updateIdx = 0;
    while (it != pool.end())
    { 
        it = flexSearch(pool.begin()+updateIdx,pool.end(),inputs.begin(),inputs.end(),flexPredicate,flexValue); //search algorithm
        updateIdx = it-pool.begin(); //position of result

        if (it != pool.end()){ //rememeber the result seed is located at index + numBlinks - 1
            results.push_back(updateIdx); //position of first blink. 
            updateIdx++; //To make sure new comparison doesn't return immediately.
        }
    }
    return results;
};

int main (){
    //This code works on all regions!
    bool is_xd = 0;
    bool is_emu5 = 0;
    region gameRegion = NTSCU;
    u32 inputSeed = 0xBA17A99E;
    int maxSearch = 20000; //overkill? could user define.
    int numBlinks = 5; // for searching. Will eventually implement parallel search so that the user can stop inputting automatically when the program finds their seed.
    int flexValue = 20; //How lenient the seed searcher should be (in frames)
    const int HEURISTIC = 69; //68.138 or until a better number is found.
    u32 seed = inputSeed;
    std::vector<pool>mainPool;
    
    //blinker vars -- condense into class with necessary functions?
    int break_time = 0;
    int sinceLastBlink = 0;
    int vFrames = 0; //What does this actually do???
    int prev_blink = 0;

    //game and region stuff
    int framesPer60 = is_xd ? 1 : 2; //used for SLB purposes. at 30fps its 2, at 60 is 1, and for xd it is slightly less than 60. DOES THIS BREAK XD?
    int interval = (gameRegion == NTSCJ) ? 4 : 5;
    float framerate = (gameRegion == PAL50) ? 40 : 33.373; //as used by CoTool, other sites report 33.375 but this is closer. 
    framerate = is_xd ? framerate / 2 : framerate;

    //generates pool of possible seeds in search range. Could later alter i and maxSearch to re-generate pool of possible seeds.
    for (int i = 0; i < maxSearch; i++)
    {
        int flag = next(seed,break_time,sinceLastBlink,interval,framesPer60);

        if (is_xd){
            framesPer60 = is_emu5 ? vFrames % 2 : (vFrames % HEURISTIC);
        }

        vFrames += 1;

        if (flag > 1){ //meaning we blinked.
            int blink = vFrames - prev_blink;
            mainPool.push_back({blink,seed});
            prev_blink = vFrames;         
        }
    }



    //debug
    for (unsigned int i = 0; i < mainPool.size(); i++)
    {
        std::cout << mainPool.at(i).blink << ", ";
        if (i % 20 == 19){
            std::cout << std::endl;
        }
    }
    
    std::cout << "\n\n";


    //Generate user input set: --currently calibrates from first blink.
     std::cout << "Enter to begin blinks:";
     std::getchar();
     
    // std::vector<int> inputBlinks = getInputBlinks(numBlinks,framerate);
    std::vector<int> inputBlinks = {89,12};
    std::cout << std::endl;



    //Search section.
    std::vector<int> results = searchPool(mainPool,inputBlinks,flexValue);


    //Results printing:
    if (results.empty()){
        std::cout << "NOT FOUND!";
    } else {
        std::cout << "Found subsequence ";
        debugPrintVec(inputBlinks);
        std::cout << "At position(s) ";
        debugPrintVec(results); 
        std::cout <<"\nSeed\t : total rng advances\n";
        for (unsigned int i = 0; i < results.size(); i++)
        {
            u32 resultSeed = mainPool[results[i]+inputBlinks.size()-1].seed; //IMPORTANT
            std::cout << i << ": " << results[i] << " : " << std::hex << resultSeed << "\t : " << std::dec << findGap(inputSeed,resultSeed,true) << std::endl;
        }
        
    }

    return 0;
}
//Once blinking is done, still need to add the streamlined way to exit the blink (like in the current blink timer stuff) -- might need yatsune for this.
