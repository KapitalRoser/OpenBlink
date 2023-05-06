#include "../../../processCore.h"

struct alteration { //xd specific, blame precise framerates.
  int frame, amount;
};

float getThreshold(int SLB){
    return static_cast<float>((-SLB+110)*(SLB-10))/150000;
    //(2 - slb-10/50) * slb-10/50 * (1/60);
}
float blinkLogic(int SLB){
    if (SLB < 60){
        return getThreshold(SLB);
    }   
    else if (SLB < 180){
        return 1.0/60;
    } else {
        return 1;
    }
}
int next(u32 &seed,int& break_time, int &sinceLastBlink, int interval, int frameRate){
    if (break_time > 0){
        break_time -= 1;
        return false;
    }       
    sinceLastBlink += frameRate;
    if (sinceLastBlink < 10){
        return false;
    }
    float percent = LCGPercentage(seed);
    //tf << std::hex << seed << " : " << std::dec << sinceLastBlink << std::endl;
    // if (seed == 0x52ac7235){
    //     std::cout << "AAAAAA: " << percent;
    // }
    if (percent <= blinkLogic(sinceLastBlink)){
        break_time = interval;
        int result = sinceLastBlink;
        sinceLastBlink = 0;
        return result;
    }     
    return true;
}

void buildChangeFramesBlink(std::vector<alteration> &set,int frameOffset, int patternOffset, int size){
    //This function may be generic enough to be used in other places too
    //where you want to combine/sync two pattern layers
    std::vector<int> vals {1,1,0};
    std::vector<int> gaps {98,1,201};
     // size is in total frames, can also set to desired number of gaps, just change the middle item of the for loop back to pattern offset.
    for (patternOffset; frameOffset < size; patternOffset++)
    {
      //std::cout << frameOffset << " : " << vals[patternOffset%vals.size()] << "\n";
      alteration a;
      a.frame = frameOffset;
      a.amount = vals[patternOffset%vals.size()];
      set.push_back(a);
      frameOffset+= gaps[patternOffset%gaps.size()];
    }
    
    //debug
    // for (unsigned int i = 0; i < set.size(); i++)
    // {
    //   printf("%d : %d\n",set[i].frame,set[i].amount);
    // }
}

int emuAdvance(int i, std::vector<alteration> &alterSet){
    //simple case
    bool shouldAdvance = 0; //either 1 or 0.9. In reality it's a long many digit float
    if (i % 2){
        shouldAdvance = 1;
    } else {
        shouldAdvance = 0;
    }
    //alter case
    for (unsigned int j = 0; j < alterSet.size(); j++) //possibly slow, dunno how to binary search on a vect of structs
    {
        if (alterSet.at(j).frame == i){
            shouldAdvance = alterSet.at(j).amount;
            //aF << i << " : " <<std::hex << seed << std::dec << "\n";
            break;
        }
    }
    return shouldAdvance;
   
}

//struct for pattern data?

int main(){
    u32 inputSeed = 0x353A8F38;
    u32 seed = inputSeed;
    bool is_jpn = 0;
    bool is_Emu5 = 0; //Dolphin 5.0 behaviour
    int min_adv = 0;
    int max_adv = 200000;
    int interval = 0;  
    int advance = min_adv;
    int vFrames = 0;
    int prev_blink = 0;
    std::vector<int> blink_interval;
    int frameRate = 1;
    int break_time = 0;
    int sinceLastBlink = 0;
    std::ofstream testF ("seedList.txt");
    //std::ofstream altF ("altFile.txt");
    int numDelays = 0;
    int totalDelays = 0;
    int moduloRate = 69;
    int offset = 0;
    int actualFrameOffset = 63; //subjective? from a press.
    int resettingAdv = 9;

    int frameOffset = 12;
    int patternOffset = 0;
    
    std::vector<int> gaps {1,201,98};
    int alterFrame = 0;
    if (is_jpn){
        interval = 4;
    } else {
        interval = 5; 
    }
    bool coToolOldVersion = false;
    if (coToolOldVersion){
        vFrames = 3;
    }

    
    std::vector<alteration> altSet;
    buildChangeFramesBlink(altSet,frameOffset,patternOffset,max_adv); 
    std::cout << "Successfully built alt frames\n";    

    //auto advance
    LCGn(seed,min_adv);
    testF << std::hex;

    printf("#\tVFrame\tAdvSinceStart\tVFrameSLB\tAdvance\t\tSeed\tSLB\n");
    while(advance < max_adv-min_adv){
        
        int flag = next(seed,break_time,sinceLastBlink,interval,frameRate);
        if (is_Emu5){
                frameRate = emuAdvance(vFrames + actualFrameOffset, altSet);
                // advance += emuAdvance(vFrames + actualFrameOffset,altSet);
                resettingAdv += emuAdvance(vFrames + actualFrameOffset,altSet);
            }
        if (flag){
            advance += frameRate;
        }
        //testF << vFrames << " a: " << std::hex << seed << " : " << resettingAdv << std::dec << " : " << emuAdvance(vFrames + actualFrameOffset,altSet) << std::endl;
        vFrames += 1;
        //This is for modern XD.
        if (vFrames % moduloRate == offset && !is_Emu5){ //minimum 115 -- maximum 3 56's in a row. 
            sinceLastBlink--;
            numDelays++;
            totalDelays++;
            //std::cout << "Deducted at: " << vFrames << "\n";
        }
        if (flag > 1){
            if (!is_jpn){
                vFrames += 1;
            }
            int blink = vFrames;
            if (prev_blink == 0){
                prev_blink = blink;
                blink_interval.push_back(blink);
            } else {
                blink_interval.push_back(blink - prev_blink);
            }
            printf("%d\t%d\t%d\t\t%d\t\t%d\t\t%x\t%d\n",blink_interval.size()-1,vFrames,advance-min_adv,blink-prev_blink,advance,seed,flag);
            // std::cout << " : " << numDelays << " : " << totalDelays << "\n";
            testF << seed << " : " << flag << "\n";
            // numDelays = 0;
            prev_blink = blink;
            resettingAdv = 0;
        }
    }
    //debugPrintVec(blink_interval);

    testF.close();
}


/*
0x801d5dd0: Original param_1 * 60.
This float is now converted to int. Is typically close to 1.

GAMECUBE EXACT FRAME RATE: 

NTSC progressive: 1,620,000/26,999 (60.0022223045297973999) fps.
NTSC interlaced: 60,750,000/1,014,391 (59.8881496385516038687) fps.
PAL60 progressive: 60/1 (60.0) fps.
PAL60 interlaced: 18,750/313 (59.9041533546325878594) fps.
PAL progressive: 50/1 (50.0) fps.
PAL interlaced: 15,625/313 (49.9201277955271565495) fps.





5.0 vs modern:
5.0 alternates between 1 and 0.9 on the rate constantly. Occiassionaly doubles up on one or the other, so not perfect.
modern follows a rough 56-56-59 trio, with some adjustments.



Essentially, the game calls the clock to find out how long it took the last frame to render. It then does some math and then divides the number by 60.
Then this number can be multiplied by 60 back to get the rate relative to the target fps of 60.
This number is then used to increment SLB. It should be >=1, so SLB increments by 1 per frame. However if the game is running fast, it isn't a full 1/60th of a second since
the previous check. Therefore the rate is <1, and thus is rounded to 0. SLB will not be incremented. 

Given that the specific result likely depends on the entire suite of operations that occur each frame between blink checks, It's unlikely/unfeasible of me to
track *everything*. Therefore I am trying to guage a pattern, or a rate that is *good enough*

I may have to make some sacrifices, if I even get lucky on that. 
See the ones that trigger for RNG reasons are much safer, and aren't as likely to be affected. They would trigger just by virtue of their point rng value.
However this directly impacts blinks that occur at the 180 slb mark. These use whatever rng value is there at the time, which completely depends on how much SLB has been
delayed by this nonsense. 

However, if my rate is close enough such that all RNG based blinks are guaranteed, then I can black out the 180's. Hopefully the other blinks occur so often that the overall
number of blinks necessary for finding the seed are the same as colo. 


A full length pattern analysis of the lag may need to wait for scripting in modern.
5.0 alternates between 1 and 0.9x every frame, so it's different to modern. 


*/