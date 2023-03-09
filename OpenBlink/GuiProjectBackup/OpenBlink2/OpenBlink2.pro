QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
RC_ICONS = eye6.ico

ICON = eye6.icns
TARGET = OpenBlink
CONFIG += c++11
QT += multimedia
#make sure the icon stuff works on mac too.

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    blinkbase.cpp \
    hotkeysdialogue.cpp \
    keycodes.cpp \
    logwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    processcoreblink.cpp \
    soundsettingsdialogue.cpp \
    timersettings.cpp \
    timersettingsdialogue.cpp

HEADERS += \
    blinkbase.h \
    hotkeysdialogue.h \
    keycodes.h \
    logwindow.h \
    mainwindow.h \
    processcoreblink.h \
    soundsettingsdialogue.h \
    timersettings.h \
    timersettingsdialogue.h

FORMS += \
    hotkeysdialogue.ui \
    logwindow.ui \
    mainwindow.ui \
    soundsettingsdialogue.ui \
    timersettingsdialogue.ui

TRANSLATIONS = OpenBlink_jp.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc


DISTFILES += \
    settings.txt


