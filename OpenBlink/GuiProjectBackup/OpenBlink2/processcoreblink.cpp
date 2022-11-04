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
