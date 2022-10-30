/********************************************************************************
** Form generated from reading UI file 'timersettingsdialogue.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMERSETTINGSDIALOGUE_H
#define UI_TIMERSETTINGSDIALOGUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_timerSettingsDialogue
{
public:
    QGridLayout *gridLayout;
    QSpinBox *exitIntervalBox;
    QSpinBox *exitInputBox;
    QDialogButtonBox *buttonBox;
    QLabel *label_7;
    QLabel *label_6;
    QLabel *label;
    QLabel *label_8;
    QSpinBox *exitOffsetBox;
    QSpinBox *exitBeepsBox;

    void setupUi(QDialog *timerSettingsDialogue)
    {
        if (timerSettingsDialogue->objectName().isEmpty())
            timerSettingsDialogue->setObjectName(QString::fromUtf8("timerSettingsDialogue"));
        timerSettingsDialogue->resize(428, 208);
        QFont font;
        font.setFamilies({QString::fromUtf8("Century Gothic")});
        timerSettingsDialogue->setFont(font);
        gridLayout = new QGridLayout(timerSettingsDialogue);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setVerticalSpacing(3);
        exitIntervalBox = new QSpinBox(timerSettingsDialogue);
        exitIntervalBox->setObjectName(QString::fromUtf8("exitIntervalBox"));
        exitIntervalBox->setMaximum(100000);
        exitIntervalBox->setValue(500);

        gridLayout->addWidget(exitIntervalBox, 1, 1, 1, 1);

        exitInputBox = new QSpinBox(timerSettingsDialogue);
        exitInputBox->setObjectName(QString::fromUtf8("exitInputBox"));
        exitInputBox->setMinimum(-10000);
        exitInputBox->setMaximum(10000);
        exitInputBox->setValue(0);

        gridLayout->addWidget(exitInputBox, 3, 1, 1, 1);

        buttonBox = new QDialogButtonBox(timerSettingsDialogue);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy);
        buttonBox->setStyleSheet(QString::fromUtf8("QPushButton{background-color: #004080;\n"
"font: 9pt \"Century Gothic\";\n"
"color: white;\n"
"font-weight: bold;\n"
"border-radius:12px;\n"
"padding:10px;\n"
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
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok|QDialogButtonBox::RestoreDefaults);
        buttonBox->setCenterButtons(false);

        gridLayout->addWidget(buttonBox, 4, 0, 1, 2);

        label_7 = new QLabel(timerSettingsDialogue);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 1, 0, 1, 1);

        label_6 = new QLabel(timerSettingsDialogue);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 0, 0, 1, 1);

        label = new QLabel(timerSettingsDialogue);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 3, 0, 1, 1);

        label_8 = new QLabel(timerSettingsDialogue);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 2, 0, 1, 1);

        exitOffsetBox = new QSpinBox(timerSettingsDialogue);
        exitOffsetBox->setObjectName(QString::fromUtf8("exitOffsetBox"));
        exitOffsetBox->setMaximum(10000000);
        exitOffsetBox->setValue(5000);

        gridLayout->addWidget(exitOffsetBox, 0, 1, 1, 1);

        exitBeepsBox = new QSpinBox(timerSettingsDialogue);
        exitBeepsBox->setObjectName(QString::fromUtf8("exitBeepsBox"));
        exitBeepsBox->setMaximum(10000);
        exitBeepsBox->setValue(5);

        gridLayout->addWidget(exitBeepsBox, 2, 1, 1, 1);


        retranslateUi(timerSettingsDialogue);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, timerSettingsDialogue, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, timerSettingsDialogue, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(timerSettingsDialogue);
    } // setupUi

    void retranslateUi(QDialog *timerSettingsDialogue)
    {
        timerSettingsDialogue->setWindowTitle(QCoreApplication::translate("timerSettingsDialogue", "Dialog", nullptr));
        label_7->setText(QCoreApplication::translate("timerSettingsDialogue", "Beeps occur in intervals of: (ms)", nullptr));
        label_6->setText(QCoreApplication::translate("timerSettingsDialogue", "Countdown begins at: (ms) ", nullptr));
        label->setText(QCoreApplication::translate("timerSettingsDialogue", "Exit Input Offset: (frames)", nullptr));
        label_8->setText(QCoreApplication::translate("timerSettingsDialogue", "Total # of beeps:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class timerSettingsDialogue: public Ui_timerSettingsDialogue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMERSETTINGSDIALOGUE_H
