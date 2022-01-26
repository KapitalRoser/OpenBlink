#include "../../processCore.h"

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
int next(u32 &seed,int& break_time, int &sinceLastBlink, int interval, int framesPer60){
    if (break_time > 0){
        break_time -= 1;
        return false;
    }       
    sinceLastBlink += framesPer60;
    if (sinceLastBlink < 10){
        return false;
    }
    float percent = LCGPercentage(seed);

    if (percent <= blinkLogic(sinceLastBlink)){
        break_time = interval;
        int result = sinceLastBlink;
        sinceLastBlink = 0;
        return result;
    }     
    return true;
}


int main(){
    u32 inputSeed = 0x353A8F38;
    u32 seed = inputSeed;
    bool is_jpn = 0;
    bool is_emu5 = 0; //Dolphin 5.0 behaviour
    bool is_xd = 1;
    int min_adv = 0;
    int max_adv = 2000;
    int interval = is_jpn ? 4 : 5;  
    int advance = min_adv;
    int vFrames = 0;
    int prev_blink = 0;
    std::vector<int> blink_interval;
    int framesPer60 = 1;
    int break_time = 0;
    int sinceLastBlink = 0;

    const int HEURISTIC = 69;

    // bool coToolOldVersion = false;
    // if (coToolOldVersion){
    //     vFrames = 3;
    // }    

    //auto advance
    LCGn(seed,min_adv);

    printf("#\tVFrame\tAdvSinceStart\tVFrameSLB\tAdvance\t\tSeed\tSLB\n");
    while(advance < max_adv-min_adv){
        int flag = next(seed,break_time,sinceLastBlink,interval,framesPer60);
        if (is_xd){
            if (is_emu5){
                if (is_emu5){
                    framesPer60 = vFrames % 2;
                }
            } else {
                if (vFrames % HEURISTIC == 0){
                    framesPer60 = 0;
                } else {
                    framesPer60 = 1;
                }
            }
        }
        if (flag){
            advance += framesPer60;
        }
        vFrames += 1;
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
            prev_blink = blink;
        }
    }
    debugPrintVec(blink_interval);
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