/********************************************************************************
** Form generated from reading UI file 'logwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGWINDOW_H
#define UI_LOGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LogWindow
{
public:
    QGridLayout *gridLayout;
    QPushButton *copyButton;
    QPushButton *okButton;
    QLabel *logLabel;

    void setupUi(QDialog *LogWindow)
    {
        if (LogWindow->objectName().isEmpty())
            LogWindow->setObjectName(QString::fromUtf8("LogWindow"));
        LogWindow->resize(400, 300);
        gridLayout = new QGridLayout(LogWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        copyButton = new QPushButton(LogWindow);
        copyButton->setObjectName(QString::fromUtf8("copyButton"));

        gridLayout->addWidget(copyButton, 1, 1, 1, 1);

        okButton = new QPushButton(LogWindow);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        gridLayout->addWidget(okButton, 1, 2, 1, 1);

        logLabel = new QLabel(LogWindow);
        logLabel->setObjectName(QString::fromUtf8("logLabel"));

        gridLayout->addWidget(logLabel, 0, 1, 1, 2);


        retranslateUi(LogWindow);

        QMetaObject::connectSlotsByName(LogWindow);
    } // setupUi

    void retranslateUi(QDialog *LogWindow)
    {
        LogWindow->setWindowTitle(QCoreApplication::translate("LogWindow", "Dialog", nullptr));
        copyButton->setText(QCoreApplication::translate("LogWindow", "Copy", nullptr));
        okButton->setText(QCoreApplication::translate("LogWindow", "OK", nullptr));
        logLabel->setText(QCoreApplication::translate("LogWindow", "LOG", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LogWindow: public Ui_LogWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGWINDOW_H
