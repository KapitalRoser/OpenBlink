#include "hotkeysdialogue.h"
#include "ui_hotkeysdialogue.h"


void HotkeysDialogue::fillButtonNames(KeyCodes k){
    ui->blinkKeyButton->setText(keyCodeToName(k.getBlinkKey()));
    ui->slowerKeyButton->setText(keyCodeToName(k.getSlowerKey()));
    ui->slowerx5KeyButton->setText(keyCodeToName(k.getSlowerX5Key()));
    ui->fasterKeyButton->setText(keyCodeToName(k.getFasterKey()));
    ui->fasterx5KeyButton->setText(keyCodeToName(k.getFasterX5Key()));
    ui->startStopKeyButton->setText(keyCodeToName(k.getStartStopKey()));
}

KeyCodes HotkeysDialogue::getKeyCodes(){ //Use these for passing data into a dialogue -- see mainwindow for calling code
    return keys;
}
void HotkeysDialogue::setKeyCodes(KeyCodes k){
    keys = k;
    fillButtonNames(keys);
}

void HotkeysDialogue::prepActiveButton(QPushButton *button){
    button->setEnabled(true);
    button->clearFocus();
    button->setText("Press key...");
}
void HotkeysDialogue::disableButtons(){
    for(QPushButton* x : keyList){
        x->setEnabled(false);
    }
}

void HotkeysDialogue::enableButtons(){
    for(QPushButton* x : keyList){
        x->setEnabled(true);
        x->setChecked(false);
    }

}

HotkeysDialogue::HotkeysDialogue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HotkeysDialogue)
{
    ui->setupUi(this);
    connect(ui->blinkKeyButton, &QPushButton::clicked, this, &HotkeysDialogue::input_clicked);
    connect(ui->slowerKeyButton, &QPushButton::clicked, this, &HotkeysDialogue::input_clicked);
    connect(ui->slowerx5KeyButton, &QPushButton::clicked,this,&HotkeysDialogue::input_clicked);
    connect(ui->fasterKeyButton, &QPushButton::clicked, this, &HotkeysDialogue::input_clicked);
    connect(ui->fasterx5KeyButton, &QPushButton::clicked,this,&HotkeysDialogue::input_clicked);
    connect(ui->startStopKeyButton, &QPushButton::clicked, this, &HotkeysDialogue::input_clicked);
    keys = KeyCodes(); //default failsafe initialization, runs before the setKeys in mainwindow
    keyList = this->findChildren<QPushButton*>();
}

HotkeysDialogue::~HotkeysDialogue()
{
    delete ui;
}

void HotkeysDialogue::input_clicked(){
    activeButton = qobject_cast<QPushButton*>(sender());
    disableButtons();
    prepActiveButton(activeButton);
    qDebug() << "NAME: " << activeButton->objectName();
    if(activeButton->objectName().contains("blink")){
        keys.markActive(eBLINK_bkt);
    } else if (activeButton->objectName().contains("slowerKey")){
        keys.markActive(eSLOWER_bkt);
    } else if (activeButton->objectName().contains("slowerx5")){
        keys.markActive(eSLOWERX5_bkt);
    } else if (activeButton->objectName().contains("fasterKey")){
        keys.markActive(eFASTER_bkt);
    } else if (activeButton->objectName().contains("fasterx5")){
        keys.markActive(eFASTERX5_bkt);
    } else if (activeButton->objectName().contains("start")){
        keys.markActive(eSTARTSTOP_bkt);
    }
}

void HotkeysDialogue::on_defaultResetButton_clicked(){
    setKeyCodes(KeyCodes()); //Calling default constructor fills object with default values.
}
void HotkeysDialogue::keyPressEvent(QKeyEvent* event){
    if(activeButton->isChecked()){
        activeButton->setText(keyCodeToName(event->key()));
        keys.setActive(event->key());
        enableButtons();
    }
}
