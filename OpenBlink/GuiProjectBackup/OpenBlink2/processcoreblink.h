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
enum coloSecondary {QUILAVA,CROCONAW,BAYLEEF}; //xd only has teddy
//enum secondaryMon {TEDDIURSA, QUILAVA, CROCONAW, BAYLEEF};
enum strCase {upper,lower}; //deprecated?


struct PokemonProperties
  {
    int hpIV = 0;
    int atkIV = 0;
    int defIV = 0;
    int spAtkIV = 0;
    int spDefIV = 0;
    int speedIV = 0;
    int hpStartingStat = 0;
    int hiddenPowerTypeIndex = 0;
    int hiddenPowerPower = 0;
    int genderIndex = 0;
    int natureIndex = 0;
    int isShiny = 0;
    u32 trainerId = 0;
  };
struct PokemonRequirements
{
  //Convert struct to class?
    int hpIV = 0;
    int atkIV = 0;
    int defIV = 0;
    int spAtkIV = 0;
    int spDefIV = 0;
    int speedIV = 0; //even if compress to array, will need to update a lot of aldelaro's functions.
    std::array<int,6> minusIV; //order matters here.
    std::array<int,6> neutralIV;
    std::array<int,6> plusIV;
    std::array<bool,25> validNatures; //convert from aldelaro's system to a straight set of nature ID's?
    std::array<bool,16> validHPTypes;
    int hiddenPowerPower = 0;
    int genderIndex = 0;
    int isShiny = 0;
    bool forceEven = 0; //depreciated.
    bool ability = 0; //unused for my purposes, maybe others will want.
};

//general functions block
u32 modpow32(u32 base, u32 exp);
int median(std::vector<int> &v);
std::string formatCase(std::string &str, strCase ulCase);
int consultPattern(int i, int offset, std::vector<int>pattern);
int ultraUltraCondensedCP(int i, int off, std::vector<int>pat); //good luck reading this lol, probably not even faster cuz compilers are smart.

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
u16 rollRNGwithHiSeed(u32 &seed);

//Could redesign above as:
void myRollRNGwithHiSeed(u32 &seed, float threshold, int numCalls);


//Pokemon Related
u32 simplePID (u32 &seed);
bool isPidShiny(const u16 TID, const u16 SID, const u32 PID);
void setIDs (u32 &seed, u32 &TID, u32 &SID);
int getPidGender(const u8 genderRatio, const u32 pid);
void extractIVs(PokemonProperties& properties, u32& seed);
void fillStarterGenHiddenPowerInfo(PokemonProperties& starter);
void coreDummyCam(uint32_t& seed,int camAngle1,int camAngle2,bool isFirst);

//basic generation -- only asks for gender ratio does not account for xd anti-shiny.
//Still unsure if I should put this here in the header, might need to modify it too much.
void generateMon(uint32_t inputSeed, int genderRatio);
//implement condensed generation

//File Reading
std::vector<int> decimalReadNumbersFromFile(std::string fileName);
std::vector<u32> hexReadNumbersFromFile(std::string fileName);
std::vector<std::string> readStringFromFile(std::string fileName);

//Debugging
int findGap(u32 behind, u32 ahead, bool forward);
void debugPrint2DVec(std::vector<std::vector<int>>set);
void debugPrintVec(std::vector<int>set);

#endif // PROCESSCOREBLINK_H
