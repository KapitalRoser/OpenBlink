#include "processcoreblink.h"

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

std::string formatCase(std::string &str, strCase ulCase){
    for (uint i = 0; i < str.length(); i++)
    {
        if (ulCase){
            str.at(i) = tolower(str.at(i));
        } else {
            str.at(i) = toupper(str.at(i));
        }
    }
    return str;
}

int consultPattern(int i, int offset, std::vector<int> pattern){
    iterInt iter = pattern.begin(); //Call this implementation when you know what pattern you're using.
    int range = pattern.size();
    if (i < offset){
        iter += (i % (offset)); //This has flaws
    } else {
        iter += (i-offset) % range; //Magic
    }
    return *iter;
}
int ultraUltraCondensedCP(int i, int off, std::vector<int> pat){
    return (i<off)*(*(pat.begin()+(i % off)))+!(i<off)*(*(pat.begin()+((i-off)%pat.size()))); //This is for shits 'n giggles, don't use this.
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
double LCG_PullHi16(uint32_t &seed){ //Original function by Aldelaro5
    const int divisor = 65536;
    double X = 0;
    LCG(seed);
    X = seed >> 16;
    X = X/divisor;
    return X;
}
float LCGPercentage(u32 &seed){
    LCG(seed);
    u32 hiSeed = seed >> 16;
    float percentResult = static_cast<float>(hiSeed)/65536;
    return percentResult;
    //return static_cast<float>(static_cast<u32>(LCG(seed) >> 16)/65536); // one liner - possibly cryptic
}
u16 rollRNGwithHiSeed(u32 &seed)
{ //mostly used in the NTSC naming screen, may have uses elsewhere, like blink.
    LCG(seed);
    u16 hiSeed = seed >> 16;
    if (static_cast<double>(hiSeed) / 65536.0 < 0.1){
        LCGn(seed, 4); //10% rule - if the hi 16 bits are numerically in the bottom 10%, reroll.
    }
    return hiSeed; //debugging.
}
void myRollRNGwithHiSeed(u32 &seed, float threshold, int numCalls){
    if (LCGPercentage(seed) < threshold){ //0.1 on name screen
        LCGn(seed,numCalls); //4 on name screen
    }
}

u32 simplePID(u32 &seed){
    u32 hId = LCG(seed) >> 16;
    u32 lId = LCG(seed) >> 16;
    u32 PID = (hId << 16) | (lId);
    return PID;
}
bool isPidShiny(const u16 TID, const u16 SID, const u32 PID)
{
    return ((TID ^ SID ^ (PID & 0xFFFF) ^ (PID >> 16)) < 8);
}
void setIDs(u32 &seed, u32 &TID, u32 &SID){
    TID = LCG(seed) >> 16; //lTrainerId
    SID = LCG(seed) >> 16; //hTrainerId
}
int getPidGender(const u8 genderRatio, const u32 pid)
{
    return genderRatio > (pid & 0xff) ? 1 : 0;
}
void extractIVs(PokemonProperties &properties, u32 &seed)
{
    // HP, ATK, DEF IV
    LCG(seed);
    properties.hpIV = (seed >> 16) & 31;
    properties.atkIV = (seed >> 21) & 31;
    properties.defIV = (seed >> 26) & 31;
    // SPEED, SPATK, SPDEF IV
    LCG(seed);
    properties.speedIV = (seed >> 16) & 31;
    properties.spAtkIV = (seed >> 21) & 31;
    properties.spDefIV = (seed >> 26) & 31;
}
void fillStarterGenHiddenPowerInfo(PokemonProperties &starter)
{
    int typeSum = (starter.hpIV & 1) + 2 * (starter.atkIV & 1) + 4 * (starter.defIV & 1) +
            8 * (starter.speedIV & 1) + 16 * (starter.spAtkIV & 1) +
            32 * (starter.spDefIV & 1);
    starter.hiddenPowerTypeIndex = typeSum * 15 / 63;
    int powerSum = ((starter.hpIV & 2) >> 1) + 2 * ((starter.atkIV & 2) >> 1) +
            4 * ((starter.defIV & 2) >> 1) + 8 * ((starter.speedIV & 2) >> 1) +
            16 * ((starter.spAtkIV & 2) >> 1) + 32 * ((starter.spDefIV & 2) >> 1);
    starter.hiddenPowerPower = (powerSum * 40 / 63) + 30;
}
void coreDummyCam(uint32_t &seed, int camAngle1, int camAngle2, bool isFirst){
    int v1 = 0;
    int modulus = isFirst ? 10 : 12;
    do{
        LCG(seed);
        v1 = (seed >> 16) % modulus;
    } while ((isFirst && (v1 >= 10 || v1 == 3)) || v1 == camAngle1 || v1 == camAngle2);
    LCG(seed);
    if (v1 >= 5){
        LCG(seed);
        if (v1 == 8){
            LCGn(seed,3);
        }
        if (v1 >= 10){
            LCGn(seed,2);
        }
    }
}
void generateMon(uint32_t inputSeed, int genderRatio){
    //   uint32_t TID = 0; //Tid isn't important here since TID is already set. *might matter for shiny check on quil.
    uint32_t PID = 0;
    uint32_t seed = inputSeed;
    uint32_t outSeed = 0;
    std::string nature = " ";
    std::string hiddenPowerType = " ";
    //Gender ratio reference:  0x7F for teddy (50/50) and 0x1F for johto starters (87.5/12.5)
    const std::string naturesList[25] = {"Hardy","Lonely","Brave","Adamant","Naughty","Bold","Docile","Relaxed",
                                         "Impish","Lax","Timid","Hasty","Serious","Jolly","Naive","Modest","Mild","Quiet","Bashful",
                                         "Rash","Calm","Gentle","Sassy","Careful","Quirky"};
    const std::string hpTypes[16] = {"Fighting", "Flying", "Poison", "Ground", "Rock", "Bug", "Ghost",
                                     "Steel", "Fire", "Water", "Grass", "Electric",  "Psychic", "Ice","Dragon","Dark"};

    std::cout << std::left;

    //Some tid/sid stuff, possibly a dummy pid
    seed = LCGn(seed,4);

    outSeed = seed;
    //Would be High bits/Secret ID, used for Shiny.

    // LCG(seed); These do not appear on shadow generation.
    // LCG(seed); //originally from Dummy ID, leftover.

    //IVS
    LCG(seed);
    int hp = (seed >> 16) & 31;
    int atk = (seed >> 21) & 31;
    int def = (seed >> 26) & 31;

    LCG(seed);
    int spe = (seed >> 16) & 31;
    int spa = (seed >> 21) & 31;
    int spd = (seed >> 26) & 31;


    LCG(seed); //Ability call
    //PID STUFF blind, considers no weights:
    uint32_t hId = LCG(seed) >> 16;
    uint32_t lId = LCG(seed) >> 16;
    PID = (hId << 16) | (lId);

    std::string displayNature = naturesList[PID % 25];
    bool pidGender = uint(genderRatio) > (PID & 0xFF);
    std::string displayGender;
    if (pidGender){
        displayGender = "Female";
    } else {
        displayGender = "Male";
    }
    std::cout
            << "Seed"
    << ": "
    << std::hex
    << std::setw(8) << outSeed
    << " PID: "
    << std::setw(8) << PID
    << std::dec
    << "  " << std::setw(2) << hp << " " << std::setw(2) << atk << " " << std::setw(2) << def << " " << std::setw(2)
    << spa << " " << std::setw(2) << spd << " " << std::setw(2) << spe << "  "
    << std::setw(7) << displayNature << "  " << displayGender
    << std::endl;
}

std::vector<int> decimalReadNumbersFromFile(std::string fileName)
{
    int lineRead = 0;
    std::vector<int> data; //Setup
    std::ifstream file(fileName);
    std::cout << "Read some data! \n";
    if (file.fail())
    {
        std::cout << "File inaccessible";
        exit(EXIT_FAILURE);
    }
    while (!(file.fail()))
    {
        file >> lineRead;
        data.push_back(lineRead);
    }
    file.close();
    std::cout << "Read: " << data.size() << " items.\n";
    return data;
}
std::vector<u32> hexReadNumbersFromFile(std::string fileName)
{
    u32 value;
    std::string lineRead = "";
    std::stringstream hexConvert;
    std::vector<u32> data; //Setup
    std::ifstream file(fileName);
    std::cout << "Read some data! \n";
    if (file.fail())
    {
        std::cout << "File inaccessible";
        exit(EXIT_FAILURE);
    }
    while (!(file.fail()))
    {
        getline(file,lineRead);
        hexConvert << std::hex << lineRead; //cuz i just HAD to have my docs in hexa and not int...;
        hexConvert >> value;
        hexConvert.clear();
        hexConvert.str("");
        data.push_back(value);
        // std::cout << "Lines read: " << data.size() << endl;
    }
    file.close();
    return data;
}
std::vector<std::string> readStringFromFile(std::string fileName)
{
    std::vector<std::string> data; //Setup
    std::string lineRead = "";
    std::ifstream file(fileName);
    if (file.fail())
    {
        std::cout << "File inaccessible";
        exit(EXIT_FAILURE);
    }
    while (!(file.fail()))
    {
        getline(file,lineRead);
        data.push_back(lineRead);
    }
    file.close();
    std::cout << "lines from " + fileName + " read: " << data.size() << std::endl;
    return data;
}

int findGap(u32 behind, u32 ahead, bool forward){
    int counter = 0;
    if (forward){ //what happens when the origin/behind is actually ahead of target/ahead? infinite loop?
        while(behind != ahead){
            LCG(behind);
            counter++;
            if (counter > 100000000){
                std::cout <<"Error! findGap() got lost!";
                break;
            }
        }
    } else { //do i need to swap the params here? I just want to prevent an infinite loop.
        while(behind != ahead){
            LCG_BACK(behind);
            counter++;
            if (counter > 100000000){
                std::cout <<"Error!";
                break;
            }
        }
    }
    return counter;
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
