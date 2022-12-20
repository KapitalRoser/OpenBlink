#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "hotkeysdialogue.h"
#include "timersettingsdialogue.h"
#include "soundsettingsdialogue.h"
#include "logwindow.h"

/*TODO:
    -BUGS:
    -Arrow keys on ArbBox
    -Bad fadeout timing for all regions
    -Final seed getting lost when arbTarget = 10 -- but only sometimes.
    -Windows and Mac Build testing.
     Then done!
//Optional
    -xd warning seeds are visually cut-off, still copyable
    -Allow gui to shrink for condensed screens like laptops.
    -Retry QThread for performance reasons -- Only for searcher, calibration runs fine on toaster
    -Add century gothic font to resources??
    -Up/Down Arrow keys to adjust arbitrary_target?
    -Clean up the .h files
    -Tidy up blink class structure to allow a parent battleblink timeline object to be used. Would replace generateBlinks()
*/

//GLOBALS
QString tableStyle =
        "QTableWidget {font: 9pt \"Century Gothic\";max-width:210px;}"
        "QTableWidget QScrollBar:vertical{background: white;border:1px solid white;border-radius:5px;}"
        "QTableWidget QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical{background:none;}"
        "QTableWidget QScrollBar::handle:vertical{"
        "background-color:#e0e0e0;"
        "border-radius: 5px;"
        "min-height: 100px;}"
        "QTableWidget QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical{background:none;}"
        "QTableWidget QHeaderView::section{background-color:white;border:none;font: 9pt \"Century Gothic\";}"
        "QTableWidget QTableCornerButton:section{background-color:white;border-top-left-radius:15px;border:none;}"
        ;
auto start = std::chrono::high_resolution_clock::now(); //super useful, leave as global

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->arbTargetBox->installEventFilter(this);
    QAction *logAction = ui->menubar->addAction("Log");
    connect(logAction,&QAction::triggered,this,&MainWindow::on_actionLog_triggered);
    QAction *githubAction = ui->menubar->addAction("GitHub");
    connect(githubAction,&QAction::triggered,this,&MainWindow::on_actionGithub_triggered);
    QAction *helpAction = ui->menubar->addAction("Help");
    connect(helpAction,&QAction::triggered,this,&MainWindow::on_actionHelp_triggered);
    std::queue<QDropShadow> shadowSet;
    shadowSet = fillShadowSet(10,this); //update this number for number of shadows needed
    applyShadow(ui->statusFrame,shadowSet);
    applyShadow(ui->seedQFrame,shadowSet);
    applyShadow(ui->timerFrame,shadowSet);
    applyShadow(ui->paramsFrame,shadowSet);
    applyShadow(ui->platformFrame,shadowSet);
    applyShadow(ui->blinkTableFrame,shadowSet);
    //repeat as necessary for each object

    tbl_pastBlink = QColor(222,222,222); //gray
    tbl_currentBlink = QColor(168,255,200); //light green
    tbl_targetBlink = QColor(255,236,116);//Gold
    tbl_upcomingBlink = QColor(255,255,255); //White

    tbl_warningBlink = QColor(255,153,102); //xd warning, not too strong.
    xdWarningIcon = QIcon(":/resfix1/sign-warning-icon.png");

    resultsActiveView = false;
    hotKeyLockState = INACTIVE;
    ui->copyButton->setVisible(false);
    ui->copyButton->setEnabled(false);

    totalTimer = new QTimer(this); //Governs the whole process
    basicTimer = new QTimer(this); //Repeats continuously. Purely to create events. Even if the sfx delays this on older pcs, the main timer remains accurate.
    exitTimer = new QTimer(this); //how often do we run this timer?

    totalTimer->setSingleShot(true); //Pretty sure this is fine
    totalTimer->setTimerType(Qt::PreciseTimer); //CRITICAL IMPORTANCE. Otherwise defaults to Coarse Timer, which can be wrong by up to 5%
    exitTimer->setSingleShot(true);
    exitTimer->setTimerType(Qt::PreciseTimer);
    //There is also a setsingleshot function, avoiding the need to declare and object. However, having the object may be useful

    //connects
    connect(basicTimer,&QTimer::timeout, this, &MainWindow::timerGUIUpdate);
    connect(totalTimer, &QTimer::timeout, this, &MainWindow::totalTimerUpdate);
    connect(exitTimer,&QTimer::timeout,this,&MainWindow::exitTimerUpdate);

    //read settings file
    if (applyAllSettings()){
        return;
    }
    //loads defaults if file doesn't exist
    keys = KeyCodes();
    userTS = TimerSettings();
    userPF = collectPlatformInputs();
    userSP = collectParamInputs();

    sfxSearchSuccess.setSource(QUrl::fromLocalFile(":/resfix1/lvlup.wav")); //Allow user to mute or adjust volume
    sfxSearchFailure.setSource(QUrl::fromLocalFile(":/resfix1/searchFailure.wav"));
    sfxBlinkOccurs.setSource(QUrl::fromLocalFile(":/resfix1/blinkWoop.wav"));
    sfxCalibrationComplete.setSource(QUrl::fromLocalFile(":/resfix1/snagSuccess.wav"));
    sfxExitCue.setSource(QUrl::fromLocalFile(":/resfix1/blinkBeep1.wav"));

    sfxSearchSuccess.setVolume(0.2);
    sfxSearchFailure.setVolume(0.2);
    sfxBlinkOccurs.setVolume(0.2);
    sfxCalibrationComplete.setVolume(0.2);
    sfxExitCue.setVolume(0.2);
    writeAllSettings(); //creates new settings file.


}

platform MainWindow::collectPlatformInputs(){
    //This is basically just a constructor
    return platform( ui->gameBox->currentIndex(),
                    (ui->gameBox->currentIndex() == 2),
                     region(ui->regionBox->currentIndex()));
}

searchParameters MainWindow::collectParamInputs()
{
    //This is also just a constructor
    return searchParameters({ui->seedEntry->text().toUInt(nullptr,16),
                             ui->searchMaxBox->value(),
                             ui->searchMinBox->value(),
                             ui->flexValueBox->value(),
                             10000,
                             ui->arbTargetBox->value()});
}


void MainWindow::writeAllSettings(){
    //this is kinda inefficient, as it get's called every time the user changes a value. But not sure how else to do it. Maybe on window exit only?
    if (!initialWriteComplete){
        return;
    }
    std::ofstream settingsW(settingsName);
    userPF = collectPlatformInputs();
    userSP = collectParamInputs();
    //platform
    settingsW << userPF.getXD() << "\n";
    settingsW << userPF.getEmu5() << "\n";
    settingsW << userPF.getRegion() << "\n";

    //search parameters
    settingsW << userSP.flexValue << "\n";
    settingsW << userSP.minSearch << "\n"; //unit Converter?
    settingsW << userSP.maxSearch << "\n";
    settingsW << userSP.arbitrary_Target << "\n";

    //hotkeys
    settingsW << keys.getBlinkKey() << "\n";
    settingsW << keys.getSlowerKey() << "\n";
    settingsW << keys.getFasterKey() << "\n";
    settingsW << keys.getStartStopKey() << "\n";

    //Timer Settings
    settingsW << userTS.offset() << "\n";
    settingsW << userTS.gap() << "\n";
    settingsW << userTS.beeps() << "\n";
    settingsW << userTS.input() << "\n";

    //Sound and Volume
    std::vector<QSoundEffect*> pkg = {&sfxSearchSuccess,&sfxSearchFailure,&sfxBlinkOccurs,&sfxCalibrationComplete,&sfxExitCue};
    for (QSoundEffect* x: pkg) {
        settingsW << x->source().toEncoded().toStdString() << "\n";
        settingsW << x->volume() << "\n";
        settingsW << x->isMuted() << "\n";
    }
    //settingsW << "END";
    settingsW.close();
}

std::vector<std::string> settingsFileRead(){
    std::ifstream settingsR(settingsName);
    std::string line;
    std::vector<std::string> settingsData;
    if (settingsR.fail()){
        //NO SETTINGS FILE
        qDebug() << "FILE NOT FOUND!";
        return {};
    }
    while (!settingsR.fail()){
        settingsR >> line;
        settingsData.push_back(line);
    }
    settingsData.pop_back();
    return settingsData; //big string
}

bool MainWindow::applyAllSettings()
{
    initialWriteComplete = false;
    std::vector<std::string> fileData = settingsFileRead();
    if (fileData.empty()){
        initialWriteComplete = true;
        return 0;
    }
//    qDebug() << "FILE DATA: ";
//    for(std::string x : fileData){
//        qDebug() << QString::fromStdString(x);
//    }
    ui->gameBox->setCurrentIndex(std::stoi(fileData[1]) ? 2 : std::stoi(fileData[0])); //really should remove emu5 line and merge with game variable.
    ui->regionBox->setCurrentIndex(std::stoi(fileData[2]));
    ui->flexValueBox->setValue(std::stoi(fileData[3]));
    ui->searchMinBox->setValue(std::stoi(fileData[4]));
    ui->searchMaxBox->setValue(std::stoi(fileData[5]));
    ui->arbTargetBox->setValue(std::stoi(fileData[6]));
    keys.setBlink(std::stoi(fileData[7]));
    keys.setSlower(std::stoi(fileData[8]));
    keys.setFaster(std::stoi(fileData[9]));
    keys.setStartStop(std::stoi(fileData[10]));

    userTS.setOffset(std::stoi(fileData[11]));
    userTS.setGap(std::stoi(fileData[12]));
    userTS.setBeeps(std::stoi(fileData[13]));
    userTS.setInput(std::stoi(fileData[14]));

    std::vector<QSoundEffect*> pkg = {&sfxSearchSuccess,&sfxSearchFailure,&sfxBlinkOccurs,&sfxCalibrationComplete,&sfxExitCue};
    for (unsigned int i = 0; i < pkg.size(); i++){
        pkg[i]->setSource(QUrl(QString::fromStdString(fileData[15+(i*3)])));
        pkg[i]->setVolume(std::stof(fileData[16+(i*3)]));
        pkg[i]->setMuted(std::stoi(fileData[17+(i*3)]));
    }
    initialWriteComplete = true;
    return 1; //success?
}

QString MainWindow::createLog()
{
    //philosophy: Store only most recent amt of data. If user spends a long time in a session it may create too much data.
    //If users are forgetful and don't log right after the bug, then consider recording for the whole session. May need a file.
    //Shouldn't need to preserve between sessions for any reason.
    //Therefore can even avoid writing to file, and keep log in ram.

    //First platform and parameter data
    QString logAdd;
    logAdd = "ENTRY____\n";
    logAdd += "GAME: " + QString::number(userPF.getXD()) + " emu? " + QString::number(userPF.getEmu5()) + " Region: " + QString::number(userPF.getRegion()) + "\n";
    logAdd += "PARAM: min/max: ("+ QString::number(userSP.minSearch)+ "," + QString::number(userSP.maxSearch) + " flex: " + QString::number(userSP.flexValue) + " target: " + QString::number(userSP.arbitrary_Target)+ "\n";
    logAdd += "Timer: " + QString::number(userTS.offset()) + "/" + QString::number(userTS.gap()) + "/" + QString::number(userTS.beeps()) + "/" + QString::number(userTS.input()) + "\n";
    logAdd += "SEED: " + QString::number(userSP.inputSeed,16) + " AfterMin: " + QString::number(seedAfterMin,16)+ "\n";
    logAdd += "SearchResult: " + QString::number(foundIdx) + " ... ";
    logAdd += foundIdx >= 0 ? "SeedFound: " + QString::number(mainPool[foundIdx].seed,16) + " pos: " + QString::number(foundIdx) + "\n" : " : SEARCH_FAILURE\n";
    logAdd += "Input blinks: ";
    for (int x : blinkList){
        logAdd += QString::number(x) + ", ";
    }
    logAdd += "\n";
    logAdd += "firstMS: " + QString::number(userTS.offset() + userPF.getFadeOutMS() + (float(userTS.input())*userPF.getFrameRate())) + "\n";
    logAdd += "END______";
    return logAdd;
}

void MainWindow::nudgeCalibration(bool direction){
    //direction 0 == slower, 1 == faster
    const int NUDGE_FACTOR = direction ? -1 : 1; //Frames
    int nudgeBy = NUDGE_FACTOR*userPF.getFrameRate(); //in MS.
    totalTimer->setInterval(totalTimer->remainingTime()+nudgeBy);
    ui->nudgeOffsetLabel->setText(QString::number(ui->nudgeOffsetLabel->text().toInt() + NUDGE_FACTOR));
}

void MainWindow::expandExitPool(int expandAmt){
    expandAmt = 10000;
    std::vector<pool>add10 = generateBlinks(exitPool.back().seed,userPF,expandAmt); //10,000 is heuristic, should generate extras.
    int iterPos = iterExit - exitPool.begin(); //save iterExit's spot
    exitPool.insert(exitPool.end(),add10.begin(),add10.end()); //expand exit pool, may expand capacity at 2^x values, changes memory address
    iterExit = exitPool.begin()+iterPos; //redeclare iterator with potentially new address.
    //Expand amt doesn't currently do anything meaningful because I have yet to allow generateBlinks to be limited by blinks as opposed to advances.
    //CRASH fixed after 2^x elements the vector is moved to a different place in memory, therefore the iterator points somewhere incorrect and a segfault occurs
    //This is basically just a stale reference problem
    //Second Crash fixed: .end()->seed does not get you the value of seed, it returns the address of seed, you need .back().seed.
    //What works for iterators doesn't always work for values.
}


void MainWindow::restoreResults(){
    postPool(exitPool.begin(),exitPool.begin()+ui->outTable->rowCount(),0); //Note that not entire pool is posted for safety reasons
    highlightTableRow(iterExit-exitPool.begin(),tbl_currentBlink);
    highlightTableRow(userSP.arbitrary_Target-1,tbl_targetBlink);
    for(int i = 0; i < iterExit-exitPool.begin(); i++){
        highlightTableRow(i,tbl_pastBlink);
    }
}


int setTimerLimit(iterP setI,iterP limiterI, float framerate){
    int timerLimit = 0;
        while(setI != limiterI){ //since setI passed by value, shouldn't affect original exitIter...right?
            if (setI < limiterI){
                timerLimit += round((setI->blink) * framerate); //This ROUNDING IS FINE.
                setI++;
            } else if (setI > limiterI){
                timerLimit -= (setI-1)->blink* framerate;
                setI--;
            }
        }
    return timerLimit;
}


int MainWindow::iterPToMS(iterP iter, float framerate){
    return round((iter->blink)*framerate);
}
void MainWindow::blinkOccurs(){
    sfxBlinkOccurs.play();
    if (resultsActiveView){
        highlightTableRow(iterExit-exitPool.begin()-1,tbl_pastBlink);
        highlightTableRow(iterExit-exitPool.begin(),tbl_currentBlink);
    }
}

void MainWindow::highlightTableRow(int row, QColor color){
    ui->outTable->item(row,0)->setBackground(QBrush(color));
    ui->outTable->item(row,1)->setBackground(QBrush(color));
}

void MainWindow::totalTimerUpdate(){
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start); //debug
    qDebug() << "Total Duration: " << float(duration.count())/1000;
    //sfxCalibrationComplete.play();
    highlightTableRow(iterExit-exitPool.begin(),tbl_targetBlink);
}

void MainWindow::timerGUIUpdate(){
    bool totalActive = totalTimer->isActive();
    bool exitActive = exitTimer->isActive();
    int blinkTiming = setTimerLimit(iterExit+1,exitPool.begin()+userSP.arbitrary_Target,userPF.getFrameRate());

    if (totalActive || exitActive){
        int mainTime = totalTimer->remainingTime();

        //Pre-convert the queue inside TS? Pass in the userPF values?
        float firstMS = userTS.offset() + userPF.getFadeOutMS() + (float(userTS.input())*userPF.getFrameRate());
        float localMS = userTS.getTiming() + userPF.getFadeOutMS();


        if (mainTime <= firstMS){
            if (!exitActive&& userTS.checkState()){
                exitTimer->start(userTS.offset());

                qDebug() << "ExitTimer Started: " << firstMS ;
                qDebug() << "First LocalMS: " << localMS;
            }
            ui->arbTargetBox->setEnabled(false); //set these to false at maintime <= offset NOT INCL INPUT becaues otherwise user could fuck shit up on the last blink or two.

            int exitTime = exitTimer->remainingTime();
            if (exitActive && exitTime <= localMS && userTS.checkState()){
                sfxBlinkOccurs.setMuted(true); //mute the blinks to prevent distraction.
                ui->timerFrame->setEnabled(false);
                qDebug() << "LocalMS:" << localMS;
                userTS.timingAdvance();
                qDebug() << userTS.getTiming() + userPF.getFadeOutMS() + (userTS.input()*userPF.getFrameRate())
                                             << " : "<< mainTime << totalTimer->remainingTime();
                sfxExitCue.play();
            }
        }

        ui->TotalTimeLabel->setText("TIME REMAINING: " + QString::number(float(mainTime)/1000)); //Can we get by updating this every 10 ms instead of 1?
        ui->localTimeLabel->setText("NEXT BLINK: " + QString::number(float(mainTime-blinkTiming)/1000));
        if (mainTime <= blinkTiming && iterExit-exitPool.begin() != userSP.arbitrary_Target-1){
            //If the clock has reached the next blink, and if its not the final blink, then proceed
            iterExit++;
            blinkOccurs();
        }
    }
    if (!totalActive && !exitActive){
        qDebug() << "BasicTimer stopped!";
        ui->TotalTimeLabel->setText("Complete!");
        u32 seedFinal = ui->outTable->item(userSP.arbitrary_Target-1,0)->text().toInt(nullptr,16);
        ui->statusLabel->setText("FINISHED! New seed: 0x" + QString::number(seedFinal,16).toUpper()
                                 + "\nTotal Advancements: " + QString::number(findGap(seedAfterMin,seedFinal,1)));
        basicTimer->stop(); //set this to be after both totalTimer and exitTimer finish
        sfxBlinkOccurs.setMuted(wasMuted);
        sfxCalibrationComplete.play();
        ui->arbTargetBox->setEnabled(true);
        ui->arbTargetBox->setFocusPolicy(Qt::NoFocus);
        ui->copyButton->setVisible(true);
        ui->copyButton->setEnabled(true);
    }
}

void MainWindow::exitTimerUpdate()
{
    qDebug() << "Exit Timer finished!";
}


void MainWindow::runCalibration(u32 seed){
    resultsActiveView = true;
    ui->outTable->clear();
    ui->outTable->setStyleSheet("QTableWidget{border:2px solid purple;padding:6px;padding-left:10px;}" + tableStyle);
    sfxSearchSuccess.play();
    //populate table with blinks
    exitPool = generateBlinks(seed,userPF,userSP.maxCalibrate);
    qDebug() << exitPool.size() << "exit blinks generated";
    ui->outTable->setRowCount(userSP.arbitrary_Target);
    ui->outTable->setHorizontalHeaderLabels(QStringList() << "Seed" << "Frames");
    iterExit = exitPool.begin();
    postPool(iterExit,iterExit+userSP.arbitrary_Target,0);
    ui->outTable->resizeColumnsToContents();
    ui->outTable->setColumnWidth(0,77);
    ui->timerFrame->setEnabled(true);
    ui->seeInputButton->setEnabled(true);
    ui->increaseBlinksButton->setEnabled(true);
    //Visual setup complete

    //INCLUDE TIME TO START EXIT BEEPING LIKE FLOWTIMER DEFAULT 5000 MS BEFORE FINISHED.

    ui->TotalTimeLabel->setText(QString::number(totalTimerLimit));
    //prep visuals
    highlightTableRow(0,tbl_currentBlink);
    highlightTableRow(userSP.arbitrary_Target-1,tbl_targetBlink);

    const int DEFAULT_MS_ADJUST = 215; //This number accounts for: 1) Delay in user reaction time to blinks 2) any delay between search and calibration due to single-threading.
    //Has no impact on exitTimer, and from the user's perspective this only affects how much they need to alter left and right. This is region independent I think. If not, reevaluate.
    //Used here and only here for the initial timer amt.
    totalTimerLimit = setTimerLimit(iterExit,exitPool.begin()+userSP.arbitrary_Target,userPF.getFrameRate()) - DEFAULT_MS_ADJUST; //End of list.
    qDebug() << "ttl: " << float(totalTimerLimit)/1000;
    start = std::chrono::high_resolution_clock::now();
    totalTimer->start(totalTimerLimit); //Test this thoroughly.
    basicTimer->start(1);

}

int MainWindow::performSearchPass(u32 &outSeed){
    if (!mainPool.empty()){
        std::vector<int> resultIndexes = searchPool(mainPool,blinkList,userSP.flexValue/2); //does not persist between searches -- for size(), null == 0
            postInterval(QString::number(resultIndexes.size()) + " seeds.",blinkList.back(),blinkList.size()-1); //TABLE UPDATE
            if (resultIndexes.size() > 1){
                ui->statusLabel->setText("Searching... " + QString::number(resultIndexes.size()) + " result(s) found!");
                return 2;
            } else if (resultIndexes.size() == 1){
                foundIdx = resultIndexes.front()+blinkList.size()-1;
                outSeed = mainPool[foundIdx].seed;
                qDebug() << QString::number(outSeed,16) << " SEED";

                ui->statusLabel->setText("SUCCESS: Seed is: 0x"
                    + QString::number(outSeed,16).toUpper()
                                         + "\nAdvances from " + QString::number(ui->searchMinBox->value()) + ": " + QString::number(findGap(seedAfterMin,outSeed,1)));
                    // + ".\nSubsequence at position: " + QString::number(resultIndexes.front())); //THIS WILL BE LOGGED
                foundIdx = resultIndexes.front();
                //Use debug if necessary
                return 1;
            } else { //Size == 0
                //Failure case
                foundIdx = -1;
                return 0;
            }

            //RECORD BLINK LIST TO LOG

    }
    return -1; //Error
}
void MainWindow::postPool(iterP setP, iterP limitP, int rowCurrent){
    while (setP != limitP){
        QTableWidgetItem *tblSeed= new QTableWidgetItem(QString::number(setP->seed,16).toUpper()); //DO I NEED DESTRUCTORS FOR THESE?
        QTableWidgetItem *fTime = new QTableWidgetItem(QString::number(setP->blink));
        tblSeed->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
        fTime->setTextAlignment(Qt::AlignCenter);
        ui->outTable->setItem(rowCurrent,0,tblSeed);
        ui->outTable->setItem(rowCurrent,1,fTime);

        QTableWidgetItem*debug = ui->outTable->item(rowCurrent,0);
        if (debug == 0 && ui->outTable->item(rowCurrent,0) == 0){
            qDebug() << "ERROR: ROW:" << QString::number(rowCurrent) << " DOES NOT EXIST";
        }
        if (setP->TCFailureChance == 1){
            tblSeed->setIcon(xdWarningIcon);
            highlightTableRow(rowCurrent,tbl_warningBlink);
            u32 ttSeed = setP->seed;
            if (userPF.getEmu5()){
                tblSeed->setToolTip("This blink has a ~60.67% chance to be early by 1 advancement.\nIf so, the seed would be: " + QString::number(LCG(ttSeed),16));
            } else {
                tblSeed->setToolTip("This blink has a ~56.78% chance of delaying 1 advancement, and a ~9.65% chance of delaying 2 advancements.\nThe seed would be: "
                                    + QString::number(LCG(ttSeed),16) + " and " + QString::number(LCG(ttSeed),16) + " respectively.");
                /*
                # 9.65% chance of 4 calls
                # 56.78% chance of 3 calls
                # 33.57% chance of 2 calls (default)
                */
            }
        }
        rowCurrent++;
        setP++;
    }
}


void MainWindow::postInterval(QString results, int f, int row){
    if (!ui->outTable->item(0,0)->text().isNull()){
        ui->outTable->setRowCount(ui->outTable->rowCount()+1);
    }
    QTableWidgetItem *resultsStr= new QTableWidgetItem(results);
    QTableWidgetItem *fTime = new QTableWidgetItem(QString::number(f));
    resultsStr->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
    fTime->setTextAlignment(Qt::AlignCenter);
    ui->outTable->setItem(row,0,resultsStr);
    ui->outTable->setItem(row,1,fTime);
}

void prepShadow(QDropShadow &shd){
    shd->setOffset(0,4);
    shd->setBlurRadius(4);
    shd->setColor(QColor(0,0,0,64));
}
std::queue<QDropShadow> fillShadowSet(int numShadows, QWidget* parent){
    std::queue<QDropShadow> set;
    for (int i = 0; i < numShadows;i++){
        QDropShadow sh = new QDropShadowObj(parent);
        prepShadow(sh);
        set.push(sh);
    }
    return set;
}
void applyShadow(QWidget* obj,std::queue<QDropShadow>&set){
    obj->setGraphicsEffect(set.front());
    set.pop(); //note that object still exists in memory until MainWindow is deleted.
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_startButton_clicked()
{
    if (ui->startButton->text() == "START"){
        //ui->pushButton->setEnabled(false);
        qDebug() << QString::number(ui->seedEntry->text().toUInt(nullptr,16),16);
        //keycodetoname
        ui->statusLabel->setText("Press " + keyCodeToName(keys.getBlinkKey()) + " to search!"); //Allow user to change hotkey.
        ui->outTable->clear();
        ui->outTable->setRowCount(1);
        ui->outTable->setColumnCount(2);
        ui->outTable->setItem(0,0,new QTableWidgetItem());
        ui->outTable->setHorizontalHeaderLabels(QStringList() << "Candidates"<<"Frames");//Dummy sizing, to set up for later

        ui->outTable->setStyleSheet("QTableWidget{border: 2px solid green;padding:6px;padding-left:10px;}" + tableStyle);
        ui->outTable->resizeColumnsToContents();

        //definitions

        userPF = collectPlatformInputs(); //remember to disable/enable the inputs.
        userTS.buildQueue();
        userSP = collectParamInputs();
        //qDebug() << userSP.inputSeed << "," << userSP.flexValue << "," << userSP.arbitrary_Target << "," << userSP.maxCalibrate << "," << userSP.maxSearch;
        blinkList.clear();
        exitPool.clear();
        mainPool.clear();

        //Move this inside blinkBase class?
        seedAfterMin = userSP.inputSeed;
        LCGn(seedAfterMin,userSP.minSearch); //abstraction is needed to prevent modification of inputSeed
        mainPool = generateBlinks(seedAfterMin,userPF,userSP.maxSearch-userSP.minSearch); //SEED IS NOT MODIFIED

        hotKeyLockState = PRESEARCH;
        ui->startButton->clearFocus();
        ui->seeInputButton->setEnabled(false);
        ui->increaseBlinksButton->setEnabled(false);
        ui->paramsFrame->setEnabled(false);
        ui->platformFrame->setEnabled(false);
        ui->seedQFrame->setEnabled(false);
        ui->copyButton->setVisible(false);
        ui->copyButton->setEnabled(false);
        ui->copyButton->setText("Copy");
        ui->pasteButton->setText("Paste");
        ui->startButton->setText("STOP");
        ui->arbTargetBox->setFocusPolicy(Qt::NoFocus);
        ui->startButton->clearFocus();
        wasMuted = sfxBlinkOccurs.isMuted();
    } else {
        ui->statusLabel->setText((hotKeyLockState == CALIBRATE) ? ui->statusLabel->text() : "STATUS" );
        totalTimer->stop();
        basicTimer->stop();
        sfxBlinkOccurs.setMuted(wasMuted);
        ui->TotalTimeLabel->setText("TIME REMAINING:");
        ui->localTimeLabel->setText("NEXT BLINK:");
        hotKeyLockState = INACTIVE;
        ui->timerFrame->setEnabled(false);
        ui->arbTargetBox->setEnabled(true);
        ui->arbTargetBox->setFocusPolicy(Qt::NoFocus);
        ui->paramsFrame->setEnabled(true);
        ui->platformFrame->setEnabled(true);
        ui->seedQFrame->setEnabled(true);
        ui->copyButton->setVisible(false);
        ui->copyButton->setEnabled(false);
        ui->nudgeOffsetLabel->setText("0");
        ui->startButton->setText("START");
    }
}


void MainWindow::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == keys.getStartStopKey()){ //valid across all states
        on_startButton_clicked();
    }
    //not in our keys class:
    if(ui->arbTargetBox->isEnabled()){
        if(event->key() == Qt::Key_Up){
            ui->arbTargetBox->setValue(ui->arbTargetBox->value()+1);
        }
        if (event->key() == Qt::Key_Down){
            ui->arbTargetBox->setValue(ui->arbTargetBox->value()-1);
        }
    }


    switch (hotKeyLockState) {
    case PRESEARCH:
        if (event->key() == keys.getBlinkKey()){
            hotKeyLockState = LISTEN;
            ui->statusLabel->setText("Listening!");
            start = std::chrono::high_resolution_clock::now();
        }
        break;
    case LISTEN:
    { //this brace allows us to declare locals in a case statement. Otherwise big error
        auto stop = std::chrono::high_resolution_clock::now(); //seems accurate enough? Switch to QDateTime if needed?
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        start = std::chrono::high_resolution_clock::now();
        const int LAG_REDUCTION = 10; //holdover, seemed to better align my code with sinapoke's. Accounts for some difference in hardware timing used.
        blinkList.push_back((duration.count()-LAG_REDUCTION)/userPF.getFrameRate());

        //Debug blink list?
        u32 seed = 0; //result of searching
        int status = performSearchPass(seed); //returns status: -1 error, 0 failure, 1 success, 2 continue search
        if (status < 2){
            //LOG NOW ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~********************!!!!!!!!!!!!!!!!!!!!!!!!!******************!!!!!!!!!!!!!!!!!!!!!!!*************!!!!!!!!!!!!!!
            logStr = createLog(); //If this creates too much lag then move it into the
            if (status == 1){
                hotKeyLockState = CALIBRATE;


                //DebugBlock
                QString line = QString::number(mainPool[0].blink) + ", ";
                for (unsigned int i = 1; i < mainPool.size(); i++) {
                    line += QString::number(mainPool[i].blink) + ", ";
                    if (i % 20 == 19){
                        qDebug() << line;
                        line = "";
                    }
                }
                qDebug() << line;

                runCalibration(seed);

            } else if (status == 0){
                ui->statusLabel->setText("FAILURE");
                sfxSearchFailure.play();
                hotKeyLockState = INACTIVE;
            }
        }
        break;
    }
    case CALIBRATE:
        if(ui->timerFrame->isEnabled()){
            if (event->key() == keys.getSlowerKey()) {
                on_slowerButton_clicked();
            }
            if (event->key() == keys.getFasterKey()){
                on_fasterButton_clicked();
            }
        }
        ui->nudgeMSLabel->setText(QString::number(float(ui->nudgeOffsetLabel->text().toInt())/userPF.getFrameRate()) + "ms");
        break;
    default:
        QWidget::keyPressEvent(event);
        return;
    }
    event->accept();
}


void MainWindow::on_seeInputButton_clicked()
{
    ui->outTable->clear();
    if (resultsActiveView){
        resultsActiveView = false;
        std::vector<pool>retroInputPool; //gotta prep a pool out of blinklist
        for (unsigned int i = 0; i<blinkList.size();i++){
            retroInputPool.push_back(pool({blinkList[i],mainPool[foundIdx+i].seed}));
        }
        postPool(retroInputPool.begin(),retroInputPool.end(),0);
        ui->outTable->setHorizontalHeaderLabels(QStringList() << "Seed" << "Input");
        ui->seeInputButton->setText("v See future blinks");
    } else {
        resultsActiveView = true;
        restoreResults();
        ui->outTable->setHorizontalHeaderLabels(QStringList() << "Seed" << "Frames");
        ui->seeInputButton->setText("^ See inputs");
    }
}

void MainWindow::on_arbTargetBox_valueChanged(int arg1)
{
    //could add input validation here, currently assumes input is invalid if getting too close to target.

    if (totalTimer->isActive() && arg1 > iterExit-exitPool.begin() + 1){ //Need buffer from 5000ms exit lock???
        iterP adjustedTarget = exitPool.begin() + arg1;//is this fine or do i need .value()?
        //temporary
        while (adjustedTarget > exitPool.end() || arg1 > ui->outTable->rowCount()){
            on_increaseBlinksButton_clicked();
            adjustedTarget = exitPool.begin() + arg1; //refresh reference
        }

        int targetOffset = setTimerLimit(exitPool.begin()+userSP.arbitrary_Target,adjustedTarget,userPF.getFrameRate());
        qDebug() << totalTimer->remainingTime() << "ms +  " << targetOffset << " = " << totalTimer->remainingTime()+targetOffset;
        //this is strictly the positive or negative adjustment from the current target to the next, not a time-point.

        totalTimer->setInterval(totalTimer->remainingTime() + targetOffset); //simply adds or removes the time as needed

        //set arb target to new target
        highlightTableRow(userSP.arbitrary_Target-1,tbl_upcomingBlink);
        userSP.arbitrary_Target = arg1;
        highlightTableRow(userSP.arbitrary_Target-1,tbl_targetBlink);
    }
}

void MainWindow::on_increaseBlinksButton_clicked()
{

    const int ARBITRARY_10_ADD = 10; //may one day use the user scrolling to automatically add more.
    ui->outTable->setRowCount(ui->outTable->rowCount()+ARBITRARY_10_ADD);
    if (uint(ui->outTable->rowCount()) > exitPool.size()){
        qDebug() << "EXPANDED EXITPOOL";
        expandExitPool(ARBITRARY_10_ADD);
        qDebug() << exitPool.size() << " blinks now.";
    }
    restoreResults();
}

void MainWindow::on_slowerButton_clicked()
{
    if (totalTimer->isActive()){
        ui->outTable->clearFocus();
        ui->arbTargetBox->clearFocus();
        nudgeCalibration(false);
    }
}

void MainWindow::on_fasterButton_clicked()
{
    if (totalTimer->isActive()){
        ui->outTable->clearFocus();
        ui->arbTargetBox->clearFocus();
        nudgeCalibration(true);
    }
}


void MainWindow::on_flexValueBox_valueChanged(int arg1)
{
    ui->flexValueHalfLabel->setText("+-" + QString::number(floor(arg1/2)) + "f");
    writeAllSettings();
}

void MainWindow::on_actionHotkeys_triggered()
{
    HotkeysDialogue keyChange;
    keyChange.setModal(true);
    keyChange.setKeyCodes(keys); //Data in
    if (keyChange.exec() == QDialog::Accepted){
        keys = keyChange.getKeyCodes(); //data out
        writeAllSettings();
    }
}

void MainWindow::on_actionTimer_triggered()
{
    timerSettingsDialogue timeSet_d;
    timeSet_d.setModal(true);
    timeSet_d.setTs(userTS);
    if (timeSet_d.exec() == QDialog::Accepted){
    userTS = timeSet_d.getTs();
    writeAllSettings();
    }
}

void MainWindow::on_actionSounds_triggered()
{
    std::vector<QSoundEffect*> pkg = {&sfxSearchSuccess,&sfxSearchFailure,&sfxBlinkOccurs,&sfxCalibrationComplete,&sfxExitCue};
    soundSettingsDialogue setSound_d;
    setSound_d.setModal(true);
    setSound_d.set_all_sfx(pkg); //Look, direct connection is cool but we gotta leave the agency up to the user.
    if (setSound_d.exec() == QDialog::Accepted){
        for (unsigned int i = 0; i < pkg.size(); i++){
            pkg[i]->setVolume(setSound_d.bundle[i]->volume());
            pkg[i]->setMuted(setSound_d.bundle[i]->isMuted());
            pkg[i]->setSource(setSound_d.bundle[i]->source());
        }
        writeAllSettings();
    }
}

void MainWindow::on_actionGithub_triggered()
{
    QDesktopServices::openUrl(QUrl("https://github.com/KapitalRoser/OpenBlink"));
}

void MainWindow::on_actionHelp_triggered()
{
    QDesktopServices::openUrl(QUrl("https://gist.github.com/KapitalRoser/08423a6e7173570677c35390ee6a6593"));
}

void MainWindow::on_actionLog_triggered()
{
    LogWindow logWin;
    logWin.setModal(true);
    logWin.setLogDisplay(logStr);
    logWin.exec();
}

void MainWindow::on_copyButton_clicked()
{
    QClipboard *clip = QApplication::clipboard();
    clip->setText(ui->outTable->item(userSP.arbitrary_Target-1,0)->text());
    ui->copyButton->setText("Copied!");
}

void MainWindow::on_pasteButton_clicked()
{
    ui->seedEntry->setText("");
    ui->seedEntry->paste();
    ui->pasteButton->setText("Pasted!");
}


void MainWindow::on_seedEntry_textChanged(const QString &arg1)
{
    ui->startButton->setEnabled(arg1.toUInt(nullptr,16)); //if arg1.toUint fails it returns false
    ui->pasteButton->setText("Paste");
}


void MainWindow::on_gameBox_currentIndexChanged(int index)
{
    writeAllSettings();
}


void MainWindow::on_regionBox_currentIndexChanged(int index)
{
    writeAllSettings();
}


void MainWindow::on_searchMinBox_valueChanged(int arg1)
{
    writeAllSettings();
}


void MainWindow::on_searchMaxBox_valueChanged(int arg1)
{
    writeAllSettings();
}


void MainWindow::on_arbTargetBox_editingFinished()
{
    writeAllSettings();
}

