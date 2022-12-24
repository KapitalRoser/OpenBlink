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

//TODO: before launching, move this into the game specific folders and update the paths.

//Settings file stuff, may need to redefine with the other applications?
const std::string settingsDelimiter = "---";
const std::string standardFileName = "settings.txt";
const std::string applicationName = "OpenBlink";

#if defined __APPLE__
const std::string settingsPath = std::string(getenv("HOME")) + "/Library/Application Support/applicationName";
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
int findGap(u32 behind, u32 ahead, bool forward = 1);
void debugPrint2DVec(std::vector<std::vector<int>>set);
void debugPrintVec(std::vector<int>set);

#endif // PROCESSCOREBLINK_H
