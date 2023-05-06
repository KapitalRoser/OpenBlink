#include "keycodes.h"

KeyCodes::KeyCodes()
{
    m_blink = Qt::Key_Shift;
    m_slower = Qt::Key_Left;
    m_slowerX5 = Qt::Key_Q;
    m_faster = Qt::Key_Right;
    m_fasterX5 = Qt::Key_E;
    m_startStop = Qt::Key_Return;
}
KeyCodes::KeyCodes(int b, int s, int sx5, int f, int fx5, int p)
{
    m_blink = b;
    m_slower = s;
    m_slowerX5 = sx5;
    m_faster = f;
    m_fasterX5 = fx5;
    m_startStop = p;
}

QString keyCodeToName(int keyCode){
    QString keyName;//will differ among platforms for certain keys like shift or control. Investigate for mac.
    for (int i = 0; i < 12 ;i++ ) {
         if (keyCode == Qt::Key_F1 + i){
             keyName = "F" + QString::number(i);
         }
    }
    switch (keyCode) {
    case Qt::Key_Shift :
        keyName = "Shift";
        break;
    case Qt::Key_Escape:
        keyName = "Escape";
        break;
    case Qt::Key_Enter:
        keyName = "Enter";
        break;
    case Qt::Key_Return:
        keyName = "Return";
        break;
    case Qt::Key_CapsLock:
        keyName = "Caps Lock";
        break;
    case Qt::Key_Control:
        keyName = "Control";
        break;
    case Qt::Key_Space :
        keyName = "Space"; //Sometimes trouble with selecting
        break;
    case Qt::Key_Alt :
        keyName = "Alt";
        break;
    case Qt::Key_Backspace :
        keyName = "Backspace";
        break;
    case Qt::Key_Left :
        keyName = "Left Arrow"; //sometimes trouble
        break;
    case Qt::Key_Right :
        keyName = "Right Arrow"; //sometimes trouble
        break;
    case Qt::Key_Up :
        keyName = "Up Arrow"; //sometimes trouble
        break;
    case Qt::Key_Down :
        keyName = "Down Arrow"; //sometimes trouble
        break;
        //Note that tab isn't implemented, can add if there's significant demand
    default:
        return QKeySequence(keyCode).toString();
        break;
    }
    return keyName;
}


int KeyCodes::getBlinkKey() const
{
    return m_blink;
}

void KeyCodes::setBlink(int blink)
{
    m_blink = blink;
}

int KeyCodes::getSlowerKey() const
{
    return m_slower;
}

int KeyCodes::getSlowerX5Key() const
{
    return m_slowerX5;
}

void KeyCodes::setSlower(int slower)
{
    m_slower = slower;
}

void KeyCodes::setSlowerX5(int sx5)
{
    m_slowerX5 = sx5;
}

int KeyCodes::getFasterKey() const
{
    return m_faster;
}

int KeyCodes::getFasterX5Key() const
{
    return m_fasterX5;
}

void KeyCodes::setFaster(int faster)
{
    m_faster = faster;
}

void KeyCodes::setFasterX5(int fx5)
{
    m_fasterX5 = fx5;
}

int KeyCodes::getStartStopKey() const
{
    return m_startStop;
}

void KeyCodes::setStartStop(int startStop)
{
    m_startStop = startStop;
}

void KeyCodes::markActive(blinkKeyTypes type){
    //replace this with a map at some point.
    switch (type) {
    case eBLINK_bkt:
        activeKey = &m_blink;
        break;
    case eSLOWER_bkt:
        activeKey = &m_slower;
        break;
    case eSLOWERX5_bkt:
        activeKey = &m_slowerX5;
        break;
    case eFASTER_bkt:
        activeKey = &m_faster;
        break;
    case eFASTERX5_bkt:
        activeKey = &m_fasterX5;
        break;
    case eSTARTSTOP_bkt:
        activeKey = &m_startStop;
        break;
    default:
        qDebug() << "ERROR: invalid blinkKeyTypeEnum, check markActive()";
        break;
    }
}

void KeyCodes::setActive(int value)
{
    *activeKey = value; //protects the private variables
}





//This function searches the file for a specific section. Might be useful somewhere.

//int findSection(const std::string filename,int sectionNum){ //Interesting function, but not useful as we gotta rewrite the file anyways...
//    std::ifstream readF (filename,std::ios::binary); //Without this, tellg() breaks
//    std::string line = "";
//    for (int i = 0; i < sectionNum; i+= (line == settingsDelimiter)){
//        readF >> line; //basically if delimiter is reached, increment i for the number of sections desired.
//        qDebug() << "Line: " << QString::fromStdString(line) << " : Pos: " << readF.tellg();
//        if (readF.eof()){
//            qDebug() << "FILE LACKS DELIMITER";
//            readF.close();
//            return -1;
//        }
//    }
//    qDebug() << readF.peek();
//    int retPos = readF.tellg();
//    retPos++; //to get end of line position.
//    retPos += settingsDelimiter.length()-1; //to get 0-indexed position after delim
//    readF.close();
//    return retPos;
//}
