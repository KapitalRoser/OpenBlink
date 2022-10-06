#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "hotkeysdialogue.h"
#include "timersettingsdialogue.h"
#include "soundsettingsdialogue.h"

/*TODO:
    -Seperate Exit Timer from Total Timer OR Start a new timer with a duration of the remaining exit time.
    -Input cleansing on seed entry
    -XD Dolphin bad frames indication
    -XD Modern bad frames indication
    -Settings file Read/Write
    -Windows and Mac Build testing.
     Then done!
//Optional
    -Retry QThread for performance reasons
    -Add century gothic font to resources??
    -Up/Down Arrow keys to adjust arbitrary_target?
    -Clean up the .h files
    -Tidy up in general
    -If the JPN devs discover battle blink in time then I suppose I'll add that
*/
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


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QAction *logAction = ui->menubar->addAction("Log");

    QAction *githubAction = ui->menubar->addAction("GitHub");
    connect(githubAction,&QAction::triggered,this,&MainWindow::on_actionGithub_triggered);
    QAction *helpAction = ui->menubar->addAction("Help");

    QAction *exitAction = ui->menubar->addAction("Exit");
    connect(exitAction,&QAction::triggered,this,&MainWindow::on_actionExit_triggered);
    std::queue<QDropShadow> shadowSet;
    shadowSet = fillShadowSet(10,this); //update this number for number of shadows needed
    applyShadow(ui->statusFrame,shadowSet);
    applyShadow(ui->seedQFrame,shadowSet);
    applyShadow(ui->timerFrame,shadowSet);
    applyShadow(ui->paramsFrame,shadowSet);
    applyShadow(ui->platformFrame,shadowSet);
    applyShadow(ui->blinkTableFrame,shadowSet);
    //repeat as necessary for each object
    resultsActiveView = false;
    hotKeyLockState = INACTIVE;
    ui->copyButton->setVisible(false);
    ui->copyButton->setEnabled(false);
    //loads defaults -- will read from file when done.
    keys = KeyCodes();
    userTS = TimerSettings();

    tbl_pastBlink = QColor(222,222,222); //gray
    tbl_currentBlink = QColor(255,236,116); //light green
    tbl_targetBlink = QColor(168,255,200); //Gold
    tbl_upcomingBlink = QColor(255,255,255); //White

    sfxSearchSuccess.setSource(QUrl::fromLocalFile(":/resfix1/lvlup.wav")); //Allow user to mute or adjust volume
    sfxSearchFailure.setSource(QUrl::fromLocalFile(":/resfix1/searchFailure.wav"));
    //sfxSearchFailure.setSource(QUrl(""));
    sfxBlinkOccurs.setSource(QUrl::fromLocalFile(":/resfix1/blinkWoop.wav"));
    sfxCalibrationComplete.setSource(QUrl::fromLocalFile(":/resfix1/snagSuccess.wav"));
    sfxExitCue.setSource(QUrl::fromLocalFile(":/resfix1/blinkBeep1.wav"));

    sfxSearchSuccess.setVolume(0.2);
    sfxSearchFailure.setVolume(0.2);
    sfxBlinkOccurs.setVolume(0.2);
    sfxCalibrationComplete.setVolume(0.2);
    sfxExitCue.setVolume(0.2);

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


    ui->arbTargetBox->setValue(15);
}

platform MainWindow::collectPlatformInputs(){
    return platform( ui->gameBox->currentIndex(),
                    (ui->gameBox->currentIndex() == 2),
                     region(ui->regionBox->currentIndex()));
}


void MainWindow::writeAllSettings(){
    std::ofstream settingsW(settingsName);
    std::string delim = "---";

    //platform
    settingsW << userPF.getXD() << "\n";
    settingsW << userPF.getEmu5() << "\n";
    settingsW << userPF.getRegion() << "\n";
    settingsW << delim << "\n";

    //search parameters
    settingsW << userSP.flexValue << "\n";
    settingsW << userSP.minSearch << "\n"; //unit Converter?
    settingsW << userSP.maxSearch << "\n";
    settingsW << userSP.arbitrary_Target << "\n";
    settingsW << delim << "\n";

    //hotkeys
    settingsW << keys.getBlinkKey() << "\n";
    settingsW << keys.getSlowerKey() << "\n";
    settingsW << keys.getFasterKey() << "\n";
    settingsW << delim << "\n";

    //Timer Settings
    settingsW << userTS.offset() << "\n";
    settingsW << userTS.gap() << "\n";
    settingsW << userTS.beeps() << "\n";
    settingsW << delim << "\n";

    //Sound and Volume
}


void MainWindow::nudgeCalibration(bool direction){
    //direction 0 == slower, 1 == faster
    const int NUDGE_FACTOR = direction ? -1 : 1; //Frames
    int nudgeBy = NUDGE_FACTOR*userPF.getFramerate(); //in MS.
    totalTimer->setInterval(totalTimer->remainingTime()+nudgeBy);
    ui->nudgeOffsetLabel->setText(QString::number(ui->nudgeOffsetLabel->text().toInt() + NUDGE_FACTOR));
}

void MainWindow::expandExitPool(int expandAmt){
    //Currentl adds in sets of ~10 blinks. Should this be changed to a set desired # of blinks? Not sure what the best thing for performance overall is here.
    std::vector<pool>add10 = generateBlinks(exitPool.end()->seed,userPF,expandAmt*100); //remember to adjust for blinks vs advances
    int iterPos = iterExit - exitPool.begin(); //save iterExit's spot
    exitPool.insert(exitPool.end(),add10.begin(),add10.end()); //expand exit pool, may expand capacity at 2^x values, changes memory address
    iterExit = exitPool.begin()+iterPos; //redeclare iterator with potentially new address.
    //could do this iterator restoration thing closer to 2^x values but that is only a tiny performance saving.
}


void MainWindow::restoreResults(){
    postPool(exitPool.begin(),exitPool.end(),0);
    highlightTableRow(iterExit-exitPool.begin(),tbl_currentBlink);
    highlightTableRow(userSP.arbitrary_Target-1,tbl_targetBlink);
    for(int i = 0; i < iterExit-exitPool.begin(); i++){
        highlightTableRow(i,tbl_pastBlink);
    }
}


int setTimerLimit(iterP setI,iterP limiterI, int framerate){
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
    int blinkTiming = setTimerLimit(iterExit+1,exitPool.begin()+userSP.arbitrary_Target,userPF.getFramerate());

    if (totalActive){
        int mainTime = totalTimer->remainingTime();


        //Pre-convert the queue inside TS? Pass in the userPF values?
        float msAdjustment = userPF.getFadeOutMS() + (float(userTS.input())*userPF.getFramerate());
        float firstMS = userTS.offset() + msAdjustment;
        float localMS = userTS.getTiming() + msAdjustment;


        if (mainTime <= firstMS){
            if (!exitActive&& userTS.checkState()){
                exitTimer->start(firstMS);
                sfxBlinkOccurs.setMuted(true); //mute the blinks to prevent distraction.
                qDebug() << "ExitTimer Started: " << firstMS ;
            }
            ui->arbTargetBox->setEnabled(false); //set these to false at maintime <= offset NOT INCL INPUT becaues otherwise user could fuck shit up on the last blink or two.
            ui->timerFrame->setEnabled(false);
            int exitTime = exitTimer->remainingTime();
            if (exitActive && exitTime <= localMS && userTS.checkState()){
                qDebug() << "LocalMS:" << localMS;
                userTS.timingAdvance();
                qDebug() << userTS.getTiming() + userPF.getFadeOutMS() + (userTS.input()*userPF.getFramerate())
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
    qDebug() << exitPool.size() << " blinks generated";
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


    totalTimerLimit = setTimerLimit(iterExit,exitPool.begin()+userSP.arbitrary_Target,userPF.getFramerate()); //End of list.
    qDebug() << "ttl: " << float(totalTimerLimit)/1000;
    start = std::chrono::high_resolution_clock::now();
    totalTimer->start(totalTimerLimit); //Test this thoroughly.
    basicTimer->start(1);


}

int MainWindow::performSearchPass(u32 &outSeed){
    if (!mainPool.empty()){
        std::vector<int> resultIndexes; //does not persist between searches -- for size(), null == 0
            resultIndexes = searchPool(mainPool,blinkList,userSP.flexValue); //these inputs do persist between searches.
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

        userSP.inputSeed =  ui->seedEntry->text().toUInt(nullptr,16);; //input cleanse
        userSP.flexValue = ui->flexValueBox->value(); //FALSE -- FLEX IS THE +- VALUE, NOT TOTAL WINDOW!!! CHECK WITH COTOOL FOR ACCURACY
        userSP.arbitrary_Target = ui->arbTargetBox->value();
        userSP.maxCalibrate = 10000; //Roll this into target?;
        userSP.maxSearch = ui->searchMaxBox->value();
        userSP.minSearch = ui->searchMinBox->value(); //UNITS?

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
        wasMuted = sfxBlinkOccurs.isMuted();
    } else {
        ui->statusLabel->setText((hotKeyLockState == CALIBRATE) ? ui->statusLabel->text() : "STATUS" );
        totalTimer->stop();
        basicTimer->stop();
        ui->TotalTimeLabel->setText("TIME REMAINING:");
        ui->localTimeLabel->setText("NEXT BLINK:");
        hotKeyLockState = INACTIVE;\
        ui->timerFrame->setEnabled(false);
        ui->arbTargetBox->setEnabled(true);
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
        blinkList.push_back((duration.count()-LAG_REDUCTION)/userPF.getFramerate());

        //Debug blink list?
        u32 seed = 0; //result of searching
        int status = performSearchPass(seed); //returns status: -1 error, 0 failure, 1 success, 2 continue search
        if (status < 2){
            //LOG NOW ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~********************!!!!!!!!!!!!!!!!!!!!!!!!!******************!!!!!!!!!!!!!!!!!!!!!!!*************!!!!!!!!!!!!!!
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
        ui->nudgeMSLabel->setText(QString::number(float(ui->nudgeOffsetLabel->text().toInt())/userPF.getFramerate()) + "ms");
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

        int targetOffset = setTimerLimit(exitPool.begin()+userSP.arbitrary_Target,adjustedTarget,userPF.getFramerate());
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

    //CRASH fixed after 2^x elements the vector is moved to a different place in memory, therefore the iterator points somewhere incorrect and a segfault occurs
    //This is basically just a stale reference problem
    if (uint(ui->outTable->rowCount()) > exitPool.size()){
        expandExitPool(ARBITRARY_10_ADD);
    }

    restoreResults();
    qDebug() << exitPool.size() << " blinks now.";

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
}

void MainWindow::on_actionHotkeys_triggered()
{
    HotkeysDialogue keyChange;
    keyChange.setModal(true);
    keyChange.setKeyCodes(keys); //Data in
    if (keyChange.exec() == QDialog::Accepted){
        keys = keyChange.getKeyCodes(); //data out
    }
}

void MainWindow::on_actionTimer_triggered()
{
     timerSettingsDialogue timeSet_d;
     timeSet_d.setModal(true);
     timeSet_d.setTs(userTS);
     if (timeSet_d.exec() == QDialog::Accepted){
        userTS = timeSet_d.getTs();
     }
     //qDebug() << "Results are: " << userTS.offset() << " | " << userTS.gap() << " | " << userTS.beeps();

}

void MainWindow::on_actionSounds_triggered()
{
    soundSettingsDialogue setSound_d;
    setSound_d.setModal(true);
    std::vector<QSoundEffect*> pkg = {&sfxSearchSuccess,&sfxSearchFailure,&sfxBlinkOccurs,&sfxCalibrationComplete,&sfxExitCue};
    setSound_d.set_all_sfx(pkg); //DIRECTLY CONNECTS THE SFX OBJECTS TO THE DIALOGUE.
    //IF WANT MORE SEPERATION THEN PASS A STRUCT OF VALUES (VOLUME, SOURCE, MUTE)
    setSound_d.exec();

}

void MainWindow::on_actionExit_triggered()
{
    QCoreApplication::quit();
}

void MainWindow::on_actionGithub_triggered()
{
    QDesktopServices::openUrl(QUrl("https://github.com/KapitalRoser/OpenBlink"));
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
    //input validation?
    ui->pasteButton->setText("Paste");
}

