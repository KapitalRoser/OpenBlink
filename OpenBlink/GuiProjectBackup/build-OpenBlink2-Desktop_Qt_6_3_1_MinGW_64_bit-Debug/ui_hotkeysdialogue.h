/********************************************************************************
** Form generated from reading UI file 'hotkeysdialogue.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOTKEYSDIALOGUE_H
#define UI_HOTKEYSDIALOGUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HotkeysDialogue
{
public:
    QLabel *label_9;
    QDialogButtonBox *buttonBox;
    QWidget *widget;
    QGridLayout *inputGrid;
    QLabel *label_13;
    QPushButton *slowerKeyButton;
    QLabel *label_10;
    QLabel *label_12;
    QPushButton *blinkKeyButton;
    QPushButton *startStopKeyButton;
    QPushButton *defaultResetButton;
    QPushButton *fasterKeyButton;
    QLabel *label_11;

    void setupUi(QDialog *HotkeysDialogue)
    {
        if (HotkeysDialogue->objectName().isEmpty())
            HotkeysDialogue->setObjectName(QString::fromUtf8("HotkeysDialogue"));
        HotkeysDialogue->resize(332, 376);
        QFont font;
        font.setFamilies({QString::fromUtf8("Century Gothic")});
        HotkeysDialogue->setFont(font);
        label_9 = new QLabel(HotkeysDialogue);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(13, 13, 134, 24));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);
        buttonBox = new QDialogButtonBox(HotkeysDialogue);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(150, 320, 169, 35));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        widget = new QWidget(HotkeysDialogue);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(40, 70, 261, 213));
        inputGrid = new QGridLayout(widget);
        inputGrid->setObjectName(QString::fromUtf8("inputGrid"));
        inputGrid->setContentsMargins(0, 0, 0, 0);
        label_13 = new QLabel(widget);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        inputGrid->addWidget(label_13, 3, 0, 1, 1);

        slowerKeyButton = new QPushButton(widget);
        slowerKeyButton->setObjectName(QString::fromUtf8("slowerKeyButton"));
        slowerKeyButton->setCheckable(true);

        inputGrid->addWidget(slowerKeyButton, 1, 1, 1, 1);

        label_10 = new QLabel(widget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        inputGrid->addWidget(label_10, 0, 0, 1, 1);

        label_12 = new QLabel(widget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        inputGrid->addWidget(label_12, 2, 0, 1, 1);

        blinkKeyButton = new QPushButton(widget);
        blinkKeyButton->setObjectName(QString::fromUtf8("blinkKeyButton"));
        blinkKeyButton->setCheckable(true);

        inputGrid->addWidget(blinkKeyButton, 0, 1, 1, 1);

        startStopKeyButton = new QPushButton(widget);
        startStopKeyButton->setObjectName(QString::fromUtf8("startStopKeyButton"));
        startStopKeyButton->setCheckable(true);

        inputGrid->addWidget(startStopKeyButton, 3, 1, 1, 1);

        defaultResetButton = new QPushButton(widget);
        defaultResetButton->setObjectName(QString::fromUtf8("defaultResetButton"));

        inputGrid->addWidget(defaultResetButton, 4, 0, 1, 2);

        fasterKeyButton = new QPushButton(widget);
        fasterKeyButton->setObjectName(QString::fromUtf8("fasterKeyButton"));
        fasterKeyButton->setCheckable(true);

        inputGrid->addWidget(fasterKeyButton, 2, 1, 1, 1);

        label_11 = new QLabel(widget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        inputGrid->addWidget(label_11, 1, 0, 1, 1);


        retranslateUi(HotkeysDialogue);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, HotkeysDialogue, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, HotkeysDialogue, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(HotkeysDialogue);
    } // setupUi

    void retranslateUi(QDialog *HotkeysDialogue)
    {
        HotkeysDialogue->setWindowTitle(QCoreApplication::translate("HotkeysDialogue", "Dialog", nullptr));
        label_9->setText(QCoreApplication::translate("HotkeysDialogue", "Change Hotkeys:", nullptr));
        label_13->setText(QCoreApplication::translate("HotkeysDialogue", "Start/Stop", nullptr));
        slowerKeyButton->setText(QCoreApplication::translate("HotkeysDialogue", "Left Arrow", nullptr));
        label_10->setText(QCoreApplication::translate("HotkeysDialogue", "Enter blink", nullptr));
        label_12->setText(QCoreApplication::translate("HotkeysDialogue", "Faster (\342\206\222 )", nullptr));
        blinkKeyButton->setText(QCoreApplication::translate("HotkeysDialogue", "Shift", nullptr));
        startStopKeyButton->setText(QCoreApplication::translate("HotkeysDialogue", "Enter", nullptr));
        defaultResetButton->setText(QCoreApplication::translate("HotkeysDialogue", "Reset to Defaults", nullptr));
        fasterKeyButton->setText(QCoreApplication::translate("HotkeysDialogue", "Right Arrow", nullptr));
        label_11->setText(QCoreApplication::translate("HotkeysDialogue", "Slower (\342\206\220 )", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HotkeysDialogue: public Ui_HotkeysDialogue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOTKEYSDIALOGUE_H
