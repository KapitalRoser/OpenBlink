/********************************************************************************
** Form generated from reading UI file 'soundsettingsdialogue.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOUNDSETTINGSDIALOGUE_H
#define UI_SOUNDSETTINGSDIALOGUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_soundSettingsDialogue
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridMain;
    QSpinBox *cueBox;
    QLabel *label_4;
    QPushButton *occursChange;
    QPushButton *completeChange;
    QLabel *label;
    QSlider *successSlide;
    QSlider *cueSlide;
    QPushButton *cueChange;
    QSlider *failureSlide;
    QPushButton *failureMute;
    QSlider *completeSlide;
    QLabel *completeFileLabel;
    QLabel *label_8;
    QSpinBox *occursBox;
    QPushButton *successMute;
    QPushButton *failureChange;
    QSpinBox *successBox;
    QLabel *label_10;
    QSpinBox *failureBox;
    QPushButton *occursMute;
    QPushButton *successChange;
    QSpinBox *completeBox;
    QLabel *successFileLabel;
    QLabel *failureFileLabel;
    QLabel *label_6;
    QLabel *cueFileLabel;
    QSlider *occursSlide;
    QLabel *occursFileLabel;
    QPushButton *cueMute;
    QPushButton *completeMute;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *soundSettingsDialogue)
    {
        if (soundSettingsDialogue->objectName().isEmpty())
            soundSettingsDialogue->setObjectName(QString::fromUtf8("soundSettingsDialogue"));
        soundSettingsDialogue->resize(803, 347);
        verticalLayout = new QVBoxLayout(soundSettingsDialogue);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridMain = new QGridLayout();
        gridMain->setObjectName(QString::fromUtf8("gridMain"));
        cueBox = new QSpinBox(soundSettingsDialogue);
        cueBox->setObjectName(QString::fromUtf8("cueBox"));
        cueBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        cueBox->setMaximum(100);

        gridMain->addWidget(cueBox, 4, 2, 1, 1);

        label_4 = new QLabel(soundSettingsDialogue);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridMain->addWidget(label_4, 1, 0, 1, 1);

        occursChange = new QPushButton(soundSettingsDialogue);
        occursChange->setObjectName(QString::fromUtf8("occursChange"));

        gridMain->addWidget(occursChange, 2, 5, 1, 1);

        completeChange = new QPushButton(soundSettingsDialogue);
        completeChange->setObjectName(QString::fromUtf8("completeChange"));

        gridMain->addWidget(completeChange, 3, 5, 1, 1);

        label = new QLabel(soundSettingsDialogue);
        label->setObjectName(QString::fromUtf8("label"));

        gridMain->addWidget(label, 0, 0, 1, 1);

        successSlide = new QSlider(soundSettingsDialogue);
        successSlide->setObjectName(QString::fromUtf8("successSlide"));
        successSlide->setMaximum(100);
        successSlide->setPageStep(1);
        successSlide->setValue(0);
        successSlide->setSliderPosition(0);
        successSlide->setOrientation(Qt::Horizontal);
        successSlide->setTickPosition(QSlider::NoTicks);

        gridMain->addWidget(successSlide, 0, 1, 1, 1);

        cueSlide = new QSlider(soundSettingsDialogue);
        cueSlide->setObjectName(QString::fromUtf8("cueSlide"));
        cueSlide->setPageStep(1);
        cueSlide->setOrientation(Qt::Horizontal);

        gridMain->addWidget(cueSlide, 4, 1, 1, 1);

        cueChange = new QPushButton(soundSettingsDialogue);
        cueChange->setObjectName(QString::fromUtf8("cueChange"));

        gridMain->addWidget(cueChange, 4, 5, 1, 1);

        failureSlide = new QSlider(soundSettingsDialogue);
        failureSlide->setObjectName(QString::fromUtf8("failureSlide"));
        failureSlide->setPageStep(1);
        failureSlide->setOrientation(Qt::Horizontal);

        gridMain->addWidget(failureSlide, 1, 1, 1, 1);

        failureMute = new QPushButton(soundSettingsDialogue);
        failureMute->setObjectName(QString::fromUtf8("failureMute"));

        gridMain->addWidget(failureMute, 1, 3, 1, 1);

        completeSlide = new QSlider(soundSettingsDialogue);
        completeSlide->setObjectName(QString::fromUtf8("completeSlide"));
        completeSlide->setPageStep(1);
        completeSlide->setOrientation(Qt::Horizontal);

        gridMain->addWidget(completeSlide, 3, 1, 1, 1);

        completeFileLabel = new QLabel(soundSettingsDialogue);
        completeFileLabel->setObjectName(QString::fromUtf8("completeFileLabel"));

        gridMain->addWidget(completeFileLabel, 3, 4, 1, 1);

        label_8 = new QLabel(soundSettingsDialogue);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridMain->addWidget(label_8, 3, 0, 1, 1);

        occursBox = new QSpinBox(soundSettingsDialogue);
        occursBox->setObjectName(QString::fromUtf8("occursBox"));
        occursBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        occursBox->setMaximum(100);

        gridMain->addWidget(occursBox, 2, 2, 1, 1);

        successMute = new QPushButton(soundSettingsDialogue);
        successMute->setObjectName(QString::fromUtf8("successMute"));

        gridMain->addWidget(successMute, 0, 3, 1, 1);

        failureChange = new QPushButton(soundSettingsDialogue);
        failureChange->setObjectName(QString::fromUtf8("failureChange"));

        gridMain->addWidget(failureChange, 1, 5, 1, 1);

        successBox = new QSpinBox(soundSettingsDialogue);
        successBox->setObjectName(QString::fromUtf8("successBox"));
        successBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        successBox->setMaximum(100);

        gridMain->addWidget(successBox, 0, 2, 1, 1);

        label_10 = new QLabel(soundSettingsDialogue);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridMain->addWidget(label_10, 4, 0, 1, 1);

        failureBox = new QSpinBox(soundSettingsDialogue);
        failureBox->setObjectName(QString::fromUtf8("failureBox"));
        failureBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        failureBox->setMaximum(100);

        gridMain->addWidget(failureBox, 1, 2, 1, 1);

        occursMute = new QPushButton(soundSettingsDialogue);
        occursMute->setObjectName(QString::fromUtf8("occursMute"));

        gridMain->addWidget(occursMute, 2, 3, 1, 1);

        successChange = new QPushButton(soundSettingsDialogue);
        successChange->setObjectName(QString::fromUtf8("successChange"));

        gridMain->addWidget(successChange, 0, 5, 1, 1);

        completeBox = new QSpinBox(soundSettingsDialogue);
        completeBox->setObjectName(QString::fromUtf8("completeBox"));
        completeBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        completeBox->setMaximum(100);

        gridMain->addWidget(completeBox, 3, 2, 1, 1);

        successFileLabel = new QLabel(soundSettingsDialogue);
        successFileLabel->setObjectName(QString::fromUtf8("successFileLabel"));

        gridMain->addWidget(successFileLabel, 0, 4, 1, 1);

        failureFileLabel = new QLabel(soundSettingsDialogue);
        failureFileLabel->setObjectName(QString::fromUtf8("failureFileLabel"));

        gridMain->addWidget(failureFileLabel, 1, 4, 1, 1);

        label_6 = new QLabel(soundSettingsDialogue);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridMain->addWidget(label_6, 2, 0, 1, 1);

        cueFileLabel = new QLabel(soundSettingsDialogue);
        cueFileLabel->setObjectName(QString::fromUtf8("cueFileLabel"));

        gridMain->addWidget(cueFileLabel, 4, 4, 1, 1);

        occursSlide = new QSlider(soundSettingsDialogue);
        occursSlide->setObjectName(QString::fromUtf8("occursSlide"));
        occursSlide->setPageStep(1);
        occursSlide->setOrientation(Qt::Horizontal);

        gridMain->addWidget(occursSlide, 2, 1, 1, 1);

        occursFileLabel = new QLabel(soundSettingsDialogue);
        occursFileLabel->setObjectName(QString::fromUtf8("occursFileLabel"));

        gridMain->addWidget(occursFileLabel, 2, 4, 1, 1);

        cueMute = new QPushButton(soundSettingsDialogue);
        cueMute->setObjectName(QString::fromUtf8("cueMute"));

        gridMain->addWidget(cueMute, 4, 3, 1, 1);

        completeMute = new QPushButton(soundSettingsDialogue);
        completeMute->setObjectName(QString::fromUtf8("completeMute"));

        gridMain->addWidget(completeMute, 3, 3, 1, 1);


        verticalLayout->addLayout(gridMain);

        buttonBox = new QDialogButtonBox(soundSettingsDialogue);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok|QDialogButtonBox::RestoreDefaults);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(soundSettingsDialogue);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, soundSettingsDialogue, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, soundSettingsDialogue, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(soundSettingsDialogue);
    } // setupUi

    void retranslateUi(QDialog *soundSettingsDialogue)
    {
        soundSettingsDialogue->setWindowTitle(QCoreApplication::translate("soundSettingsDialogue", "Dialog", nullptr));
        label_4->setText(QCoreApplication::translate("soundSettingsDialogue", "Search Failure", nullptr));
        occursChange->setText(QCoreApplication::translate("soundSettingsDialogue", "change...", nullptr));
        completeChange->setText(QCoreApplication::translate("soundSettingsDialogue", "change...", nullptr));
        label->setText(QCoreApplication::translate("soundSettingsDialogue", "Search Success", nullptr));
        cueChange->setText(QCoreApplication::translate("soundSettingsDialogue", "change...", nullptr));
        failureMute->setText(QCoreApplication::translate("soundSettingsDialogue", "\360\237\224\212\360\237\224\210", nullptr));
        completeFileLabel->setText(QCoreApplication::translate("soundSettingsDialogue", "snag_success.wav", nullptr));
        label_8->setText(QCoreApplication::translate("soundSettingsDialogue", "Calibration Complete", nullptr));
        successMute->setText(QCoreApplication::translate("soundSettingsDialogue", "\360\237\224\212\360\237\224\210", nullptr));
        failureChange->setText(QCoreApplication::translate("soundSettingsDialogue", "change...", nullptr));
        label_10->setText(QCoreApplication::translate("soundSettingsDialogue", "Exit Cue", nullptr));
        occursMute->setText(QCoreApplication::translate("soundSettingsDialogue", "\360\237\224\212\360\237\224\210", nullptr));
        successChange->setText(QCoreApplication::translate("soundSettingsDialogue", "change...", nullptr));
        successFileLabel->setText(QCoreApplication::translate("soundSettingsDialogue", "snag_success.wav", nullptr));
        failureFileLabel->setText(QCoreApplication::translate("soundSettingsDialogue", "snag_success.wav", nullptr));
        label_6->setText(QCoreApplication::translate("soundSettingsDialogue", "Blink Occurs", nullptr));
        cueFileLabel->setText(QCoreApplication::translate("soundSettingsDialogue", "snag_success.wav", nullptr));
        occursFileLabel->setText(QCoreApplication::translate("soundSettingsDialogue", "snag_success.wav", nullptr));
        cueMute->setText(QCoreApplication::translate("soundSettingsDialogue", "\360\237\224\212\360\237\224\210", nullptr));
        completeMute->setText(QCoreApplication::translate("soundSettingsDialogue", "\360\237\224\212\360\237\224\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class soundSettingsDialogue: public Ui_soundSettingsDialogue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOUNDSETTINGSDIALOGUE_H
