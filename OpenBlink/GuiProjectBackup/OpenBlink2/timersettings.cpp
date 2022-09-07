#include "timersettings.h"

TimerSettings::TimerSettings()
{
    m_offset = 5000;
    m_gap = 500;
    m_beeps = 5;
    if (validate()){
        buildQueue();
    }
}

TimerSettings::TimerSettings(int offset, int gap, int beeps)
{
    m_offset = offset; //Try not to use this constructor, if you manually input a invalid item, then queue wont build.
    m_gap = gap;
    m_beeps = beeps;
    if (validate()){
        buildQueue();
    }
}

bool TimerSettings::validate(){
    return (m_beeps-1)*m_gap <= m_offset;
}
//ex. 11 Beeps allowed for 5000ms. (beep on begin, and beep on end, so 11 inclusive.)
//500*10 = 5000 so 11-1 = 10 * 500 == 5000, all works out.

bool TimerSettings::updateFactor(int &changed, int input)
{
    changed = input;
    if (validate()){
        buildQueue();
        return 1;
    } else {
        if (checkState()){
            m_timings = {}; //Queue isn't valid anymore, so clear it.
        }
        return 0; //failure. value is still changed, but error code means that queue isn't built
    }
}
void TimerSettings::buildQueue()
{
    m_timings = {}; //clear through assignment
    for(int i = m_beeps-1; i >= 0; i--){ //More efficient than a if !(i % gap) style loop.
        m_timings.push(i*m_gap);
    }
}

int TimerSettings::getTiming()
{
    if (checkState()){
        return m_timings.front();
    } else {
        return -1;
    }
}

void TimerSettings::timingAdvance(){
    if(checkState()){
        m_timings.pop();
    }
}

int TimerSettings::offset() const
{
    return m_offset;
}

bool TimerSettings::setOffset(int offset)
{
    return updateFactor(m_offset,offset);
}

int TimerSettings::gap() const
{
    return m_gap;
}

bool TimerSettings::setGap(int gap)
{
    return updateFactor(m_gap,gap);
}

int TimerSettings::beeps() const
{
    return m_beeps;
}

bool TimerSettings::checkState()
{
    return !m_timings.empty(); //true == valid state, false == invalid state
}

bool TimerSettings::setBeeps(int beeps)
{
    return updateFactor(m_beeps,beeps);
}


