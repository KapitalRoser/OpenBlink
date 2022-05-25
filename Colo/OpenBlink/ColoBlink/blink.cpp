#include "../../../processCore.h"


float getThreshold(int SLB){
    return static_cast<float>((-SLB+110)*(SLB-10))/150000;
}

void printBlinks(int i, int rngCount, int fBG, int minFrames, u32 seed){
    std::cout <<std::dec << std::setw(4) << i << " : "
    << std::setw(6) << rngCount << " : " 
    << std::setw(6) << fBG << " : " 
    << std::setw(6) << rngCount + minFrames << " : " 
    << std::setw(8) << std::hex << seed << std::endl;
}


float blinkLogic(int sinceLastBlink){
    float tHold;
    if (sinceLastBlink >= 10){
        if (sinceLastBlink < 60){
            tHold = getThreshold(sinceLastBlink);  
        } else if (sinceLastBlink < 180){
            tHold = 1.0/60;
        } else {
            tHold = 1; 
        }
    return tHold;
    }
    return -1;
}

int blink(u32 &seed,int &blinkGap, int& sinceLastBlink,int slbFactor,std::vector<int>&SLBList){
    if (blinkGap > 0){
        blinkGap--;
        return 0;
    }

    sinceLastBlink+=slbFactor;
    float threshold = blinkLogic(sinceLastBlink);

    if (threshold < 0){
        return 0;
    }

    float percentRoll = LCGPercentage(seed);
    if (percentRoll <= threshold){
        SLBList.push_back(sinceLastBlink);
        sinceLastBlink = 0;
        return 2;
    }
    return 1;
}



int main(){
    u32 inputSeed = 0x353A8F38;
    u32 seed = inputSeed;
    int frameWindow = 2000;
    float threshold = 0;
    region rate = NTSCU; 
    float frameSpeed = 60;
    int slbFactor = 2;
    int visualminGap = 5; //4 apparently for EU.
    std::vector<int>SLBList;
    if (rate == PAL60 || rate == PAL50){
        visualminGap = 4;
    }
    if (rate == PAL50) {
        frameSpeed = 50; //currently does nothing? Not necessary for logic?
    }
    int blinkGap = visualminGap;
    int blinkFlag;
    int sinceLastBlink = 0; 

    int visualFrame = 6918;
    int vFrameFromStart = 0;

    // int countRngCalls = 0;
    // for (int i = 0; i < frameWindow;i++) //increment is conditional
    // {   
    //     if (blinkGap > 0){
    //         blinkGap--;
    //     }
    //     sinceLastBlink += slbFactor;
    //     threshold = 0;
    //     if (sinceLastBlink >= 10){
    //         if (sinceLastBlink < 60){
    //             threshold = getThreshold(sinceLastBlink);  
    //         } else if (sinceLastBlink < 180){
    //             threshold = 1.0/60;
    //         } else {
    //             threshold = 1; 
    //         }
    //         float percentRoll = LCGPercentage(seed);
    //         countRngCalls++;
    //         if (percentRoll <= threshold){
    //             //std::cout << "Blink at: " << std::hex << seed << std::endl;
    //             blinkFlag = true;
    //             SLBList.push_back(sinceLastBlink);
    //             printBlinks(i,countRngCalls,sinceLastBlink,0,seed);
    //             sinceLastBlink = 0;
    //             blinkGap = visualminGap; 
                
                
    //         }
    //     } else {
    //         i--; //extends searching
    //     }
    
    // }

    int waitAdvances = 0;
    int successAdvances = 0;
    int formattedBlinkGap = 0;
    while(successAdvances < frameWindow){
        blinkFlag = blink(seed,blinkGap,sinceLastBlink,slbFactor,SLBList);
        waitAdvances++;
        if (formattedBlinkGap == 0){
            formattedBlinkGap = SLBList.front();
        } else {
            formattedBlinkGap = SLBList.back() - SLBList.at(SLBList.size()-2);
        }
        if (blinkFlag > 0){
            successAdvances++;
        }
        if (blinkFlag == 2){
            printBlinks(waitAdvances,successAdvances,formattedBlinkGap,0,seed);
        }

    }






    return 0;
}

