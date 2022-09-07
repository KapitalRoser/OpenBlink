#include "soundsettingsdialogue.h"
#include "ui_soundsettingsdialogue.h"
#include <QFileDialog>


soundSettingsDialogue::soundSettingsDialogue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::soundSettingsDialogue)
{
    ui->setupUi(this);
    connect(ui->buttonBox->button(QDialogButtonBox::RestoreDefaults),&QPushButton::clicked,
            this,&soundSettingsDialogue::buttonBox_reset);
}

soundSettingsDialogue::~soundSettingsDialogue()
{
    delete ui;
}

void soundSettingsDialogue::set_all_sfx(std::vector<QSoundEffect*> in)
{
    bundle = in;
    updateAllValues();
}

std::vector<QSoundEffect*> soundSettingsDialogue::get_all_sfx()
{
    std::vector<QSoundEffect*> out;
    for (QSoundEffect* i : bundle) {
        out.push_back(i);
    }
    return out;
}

void soundSettingsDialogue::updateValue(float vol, QSpinBox* box, QSlider* slide)
{
    vol *= 100;
    box->setValue(vol);
    slide->setValue(vol);
}

void soundSettingsDialogue::updateAllValues()
{
        //I hate this duplication.
        //ideas: struct of bundled object pointers, trouble is...how to address/indicate which item in the vector?
        //maybe findChild by ID? Name? Type? Go row by row of grid?
        updateValue(bundle[0]->volume(),ui->successBox,ui->successSlide);
        updateValue(bundle[1]->volume(),ui->failureBox,ui->failureSlide);
        updateValue(bundle[2]->volume(),ui->occursBox,ui->occursSlide);
        updateValue(bundle[3]->volume(),ui->completeBox,ui->completeSlide);
        updateValue(bundle[4]->volume(),ui->cueBox,ui->cueSlide);

        updateMute(bundle[0]->isMuted(),ui->successMute);
        updateMute(bundle[1]->isMuted(),ui->failureMute);
        updateMute(bundle[2]->isMuted(),ui->occursMute);
        updateMute(bundle[3]->isMuted(),ui->completeMute);
        updateMute(bundle[4]->isMuted(),ui->cueMute);

        updateFilePath(bundle[0]->source().toString(),ui->successFileLabel);
        updateFilePath(bundle[1]->source().toString(),ui->failureFileLabel);
        updateFilePath(bundle[2]->source().toString(),ui->occursFileLabel);
        updateFilePath(bundle[3]->source().toString(),ui->completeFileLabel);
        updateFilePath(bundle[4]->source().toString(),ui->cueFileLabel);

}
void soundSettingsDialogue::updateMute(bool mute, QPushButton *button)
{
    button->setText(mute ? "🔈" : "🔊");
}

void soundSettingsDialogue::updateFilePath(QString fileName, QLabel* fileLabel)
{
    if (fileName.isEmpty()){
        //From button
        fileName =
            QFileDialog::getOpenFileName(
                this,
                "Open Audio File",
                QDir::currentPath(),
                "WAV files (*.wav);"
            );
    }
    //Save filename as source for sfx.
    fileName = QFileInfo(fileName).fileName();
    fileLabel->setText(fileName);
    //return filename?
}

void soundSettingsDialogue::buttonBox_reset()
{

    for (unsigned int i = 0; i < 5;i++) {
        bundle[i] = new QSoundEffect;
        bundle[i]->setVolume(0.2f);
        bundle[i]->setMuted(false);
    }
    bundle[0]->setSource(QUrl::fromLocalFile(":/resfix1/lvlup.wav"));
    bundle[1]->setSource(QUrl::fromLocalFile(":/resfix1/searchFailure.wav"));
    bundle[2]->setSource(QUrl::fromLocalFile(":/resfix1/blinkWoop.wav"));
    bundle[3]->setSource(QUrl::fromLocalFile(":/resfix1/snagSuccess.wav"));
    bundle[4]->setSource(QUrl::fromLocalFile(":/resfix1/blinkBeep1.wav"));

    updateAllValues();
}

void soundSettingsDialogue::on_successChange_clicked()
{
    updateFilePath("",ui->successFileLabel); //This is duped for each button... surely there's a better way.
    //set source of sfx
}

void soundSettingsDialogue::on_successSlide_valueChanged(int value)
{
    ui->successBox->setValue(value);
    bundle[0]->setVolume(float(value)/100);
}

void soundSettingsDialogue::on_successBox_valueChanged(int arg1)
{
    ui->successSlide->setValue(arg1);
    bundle[0]->setVolume(float(arg1)/100);
}

void soundSettingsDialogue::on_successMute_clicked()
{
    updateMute(!bundle[0]->isMuted(),ui->successMute); //flips mute status.
    bundle[0]->setMuted(!bundle[0]->isMuted());
}
