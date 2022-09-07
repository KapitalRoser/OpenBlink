#include "keycodes.h"

KeyCodes::KeyCodes()
{
    m_blink = 0x01000020;
    m_slower = 0x01000012;
    m_faster = 0x01000014;
}
KeyCodes::KeyCodes(int b, int s, int f)
{
    m_blink = b;
    m_slower = s;
    m_faster = f;
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

void KeyCodes::setSlower(int slower)
{
    m_slower = slower;
}

int KeyCodes::getFasterKey() const
{
    return m_faster;
}

void KeyCodes::setFaster(int faster)
{
    m_faster = faster;
}

void KeyCodes::markActive(blinkKeyTypes type){
    if (type == eBLINK_bkt){
        activeKey = &m_blink;
    } else if (type == eSLOWER_bkt){
        activeKey = &m_slower;
    } else if (type == eFASTER_bkt){
        activeKey = &m_faster;
    } else {
        qDebug() << "ERROR: invalid blinkKeyType enum";
    }
}

void KeyCodes::setActive(int value)
{
    *activeKey = value; //protects the private variables
}

//void KeyCodes::alterKey(blinkKeyTypes type, int value){
//    if(type == eBLINK_bkt){
//        m_blink = value;
//    } else if (type == eSLOWER_bkt){
//        m_slower = value;
//    } else if (type == eFASTER_bkt){
//        m_faster = value;
//    } else {
//        qDebug() << "Key Type ERROR in setting";
//    }
//}



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
