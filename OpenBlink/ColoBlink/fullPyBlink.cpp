#include "../../processCore.h"

float getThreshold(int SLB){
    return static_cast<float>((-SLB+110)*(SLB-10))/150000;
}

int next(u32 &seed,int& break_time, int &sinceLastBlink, int interval){
    int result;
    float threshold;
    if (break_time > 0){
        break_time -= 1;
        return false;
    }       
    sinceLastBlink += 2;
    if (sinceLastBlink < 10){
        return false;
    }
    if (sinceLastBlink < 60){
        threshold = getThreshold(sinceLastBlink);
    }   
    else if (sinceLastBlink < 180){
        threshold = 1.0/60;
    } else {
        threshold = 1;
    }
    float percent = LCGPercentage(seed);
    if (percent <= threshold){
        break_time = interval;
        result = sinceLastBlink;
        sinceLastBlink = 0;
        return result;
    }     
    return true;
}

int main(){
    u32 inputSeed = 0x353A8F38;
    u32 seed = inputSeed;
    bool is_eu = 0;
    int min_adv = 0;
    int max_adv = 2000;
    int interval = 0;  
    int advance = min_adv;
    int wait_advance = 0;
    int prev_blink = 0;
    std::vector<int> blink_interval;
    int break_time = 0;
    int sinceLastBlink = 0;
    if (is_eu){
        interval = 5;
    } else {
        interval = 4;
    }
    
    //auto advance
    // tracker = BlinkTracker(seed);
    // for (int i = 0; i < min_adv){
    //     next(seed,break_time,sinceLastBlink,interval);
    // }
    LCGn(seed,min_adv);

    
    printf("VFrame\tAdvSinceStart\tVFrameSLB\tAdvance\t\tSeed\n");
    while(advance < max_adv-min_adv){
        int flag = next(seed,break_time,sinceLastBlink,interval);
        //std::cout << "flag res: " << flag << "\n";
        if (flag){
            advance += 1;
        }
        wait_advance += 1;
        if (flag != true){
            if (flag != false){
                u32 current_seed = seed;
                int blink = wait_advance;
                if (prev_blink == 0){
                    prev_blink = blink;
                    blink_interval.push_back(blink);
                } else {
                    blink_interval.push_back(blink - prev_blink);
                }
                printf("%d\t%d\t\t%d\t\t%d\t\t%x\n",wait_advance,advance-min_adv,blink-prev_blink,advance,current_seed);
                prev_blink = blink;
            }
        }
    }
    debugPrintVec(blink_interval);


}
    