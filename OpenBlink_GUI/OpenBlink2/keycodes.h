#ifndef KEYCODES_H
#define KEYCODES_H

#include <QObject>
#include <QKeyEvent>


enum blinkKeyTypes {eBLINK_bkt, eSLOWER_bkt,eSLOWERX5_bkt, eFASTER_bkt, eFASTERX5_bkt, eSTARTSTOP_bkt};

class KeyCodes
{
public:
    KeyCodes();
    KeyCodes(int b, int s, int sx5, int f, int fx5, int p);

    int getBlinkKey() const;
    int getSlowerKey() const;
    int getSlowerX5Key() const;
    int getFasterKey() const;
    int getFasterX5Key() const;
    int getStartStopKey() const;
    void setBlink(int blink);
    void setSlower(int slower);
    void setSlowerX5(int sx5);
    void setFaster(int faster);
    void setFasterX5(int fx5);
    void setStartStop(int startStop);
    void markActive(blinkKeyTypes type);
    void setActive(int value);

private:
    int *activeKey = nullptr;
    int m_blink = 0; //used when keyCodes is uninitialized
    int m_slower = 0;
    int m_slowerX5 = 0;
    int m_faster = 0;
    int m_fasterX5 = 0;
    int m_startStop = 0;
};

//KeyCodeToName is NOT defined as a member function, but rather as an accessory function USED by this class AND OTHERS.
//at least for now.
QString keyCodeToName(int keyCode);

#endif // KEYCODES_H
