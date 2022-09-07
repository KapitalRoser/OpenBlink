#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QKeyEvent>
#include <QSoundEffect>
#include <QDir>
#include "blinkbase.h"
#include "keycodes.h"
#include "timersettings.h" //not to be confused with the timersettingsdialogue class

//MAKE SURE TO GO THROUGH PROCESS CORE AND BLINK BASE TO PRUNE ALL THE DEPRECATED CODE
//THERE'S A LOT OF UNUSED JUNK IN THERE!!!

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool keyUnlock;
    bool searchUnlock;
    bool resultsActiveView;
    searchParameters userSP;
    platform userPF;
    TimerSettings userTS;
    KeyCodes keys;
    std::vector<int> blinkList;
    std::vector<pool> mainPool;
    std::vector<pool> exitPool;
    iterP iterExit;

    QColor tbl_pastBlink;
    QColor tbl_currentBlink;
    QColor tbl_targetBlink;
    QColor tbl_upcomingBlink;

    //Timers
    QTimer *totalTimer; //Runs till target
    int totalTimerLimit;
    int localBlinkMs;
    QTimer *basicTimer; //Updates Gui

    //sfx
    QSoundEffect sfxSearchSuccess;
    QSoundEffect sfxSearchFailure;
    QSoundEffect sfxBlinkOccurs;
    QSoundEffect sfxCalibrationComplete;
    QSoundEffect sfxExitCue;

    //There is probably a way to use just one or two timers instead, but likely more convoluted.

    //lots of these things are declared inside mainWindow to make logging easier
    int foundIdx;
    void postInterval(QString results, int f, int row);
    void postPool(iterP setP, iterP limitP, int rowCurrent);
    void keyPressEvent(QKeyEvent* event);
    int performSearchPass(u32 &outSeed);
    void runCalibration(u32 seed);
    void highlightTableRow(int row,QColor color);
    int iterPToMS(iterP iter, float framerate);
    void restoreResults();
    void expandExitPool(int expandAmt);
    void nudgeCalibration(bool direction);
    platform collectPlatformInputs();
    void writeAllSettings();
private slots:
    void on_pushButton_clicked();

    void on_seeInputButton_clicked();

    void totalTimerUpdate();

    void timerGUIUpdate();

    void blinkOccurs();

    void on_arbTargetBox_valueChanged(int arg1);

    void on_increaseBlinksButton_clicked();

    void on_pushButton_3_clicked();

    void on_slowerButton_clicked();

    void on_fasterButton_clicked();

    void on_galesRadio_clicked();

    void on_coloRadio_clicked();

    void on_palRadio_clicked();

    void on_ntscuRadio_clicked();

    void on_ntscjRadio_clicked();

    void on_flexValueBox_valueChanged(int arg1);

    void on_actionHotkeys_triggered();

    void on_actionTimer_triggered();

    void on_actionSounds_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
