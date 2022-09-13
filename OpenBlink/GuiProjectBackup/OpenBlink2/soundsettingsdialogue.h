#ifndef SOUNDSETTINGSDIALOGUE_H
#define SOUNDSETTINGSDIALOGUE_H

#include <QDialog>
#include <QSpinBox>
#include <QSlider>
#include <QLabel>
#include <QSoundEffect>
#include <map>
//Idea to store a struct of the needed buttons to update,
//Then create a vector of those items
//Pass that vector or struct into function.
//Allow looping of all buttons with ptrs.
//struct boundItems{
//    QSoundEffect* sfxPtr; //Belong?
//    QSlider* slide;
//    QSpinBox* box;
//    QPushButton* muteButton;
//    QPushButton* changeButton; //needed?
//    QLabel* fileLabel;
//};

enum effects {SUCCESS,FAILURE,OCCURS,COMPLETE,CUE};

enum columns {VOLUME = 1, MUTE = 3,FILENAME = 4};


namespace Ui {
class soundSettingsDialogue;
}

class soundSettingsDialogue : public QDialog
{
    Q_OBJECT

public:
    explicit soundSettingsDialogue(QWidget *parent = nullptr);
    ~soundSettingsDialogue();


    std::vector<QSoundEffect *> bundle;
    std::map<effects, QString> m;
//    std::vector<boundItems> set;
    void set_all_sfx(std::vector<QSoundEffect*>in);
    std::vector<QSoundEffect*> get_all_sfx();
    void initialSetup(effects effect);
    void updateVolume(float vol, effects effect);
    void updateMute(bool mute, QPushButton* button);
    QUrl updateFilePath(QString fileName, QLabel* fileLabel);
    void demoSFX(effects sfx);

private slots:
    //void volumeInput_released();
    void slide_Released();
    void slide_Moved();
    void box_Editing_Finished();
    void box_value_changed();
    void mute_clicked();
    void fileChange_clicked();

    void buttonBox_reset();


private:
    Ui::soundSettingsDialogue *ui;
};

#endif // SOUNDSETTINGSDIALOGUE_H
