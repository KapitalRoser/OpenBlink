#include "timersettingsdialogue.h"
#include "ui_timersettingsdialogue.h"
#include <QPushButton>

timerSettingsDialogue::timerSettingsDialogue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::timerSettingsDialogue)
{
    ui->setupUi(this);
    connect(ui->buttonBox->button(QDialogButtonBox::RestoreDefaults),&QPushButton::clicked,
            this,&timerSettingsDialogue::on_buttonBox_reset);
}

timerSettingsDialogue::~timerSettingsDialogue()
{
    delete ui;
}

TimerSettings timerSettingsDialogue::getTs() const
{
    return ts;
}

void timerSettingsDialogue::setTs(const TimerSettings &value)
{
    ts = value;
    ui->exitOffsetBox->setValue(ts.offset());
    ui->exitIntervalBox->setValue(ts.gap());
    ui->exitBeepsBox->setValue(ts.beeps());
    ui->exitInputBox->setValue(-ts.input());
}

void timerSettingsDialogue::validateInput(bool condition)
{
    if (condition){
        //success
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
        ui->buttonBox->button(QDialogButtonBox::Ok)->setText("OK");
        ui->buttonBox->button(QDialogButtonBox::Ok)->setStyleSheet("color: black");
        //Function has already builtQueue()
    } else {
        //failed
        //Error message
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
        ui->buttonBox->button(QDialogButtonBox::Ok)->setText("INVALID");
        ui->buttonBox->button(QDialogButtonBox::Ok)->setStyleSheet("color: red"); //This might cause problems
    }
}

void timerSettingsDialogue::on_buttonBox_reset()
{
    ts = TimerSettings();
    setTs(ts);
}

void timerSettingsDialogue::on_exitOffsetBox_valueChanged(int arg1)
{
    validateInput(ts.setOffset(arg1));
}
void timerSettingsDialogue::on_exitIntervalBox_valueChanged(int arg1)
{
    validateInput(ts.setGap(arg1));
}

void timerSettingsDialogue::on_exitBeepsBox_valueChanged(int arg1)
{
    validateInput(ts.setBeeps(arg1));
}

void timerSettingsDialogue::on_exitInputBox_valueChanged(int arg1)
{
    ts.setInput(-arg1);
    qDebug() << QString::number(-arg1);
}

