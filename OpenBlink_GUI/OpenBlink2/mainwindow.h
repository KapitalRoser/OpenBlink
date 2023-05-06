#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QKeyEvent>
#include <QSoundEffect>
#include <QDir>
#include <QGraphicsDropShadowEffect>
#include <QDesktopServices>
#include <QClipboard>
#include <filesystem>
#include <QMessageBox>
#include "blinkbase.h"
#include "keycodes.h"
#include "timersettings.h" //not to be confused with the timersettingsdialogue class

//MAKE SURE TO GO THROUGH PROCESS CORE AND BLINK BASE TO PRUNE ALL THE DEPRECATED CODE
//THERE'S A LOT OF UNUSED JUNK IN THERE!!!

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

typedef QGraphicsDropShadowEffect* QDropShadow;
typedef QGraphicsDropShadowEffect QDropShadowObj;
enum keyUnlock {INACTIVE, PRESEARCH, LISTEN, CALIBRATE};
//All states allow start/stop
//PRESEARCH = Only shift but not search
//Listen = Only Shift but now shift
//Calibrate = NO shift, allow slow/faster


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool keyUnlock;
    bool searchUnlock;
    int hotKeyLockState;
    bool resultsActiveView;
    u32 seedAfterMin;
    QString seedInfo;

    bool initialWriteComplete;

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

    QColor tbl_warningBlink;

    //QGraphicsDropShadowEffect* std_Shadow;

    //Timers
    QTimer *totalTimer; //Runs till target
    int totalTimerLimit;
    int localBlinkMs;
    QTimer *basicTimer; //Updates Gui
    QTimer *exitTimer; //Need to test if this can completely replace.

    QIcon xdWarningIcon;
    //sfx
    QSoundEffect sfxSearchSuccess;
    QSoundEffect sfxSearchFailure;
    QSoundEffect sfxBlinkOccurs;
    QSoundEffect sfxCalibrationComplete;
    QSoundEffect sfxExitCue;
    bool wasMuted;

    //There is probably a way to use just one or two timers instead, but likely more convoluted.

    //lots of these things are declared inside mainWindow to make logging easier
    int foundIdx;

    QString logStr; //VERY IMPORTANT


    void postInterval(QString results, int f, int row);
    void postPool(iterP setP, iterP limitP, int rowCurrent);
    void keyPressEvent(QKeyEvent* event);
    int performSearchPass(u32 &outSeed);
    void runCalibration(u32 seed);
    void highlightTableRow(int row,QColor color);
    int iterPToMS(iterP iter, float framerate);
    void restoreResults();
    void expandExitPool(int expandAmt = 10000);
    void nudgeCalibration(bool direction);
    platform collectPlatformInputs();
    searchParameters collectParamInputs();
    void writeAllSettings();
    bool applyAllSettings();
    QString createLog();

private slots:
    void on_startButton_clicked();

    void on_seeInputButton_clicked();

    void totalTimerUpdate();

    void timerGUIUpdate();

    void exitTimerUpdate();

    void blinkOccurs();

    void on_arbTargetBox_valueChanged(int arg1);

    void on_increaseBlinksButton_clicked();

    void on_slowerButton_clicked();

    void on_fasterButton_clicked();

    void on_flexValueBox_valueChanged(int arg1);

    void on_actionHotkeys_triggered();

    void on_actionTimer_triggered();

    void on_actionSounds_triggered();

    void on_actionGithub_triggered();

    void on_actionHelp_triggered();

    void on_actionLog_triggered();

    void on_copyButton_clicked();

    void on_pasteButton_clicked();

    void on_seedEntry_textChanged(const QString &arg1);

    void on_gameBox_currentIndexChanged(int index);

    void on_regionBox_currentIndexChanged(int index);

    void on_searchMinBox_valueChanged(int arg1);

    void on_searchMaxBox_valueChanged(int arg1);

    void on_arbTargetBox_editingFinished();

    void on_targetSeedEntry_selectionChanged();

    void on_targetPasteButton_clicked();

    void on_targetSeedEntry_textChanged(const QString &arg1);

    void on_targetSeedSearchButton_clicked();

    void on_targetSeedEntry_editingFinished();

    void on_slowerButtonX5_clicked();

    void on_fasterButtonX5_clicked();

private:
    Ui::MainWindow *ui;
};
//outside class
void applyShadow(QWidget* obj,std::queue<QDropShadow>&set);
std::queue<QDropShadow> fillShadowSet(int numShadows, QWidget* parent);
std::vector<std::string> settingsFileRead();
#endif // MAINWINDOW_H
