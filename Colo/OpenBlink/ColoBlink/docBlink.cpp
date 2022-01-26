#include "../../processCore.h"


float getThreshold(int SLB){
    return static_cast<float>((-SLB+110)*(SLB-10))/150000;
    //(2 - slb-10/50) * slb-10/50 * (1/60);
}
float literalThreshold(int SLB){
    float f0,f2,f1,f3,f31; //courtesy of lincoln's decomp of cotool.
    f0 = 0.0166667;
    f2 = 50;
    f1 = 2;
    f3 = SLB - 10;
    f2 = f3 / f2;
    f1 = f1 - f2;
    f31 = f2 * f1;
    f31 = f31 * f0;
    return f31;
}
//This program calculates all the logic for the blinking process.
//In the future, the reverse engineering of this to determine the seed is necessary.
//Technically this is enough to do catch rng.

int main(){
    u32 seed = 0x353A8F38;
    int frameWindow = 2000;
    float threshold = 0;
    region rate = NTSCU; //All rates except PAL 50hz work.
    float frameSpeed = 60;
    int slbFactor = 2; //This is "speedfactor" in ghidra. Idk where in memory it gets it, but it's always 2.
    //It turns out XD has some extra stuff goin on.
    // bool xd = true;
    // if (xd){
    //     slbFactor = 1;
    // }
    if (rate == PAL50) {
        frameSpeed = 50;
    }
    int sinceLastBlink = 0; //in 60fps, incremented by 2 for colo, 1 for xd.
    for (int i = 0; i < frameWindow; i++)
    {
        sinceLastBlink += slbFactor;
        threshold = 0;
        //blink logic -- set threshhold block
        if (sinceLastBlink > 10){
            if (sinceLastBlink < 60){
                threshold = getThreshold(sinceLastBlink);
            } else if (sinceLastBlink < 180){
                threshold = 1.0/60;
            } else {
                threshold = 1; //guarantee
            }
        }
        
        // if (i > 208 && i < 225){
        //     std::cout << std::dec << i << ": " << sinceLastBlink << ": " <<threshold <<": "<<std::hex<< seed<< std::endl; 
        // }

        //evaulate blink.
        float percentRoll = LCGPercentage(seed);
        //std::cout << "Evaluating: " << std::hex << seed << std::dec  << " With a value of: " << percentRoll << "\n";
        if (percentRoll <= threshold){
            //std::cout << "Blink at: " <<std::dec << i << " since " << sinceLastBlink<<  " with thresh: " << threshold << " : " << std::hex << seed << std::endl;
            std::cout << "Blink at: " << std::hex << seed << std::endl;
            sinceLastBlink = 8; //wtf lol
        }
        
        //std::cout << std::setprecision(17) << sinceLastBlink <<" : "<< threshold<< std::endl;
    }
     
    return 0;
}

//This works on NTSC! -- and presumably PAl 60hz as well.

/*

Frames since last blink are calculated at the 60 fps mark, even tho the game runs at 30. This is nice
for xd since that game does run 60fps on the poke menu.

There must be at least 10 frames have passed (5 at 30)
10th frame is 0%

12th frame is roughly 1/12 * 1/60.

Actual math is in func 801df1d0;

(2 - X) * 1/60

2/50 float rounded, perfect 0.04 would be: 3FA47AE147AE147B
instead it is rounded to: 0.039... so 3FA47AE140000000
0.039999999105930328369140625

2 - this num: 1.9600000381469727
1.96... * 0.0399999... = 0.784

sinceLastBlink -= 10;
div50 = sinceLastBlink / 50;

factor A = 2 - div50
factor B = factor A * div50
factor C = factor B * 1/60

Equation comes out to:
(2 - slb-10/50) * slb-10/50 * (1/60);
Will check float rounding but thanks to symbolab its equivalent to:
(-slb + 110) * (slb-10) / 150000

float rounding appears ok! :D

If sinceLastBlink is < 60 then
Do a bunch of math to gradually raise chances up to the 1/60 mark.


if sinceLastBlink is <180 then
threshold is 1/60 or 1.666... %
else 
guaranteed to blink (threshold = 1 -> 100%)
*/