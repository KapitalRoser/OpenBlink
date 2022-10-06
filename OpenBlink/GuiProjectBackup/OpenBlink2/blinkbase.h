#ifndef BLINKBASE_H
#define BLINKBASE_H
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

#include <Windows.h>
#include <conio.h>
#include "processcoreblink.h"


struct pool {
    int blink = 0;
    u32 seed = 0;
};

typedef std::vector<pool>::iterator iterP;
typedef std::vector<int>::iterator iterI;


class blinkVars {
private:
    int m_breakTime = 0;
    int m_sinceLastBlink = 0;
    int m_interval = 0;

    //internal functions
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
public:
    blinkVars(){
        m_interval = 5;
    }
    blinkVars(region platformRegion){
        m_interval = (platformRegion == NTSCJ) ? 4 : 5;
    }

    //honestly framesPer60 should be in this class but I had a good reason why it shouldn't that I don't remember.
    int next (u32 &seed, int framesPer60){ //these params come from external source
        if (m_breakTime > 0){
            m_breakTime--;
            return false;
        }
        m_sinceLastBlink += framesPer60;
        if (m_sinceLastBlink < 10){
            return false;
        }
        if (LCGPercentage(seed) <= blinkLogic(m_sinceLastBlink)){
            m_breakTime = m_interval;
            int result = m_sinceLastBlink;
            m_sinceLastBlink = 0;
            return result;
        }
        return true; //I don't think this triggers in normal operation
    }

    //getters
    int getBreakTime(){return m_breakTime;}
    int getSinceLastBlink(){return m_sinceLastBlink;}
    int getInterval(){return m_interval;}
    //setters
    void setBreakTime(int input){m_breakTime = input;}
    void setSinceLastBlink(int input){m_sinceLastBlink = input;}
    void setInterval(int input){m_interval = input;}
};


struct incBlinkMsg{ //maybe not necessary for qt implementation?
    int targetIdx = 0;
    float framerate = 0;
    std::vector<int> blinksMS; //This is already in MS to save on timer computing resources.
    std::vector<int> blinksF; //may morph into pool if desired.
};

class platform{
    private: //define here or export to .cpp?
    int HEURISTIC = 69; //Nice - XD, rate of Time Compensation failures. ~68.138 or until a better number is found.
    bool m_is_xd = 0, m_is_emu5 = 0;
    region m_gameRegion = NTSCU;
    float m_framerate = 33.373; //as used by CoTool, other sites report 33.375 but this is closer.
    int m_fadeFrames = 5; //overwritten
    int m_fadeOutMS = round(m_framerate*m_fadeFrames); //will need to find rate acrosss all regions/games.
    //FadeOutMS gets added to the exit timer beeps, making them occur EARLIER.
    public:
    platform(){
        m_is_xd = 0;
        m_is_emu5 = 0;
        m_gameRegion = NTSCU;
    }
    platform(bool is_xd, bool is_emu5, region gameRegion){ //make a better constructor.
        m_is_xd = is_xd;
        m_is_emu5 = is_emu5;
        m_gameRegion = gameRegion;
        m_framesPer60 = is_xd ? 1 : 2; //used for SLB purposes. at 30fps its 2, at 60 is 1, and for xd it is slightly less than 60. Redundant??
        m_framerate = gameRegion == PAL50 ? is_xd ? 40/2:40 : is_xd ? 33.373/2:33.373; //xd halves the framerate.
        m_fadeFrames = gameRegion == PAL50 ? is_xd ? 19:11 : is_xd ? 21:13;
        //FADE FRAMES SHOULD BE USER ADJSUTABLE TOO, THE SAME WAY YOU WOULD IN THE MAIN TOOL.
        //Interestingly, flowtimer doesn't account for this, is left to the user to adjust
        //PAL50 < OTHERS
        //Why did I feel the need to alter this.
        //?? either restore to old cli numbers OR peek at what cotool does?
        //Gonna assume smallest number for now.
           //PAL60 == 22, sometimes 21?
           //PAL50 == 19, sometimes 20?
           //NTSCU == 21 to 23?
           //JPN == 22, sometimes 21?
            //Emu5 seems to be the same as modern here.
        m_fadeFrames += 5; //Target center of blink instead of beginning.
        m_fadeOutMS = round(m_framerate*m_fadeFrames);
    }

    int m_framesPer60 = 0; //The only variable that changes often --really should be part of blinkState but not sure how to write it.
    //why is this zero????
    void verifyFP60(int vFrames){
        if (m_is_xd){
            m_framesPer60 = m_is_emu5 ? vFrames % 2 : (vFrames % HEURISTIC);
        }
    }

    //technically these could be defined in .cpp rather than here in the .h
    bool getXD(){return m_is_xd;}
    bool getEmu5(){return m_is_emu5;}
    region getRegion(){return m_gameRegion;}
    float getFramerate(){return m_framerate;}
    int getFadeOutMS(){return m_fadeOutMS;}
    //can add a getter/setter function for framesPer60 if I really wanted to keep all vars private.

    void setXD(bool input){m_is_xd = input;}
    void setEmu5(bool input){m_is_emu5 = input;}
    void setRegion(region input){m_gameRegion = input;}
    void setFramerate(float input){m_framerate = input;}
    void setFadeOutMS(int input){m_fadeOutMS = input;} //should this really exist? Or should this only be set by constructor?
};


struct searchParameters {
    u32 inputSeed = 0;
    int maxSearch = 0; //Have different units possible like frames, seconds, advances, and blinks. -- maybe in the future
    int minSearch = 0;
    int flexValue = 0;
    int maxCalibrate = 0;
    int arbitrary_Target = 0;
};

std::vector<pool> generateBlinks(u32 seed, platform &userPlatform, int limit);
std::vector<int> searchPool(std::vector<pool> pool, std::vector<int>inputs, int flexValue);

#endif // BLINKBASE_H
