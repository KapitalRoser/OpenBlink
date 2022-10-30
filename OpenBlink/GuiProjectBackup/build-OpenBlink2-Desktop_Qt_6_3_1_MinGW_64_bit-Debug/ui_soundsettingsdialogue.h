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

QT_BEGIN_NAMESPACE

class Ui_soundSettingsDialogue
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QSlider *successSlide;
    QSpinBox *successBox;
    QPushButton *successMute;
    QLabel *successFileLabel;
    QPushButton *successChange;
    QLabel *label_4;
    QSlider *failureSlide;
    QSpinBox *failureBox;
    QPushButton *failureMute;
    QLabel *failureFileLabel;
    QPushButton *failureChange;
    QLabel *label_6;
    QSlider *occursSlide;
    QSpinBox *occursBox;
    QPushButton *occursMute;
    QLabel *occursFileLabel;
    QPushButton *occursChange;
    QLabel *label_8;
    QSlider *completeSlide;
    QSpinBox *completeBox;
    QPushButton *completeMute;
    QLabel *completeFileLabel;
    QPushButton *completeChange;
    QLabel *label_10;
    QSlider *cueSlide;
    QSpinBox *cueBox;
    QPushButton *cueMute;
    QLabel *cueFileLabel;
    QPushButton *cueChange;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *soundSettingsDialogue)
    {
        if (soundSettingsDialogue->objectName().isEmpty())
            soundSettingsDialogue->setObjectName(QString::fromUtf8("soundSettingsDialogue"));
        soundSettingsDialogue->resize(736, 258);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(soundSettingsDialogue->sizePolicy().hasHeightForWidth());
        soundSettingsDialogue->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamilies({QString::fromUtf8("Century Gothic")});
        soundSettingsDialogue->setFont(font);
        gridLayout = new QGridLayout(soundSettingsDialogue);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setVerticalSpacing(3);
        label = new QLabel(soundSettingsDialogue);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        successSlide = new QSlider(soundSettingsDialogue);
        successSlide->setObjectName(QString::fromUtf8("successSlide"));
        successSlide->setMaximum(100);
        successSlide->setPageStep(1);
        successSlide->setValue(0);
        successSlide->setSliderPosition(0);
        successSlide->setOrientation(Qt::Horizontal);
        successSlide->setTickPosition(QSlider::NoTicks);

        gridLayout->addWidget(successSlide, 0, 1, 1, 1);

        successBox = new QSpinBox(soundSettingsDialogue);
        successBox->setObjectName(QString::fromUtf8("successBox"));
        successBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        successBox->setMaximum(100);

        gridLayout->addWidget(successBox, 0, 2, 1, 1);

        successMute = new QPushButton(soundSettingsDialogue);
        successMute->setObjectName(QString::fromUtf8("successMute"));

        gridLayout->addWidget(successMute, 0, 3, 1, 1);

        successFileLabel = new QLabel(soundSettingsDialogue);
        successFileLabel->setObjectName(QString::fromUtf8("successFileLabel"));

        gridLayout->addWidget(successFileLabel, 0, 4, 1, 1);

        successChange = new QPushButton(soundSettingsDialogue);
        successChange->setObjectName(QString::fromUtf8("successChange"));

        gridLayout->addWidget(successChange, 0, 5, 1, 1);

        label_4 = new QLabel(soundSettingsDialogue);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        failureSlide = new QSlider(soundSettingsDialogue);
        failureSlide->setObjectName(QString::fromUtf8("failureSlide"));
        failureSlide->setPageStep(1);
        failureSlide->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(failureSlide, 1, 1, 1, 1);

        failureBox = new QSpinBox(soundSettingsDialogue);
        failureBox->setObjectName(QString::fromUtf8("failureBox"));
        failureBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        failureBox->setMaximum(100);

        gridLayout->addWidget(failureBox, 1, 2, 1, 1);

        failureMute = new QPushButton(soundSettingsDialogue);
        failureMute->setObjectName(QString::fromUtf8("failureMute"));

        gridLayout->addWidget(failureMute, 1, 3, 1, 1);

        failureFileLabel = new QLabel(soundSettingsDialogue);
        failureFileLabel->setObjectName(QString::fromUtf8("failureFileLabel"));

        gridLayout->addWidget(failureFileLabel, 1, 4, 1, 1);

        failureChange = new QPushButton(soundSettingsDialogue);
        failureChange->setObjectName(QString::fromUtf8("failureChange"));

        gridLayout->addWidget(failureChange, 1, 5, 1, 1);

        label_6 = new QLabel(soundSettingsDialogue);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 2, 0, 1, 1);

        occursSlide = new QSlider(soundSettingsDialogue);
        occursSlide->setObjectName(QString::fromUtf8("occursSlide"));
        occursSlide->setPageStep(1);
        occursSlide->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(occursSlide, 2, 1, 1, 1);

        occursBox = new QSpinBox(soundSettingsDialogue);
        occursBox->setObjectName(QString::fromUtf8("occursBox"));
        occursBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        occursBox->setMaximum(100);

        gridLayout->addWidget(occursBox, 2, 2, 1, 1);

        occursMute = new QPushButton(soundSettingsDialogue);
        occursMute->setObjectName(QString::fromUtf8("occursMute"));

        gridLayout->addWidget(occursMute, 2, 3, 1, 1);

        occursFileLabel = new QLabel(soundSettingsDialogue);
        occursFileLabel->setObjectName(QString::fromUtf8("occursFileLabel"));

        gridLayout->addWidget(occursFileLabel, 2, 4, 1, 1);

        occursChange = new QPushButton(soundSettingsDialogue);
        occursChange->setObjectName(QString::fromUtf8("occursChange"));

        gridLayout->addWidget(occursChange, 2, 5, 1, 1);

        label_8 = new QLabel(soundSettingsDialogue);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 3, 0, 1, 1);

        completeSlide = new QSlider(soundSettingsDialogue);
        completeSlide->setObjectName(QString::fromUtf8("completeSlide"));
        completeSlide->setPageStep(1);
        completeSlide->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(completeSlide, 3, 1, 1, 1);

        completeBox = new QSpinBox(soundSettingsDialogue);
        completeBox->setObjectName(QString::fromUtf8("completeBox"));
        completeBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        completeBox->setMaximum(100);

        gridLayout->addWidget(completeBox, 3, 2, 1, 1);

        completeMute = new QPushButton(soundSettingsDialogue);
        completeMute->setObjectName(QString::fromUtf8("completeMute"));

        gridLayout->addWidget(completeMute, 3, 3, 1, 1);

        completeFileLabel = new QLabel(soundSettingsDialogue);
        completeFileLabel->setObjectName(QString::fromUtf8("completeFileLabel"));

        gridLayout->addWidget(completeFileLabel, 3, 4, 1, 1);

        completeChange = new QPushButton(soundSettingsDialogue);
        completeChange->setObjectName(QString::fromUtf8("completeChange"));

        gridLayout->addWidget(completeChange, 3, 5, 1, 1);

        label_10 = new QLabel(soundSettingsDialogue);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 4, 0, 1, 1);

        cueSlide = new QSlider(soundSettingsDialogue);
        cueSlide->setObjectName(QString::fromUtf8("cueSlide"));
        cueSlide->setPageStep(1);
        cueSlide->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(cueSlide, 4, 1, 1, 1);

        cueBox = new QSpinBox(soundSettingsDialogue);
        cueBox->setObjectName(QString::fromUtf8("cueBox"));
        cueBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        cueBox->setMaximum(100);

        gridLayout->addWidget(cueBox, 4, 2, 1, 1);

        cueMute = new QPushButton(soundSettingsDialogue);
        cueMute->setObjectName(QString::fromUtf8("cueMute"));

        gridLayout->addWidget(cueMute, 4, 3, 1, 1);

        cueFileLabel = new QLabel(soundSettingsDialogue);
        cueFileLabel->setObjectName(QString::fromUtf8("cueFileLabel"));

        gridLayout->addWidget(cueFileLabel, 4, 4, 1, 1);

        cueChange = new QPushButton(soundSettingsDialogue);
        cueChange->setObjectName(QString::fromUtf8("cueChange"));

        gridLayout->addWidget(cueChange, 4, 5, 1, 1);

        buttonBox = new QDialogButtonBox(soundSettingsDialogue);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy1);
        buttonBox->setStyleSheet(QString::fromUtf8("QPushButton{background-color: #004080;\n"
"font: 9pt \"Century Gothic\";\n"
"color: white;\n"
"font-weight: bold;\n"
"border-radius:15px;\n"
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

        gridLayout->addWidget(buttonBox, 5, 0, 1, 6);

        QWidget::setTabOrder(successSlide, successBox);
        QWidget::setTabOrder(successBox, successMute);
        QWidget::setTabOrder(successMute, successChange);
        QWidget::setTabOrder(successChange, failureSlide);
        QWidget::setTabOrder(failureSlide, failureBox);
        QWidget::setTabOrder(failureBox, failureMute);
        QWidget::setTabOrder(failureMute, failureChange);
        QWidget::setTabOrder(failureChange, occursSlide);
        QWidget::setTabOrder(occursSlide, occursBox);
        QWidget::setTabOrder(occursBox, occursMute);
        QWidget::setTabOrder(occursMute, occursChange);
        QWidget::setTabOrder(occursChange, completeSlide);
        QWidget::setTabOrder(completeSlide, completeBox);
        QWidget::setTabOrder(completeBox, completeMute);
        QWidget::setTabOrder(completeMute, completeChange);
        QWidget::setTabOrder(completeChange, cueSlide);
        QWidget::setTabOrder(cueSlide, cueBox);
        QWidget::setTabOrder(cueBox, cueMute);
        QWidget::setTabOrder(cueMute, cueChange);

        retranslateUi(soundSettingsDialogue);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, soundSettingsDialogue, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, soundSettingsDialogue, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(soundSettingsDialogue);
    } // setupUi

    void retranslateUi(QDialog *soundSettingsDialogue)
    {
        soundSettingsDialogue->setWindowTitle(QCoreApplication::translate("soundSettingsDialogue", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("soundSettingsDialogue", "Search Success", nullptr));
        successMute->setText(QCoreApplication::translate("soundSettingsDialogue", "\360\237\224\212\360\237\224\210", nullptr));
        successFileLabel->setText(QCoreApplication::translate("soundSettingsDialogue", "snag_success.wav", nullptr));
        successChange->setText(QCoreApplication::translate("soundSettingsDialogue", "change...", nullptr));
        label_4->setText(QCoreApplication::translate("soundSettingsDialogue", "Search Failure", nullptr));
        failureMute->setText(QCoreApplication::translate("soundSettingsDialogue", "\360\237\224\212\360\237\224\210", nullptr));
        failureFileLabel->setText(QCoreApplication::translate("soundSettingsDialogue", "snag_success.wav", nullptr));
        failureChange->setText(QCoreApplication::translate("soundSettingsDialogue", "change...", nullptr));
        label_6->setText(QCoreApplication::translate("soundSettingsDialogue", "Blink Occurs", nullptr));
        occursMute->setText(QCoreApplication::translate("soundSettingsDialogue", "\360\237\224\212\360\237\224\210", nullptr));
        occursFileLabel->setText(QCoreApplication::translate("soundSettingsDialogue", "snag_success.wav", nullptr));
        occursChange->setText(QCoreApplication::translate("soundSettingsDialogue", "change...", nullptr));
        label_8->setText(QCoreApplication::translate("soundSettingsDialogue", "Calibration Complete", nullptr));
        completeMute->setText(QCoreApplication::translate("soundSettingsDialogue", "\360\237\224\212\360\237\224\210", nullptr));
        completeFileLabel->setText(QCoreApplication::translate("soundSettingsDialogue", "snag_success.wav", nullptr));
        completeChange->setText(QCoreApplication::translate("soundSettingsDialogue", "change...", nullptr));
        label_10->setText(QCoreApplication::translate("soundSettingsDialogue", "Exit Cue", nullptr));
        cueMute->setText(QCoreApplication::translate("soundSettingsDialogue", "\360\237\224\212\360\237\224\210", nullptr));
        cueFileLabel->setText(QCoreApplication::translate("soundSettingsDialogue", "snag_success.wav", nullptr));
        cueChange->setText(QCoreApplication::translate("soundSettingsDialogue", "change...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class soundSettingsDialogue: public Ui_soundSettingsDialogue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOUNDSETTINGSDIALOGUE_H
