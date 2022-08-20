#include "blinkobj.h"
#include "processcoreblink.h"
blinkObj::blinkObj()
{

}



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



struct pool {
    int blink = 0;
    u32 seed = 0;
};

typedef std::vector<pool>::iterator iterP;
typedef std::vector<int>::iterator iterI;


class platform{
    private: //define here or export to .cpp?

    const int HEURISTIC = 69; //Nice - XD, rate of Time Compensation failures. ~68.138 or until a better number is found.
    bool m_is_xd = 0, m_is_emu5 = 0;
    region m_gameRegion = NTSCU;
    float m_framerate = 33.373;
    public:
    platform(){
        m_is_xd = 0;
        m_is_emu5 = 0;
        m_gameRegion = NTSCU;
    }
    platform(bool is_xd, bool is_emu5, region gameRegion){
        m_is_xd = is_xd;
        m_is_emu5 = is_emu5;
        m_gameRegion = gameRegion;
        m_framesPer60 = is_xd ? 1 : 2; //used for SLB purposes. at 30fps its 2, at 60 is 1, and for xd it is slightly less than 60. DOES THIS BREAK XD?
        m_framerate = (gameRegion == PAL50) ? 40 : 33.373; //as used by CoTool, other sites report 33.375 but this is closer.
        m_framerate = is_xd ? m_framerate / 2 : m_framerate;
    }
    int m_framesPer60 = 0; //The only variable that changes often --really should be part of blinkState but not sure how to write it.


    void verifyFP60(int vFrames){
        if (m_is_xd){
            m_framesPer60 = m_is_emu5 ? vFrames % 2 : (vFrames % HEURISTIC);
        }
    }


    //Getters
    bool getXD(){return m_is_xd;}
    bool getEmu5(){return m_is_emu5;}
    region getRegion(){return m_gameRegion;}
    float getFramerate(){return m_framerate;}
    //can add a getter/setter function for framesPer60 if I really wanted to keep all vars private.

    //Setters
    void setXD(bool input){m_is_xd = input;}
    void setEmu5(bool input){m_is_emu5 = input;}
    void setRegion(region input){m_gameRegion = input;}
    void setFramerate(float input){m_framerate = input;}

};
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


//The function in which blinkstate operates

std::vector<pool> generateBlinks(u32 seed, platform &userPlatform, int limit){
    //Why do we pass in blinkState instead of declaring here? NOT SEEING A GOOD REASON WHY NOT. GETS RESET ANYWAY FOR EXITPOOL.
    blinkVars blinkState = blinkVars(userPlatform.getRegion());
    std::vector<pool>outPool;
    int vFrames = 0, prev_blink = 0;
    for (int i = 0; i < limit; i++)
        {
            int flag = blinkState.next(seed,userPlatform.m_framesPer60); //trying to resist the urge to make a full blink class because it'll get ambiguous quickly. --??????????
            userPlatform.verifyFP60(vFrames);
            vFrames++;

            if (flag > 1){ //meaning we blinked.
                int blink = vFrames - prev_blink;
                outPool.push_back({blink,seed});
                prev_blink = vFrames;
            }
        }
    return outPool;
}
