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
    std::string empt = "";
    std::chrono::milliseconds duration;
    int lagReduction = 10; //Estimated, for some reason CoTool either runs faster than my code or does some kind of math to reduce the frames slightly.
    for(int i = 0; i < numBlinks; i++){
        auto start = std::chrono::high_resolution_clock::now(); //for some reason I can't declare these earlier? Requires auto?
        std::getline(std::cin,empt); //Will eventually need to add a way to use different keys besides enter. Maybe replace with getChar?
        auto stop = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start); //milliseconds cast.
        observed.push_back((duration.count()-lagReduction)/framerate); //this framerate is dependent on region. At least, that's how CoTool does it.
        std::cout << "blink: " << i << ": " << observed.back(); //debug
    }
    return observed;
}

int main (){
    //This code works on all regions!
    //initial search array setup
    bool is_xd = 0;
    bool is_emu5 = 0;
    region gameRegion = NTSCU;


    u32 inputSeed = 0xBA17A99E;
    int maxSearch = 20000; //overkill? could user define.
    int numBlinks = 5; // for searching. Will eventually implement parallel search so that the user can stop inputting automatically when the program finds their seed.
    int flexValue = 20; //How lenient the seed searcher should be (in frames)
    float framerate = 33.373; //as used by CoTool, other sites report 33.375 but this is closer. 
    const int HEURISTIC = 69; //68.138 or until a better number is found.
    int framesPer60 = is_xd ? 1 : 2; //used for SLB purposes. at 30fps its 2, at 60 is 1, and for xd it is slightly less than 60. DOES THIS BREAK XD?
    u32 seed = inputSeed;
    std::vector<int>searchPool;
    std::vector<u32>seedPool;
    
    //blinker vars -- condense into struct?
    int break_time = 0;
    int sinceLastBlink = 0;
    int interval = 0;
    int vFrames = 0; //this vframe thing is kinda pointless tbh.
    int prev_blink = 0;
    
    
    //FDFE943

    interval = (gameRegion == NTSCJ) ? 4 : 5;
    framerate = (gameRegion == PAL50) ? 40 : 33.373;
    framerate = is_xd ? framerate / 2 : framerate;

    // if (gameRegion == NTSCJ){
    //     interval = 4;
    // } else {
    //     interval = 5;
    //     if (gameRegion == PAL50){
    //         framerate = 40;
    //     }
    // }
    // if (is_xd){
    //     framerate = framerate / 2;
    // }

    //generates pool of possible seeds in search range. Could later alter i and maxSearch to re-generate pool of possible seeds.
    for (int i = 0; i < maxSearch; i++)
    {
        int flag = next(seed,break_time,sinceLastBlink,interval,framesPer60);
        if (is_xd){
            if (is_emu5){
                if (is_emu5){
                    framesPer60 = vFrames % 2;
                }
            } else {
                if (vFrames % HEURISTIC == 0){
                    framesPer60 = 0;
                } else {
                    framesPer60 = 1;
                }
            }
        }
        vFrames += 1;
        if (flag > 1){ //meaning we blinked.
            int blink = vFrames;
            if (prev_blink == 0){
                prev_blink = blink;
                searchPool.push_back(blink);
            } else {
                searchPool.push_back(blink - prev_blink);
            }
            seedPool.push_back(seed);
            prev_blink = blink;
        }
    }
    debugPrintVec(searchPool);
    std::cout << "\n\n";


    //Generate user input set:
     //init -- so user starts on their own terms.
     std::cout << "Enter to begin blinks:";
     std::getchar();
     
    std::vector<int> inputBlinks = getInputBlinks(numBlinks,framerate);
    std::cout << std::endl;
    debugPrintVec(inputBlinks);


    // //now we search for the sublist in the pool.

    std::vector<int> iterSet(searchPool.begin(), searchPool.end()); 
    std::vector<int> results;
    std::vector<u32> seedResults;
    iter it;  
    int updateIdx = 0;

    //Finds ALL matches of the subsequence in the search pool. Produces two vectors, one for position and one for seed.
    //may need to rework which blink gets output to results so that the print makes sense. 
    while (it != iterSet.end())
    { 
        it = flexSearch(iterSet.begin()+updateIdx,iterSet.end(),inputBlinks.begin(),inputBlinks.end(),flexPredicate,flexValue); //search algorithm
        updateIdx = it-iterSet.begin(); //position of result
        //std::cout << "Update Idx: " << updateIdx << std::endl; //debug
        if (it != iterSet.end()){
        results.push_back(updateIdx); //position of first blink. 
        seedResults.push_back(seedPool[updateIdx+numBlinks-1]); //final blink's seed.
        //debugPrintVec(results);
        std::cout << "Added!\n";
        updateIdx++; //To make sure new comparison doesn't return immediately.
        }// else break
    }


    //Results printing:
    if (results.empty()){
        std::cout << "NOT FOUND!";
    } else {
        std::cout << "Found subsequence ";
        debugPrintVec(inputBlinks);
        std::cout << "At position(s) ";
        debugPrintVec(results); 
        std::cout <<"\nSeed\t : total rng advances\n";
        for (unsigned int i = 0; i < seedResults.size(); i++)
        {
            std::cout  << std::hex << seedResults[i] << "\t : " << std::dec << findGap(inputSeed,seedResults[i],true) << std::endl;
        }
        
    }

    return 0;
}
//Once blinking is done, still need to add the streamlined way to exit the blink (like in the current blink timer stuff) -- might need yatsune for this.
