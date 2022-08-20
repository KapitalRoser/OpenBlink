#include "mainwindow.h"
#include "ui_mainwindow.h"


//These are almost entirely just debug globals.
auto start = std::chrono::high_resolution_clock::now();

int msDelayTotal = 0;
int prevTime = 0;

float debugGapStore = 0;
float totalGap = 0;

int storeTotalPrev = 0;

bool finFlag = false; //MOVE THIS INTERNALLY IF IT WORKS




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

            /*
            Unnecessary optizimation:
            timerLimit += setI->blink * (setI < limiterI ? 1 : -1); //this might work?
            timerLimit = setI < limiterI ? timerLimit + setI->blink : timerLimit - setI->blink;
            setI = setI < limiterI ? setI + 1 : setI - 1;


            old:
            timerLimit += setI->blink * framerate;
            setI++;
            */

        }

    return timerLimit;
}


void MainWindow::testTimerUpdate(){
    qDebug() << "Timer finished!" << simulTimerSet[0]->isActive() << simulTimerSet[1]->isActive();
    sfxCalibrationComplete.play();
}

int MainWindow::iterPToMS(iterP iter, float framerate){ //Move internally?
    //qDebug() << "Round: " << iter->blink*framerate << " to " << round(iter->blink*framerate); //this rounding stuff is fine I think.
    return round((iter->blink)*framerate);
}
void MainWindow::blinkOccurs(){
    sfxBlinkOccurs.play();
    //tableCurrentRow++; //Instead iterate based on the internal exitPool Iterator?
    //ui->outTable->selectRow(tableCurrentRow); //IF ROW DOESN'T EXIST, SELECT WON'T CRASH
    // iterExit-1, current, iterExit-2 is previous?
    if (resultsActiveView){
        highlightTableRow(iterExit-exitPool.begin()-1,tbl_pastBlink);
        highlightTableRow(iterExit-exitPool.begin(),tbl_currentBlink);
    }


    //qDebug() << QString::number(tableCurrentRow);
}

void MainWindow::highlightTableRow(int row, QColor color){
    ui->outTable->item(row,0)->setBackground(QBrush(color));
    ui->outTable->item(row,1)->setBackground(QBrush(color));
}

void MainWindow::totalTimerUpdate(){
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    qDebug() << "Total Duration: " << float(duration.count())/1000;
    sfxCalibrationComplete.play(); //Is this it?
    highlightTableRow(iterExit-exitPool.begin(),tbl_targetBlink);
    ui->arbTargetBox->setEnabled(true);
}

//void MainWindow::localTimerUpdateA(){

//    iterExit++;
//    if (iterExit - exitPool.begin() <= userSP.arbitrary_Target-1){
//        //finFlag = true; //THIS IS OK ON FINAL?
//        float shouldMS = float(setTimerLimit(exitPool.begin(),iterExit,userPlatform.getFramerate()))/1000;
//        float elapsedMS = float(totalTimerLimit)/1000 - float(totalTimer->remainingTime())/1000;
//        float gap = shouldMS - elapsedMS;
//        if (iterExit-exitPool.begin()>1){
//          totalGap += gap-debugGapStore;
//        }

//        qDebug() << "TimerA: Blink ms: " << iterPToMS(iterExit,userPlatform.getFramerate()) << ". Total MS Should be: "
//        << shouldMS << ". Total MS is: " << elapsedMS << ". Gap is: " << gap << ". Change: " << gap-debugGapStore
//        << "Accumulated Gap: " << totalGap;
//        debugGapStore = gap;
//        localTimerA->start(iterPToMS(iterExit,userPlatform.getFramerate()));
//        blinkOccurs();
//    }

//    //we sometimes crash on the final blink.
//    //NOT ACCUMULATED DEBT. Total debt is almost nothing. 300-500 ms accuracy problem seems to have to do with the last blink.
//    //Blinks ending on a small number lik 18 or 25 have very small delays. Then others jump all the way up to 1 or 2 frame delay.
//    //auto stop = std::chrono::high_resolution_clock::now();
//    //auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - localStart);
//    //msDelayTotal += duration.count();
//    //ui->delayLabel->setText(QString::number(duration.count()) + " " + QString::number(msDelayTotal));
//}

//void MainWindow::localTimerUpdateB(){
//    iterExit++;
//    if (iterExit - exitPool.begin() <= userSP.arbitrary_Target-1){
//        finFlag = true;
//        qDebug() << "TimerA is Started";
//        localTimerA->start(iterPToMS(iterExit,userPlatform.getFramerate()));
//    }
//}

void MainWindow::timerGUIUpdate(){

    //calls to remainingTime() are basically free, much faster than restarting the blink timer constantly so lets just use that for everything.
    //THIS TIMER ISN'T PERFECT. SOMETIMES TIME BETWEEN CALLS IS >1 MS, AT LEAST ACCORDING TO MAINTIME
    //MAYBE NOT ACCORDING TO STD CHRONO TIME?

    int mainTime = 0;
//    bool localActive = localTimerA->isActive();
    bool totalActive = totalTimer->isActive();
    int blinkTiming = setTimerLimit(iterExit+1,exitPool.begin()+userSP.arbitrary_Target,userPlatform.getFramerate());
    //if (localActive){
  //  localTime = localTimerA->remainingTime();
    //}

    if (totalActive){
        mainTime = totalTimer->remainingTime();
        ui->TotalTimeLabel->setText("TIME REMAINING: " + QString::number(float(mainTime)/1000)); //Can we get by updating this every 10 ms instead of 1?
//        if (storeTotalPrev - mainTime > 1){
//            qDebug() << mainTime;
//        }
//        storeTotalPrev = mainTime;
        //qDebug() << QString::number(float(totalTimer->remainingTime())/1000);
//        if (prevTime - float(totalTimer->remainingTime())/1000 > 1){
//            qDebug() << "FROZE: " << QString::number(prevTime - float(totalTimer->remainingTime())/1000);
//        }
//        prevTime = float(totalTimer->remainingTime())/1000;
//    }


//        int store = totalTimer->remainingTime();
//        if (totalTimerLimit - store >= iterPToMS(iterExit,userPlatform.getFramerate())){
//            iterExit++;
//            sfxBlinkOccurs.play();
//            tableCurrentRow++; //Instead iterate based on the internal exitPool Iterator?
//            ui->outTable->selectRow(tableCurrentRow); //IF ROW DOESN'T EXIST, SELECT WON'T CRASH LOOL
//            qDebug() << QString::number(tableCurrentRow);
//            //Could remove localTimer and just have basicTimer check totalTimer.duration() and base the blink timings off that
//        }



        //A AND B TIMER WHERE A TIMER STARTS THE B TIMER BEFORE CALLING STOP FUNCS.
//    if (localActive){
//        ui->localTimeLabel->setText("NEXT BLINK: " + QString::number(float(localTime)/1000)); //45ms delay between blinks?? Or is that just final blink delay??
//    }
    ui->localTimeLabel->setText("NEXT BLINK: " + QString::number(float(mainTime-blinkTiming)/1000));
//    if (localTimerB->isActive()){
//        ui->localTimeLabel->setText("NEXT BLINK: " + QString::number(float(localTimerB->remainingTime())/1000));
//    }
    int TEMP_EXIT_BUFFER = 5000;
    if (mainTime <= TEMP_EXIT_BUFFER){
        if (ui->arbTargetBox->isEnabled()){
            ui->arbTargetBox->setEnabled(false);
        }
       ui->exitTimeLabel->setText("Exit: " + QString::number(float(mainTime)/1000));
    }


//    if (finFlag){
//        finFlag = false;
//        blinkOccurs();
//        //Could remove localTimer and just have basicTimer check totalTimer.duration() and base the blink timings off that.
//    }

    if (mainTime <= blinkTiming && iterExit-exitPool.begin() != userSP.arbitrary_Target-1){
        //If the clock has reached the next blink, and if its not the final blink, then proceed
        iterExit++;
        blinkOccurs();
    }


}






//    if (localActive){
//        ui->localTimeLabel->setText("NEXT BLINK: " + QString::number(float(localTimerA->remainingTime())/1000)); //45ms delay between blinks?? Or is that just final blink delay??
//    }
    if (!totalActive){
        qDebug() << "BasicTimer stopped!";
        ui->TotalTimeLabel->setText("Complete! Seed is: " + ui->outTable->item(userSP.arbitrary_Target-1,0)->text()); //0 is seed column -- fix MAGIC NUMBER
        basicTimer->stop();
    }
}




void MainWindow::runCalibration(u32 seed){
    resultsActiveView = true;
    //populate table with blinks
    exitPool = generateBlinks(seed,userPlatform,userSP.maxCalibrate);

//    for (int i = 0; i < exitPool.size();i++){
//        exitPool[i].blink = 95;
//    }

    ui->outTable->setRowCount(userSP.arbitrary_Target);
//    for (unsigned int i = 0; i < exitPool.size(); i++){
//        postPool(exitPool[i].seed,exitPool[i].blink); //ADD MS TO TABLE??? NEED MORE ROWS????
//    }
    iterExit = exitPool.begin();
    postPool(iterExit,iterExit+userSP.arbitrary_Target,0);
//    tableCurrentRow = 0;

    //Visual setup complete



    int TEMP_msOffset = 0; //UNTIL INPUT IS IMPLEMENTED



    //INCLUDE TIME TO START EXIT BEEPING LIKE FLOWTIMER DEFAULT 5000 MS BEFORE FINISHED.

    ui->TotalTimeLabel->setText(QString::number(totalTimerLimit));
    //prep visuals
    highlightTableRow(0,tbl_currentBlink);
    highlightTableRow(userSP.arbitrary_Target-1,tbl_targetBlink);


    totalTimerLimit = setTimerLimit(iterExit,exitPool.begin()+userSP.arbitrary_Target,userPlatform.getFramerate()); //End of list.
    qDebug() << "ttl: " << float(totalTimerLimit)/1000;
    start = std::chrono::high_resolution_clock::now();
    totalTimer->start(totalTimerLimit); //Test this thoroughly.
    //localTimerA->start(round(iterPToMS(iterExit,userPlatform.getFramerate())));
    basicTimer->start(1);
}

int MainWindow::performSearchPass(u32 &outSeed){
    if (!mainPool.empty()){
        std::vector<int> resultIndexes; //does not persist between searches -- for size(), null == 0
            resultIndexes = searchPool(mainPool,blinkList,userSP.flexValue); //these inputs do persist between searches.
            postInterval(QString::number(resultIndexes.size()) + " seeds.",blinkList.back(),blinkList.size()-1); //TABLE UPDATE
            if (resultIndexes.size() > 1){
                ui->statusLabel->setText("Searching... " + QString::number(resultIndexes.size()) + " result(s) found!");
                //TABLE:

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
                ui->statusLabel->setText("FAILURE");
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
        rowCurrent++; //used for later population
        setP++;
    }
}


void MainWindow::postInterval(QString results, int f, int row){
    ui->outTable->setRowCount(ui->outTable->rowCount()+1);
    QTableWidgetItem *resultsStr= new QTableWidgetItem(results); //DO I NEED DESTRUCTORS FOR THESE?
    QTableWidgetItem *fTime = new QTableWidgetItem(QString::number(f));
    ui->outTable->setItem(row,0,resultsStr);
    ui->outTable->setItem(row,1,fTime);
    //tableCurrentRow++; //used for initial keypress event
}



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    keyUnlock = false;
    searchUnlock = false;
    resultsActiveView = false;



    //tableCurrentRow = 0;
    tbl_pastBlink = QColor(222,222,222);
    tbl_currentBlink = QColor(255,236,116);
    tbl_targetBlink = QColor(168,255,200);
    tbl_upcomingBlink = QColor(255,255,255);

    sfxSearchSuccess.setSource(QUrl::fromLocalFile(":/resfix1/lvlup.wav")); //Allow user to mute or adjust volume
    sfxBlinkOccurs.setSource(QUrl::fromLocalFile(":/resfix1/blinkWoop.wav"));
    sfxCalibrationComplete.setSource(QUrl::fromLocalFile(":/resfix1/snagSuccess.wav"));
    sfxSearchSuccess.setVolume(0.2f);
    sfxBlinkOccurs.setVolume(0.2f);
    sfxCalibrationComplete.setVolume(0.2f);

    totalTimer = new QTimer(this);
//    localTimerA = new QTimer(this); //Destroy?
//    localTimerB = new QTimer(this);
    simulTimerSet = std::vector<QTimer*>{new QTimer(this),new QTimer(this)};
    basicTimer = new QTimer(this); //Repeats continuously. Purely to create events.

    totalTimer->setSingleShot(true); //Pretty sure this is fine
//    localTimerA->setSingleShot(true);
//    localTimerB->setSingleShot(true);
    simulTimerSet[0]->setSingleShot(true);
    simulTimerSet[1]->setSingleShot(true);

    //There is also a setsingleshot function, avoiding the need to declare and object. However, having the object may be useful

    //connects
    connect(basicTimer,&QTimer::timeout, this, &MainWindow::timerGUIUpdate);
    connect(totalTimer, &QTimer::timeout, this, &MainWindow::totalTimerUpdate);
//    connect(localTimerA, &QTimer::timeout, this, &MainWindow::localTimerUpdateA);
//    connect(localTimerB, &QTimer::timeout, this, &MainWindow::localTimerUpdateB);
    connect(simulTimerSet[0], &QTimer::timeout, this, &MainWindow::totalTimerUpdate);
    connect(simulTimerSet[1], &QTimer::timeout, this, &MainWindow::totalTimerUpdate);
    //exit timer need connect?


    ui->arbTargetBox->setValue(15);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    qDebug() << QString::number(ui->seedEntry->text().toUInt(nullptr,16),16);
    ui->statusLabel->setText("Press Shift to search!"); //Allow user to change hotkey.
    //ui->outTable->setRowCount(20); //SHOULDN'T THIS BE UPDATED AS THE USER ENTERS BLINKS???
    ui->outTable->setColumnCount(2);
    ui->outTable->setStyleSheet("border-style: solid; border-width: 2px; border-color: green");

    //definitions
    userPlatform = platform(0,0,NTSCU);
    userSP.inputSeed =  ui->seedEntry->text().toUInt(nullptr,16);; //input cleanse
    userSP.flexValue = 10;
    userSP.arbitrary_Target = ui->arbTargetBox->value();
    userSP.maxCalibrate = 10000;
    userSP.maxSearch = 20000;
    userSP.minSearch = 0;

    blinkList.clear();
    exitPool.clear();
    mainPool.clear();
    mainPool = generateBlinks(userSP.inputSeed,userPlatform,userSP.maxSearch); //SEED IS NOT MODIFIED

    keyUnlock = true;

}


void MainWindow::keyPressEvent(QKeyEvent* event)
{
    //SO THIS FUNC CALLS EVERY TIME THERE'S A KEY
    int KeyToBlink = 0x01000020; //Modifiable later.
    if (event->key() == KeyToBlink) {
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
                const int LAG_REDUCTION = 10; //holdover, seems to better align my code with sinapoke's. Accounts for some difference in hardware timing used.
                blinkList.push_back((duration.count()-LAG_REDUCTION)/userPlatform.getFramerate());

                //Debug blink list?
                u32 seed = 0; //result of searching
                int status = performSearchPass(seed); //returns status: -1 error, 0 failure, 1 success, 2 continue search
                if (status < 2){
                    //LOG NOW ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~********************!!!!!!!!!!!!!!!!!!!!!!!!!******************!!!!!!!!!!!!!!!!!!!!!!!*************!!!!!!!!!!!!!!
                    ui->outTable->clear();
                    keyUnlock = false;
                    //tableCurrentRow = 0;
                    if (status == 1){
                     //PROCEED TO CALIBRATE
                     ui->outTable->setStyleSheet("border-style: solid; border-width: 2px; border-color: purple");
                     //runTimer();
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

                    }
                }
                /*

                if status success
                clear table
                emit runTimer()

                if status fail or error
                clear table
                stop search
                reset search

                if continue do nothing

                */

            }
            event->accept();
        }
    }
    else {
        // The next two lines are equivalent. Use only one, and do it
        // consistently, but do it at least once if you don't handle the event.
        QWidget::keyPressEvent(event);
        event->ignore();
    }
}

void MainWindow::on_pushButton_2_clicked() //eventually get rid of this?
{
    totalTimer->stop();
    //localTimerA->stop();
    basicTimer->stop();
    ui->statusLabel->setText("STATUS");
    ui->TotalTimeLabel->setText("TIME REMAINING:");
    ui->outTable->clear();
    ui->outTable->setRowCount(0);
    //tableCurrentRow = 0;
    keyUnlock = false;
    searchUnlock = false;
    ui->arbTargetBox->setEnabled(true);
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

    if (totalTimer->isActive() && arg1 > iterExit-exitPool.begin() + 1){
        iterP adjustedTarget = exitPool.begin() + arg1;//is this fine or do i need .value()?
        //temporary
        while (adjustedTarget > exitPool.end() || arg1 > ui->outTable->rowCount()){
            on_increaseBlinksButton_clicked();
        }

        int targetOffset = setTimerLimit(exitPool.begin()+userSP.arbitrary_Target,adjustedTarget,userPlatform.getFramerate());
        qDebug() << totalTimer->remainingTime() << "ms +  " << targetOffset << " = " << totalTimer->remainingTime()+targetOffset;
        //this is strictly the positive or negative adjustment from the current target to the next, not a time-point.

        //new total = time from current blink to target blink
        //auto startt = std::chrono::high_resolution_clock::now();
        totalTimer->setInterval(totalTimer->remainingTime() + targetOffset); //simply adds or removes the time as needed
//        auto stopt = std::chrono::high_resolution_clock::now();
//        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stopt - startt);
//        msDelayTotal += duration.count();
//        qDebug() << "delay: " << duration.count() << ". total: " << float(msDelayTotal)/1000;
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
        std::vector<pool>add10 = generateBlinks(exitPool.end()->seed,userPlatform,ARBITRARY_10_ADD*100); //remember to adjust for blinks vs advances
        for (pool p : add10){
            exitPool.push_back(p);
        } //requires testing to make sure it's accurate.
    }
    restoreResults();

}

void MainWindow::on_pushButton_3_clicked()
{
//    simulTimerSet[0]->start(1000);
//    simulTimerSet[1]->start(1000);
//    start = std::chrono::high_resolution_clock::now();
    auto testStart = std::chrono::high_resolution_clock::now();
    QString store;
    for (int i = 0; i < 300000; i++){
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        start = std::chrono::high_resolution_clock::now();
        store = QString::number(duration.count());
    }
    auto testStop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(testStop - testStart);
    qDebug() << "Test1: " << duration.count();

}
