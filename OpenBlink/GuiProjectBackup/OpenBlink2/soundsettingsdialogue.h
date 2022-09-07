#ifndef SOUNDSETTINGSDIALOGUE_H
#define SOUNDSETTINGSDIALOGUE_H

#include <QDialog>
#include <QSpinBox>
#include <QSlider>
#include <QLabel>
#include <QSoundEffect>

//Idea to store a struct of the needed buttons to update,
//Then create a vector of those items
//Pass that vector or struct into function.
//Allow looping of all buttons with ptrs.
//struct boundItems{
//    QSoundEffect* sfxPtr; //Belong?
//    float volume;
//    bool mute;
//    QString fileName; //path?
//    QSlider* slide;
//    QSpinBox* box;
//    QPushButton* muteButton;
//    QPushButton* changeButton; //needed?
//    QLabel* fileLabel;
//};

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
    void set_all_sfx(std::vector<QSoundEffect*>in);
    std::vector<QSoundEffect*> get_all_sfx();
    void updateValue(float vol, QSpinBox* box, QSlider* slide);
    void updateAllValues();
    void updateMute(bool mute, QPushButton* button);
    void updateFilePath(QString fileName, QLabel* fileLabel);
private slots:
    void buttonBox_reset();

    void on_successChange_clicked();

    void on_successSlide_valueChanged(int value);

    void on_successBox_valueChanged(int arg1);

    void on_successMute_clicked();

private:
    Ui::soundSettingsDialogue *ui;
};

#endif // SOUNDSETTINGSDIALOGUE_H
