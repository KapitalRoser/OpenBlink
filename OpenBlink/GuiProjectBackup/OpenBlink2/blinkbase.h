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
    float TCFailureChance = 0;
};

typedef std::vector<pool>::iterator iterP;
typedef std::vector<int>::iterator iterI;

struct searchParameters {
    u32 inputSeed = 0;
    int maxSearch = 0; //Have different units possible like frames, seconds, advances, and blinks. -- maybe in the future
    int minSearch = 0;
    int flexValue = 0;
    int maxCalibrate = 0;
    int arbitrary_Target = 0;
};

class blinkVars {
private:
    int m_breakTime = 0;
    int m_sinceLastBlink = 0;
    int m_interval = 0;
    int m_framesPer60 = 0;
    //Add frames per 60 here with a constructor dependent on platform,
    //or make this a child object of platform?

    //internal functions
    float getThreshold(int SLB){
        return static_cast<float>((-SLB+110)*(SLB-10))/150000;
    }
    float blinkLogic(int SLB){
        if (SLB < 60){ //Rising rate
            return getThreshold(SLB);
        }
        else if (SLB < 180){ //Fixed rate
            return 1.0/60;
        } else { //Guaranteed rate
            return 1;
        }
    }
public:
    blinkVars(){
        m_interval = 5;
        m_framesPer60 = 2;
    }
    blinkVars(region platformRegion, bool xd){
        m_interval = (platformRegion == NTSCJ) ? 4 : 5;
        if (xd){
            m_interval = 13; //console may be higher.
            m_framesPer60 = 1;
        }
    }

    int next (u32 &seed, int framesPer60){ //these params come from external source
        if (m_breakTime > 0){
            m_breakTime--;
            return false;
        }
        m_sinceLastBlink += framesPer60;
        if (m_sinceLastBlink < 10){
            return false; //use this to indicate rising rate?
            //maybe return negative(SLB) to indicate where in rising rate they are??
        }
        float percent = LCGPercentage(seed);
        if (percent <= blinkLogic(m_sinceLastBlink)){
            m_breakTime = m_interval;
            int result = m_sinceLastBlink;
            m_sinceLastBlink = 0;
            return result;
        }
        return true; //This triggers when SLB > 10 but fails the condition -- should this be 0?
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

class platform{
    private: //define here or export to .cpp?
    bool m_is_xd = 0, m_is_emu5 = 0;
    region m_gameRegion = NTSCU;
    float m_frameRate = 33.373; //as used by CoTool, other sites report 33.375 but this is closer.
    int m_fadeFrames = 0; //overwritten
    int m_fadeOutMS = round(m_frameRate*m_fadeFrames); //will need to find rate acrosss all regions/games.
    //FadeOutMS gets added to the exit timer beeps, making them occur EARLIER.
    int m_framesPer60 = 0; //also overwritten
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
        m_framesPer60 = is_xd ? 1 : 2; //used for SLB purposes. at 30fps its 2, at 60 is 1, and for xd it is slightly less than 60.
        m_frameRate = gameRegion == PAL50 ? is_xd ? 40/2 : 40 : is_xd ? 33.373/2 : 33.373; //xd halves the framerate.
        //m_fadeFrames = gameRegion == PAL50 ? is_xd ? 19:11 : is_xd ? 21:13;
        //For whatever reason, attempting to account for the blink fadeout actually causes the user to be really early. I don't really know why.
        //Just leave it at zero unless you have a good reason and your testing supports it.
        m_fadeFrames += 5; //Target center of blink instead of beginning.
        m_fadeOutMS = round(m_frameRate*m_fadeFrames);
    }

    void verifyFP60(int vFrames){
        if (!m_is_xd){
            return;
        }
        m_framesPer60 = m_is_emu5 ? vFrames % 2 : 1;
    }

    //technically these could be defined in .cpp rather than here in the .h
    bool getXD(){return m_is_xd;}
    bool getEmu5(){return m_is_emu5;}
    region getRegion(){return m_gameRegion;}
    float getFrameRate(){return m_frameRate;}
    int getFadeOutMS(){return m_fadeOutMS;}
    int getFramesPer60(){return m_framesPer60;}
    //can add a getter/setter function for framesPer60 if I really wanted to keep all vars private.

    void setXD(bool input){m_is_xd = input;}
    void setEmu5(bool input){m_is_emu5 = input;}
    void setRegion(region input){m_gameRegion = input;}
    void setFrameRate(float input){m_frameRate = input;}
    void setFadeOutMS(int input){m_fadeOutMS = input;} //should this really exist? Or should this only be set by constructor?
    void setFramesPer60(int input){m_framesPer60 = input;}
};



std::vector<pool> generateBlinks(u32 seed, platform &userPlatform, int limit);
std::vector<int> searchPool(std::vector<pool> pool, std::vector<int>inputs, int flexValue);

#endif // BLINKBASE_H
