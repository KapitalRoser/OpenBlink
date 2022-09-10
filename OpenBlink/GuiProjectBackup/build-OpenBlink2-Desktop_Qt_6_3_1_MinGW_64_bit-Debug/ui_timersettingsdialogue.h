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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_timerSettingsDialogue
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_8;
    QLabel *label_7;
    QLabel *label_6;
    QSpinBox *exitIntervalBox;
    QSpinBox *exitOffsetBox;
    QSpinBox *exitBeepsBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *timerSettingsDialogue)
    {
        if (timerSettingsDialogue->objectName().isEmpty())
            timerSettingsDialogue->setObjectName(QString::fromUtf8("timerSettingsDialogue"));
        timerSettingsDialogue->resize(313, 226);
        layoutWidget = new QWidget(timerSettingsDialogue);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 30, 271, 161));
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 2, 0, 1, 1);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 1, 0, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 0, 0, 1, 1);

        exitIntervalBox = new QSpinBox(layoutWidget);
        exitIntervalBox->setObjectName(QString::fromUtf8("exitIntervalBox"));
        exitIntervalBox->setMaximum(100000);
        exitIntervalBox->setValue(500);

        gridLayout->addWidget(exitIntervalBox, 1, 1, 1, 1);

        exitOffsetBox = new QSpinBox(layoutWidget);
        exitOffsetBox->setObjectName(QString::fromUtf8("exitOffsetBox"));
        exitOffsetBox->setMaximum(10000000);
        exitOffsetBox->setValue(5000);

        gridLayout->addWidget(exitOffsetBox, 0, 1, 1, 1);

        exitBeepsBox = new QSpinBox(layoutWidget);
        exitBeepsBox->setObjectName(QString::fromUtf8("exitBeepsBox"));
        exitBeepsBox->setMaximum(10000);
        exitBeepsBox->setValue(5);

        gridLayout->addWidget(exitBeepsBox, 2, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 2);

        buttonBox = new QDialogButtonBox(layoutWidget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setEnabled(true);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok|QDialogButtonBox::RestoreDefaults);
        buttonBox->setCenterButtons(false);

        gridLayout_2->addWidget(buttonBox, 1, 1, 2, 1);


        retranslateUi(timerSettingsDialogue);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, timerSettingsDialogue, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, timerSettingsDialogue, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(timerSettingsDialogue);
    } // setupUi

    void retranslateUi(QDialog *timerSettingsDialogue)
    {
        timerSettingsDialogue->setWindowTitle(QCoreApplication::translate("timerSettingsDialogue", "Dialog", nullptr));
        label_8->setText(QCoreApplication::translate("timerSettingsDialogue", "Total # of beeps:", nullptr));
        label_7->setText(QCoreApplication::translate("timerSettingsDialogue", "Beeps occur in intervals of: (ms)", nullptr));
        label_6->setText(QCoreApplication::translate("timerSettingsDialogue", "Countdown begins at: (ms) ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class timerSettingsDialogue: public Ui_timerSettingsDialogue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMERSETTINGSDIALOGUE_H
