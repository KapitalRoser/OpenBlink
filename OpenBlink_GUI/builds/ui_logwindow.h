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
    QPushButton *okButton;
    QLabel *logLabel;
    QPushButton *copyButton;

    void setupUi(QDialog *LogWindow)
    {
        if (LogWindow->objectName().isEmpty())
            LogWindow->setObjectName(QString::fromUtf8("LogWindow"));
        LogWindow->resize(377, 300);
        gridLayout = new QGridLayout(LogWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        okButton = new QPushButton(LogWindow);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(okButton->sizePolicy().hasHeightForWidth());
        okButton->setSizePolicy(sizePolicy);
        okButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color: #004080;\n"
"font: \"Century Gothic\";\n"
"font-size: auto;\n"
"color: white;\n"
"font-weight: bold;\n"
"border-radius:20px;\n"
"}\n"
"QPushButton:hover{\n"
"background-color: #265d93;\n"
"}\n"
"QPushButton:pressed{\n"
"background-color: #004080;\n"
"}\n"
"QPushButton:disabled{\n"
"background-color:#e0e0e0;\n"
"font-weight:normal;\n"
"color:grey;\n"
"}"));

        gridLayout->addWidget(okButton, 2, 1, 1, 1);

        logLabel = new QLabel(LogWindow);
        logLabel->setObjectName(QString::fromUtf8("logLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(logLabel->sizePolicy().hasHeightForWidth());
        logLabel->setSizePolicy(sizePolicy1);
        logLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout->addWidget(logLabel, 0, 0, 1, 2);

        copyButton = new QPushButton(LogWindow);
        copyButton->setObjectName(QString::fromUtf8("copyButton"));
        sizePolicy.setHeightForWidth(copyButton->sizePolicy().hasHeightForWidth());
        copyButton->setSizePolicy(sizePolicy);
        copyButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color: #004080;\n"
"font: \"Century Gothic\";\n"
"font-size: auto;\n"
"color: white;\n"
"font-weight: bold;\n"
"border-radius:20px;\n"
"}\n"
"QPushButton:hover{\n"
"background-color: #265d93;\n"
"}\n"
"QPushButton:pressed{\n"
"background-color: #004080;\n"
"}\n"
"QPushButton:disabled{\n"
"background-color:#e0e0e0;\n"
"font-weight:normal;\n"
"color:grey;\n"
"}"));

        gridLayout->addWidget(copyButton, 2, 0, 1, 1);

        gridLayout->setRowStretch(0, 5);
        gridLayout->setRowStretch(1, 6);
        gridLayout->setRowStretch(2, 3);

        retranslateUi(LogWindow);

        QMetaObject::connectSlotsByName(LogWindow);
    } // setupUi

    void retranslateUi(QDialog *LogWindow)
    {
        LogWindow->setWindowTitle(QCoreApplication::translate("LogWindow", "Log output", nullptr));
        okButton->setText(QCoreApplication::translate("LogWindow", "OK", nullptr));
        logLabel->setText(QCoreApplication::translate("LogWindow", "LOG", nullptr));
        copyButton->setText(QCoreApplication::translate("LogWindow", "Copy", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LogWindow: public Ui_LogWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGWINDOW_H
