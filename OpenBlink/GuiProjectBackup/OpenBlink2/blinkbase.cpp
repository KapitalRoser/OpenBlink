#include "blinkbase.h"

typedef std::vector<pool>::iterator iterP;
typedef std::vector<int>::iterator iterI;

//Blink functions
std::vector<pool> generateBlinks(u32 seed, platform &userPlatform, int limit){
    blinkVars blinkState = blinkVars(userPlatform.getRegion(),userPlatform.getXD()); //Heck yea, found a way to declare here.
    std::vector<pool>outPool;
    int vFrames = 0, prev_blink = 0;
    for (int i = 0; i < limit; i++)
        {
            int flag = blinkState.next(seed,userPlatform.m_framesPer60); //trying to resist the urge to make a full blink class because it'll get ambiguous quickly. --??????????
            userPlatform.verifyFP60(vFrames);
            vFrames++;

            float TCFChance = 0; //As per Emu5 odds, still WIP for console/modern
            if (userPlatform.getXD()){
                //verify fp60
                if (flag < 0){
                    TCFChance = float(-(flag) + 1)/150;
                }
                if(flag == 180){
                    TCFChance = 91.0/150; //90 valid slots of 150, + 1 for the 98/99 slot.
                }
            }
            if (flag > 1){ //meaning we blinked.
                int blink = vFrames - prev_blink;
                outPool.push_back({blink,seed,TCFChance});
                prev_blink = vFrames;
            }
            if (!flag){
                limit++;  //does not increment when slb > 10? Includes break time and negative brackets.
            }
        }
    return outPool;
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
