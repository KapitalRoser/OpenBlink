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

int findGap(u32 behind, u32 ahead, bool forward = 0){
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
