#ifndef HOTKEYSDIALOGUE_H
#define HOTKEYSDIALOGUE_H

#include <QDialog>
#include <QKeyEvent>
#include "blinkbase.h"
#include "keycodes.h"


namespace Ui {

class HotkeysDialogue;
}

class HotkeysDialogue : public QDialog
{
    Q_OBJECT

public:
    explicit HotkeysDialogue(QWidget *parent = nullptr);
    ~HotkeysDialogue();

    int blinkKey, slowerKey,fasterKey; //short, easy to work with. Packaged into keyCodes() object to be sent to MainWindow().
    KeyCodes keys;
    //Could store these as a keyCodes object directly, but watch out for the verbosity.
    int* activeKey;
    QPushButton* activeButton;

    void keyPressEvent(QKeyEvent* event);

    KeyCodes getKeyCodes();
    void setKeyCodes(KeyCodes k);
    void fillButtonNames(KeyCodes k);
    void prepActiveButton(QPushButton* button);
    void disableButtons();
    void enableButtons();

private slots:
    void input_clicked();

    void defaultResetButton_clicked();

private:
    Ui::HotkeysDialogue *ui;
};

#endif // HOTKEYSDIALOGUE_H
