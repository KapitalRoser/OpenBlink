/********************************************************************************
** Form generated from reading UI file 'hotkeysdialogue.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
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
    QWidget *layoutWidget;
    QGridLayout *inputGrid;
    QPushButton *fasterx5KeyButton;
    QLabel *label_11;
    QLabel *label_14;
    QPushButton *slowerx5KeyButton;
    QLabel *label_10;
    QPushButton *fasterKeyButton;
    QLabel *label_13;
    QPushButton *defaultResetButton;
    QPushButton *slowerKeyButton;
    QLabel *label_12;
    QPushButton *blinkKeyButton;
    QPushButton *startStopKeyButton;
    QLabel *label_15;

    void setupUi(QDialog *HotkeysDialogue)
    {
        if (HotkeysDialogue->objectName().isEmpty())
            HotkeysDialogue->setObjectName("HotkeysDialogue");
        HotkeysDialogue->resize(332, 448);
        QFont font;
        font.setFamilies({QString::fromUtf8("Century Gothic")});
        HotkeysDialogue->setFont(font);
        label_9 = new QLabel(HotkeysDialogue);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(13, 13, 134, 24));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);
        buttonBox = new QDialogButtonBox(HotkeysDialogue);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(150, 390, 169, 35));
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
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        layoutWidget = new QWidget(HotkeysDialogue);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(40, 50, 261, 325));
        inputGrid = new QGridLayout(layoutWidget);
        inputGrid->setObjectName("inputGrid");
        inputGrid->setContentsMargins(0, 0, 0, 0);
        fasterx5KeyButton = new QPushButton(layoutWidget);
        fasterx5KeyButton->setObjectName("fasterx5KeyButton");
        fasterx5KeyButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color: #004080;\n"
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
        fasterx5KeyButton->setCheckable(true);

        inputGrid->addWidget(fasterx5KeyButton, 4, 1, 1, 1);

        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName("label_11");

        inputGrid->addWidget(label_11, 1, 0, 1, 1);

        label_14 = new QLabel(layoutWidget);
        label_14->setObjectName("label_14");

        inputGrid->addWidget(label_14, 4, 0, 1, 1);

        slowerx5KeyButton = new QPushButton(layoutWidget);
        slowerx5KeyButton->setObjectName("slowerx5KeyButton");
        slowerx5KeyButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color: #004080;\n"
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
        slowerx5KeyButton->setCheckable(true);

        inputGrid->addWidget(slowerx5KeyButton, 2, 1, 1, 1);

        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName("label_10");

        inputGrid->addWidget(label_10, 0, 0, 1, 1);

        fasterKeyButton = new QPushButton(layoutWidget);
        fasterKeyButton->setObjectName("fasterKeyButton");
        fasterKeyButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color: #004080;\n"
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
        fasterKeyButton->setCheckable(true);

        inputGrid->addWidget(fasterKeyButton, 3, 1, 1, 1);

        label_13 = new QLabel(layoutWidget);
        label_13->setObjectName("label_13");

        inputGrid->addWidget(label_13, 5, 0, 1, 1);

        defaultResetButton = new QPushButton(layoutWidget);
        defaultResetButton->setObjectName("defaultResetButton");
        defaultResetButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color: #004080;\n"
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

        inputGrid->addWidget(defaultResetButton, 6, 0, 1, 2);

        slowerKeyButton = new QPushButton(layoutWidget);
        slowerKeyButton->setObjectName("slowerKeyButton");
        slowerKeyButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color: #004080;\n"
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
        slowerKeyButton->setCheckable(true);

        inputGrid->addWidget(slowerKeyButton, 1, 1, 1, 1);

        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName("label_12");

        inputGrid->addWidget(label_12, 3, 0, 1, 1);

        blinkKeyButton = new QPushButton(layoutWidget);
        blinkKeyButton->setObjectName("blinkKeyButton");
        blinkKeyButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color: #004080;\n"
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
        blinkKeyButton->setCheckable(true);

        inputGrid->addWidget(blinkKeyButton, 0, 1, 1, 1);

        startStopKeyButton = new QPushButton(layoutWidget);
        startStopKeyButton->setObjectName("startStopKeyButton");
        startStopKeyButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color: #004080;\n"
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
        startStopKeyButton->setCheckable(true);

        inputGrid->addWidget(startStopKeyButton, 5, 1, 1, 1);

        label_15 = new QLabel(layoutWidget);
        label_15->setObjectName("label_15");

        inputGrid->addWidget(label_15, 2, 0, 1, 1);


        retranslateUi(HotkeysDialogue);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, HotkeysDialogue, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, HotkeysDialogue, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(HotkeysDialogue);
    } // setupUi

    void retranslateUi(QDialog *HotkeysDialogue)
    {
        HotkeysDialogue->setWindowTitle(QCoreApplication::translate("HotkeysDialogue", "Dialog", nullptr));
        label_9->setText(QCoreApplication::translate("HotkeysDialogue", "Change Hotkeys:", nullptr));
        fasterx5KeyButton->setText(QString());
        label_11->setText(QCoreApplication::translate("HotkeysDialogue", "Slower (\342\206\220 )", nullptr));
        label_14->setText(QCoreApplication::translate("HotkeysDialogue", "Faster x 5", nullptr));
        slowerx5KeyButton->setText(QString());
        label_10->setText(QCoreApplication::translate("HotkeysDialogue", "Enter blink", nullptr));
        fasterKeyButton->setText(QString());
        label_13->setText(QCoreApplication::translate("HotkeysDialogue", "Start/Stop", nullptr));
        defaultResetButton->setText(QCoreApplication::translate("HotkeysDialogue", "Reset to Defaults", nullptr));
        slowerKeyButton->setText(QString());
        label_12->setText(QCoreApplication::translate("HotkeysDialogue", "Faster (\342\206\222 )", nullptr));
        blinkKeyButton->setText(QString());
        startStopKeyButton->setText(QString());
        label_15->setText(QCoreApplication::translate("HotkeysDialogue", "Slower x 5", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HotkeysDialogue: public Ui_HotkeysDialogue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOTKEYSDIALOGUE_H
