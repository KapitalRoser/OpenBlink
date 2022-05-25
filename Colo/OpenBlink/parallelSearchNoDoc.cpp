#include "../../processCore.h"

#include <mutex>
#include <condition_variable>
#include <queue>


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
int nextB (u32 &seed, blinkVars &b, int framesPer60){
    if (b.break_time > 0){
        b.break_time -= 1;
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
void printResults(std::vector<int> results,std::vector<int> inputBlinks,std::vector<pool>mainPool,int numBlinks, u32 inputSeed){
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
            u32 resultSeed = mainPool[results[i]+numBlinks-1].seed; //IMPORTANT
            std::cout  << std::hex << resultSeed << "\t : " << std::dec << findGap(inputSeed,resultSeed,true) << std::endl;
        }
        
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

int main (){
    //This code works on all regions!

    //~~~~~~~~USER INPUT~~~~~~~~~~~~~~
    bool is_xd = 0, is_emu5 = 0;
    region gameRegion = NTSCU;
    u32 inputSeed = 0xBA17A99E;
    int maxSearch = 20000; //overkill? could user define.
    int numBlinks = 5; // for searching. Will eventually implement parallel search so that the user can stop inputting automatically when the program finds their seed.
    int flexValue = 20; //How lenient the seed searcher should be (in frames)
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    const int HEURISTIC = 69;
    u32 seed = inputSeed;
    std::vector<pool>mainPool;
    blinkVars blinkState;
    int vFrames = 0, prev_blink = 0;

    int framesPer60 = is_xd ? 1 : 2;
    float framerate = (gameRegion == PAL50) ? 40 : 33.373;
    framerate = is_xd ? framerate / 2 : framerate;
    blinkState.interval = (gameRegion == NTSCJ) ? 4 : 5;

    for (int i = 0; i < maxSearch; i++)
    {
        int flag = nextB(seed,blinkState,framesPer60);
        if (is_xd){
        framesPer60 = is_emu5 ? vFrames % 2 : (vFrames % HEURISTIC);
        }
        vFrames++;
        if (flag > 1){
            int blink = vFrames - prev_blink;
            mainPool.push_back({blink,seed});
            prev_blink = vFrames;         
        }
    }
    std::cout << "Enter to begin blinks:";
    std::getchar();
    std::vector<int> inputBlinks = getInputBlinks(numBlinks,framerate);
    std::cout << std::endl;

    std::vector<int> results = searchPool(mainPool,inputBlinks,flexValue);
    printResults(results,inputBlinks,mainPool,numBlinks,inputSeed);

    return 0;
}
