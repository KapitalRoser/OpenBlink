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
            vFrames++;

            float TCFChance = 0; //As per Emu5 odds, still WIP for console/modern
            if (userPlatform.getXD()){
                userPlatform.verifyFP60(vFrames);
                if (userPlatform.getEmu5()){
                    if (flag < 0){
                        TCFChance = float(-(flag) + 1)/150;
                    }
                    if(flag == 180){
                        TCFChance = 91.0/150; //90 valid slots of 150, + 1 for the 98/99 slot.
                    }
                } else {
                    if (flag < 0){
                        TCFChance = float(-(flag)/56); //At worst. Values of 59 and 115 are also possible, along with other glitchy and unlikely scenarios.
                    }
                    if (flag == 180){
                        //Seed is at least 1 or two above where it should be.
                        //Call LCG(seed) here?? Or leave that to the warning.
                        //I don't think it's possible to have the 180 frame be not at least 1 call affected.
                        //guarantee at least 1 call. No recorded evidence of a 180 gap.
                        //If assume only 56's, then:
                    }
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






/*

1
00200100200100
10001
02002020
0202002001
00200100200100
1000100100
0102002020
2002
00200100200100
200100
1000100100
20200202
00200100200100
200100
200
1001000
10010??







100
200100
200100

10001
02002020
02020020

01
00200100200100

10001
0010001
02002020
20

02
00200100200100

200100
10001
0010
0202002

02
00200100200100

200100
2
0010010
0010010









1
00
200100
200100

10001
02002020

02020020

01
00
200100
200100

1000100
10001
02002020

200 :: OR :: 020

200
200100
200100

200100
1000100
10
02020020

200
200100
200100

200100
2
0010010
0010010


1002
0010
0200
1001
0001
0200
2020
0202
0020
0100
2001
0020
0100
1000
1001
0001
0200
2020
2002
0020
0100
2001
0020
0100
1000
1001
0020
2002
0200
2001
0020
0100
2001
0020
0100
1000
1001
0








1: 100%
2: 56 - 56: 100%
2: 56 + 59: 100%
2: 56 + 115: 100%
2: 59 + 59: 100% ::118 no recorded evidence
2: 59 + 115: 100%
2: 115 + 115: 179/230 = 77.83% :: no recorded evidence
3: 56 * 3: 100%
3: 59* 3: 100% : no recorded evidence
3: 115 * 3: 51% : no recorded evidence
3: 56*2 + 59:100%
3: 56 + 59*2: 100%
3: 56 + 59 + 115: 77.83% :: 0 1 2 is not recorded, but 1 0 2 or 2 0 1 is
3: 59*2 + 115: 76.82% not recorded.
4: 56*4 : 79.91% :: not recorded
4: 56*3 + 59: 78.85% :: 1000, 0100,0010,0001. Pretty often tbh
4: 56*2 + 59*2: 77.82% :: 1001, 1010, 0101 recorded, 1100, 0110,0011 not recorded
4: 56*1 + 59*3: 76.82% :: not recorded
4: 56*3 + 115 :: 63.25% :: 2000, 0200, 0020,
*/









