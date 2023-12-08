#ifndef PROCESSCOREBLINK_H
#define PROCESSCOREBLINK_H

#include <iostream>
#include <iomanip>
#include <array>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <math.h>
#include <queue>
#include <stdio.h>
#include <filesystem>
#include <sys/stat.h>

//TODO: before launching, move this into the game specific folders and update the paths.

//Settings file stuff, may need to redefine with the other applications?
const std::string settingsDelimiter = "---";
const std::string standardFileName = "settings.txt";
const std::string applicationName = "OpenBlink";

#if defined __APPLE__
const std::string settingsPath = std::string(getenv("HOME")) + "/Library/Application Support/OpenBlink";
const std::string settingsName = settingsPath + "/" + standardFileName;
#else
const std::string settingsName = standardFileName;
#endif


//Typedef block
typedef unsigned int uint;
typedef uint8_t u8;
typedef int8_t s8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int64_t s64;
typedef std::vector<int>::iterator iterInt;

enum games {COLO, XD};
enum region {NTSCU,PAL60,PAL50,NTSCJ}; //Switch to NTSC, PAL and JPN? NTSC-U, PAL, NTSC-J is most correct but LONG.
enum emuVer {STABLE,MODERN}; //Stable == 5.0, only matters for xd so far.

//general functions block
u32 modpow32(u32 base, u32 exp);

//RNG Block
u32 LCG(u32& seed);
u32 LCG_BACK(u32 &seed);
u32 LCGn(u32& seed, const u32 n);
u32 LCGn_BACK(u32&seed, const u32 n);

//Only difference between LCGPullHi16 and LCGPercentage is one is stored as float the other as double.
//Does this really matter or can all uses be stored as float? Currently used by npc and palPal
//rand_f for float, ingame name. not all that helpful. In my experience its used as a percentage so I don't see why I can't just use LCGPercentage.
double LCG_PullHi16 (uint32_t &seed);
float LCGPercentage(u32& seed);

//Debugging
//int findGap(u32 behind, u32 ahead, bool forward = 1);
int findGapInRange(u32 source, u32 target, uint range);
int findGapUntil(u32 source, u32 target, u32 limit);
int findGapDirectionless(u32 source, u32 target, int bailout = INT_MAX,bool *ok = nullptr);
double findGapConfident(u32 source, u32 target, bool forward = 1);
void debugPrint2DVec(std::vector<std::vector<int>>set);
void debugPrintVec(std::vector<int>set);



u32 modpow32(u32 base, u32 exp)
{
  u32 result = 1;
  while (exp > 0)
  {
    if (exp & 1)
      result = result * base;
    base = base * base;
    exp >>= 1;
  }
  return result;
}
int median(std::vector<int> &v)
{
    size_t n = v.size() / 2;
    nth_element(v.begin(), v.begin()+n, v.end());
    return v[n];
}

u32 LCG(u32 &seed){
    seed = seed * 214013 + 2531011;
    return seed;
}
u32 LCGn(u32 &seed, const u32 n)
{
    if (!n){
        return seed;
    }
    u32 ex = n - 1;
    u32 q = 0x343fd;
    u32 factor = 1;
    u32 sum = 0;
    while (ex > 0)
    {
        if (!(ex & 1))
        {
            sum = sum + (factor * modpow32(q, ex));
            ex--;
        }
        factor *= (1 + q);
        q *= q;
        ex /= 2;
    }
    seed = (seed * modpow32(0x343fd, n)) + (sum + factor) * 0x269EC3;
    return seed;
}

u32 LCG_BACK(u32 &seed) {
    seed = seed * 0xB9B33155 + 0xA170F641;
    return seed;
}
u32 LCGn_BACK(u32 &seed, const u32 n){
    u32 ex = n - 1;
    u32 q = 0xB9B33155;
    u32 factor = 1;
    u32 sum = 0;
    while (ex > 0)
    {
        if (!(ex & 1))
        {
            sum = sum + (factor * modpow32(q, ex));
            ex--;
        }
        factor *= (1 + q);
        q *= q;
        ex /= 2;
    }
    seed = (seed * modpow32(0xB9B33155, n)) + (sum + factor) * 0xA170F641;
    return seed;
}
float LCGPercentage(u32 &seed){
    LCG(seed);
    u32 hiSeed = seed >> 16;
    float percentResult = static_cast<float>(hiSeed)/65536;
    return percentResult;
    //return static_cast<float>(static_cast<u32>(LCG(seed) >> 16)/65536); // one liner - possibly cryptic
}

//Old findGap
//int findGap(u32 behind, u32 ahead, bool forward){
//    int counter = 0;
//    if (behind == ahead){
//        return 0;
//    }
//    if (forward){ //what should happen when the origin/behind is actually ahead of target/ahead?
//        while(behind != ahead){
//            LCG(behind);
//            counter++;
//            if (counter > 100000000){
//                std::cout <<"Error! findGap() got lost!";
//                break;
//            }
//        }
//    } else { //do i need to swap the params here? I just want to prevent an infinite loop.
//        while(behind != ahead){
//            LCG_BACK(behind);
//            counter++; //should we return this as a negative number?
//            if (counter > 100000000){
//                std::cout <<"Error!";
//                break;
//            }
//        }
//    }
//    return counter;
//}



int findGapInRange(u32 source, u32 target, uint range){
    //range is a discrete number of advances
    if (source == target){
        return 0;
    }
    uint counter = 0;
    while (source != target && counter < range){
        LCG(source);
        counter++;
        if (source == target){
            return counter;
        }
    }
    return -1; //replace with bool parameter?
}
int findGapUntil(u32 source, u32 target, u32 limit){
    //Finds a seed if it exists until or unless a limit seed is reached.
    //Returns -1 on failure.
    if (source == target){
        return 0;
    }
    int counter = 0;
    while (source != limit){
        LCG(source);
        counter++;
        if (source == target){
            return counter;
        }
    }
    //std::cout << std::hex << "findGapUntil() did not find seeds from: " << source << " find: " << target << "until: " << limit;
    return -1;
}

/*usage:
 * bool* resultValid;
 * int x = findGap(seed,targetseed,&resultValid);
 * resultValid is optional and will represent a success or failure, without relying solely on the return value alone.
*/
int findGapDirectionless(u32 source, u32 target, int bailout, bool* ok){
    //Searches both directions from source simultaneously, useful for when it's unclear whether the seed is ahead or behind the target.
    //Say it could be 20 calls ahead of target but user may have overshot, so need to check behind. This finds that. However, may come with performance issues at higher distances.
    //That's because a target 100K calls away actually endures 200K calls to LCG()
    //Would love a mathematical way to know if something was ahead or behind the target in O(1) or something.
    if (source == target){
        return 0;
    }
    double countUp = 0;
    double countDown = 0;
    u32 sourceUp = source;
    u32 sourceDown = source;
    while (sourceDown != target){
        if (countDown == -bailout || countUp == bailout){
            if(ok){*ok = false;}
            return 0;
        }
        LCG(sourceUp);
        countUp++;
        if (sourceUp == target){
            if(ok){*ok = true;}
            return countUp;
        }
        LCG_BACK(sourceDown);
        countDown++;
        //debug
        if (countUp == 100000000 || countDown == -100000000){
            std::cout << std::hex<< "findGapDirectionless() has likely failed: " << source << " to " << target;
        }
    }
    if(ok){*ok = true;}
    return -countDown++; //negative result, do not confuse with negative from findGapInRange
}
double findGapConfident(u32 source, u32 target, bool forward){
    //Caller is CONFIDENT that they know the direction of search.
    //Otherwise will take an extremely long time and produce a strange result. If used as intended, performance will be faster than directionless alternative.
    if (source == target){
        return 0;
    }
    double countUp = 0;
    double countDown = 0;
    while (source != target){
        if (forward){
            countUp++;
            LCG(source);
        } else {
            countDown--;
            LCG_BACK(source);
        }
        if (source == target){
            return (countUp > countDown) ? countUp : countDown; //one value will be >1, and the other will be 0
        }
    }
    return 0;
}








void debugPrint2DVec(std::vector<std::vector<int> > set){
    //FOR DEBUG:
    for (uint i = 0; i < set.size(); i++){
        for (uint j = 0; j < set.at(i).size(); j++){
            std::cout << set.at(i).at(j) << ", ";
        }
        std::cout << std::endl;
    }
}
void debugPrintVec(std::vector<int> set){
    for (uint i = 0; i < set.size(); i++)
    {
        std::cout << set.at(i);
        if (i != set.size()-1){
            std::cout << ", ";
        } else {
            std::cout <<".\n";
        }
        if (i % 20 == 19){
            std::cout << std::endl;
        }
    }
}





#endif // PROCESSCOREBLINK_H
