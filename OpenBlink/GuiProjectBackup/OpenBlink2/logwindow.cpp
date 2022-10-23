#include "logwindow.h"
#include "ui_logwindow.h"

LogWindow::LogWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogWindow)
{
    ui->setupUi(this);
    ui->logLabel->setText(displayStr);
}

LogWindow::~LogWindow()
{
    delete ui;
}
