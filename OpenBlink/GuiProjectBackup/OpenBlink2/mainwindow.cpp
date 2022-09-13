#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "hotkeysdialogue.h"
#include "timersettingsdialogue.h"
#include "soundsettingsdialogue.h"

//These are almost entirely just debug globals.
auto start = std::chrono::high_resolution_clock::now();



platform MainWindow::collectPlatformInputs(){
    //collection of inputs is done all at once so that the user can't change them while the search is running.

   //could make a loop looking for selected children but that's overcomplicating things for just a few options
    region gr;
    if (ui->ntscuRadio->isChecked()){
        gr = NTSCU;
    } else if (ui->ntscjRadio->isChecked()){
        gr = NTSCJ;
    } else {
        gr = ui->palHzBox->currentIndex()? PAL50 : PAL60; //not in love with the dropdown, the ux of that is icky.
    }
    return platform(ui->galesRadio->isChecked(),ui->emu5CheckBox->isChecked(),gr);
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
    //sfxExitCue.play(); //If this is better, then is it better to include it here or in the regular timer rhythm?
    sfxCalibrationComplete.play(); //Is this it?

    highlightTableRow(iterExit-exitPool.begin(),tbl_targetBlink);
    ui->arbTargetBox->setEnabled(true);
}

void MainWindow::timerGUIUpdate(){

    //calls to remainingTime() are basically free, much faster than restarting the blink timer constantly so lets just use that for everything.
    //THIS TIMER ISN'T PERFECT. SOMETIMES TIME BETWEEN CALLS IS >1 MS, AT LEAST ACCORDING TO MAINTIME
    //MAYBE NOT ACCORDING TO STD CHRONO TIME?

    int mainTime = 0;
    bool totalActive = totalTimer->isActive();
    int blinkTiming = setTimerLimit(iterExit+1,exitPool.begin()+userSP.arbitrary_Target,userPF.getFramerate());

    if (totalActive){
        mainTime = totalTimer->remainingTime();
        ui->TotalTimeLabel->setText("TIME REMAINING: " + QString::number(float(mainTime)/1000)); //Can we get by updating this every 10 ms instead of 1?

        ui->localTimeLabel->setText("NEXT BLINK: " + QString::number(float(mainTime-blinkTiming)/1000));

        //Make sure to mathematically validate these, such that the beeps * interval is < Offset.
        if (mainTime <= userTS.offset() + userPF.getFadeOutMS()){
            if (ui->arbTargetBox->isEnabled()){
                ui->arbTargetBox->setEnabled(false);
            }
            ui->slowerButton->setEnabled(false);
            ui->fasterButton->setEnabled(false);
            if (mainTime <= userTS.getTiming() + userPF.getFadeOutMS() && userTS.getTiming() != -1){
                sfxExitCue.play();
                qDebug() << userTS.getTiming() + userPF.getFadeOutMS();
                userTS.timingAdvance();
            }
        }


        if (mainTime <= blinkTiming && iterExit-exitPool.begin() != userSP.arbitrary_Target-1){
            //If the clock has reached the next blink, and if its not the final blink, then proceed
            iterExit++;
            blinkOccurs();
        }


}

    if (!totalActive){
        qDebug() << "BasicTimer stopped!";
        ui->TotalTimeLabel->setText("Complete! Seed is: " + ui->outTable->item(userSP.arbitrary_Target-1,0)->text()); //0 is seed column -- fix MAGIC NUMBER
        basicTimer->stop();
    }
}


void MainWindow::runCalibration(u32 seed){
    resultsActiveView = true;
    //populate table with blinks
    exitPool = generateBlinks(seed,userPF,userSP.maxCalibrate);
    qDebug() << exitPool.size() << " blinks generated";

    ui->outTable->setRowCount(userSP.arbitrary_Target);

    iterExit = exitPool.begin();
    postPool(iterExit,iterExit+userSP.arbitrary_Target,0);

    ui->slowerButton->setEnabled(true);
    ui->fasterButton->setEnabled(true);
    ui->seeInputButton->setEnabled(true);
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
                    + ".\nSubsequence at position: " + QString::number(resultIndexes.front()));
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
        ui->outTable->setItem(rowCurrent,0,tblSeed);
        ui->outTable->setItem(rowCurrent,1,fTime);
        rowCurrent++;
        setP++;
    }
}


void MainWindow::postInterval(QString results, int f, int row){
    ui->outTable->setRowCount(ui->outTable->rowCount()+1);
    QTableWidgetItem *resultsStr= new QTableWidgetItem(results);
    QTableWidgetItem *fTime = new QTableWidgetItem(QString::number(f));
    ui->outTable->setItem(row,0,resultsStr);
    ui->outTable->setItem(row,1,fTime);
}



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    keyUnlock = false;
    searchUnlock = false;
    resultsActiveView = false;

    //loads defaults -- will read from file when done.
    keys = KeyCodes();
    userTS = TimerSettings();

    tbl_pastBlink = QColor(222,222,222);
    tbl_currentBlink = QColor(255,236,116);
    tbl_targetBlink = QColor(168,255,200);
    tbl_upcomingBlink = QColor(255,255,255);

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
    basicTimer = new QTimer(this); //Repeats continuously. Purely to create events.

    totalTimer->setSingleShot(true); //Pretty sure this is fine
    totalTimer->setTimerType(Qt::PreciseTimer); //CRITICAL IMPORTANCE. Otherwise defaults to Coarse Timer, which can be wrong by up to 5%

    //There is also a setsingleshot function, avoiding the need to declare and object. However, having the object may be useful

    //connects
    connect(basicTimer,&QTimer::timeout, this, &MainWindow::timerGUIUpdate);
    connect(totalTimer, &QTimer::timeout, this, &MainWindow::totalTimerUpdate);


    ui->arbTargetBox->setValue(15);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    if (ui->pushButton->text() == "START"){
        //ui->pushButton->setEnabled(false);
        qDebug() << QString::number(ui->seedEntry->text().toUInt(nullptr,16),16);

        //keycodetoname
        ui->statusLabel->setText("Press " + keyCodeToName(keys.getBlinkKey()) + " to search!"); //Allow user to change hotkey.

        ui->outTable->clear();
        ui->outTable->setRowCount(0);
        ui->outTable->setColumnCount(2);
        ui->outTable->setStyleSheet("border-style: solid; border-width: 2px; border-color: green");

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
        u32 seed = userSP.inputSeed;
        LCGn(seed,userSP.minSearch); //abstraction is needed to prevent modification
        mainPool = generateBlinks(seed,userPF,userSP.maxSearch-userSP.minSearch); //SEED IS NOT MODIFIED

        keyUnlock = true;
        ui->pushButton->clearFocus();
        ui->seeInputButton->setEnabled(false);
        ui->pushButton->setText("STOP");
    } else {
        totalTimer->stop();
        basicTimer->stop();
        ui->statusLabel->setText("STATUS");
        ui->TotalTimeLabel->setText("TIME REMAINING:");
        ui->localTimeLabel->setText("NEXT BLINK:");
        keyUnlock = false;
        searchUnlock = false;
        ui->arbTargetBox->setEnabled(true);
        ui->nudgeOffsetLabel->setText("0");
        ui->pushButton->setText("START");
    }
}


void MainWindow::keyPressEvent(QKeyEvent* event)
{
    //SO THIS FUNC CALLS EVERY TIME THERE'S A KEY

    //Keys to change target?

    if (event->key() == keys.getBlinkKey()) {
        if (keyUnlock){
            if (!searchUnlock){
                searchUnlock = true;
                ui->statusLabel->setText("Listening!");
                start = std::chrono::high_resolution_clock::now();
            } else {
                //do stuff
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

                    keyUnlock = false;
                    if (status == 1){
                        //PROCEED TO CALIBRATE
                        ui->outTable->clear();
                        ui->outTable->setStyleSheet("border-style: solid; border-width: 2px; border-color: purple");
                        sfxSearchSuccess.play();
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
                    }
                }
            }
            event->accept();
        }
    }
    else if (event->key() == keys.getSlowerKey()) {
        on_slowerButton_clicked();
        event->accept();
    } else if (event->key() == keys.getFasterKey()){
        on_fasterButton_clicked();
        event->accept();
    } else {
        QWidget::keyPressEvent(event);
    }
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
        ui->seeInputButton->setText("v See future blinks");
    } else {
        resultsActiveView = true;
        restoreResults();
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
        nudgeCalibration(false);
    }
}

void MainWindow::on_fasterButton_clicked()
{
    if (totalTimer->isActive()){
        nudgeCalibration(true);
    }
}

void MainWindow::on_galesRadio_clicked()
{
    ui->emu5CheckBox->setEnabled(true);
}

void MainWindow::on_coloRadio_clicked()
{
    ui->emu5CheckBox->setEnabled(false);
    ui->emu5CheckBox->setChecked(false);
}

void MainWindow::on_palRadio_clicked()
{
    ui->palHzBox->setEnabled(true);
}

void MainWindow::on_ntscuRadio_clicked()
{
    ui->palHzBox->setEnabled(false);
    ui->palHzBox->setCurrentIndex(0);
}

void MainWindow::on_ntscjRadio_clicked()
{
    ui->palHzBox->setEnabled(false);
    ui->palHzBox->setCurrentIndex(0);
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
     qDebug() << "Results are: " << userTS.offset() << " | " << userTS.gap() << " | " << userTS.beeps();

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
