#ifndef TIMERSETTINGS_H
#define TIMERSETTINGS_H

#include "processcoreblink.h"
class TimerSettings
{
public:
    TimerSettings();
    TimerSettings(int offset, int gap, int beeps);
    void buildQueue(); //public if needed to rebuild outside of class?
    int getTiming();
    void timingAdvance();
    bool validate();
    bool updateFactor(int &changed, int input);
    int offset() const;
    int gap() const;
    int beeps() const;
    bool checkState();

    bool setGap(int gap); //bool allows for validate() to return an error
    bool setOffset(int offset); //If need more error codes then expand to int
    bool setBeeps(int beeps); //Should only need "Failed" or "Succeeded"


private:
    int m_offset;
    int m_gap;
    int m_beeps;

    std::queue<int> m_timings;
};

#endif // TIMERSETTINGS_H
