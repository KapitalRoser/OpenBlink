#include "../../processCore.h"

float getThreshold(int SLB){
    return static_cast<float>((-SLB+110)*(SLB-10))/150000;
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
int next(u32 &seed,int& break_time, int &sinceLastBlink, int interval){
    if (break_time > 0){
        break_time -= 1;
        return false;
    }       
    sinceLastBlink += 2;
    if (sinceLastBlink < 10){
        return false;
    }
    if (LCGPercentage(seed) <= blinkLogic(sinceLastBlink)){
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
    int min_adv = 0;
    int max_adv = 10000;
    int interval = 0;  
    int advance = min_adv;
    int vFrames = 0;
    int prev_blink = 0;
    std::vector<int> blink_interval;
    int break_time = 0;
    int sinceLastBlink = 0;
    if (is_jpn){
        interval = 4;
    } else {
        interval = 5; 
    }
    
    bool coToolOldVersion = true;
    if (coToolOldVersion){
        vFrames = 3;
    }
    //auto advance
    LCGn(seed,min_adv);

    printf("#\tVFrame\tAdvSinceStart\tVFrameSLB\tAdvance\t\tSeed\n");
    while(advance < max_adv-min_adv){
        int flag = next(seed,break_time,sinceLastBlink,interval);
        if (flag){
            advance += 1;
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
            printf("%d\t%d\t%d\t\t%d\t\t%d\t\t%x\n",blink_interval.size()-1,vFrames,advance-min_adv,blink-prev_blink,advance,seed);
            prev_blink = blink;
        }
    }
    //debugPrintVec(blink_interval);


}
    