#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QKeyEvent>
#include <QSoundEffect>
#include <QDir>
#include "blinkbase.h"


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
    platform userPlatform;
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
//    QTimer *localTimerA; //Runs till next blink
//    QTimer *localTimerB;
    std::vector<QTimer*> simulTimerSet;
    QTimer *basicTimer; //Updates Gui
    int exitOffset; //ms
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

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_seeInputButton_clicked();

    void totalTimerUpdate();
//    void localTimerUpdateA();
//    void localTimerUpdateB();

    void testTimerUpdate();

    void timerGUIUpdate();

    void blinkOccurs();

    void on_arbTargetBox_valueChanged(int arg1);

    void on_increaseBlinksButton_clicked();

    void on_pushButton_3_clicked();

private:
    QSoundEffect sfxSearchSuccess;
    QSoundEffect sfxBlinkOccurs;
    QSoundEffect sfxCalibrationComplete;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
