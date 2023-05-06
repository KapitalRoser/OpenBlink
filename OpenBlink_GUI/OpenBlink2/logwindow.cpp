#include "logwindow.h"
#include "ui_logwindow.h"

LogWindow::LogWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogWindow)
{
    ui->setupUi(this);
}

LogWindow::~LogWindow()
{
    delete ui;
}

void LogWindow::setLogDisplay(QString str)
{
    displayStr = str;
    ui->logLabel->setText(str);
}

void LogWindow::on_okButton_clicked()
{
    this->accept();
}



void LogWindow::on_copyButton_clicked()
{
    QClipboard *clip = QApplication::clipboard();
    clip->setText(displayStr);
    ui->copyButton->setText("Copied!");
}

