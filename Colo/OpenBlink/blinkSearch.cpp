#include "../../processCore.h"

typedef std::vector<int>::iterator iter;

iter flexSearch ( iter first1, iter last1, iter first2, iter last2, bool (*pred)(int,int,int),int flex){
  if (first2==last2) return first1; 
  while (first1!=last1){
    iter it1 = first1;
    iter it2 = first2;
    while (pred(*it1,*it2,flex)) {
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

float getThreshold(int SLB){
    return static_cast<float>((-SLB+110)*(SLB-10))/150000;
}
float blinkLogic(int SLB){
    if (SLB < 60){
        return getThreshold(SLB);
    }   
    else if (SLB < 180){
        return 1.0/60;
    } else {
        return 1;
    }
}
int next(u32 &seed,int& break_time, int &sinceLastBlink, int interval){
    if (break_time > 0){
        break_time -= 1;
        return false;
    }       
    sinceLastBlink += 2;
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



int main (){

    //initial search array setup
    u32 inputSeed = 0x353A8F38;
    u32 seed = inputSeed;
    int maxSearch = 10000; //overkill? could user define.
    std::vector<int>searchPool;
    
    //blinker vars -- condense into class?
    int break_time = 0;
    int sinceLastBlink = 0;
    int interval = 4;
    int vFrames = 0;
    int prev_blink = 0;

    //timer vars:
    float framerate = 33.375; //any need for 32.875 of JPN?
    
    region game = NTSCU;
    if (game == PAL50 || game == PAL60){
        interval = 5;
        if (game == PAL50){
            framerate = 40;
        }
    }

    

    //generates pool of possible seeds in search range. Could later alter i and maxSearch to re-generate pool of possible seeds.
    for (int i = 0; i < maxSearch; i++)
    {
        int flag = next(seed,break_time,sinceLastBlink,interval);
        vFrames += 1;
        if (flag > 1){ //meaning we blinked.
            int blink = vFrames;
            if (prev_blink == 0){
                prev_blink = blink;
                searchPool.push_back(blink);
            } else {
                searchPool.push_back(blink - prev_blink);
            }
            prev_blink = blink;
        }
    }
    debugPrintVec(searchPool);
    std::cout << "\n\n\n";
    //For now we do things the way coTool kinda does them -- might need 
    



    //Generate user input set:
     std::string empt = "";
     std::vector<int>inputBlinks;
     std::chrono::milliseconds duration;
     std::cout << "Begin Blinks!";
     std::getline(std::cin,empt);
     int i = 0;
    while (i < 4){
        auto start = std::chrono::high_resolution_clock::now();
        std::getline(std::cin,empt);
        auto stop = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        inputBlinks.push_back((duration.count()-10)/framerate);
        std::cout << "blink: " << i;
        i++;
    }
    std::cout << std::endl;
    debugPrintVec(inputBlinks);





    // //now we search for the sublist in the pool.
    int flexValue = 10;
    std::vector<int> elems = searchPool;
    std::vector<int> myVector(elems.begin(), elems.end()); 
    std::vector<int> results;
    iter it;  

    // Find the first subsequence
    //May search for others by starting search again from the end of wherever the successful seed is, if any.
    std::vector<int>sub2 = inputBlinks;
    int updateIdx = 0;
    while (it != myVector.end())
    { 
        it = flexSearch(myVector.begin()+updateIdx,myVector.end(),sub2.begin(),sub2.end(),flexPredicate,flexValue); //search algorithm
        updateIdx = it-myVector.begin(); //position of result
        //std::cout << "Update Idx: " << updateIdx << std::endl; //debug
        if (it != myVector.end()){
        results.push_back(updateIdx);
        //debugPrintVec(results);
        updateIdx++; //To make sure new comparison doesn't return immediately.
        }// else break
    }

    //Results printing:
    if (results.back() == myVector.size()){
        std::cout << "NOT FOUND!";
    } else {
        std::cout << "Found subsequence ";
        debugPrintVec(sub2);
        std::cout << "At position(s) ";
        debugPrintVec(results); 
    }
    

    return 0;
}