#ifndef TIMERSETTINGSDIALOGUE_H
#define TIMERSETTINGSDIALOGUE_H

#include <QDialog>
#include "timersettings.h"

namespace Ui {
class timerSettingsDialogue;
}

class timerSettingsDialogue : public QDialog
{
    Q_OBJECT

public:
    explicit timerSettingsDialogue(QWidget *parent = nullptr);
    ~timerSettingsDialogue();
    TimerSettings ts;

    TimerSettings getTs() const;
    void setTs(const TimerSettings &value);
    void validateInput(bool condition);

private slots:
    void on_buttonBox_reset();

    void on_exitOffsetBox_valueChanged(int arg1);

    void on_exitIntervalBox_valueChanged(int arg1);

    void on_exitBeepsBox_valueChanged(int arg1);

    void on_exitInputBox_valueChanged(int arg1);

private:
    Ui::timerSettingsDialogue *ui;
};

#endif // TIMERSETTINGSDIALOGUE_H
