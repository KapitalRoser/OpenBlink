#include "soundsettingsdialogue.h"
#include "ui_soundsettingsdialogue.h"
#include <QFileDialog>

effects findEffect(const std::map<effects,QString> &in, QString k){
    for (auto& it : in){
        if (it.second == k){
            return it.first;
        }
    }
    return SUCCESS; //ERROR CASE
}

soundSettingsDialogue::soundSettingsDialogue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::soundSettingsDialogue)
{
    ui->setupUi(this);
    m = {
       {SUCCESS,"success"},
       {FAILURE,"failure"},
       {OCCURS,"occurs",},
       {COMPLETE,"complete"},
       {CUE,"cue"},
   };
    connect(ui->buttonBox->button(QDialogButtonBox::RestoreDefaults),&QPushButton::clicked,
            this,&soundSettingsDialogue::buttonBox_reset);


    QList<QSlider*> ls = this->findChildren<QSlider*>();
    for (QSlider* x : ls) {
        connect(x,&QSlider::sliderReleased,
                this,&soundSettingsDialogue::volumeInput_released);
        connect(x,&QSlider::sliderMoved,
                this,&soundSettingsDialogue::slide_Moved);
    }

    QList<QSpinBox*> lb = this->findChildren<QSpinBox*>();
    for(QSpinBox* x : lb){
        connect(x,&QSpinBox::editingFinished,
                this,&soundSettingsDialogue::volumeInput_released);
        connect(x,&QSpinBox::valueChanged,
                this,&soundSettingsDialogue::box_value_changed);
    }

    QRegularExpression exp("Mute");
    QList<QPushButton*> lm = this->findChildren<QPushButton*>(exp);
    for(QPushButton* x : lm){
        connect (x,&QPushButton::clicked,
                 this,&soundSettingsDialogue::mute_clicked);
    }

    exp.setPattern("Change");
    lm = this->findChildren<QPushButton*>(exp);
    for(QPushButton* x : lm){
        connect (x,&QPushButton::clicked,
                 this,&soundSettingsDialogue::fileChange_clicked);
    }

}

soundSettingsDialogue::~soundSettingsDialogue()
{
    delete ui;
}

void soundSettingsDialogue::set_all_sfx(std::vector<QSoundEffect*> in)
{
    bundle = in;
    for (unsigned int i = 0; i < bundle.size(); ++i) {
        initialSetup(effects(i));
    }
}

std::vector<QSoundEffect*> soundSettingsDialogue::get_all_sfx()
{
    std::vector<QSoundEffect*> out;
    for (QSoundEffect* i : bundle) {
        out.push_back(i);
    }
    return out;
}

void soundSettingsDialogue::initialSetup(effects effect)
{
    //this->blockSignals(true);//DANGEROUS
    updateVolume(bundle[effect]->volume(),effect); //Avoid signals with glob flag? Or with diff signal? Or block signals
    updateMute(bundle[effect]->isMuted(),this->findChild<QPushButton*>(m[effect]+"Mute")); //No signals triggered
    updateFilePath(bundle[effect]->source().toString(),this->findChild<QLabel*>(m[effect]+"FileLabel")); //No signals triggered
    //this->blockSignals(false);
}

void soundSettingsDialogue::updateVolume(float vol, effects effect)
{
    //Only used initially.
    vol *= 100;
    QSpinBox* activeB = this->findChild<QSpinBox*>(m[effect]+"Box");
    activeB->blockSignals(true);
    activeB->setValue(vol);
    activeB->blockSignals(false); //not required for slider...
    this->findChild<QSlider*>(m[effect]+"Slide")->setValue(vol);
}

void soundSettingsDialogue::updateMute(bool mute, QPushButton *button)
{
    button->setText(mute ? "🔈" : "🔊");
}

QUrl soundSettingsDialogue::updateFilePath(QString fileName, QLabel* fileLabel)
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
    fileName = QFileInfo(fileName).fileName();
    fileLabel->setText(fileName);
    return QUrl("file:" + fileName);
}

void soundSettingsDialogue::demoSFX(effects sfx)
{
    bundle[sfx]->play();
}

void soundSettingsDialogue::volumeInput_released()
{
    int value = 0;
    int chopAmt = 0;
    if (QString(sender()->metaObject()->className()) == "QSlider"){
        value = qobject_cast<QSlider*>(sender())->value();
        chopAmt = 5;
    } else {
        value = qobject_cast<QSpinBox*>(sender())->value();
        chopAmt = 3;
    }
    QString sName = sender()->objectName().chopped(chopAmt);

    QSlider* activeS = this->findChild<QSlider*>(sName + "Slide");
    QSpinBox* activeB = this->findChild<QSpinBox*>(sName + "Box");
    activeS->setValue(value);
    activeB->setValue(value);

    bundle[findEffect(m,sName)]->setVolume(float(value/100));
    demoSFX(findEffect(m,sName));
}

void soundSettingsDialogue::slide_Moved()
{
    QSlider* activeS = qobject_cast<QSlider*>(sender());
    this->findChild<QSpinBox*>(activeS->objectName().chopped(5)+"Box")->setValue(activeS->value());

}

void soundSettingsDialogue::box_value_changed()
{
    QSpinBox* activeB = qobject_cast<QSpinBox*>(sender()); //something to do with this.
    this->findChild<QSpinBox*>(activeB->objectName().chopped(3)+"Slide")->setValue(activeB->value());
}

void soundSettingsDialogue::mute_clicked()
{
    QPushButton* activeBtn = qobject_cast<QPushButton*>(sender());
    QString bName = activeBtn->objectName().chopped(4);
    bool status = !bundle[findEffect(m,bName)]->isMuted();
    bundle[findEffect(m,bName)]->setMuted(status);
    updateMute(status,activeBtn);
    demoSFX(findEffect(m,bName));
}

void soundSettingsDialogue::fileChange_clicked()
{
    QPushButton* activeBtn = qobject_cast<QPushButton*>(sender());
    QString bName = activeBtn->objectName().chopped(6);
    bundle[findEffect(m,bName)]->setSource(updateFilePath("",this->findChild<QLabel*>(bName+"FileLabel")));
    demoSFX(findEffect(m,bName));
    //If converting from string to QUrl, remember to put some indicator in front like "file:" and then the path.
    //Otherwise throws a decoding error.
}

void soundSettingsDialogue::buttonBox_reset()
{

    for (unsigned int i = 0; i < 5;i++) {
        bundle[i] = new QSoundEffect;
        bundle[i]->setVolume(0.2f);
        bundle[i]->setMuted(false);
    }
    bundle[SUCCESS]->setSource(QUrl::fromLocalFile(":/resfix1/lvlup.wav"));
    bundle[FAILURE]->setSource(QUrl::fromLocalFile(":/resfix1/searchFailure.wav"));
    bundle[OCCURS]->setSource(QUrl::fromLocalFile(":/resfix1/blinkWoop.wav"));
    bundle[COMPLETE]->setSource(QUrl::fromLocalFile(":/resfix1/snagSuccess.wav"));
    bundle[CUE]->setSource(QUrl::fromLocalFile(":/resfix1/blinkBeep1.wav"));
    set_all_sfx(bundle);
}

//void soundSettingsDialogue::on_successMute_clicked()
//{
//    updateMute(!bundle[0]->isMuted(),ui->successMute); //flips mute status.
//    bundle[0]->setMuted(!bundle[0]->isMuted());
//}
