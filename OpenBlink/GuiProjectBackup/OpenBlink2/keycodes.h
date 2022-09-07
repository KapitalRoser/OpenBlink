#ifndef KEYCODES_H
#define KEYCODES_H

#include <QObject>
#include <QKeyEvent>


enum blinkKeyTypes {eBLINK_bkt, eSLOWER_bkt, eFASTER_bkt};
//Honestly, this name no longer fits if being used for other applications. It really should be BlinkKeys or something.
class KeyCodes
{
public:
    KeyCodes();
    KeyCodes(int b, int s, int f);

    int getBlinkKey() const;
    int getSlowerKey() const;
    int getFasterKey() const;
    void setBlink(int blink);
    void setSlower(int slower);
    void setFaster(int faster);
    void markActive(blinkKeyTypes type);
    void setActive(int value);

private:
    int *activeKey = nullptr;
    int m_blink = 0; //used when keyCodes is uninitialized
    int m_slower = 0;
    int m_faster = 0;

};

//KeyCodeToName is NOT defined as a member function, but rather as an accessory function USED by this class AND OTHERS.
//at least for now.
QString keyCodeToName(int keyCode);


#endif // KEYCODES_H

//    keyCodes (const keyCodes&  k1) { //error, something about trivial operations
//        m_blink = k1.m_blink; //Only declare a copy constructor if I have something unique to add
//        m_slower = k1.m_slower;
//        m_faster = k1.m_faster;
//    }

//could add in get_key_name code if needed? Maybe other funcs?
//Keyname would require writing a std:: version of the current Qt func in HotkeyDialogue
//Such a function would be OS specific, so one for Mac, and a different one for windows, maybe linux.
//Honestly could really beef up this class with lots of stuff from hotkeydialogue.
//Might get a bit verbose though
