#ifndef LOGWINDOW_H
#define LOGWINDOW_H

#include <QDialog>
#include <QClipboard>

namespace Ui {
class LogWindow;
}

class LogWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LogWindow(QWidget *parent = nullptr);
    ~LogWindow();

    QString displayStr;
    void setLogDisplay(QString str);

private slots:
    void on_okButton_clicked();

    void on_copyButton_clicked();

private:
    Ui::LogWindow *ui;
};

#endif // LOGWINDOW_H
