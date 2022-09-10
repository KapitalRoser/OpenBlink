/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionHotkeys;
    QAction *actionSounds;
    QAction *actionTimer;
    QWidget *centralwidget;
    QPushButton *pushButton;
    QLabel *statusLabel;
    QLabel *TotalTimeLabel;
    QLabel *localTimeLabel;
    QGroupBox *groupBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *seeInputButton;
    QTableWidget *outTable;
    QPushButton *increaseBlinksButton;
    QHBoxLayout *horizontalLayout;
    QPushButton *slowerButton;
    QPushButton *fasterButton;
    QLabel *nudgeOffsetLabel;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QLineEdit *seedEntry;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_3;
    QSpinBox *flexValueBox;
    QLabel *flexValueHalfLabel;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QSpinBox *searchMinBox;
    QLabel *label_4;
    QSpinBox *searchMaxBox;
    QComboBox *palHzBox_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QSpinBox *arbTargetBox;
    QWidget *layoutWidget1;
    QHBoxLayout *gameHorizLayout;
    QRadioButton *coloRadio;
    QHBoxLayout *horizontalLayout_8;
    QRadioButton *galesRadio;
    QCheckBox *emu5CheckBox;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *ntscuRadio;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *palRadio;
    QComboBox *palHzBox;
    QRadioButton *ntscjRadio;
    QMenuBar *menubar;
    QMenu *menuSettings;
    QMenu *menuHelp;
    QMenu *menuExit;
    QMenu *menuGithub;
    QMenu *menuLog;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(838, 709);
        actionHotkeys = new QAction(MainWindow);
        actionHotkeys->setObjectName(QString::fromUtf8("actionHotkeys"));
        actionSounds = new QAction(MainWindow);
        actionSounds->setObjectName(QString::fromUtf8("actionSounds"));
        actionTimer = new QAction(MainWindow);
        actionTimer->setObjectName(QString::fromUtf8("actionTimer"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(350, 510, 141, 51));
        statusLabel = new QLabel(centralwidget);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));
        statusLabel->setGeometry(QRect(110, 490, 181, 61));
        statusLabel->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);
        TotalTimeLabel = new QLabel(centralwidget);
        TotalTimeLabel->setObjectName(QString::fromUtf8("TotalTimeLabel"));
        TotalTimeLabel->setGeometry(QRect(110, 540, 181, 21));
        localTimeLabel = new QLabel(centralwidget);
        localTimeLabel->setObjectName(QString::fromUtf8("localTimeLabel"));
        localTimeLabel->setGeometry(QRect(110, 580, 181, 21));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(540, 60, 271, 581));
        verticalLayoutWidget = new QWidget(groupBox);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 20, 271, 561));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        seeInputButton = new QPushButton(verticalLayoutWidget);
        seeInputButton->setObjectName(QString::fromUtf8("seeInputButton"));
        seeInputButton->setEnabled(false);

        verticalLayout->addWidget(seeInputButton);

        outTable = new QTableWidget(verticalLayoutWidget);
        outTable->setObjectName(QString::fromUtf8("outTable"));

        verticalLayout->addWidget(outTable);

        increaseBlinksButton = new QPushButton(verticalLayoutWidget);
        increaseBlinksButton->setObjectName(QString::fromUtf8("increaseBlinksButton"));

        verticalLayout->addWidget(increaseBlinksButton);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        slowerButton = new QPushButton(verticalLayoutWidget);
        slowerButton->setObjectName(QString::fromUtf8("slowerButton"));
        slowerButton->setEnabled(false);

        horizontalLayout->addWidget(slowerButton);

        fasterButton = new QPushButton(verticalLayoutWidget);
        fasterButton->setObjectName(QString::fromUtf8("fasterButton"));
        fasterButton->setEnabled(false);

        horizontalLayout->addWidget(fasterButton);


        verticalLayout->addLayout(horizontalLayout);

        nudgeOffsetLabel = new QLabel(verticalLayoutWidget);
        nudgeOffsetLabel->setObjectName(QString::fromUtf8("nudgeOffsetLabel"));
        nudgeOffsetLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(nudgeOffsetLabel);

        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(100, 190, 416, 281));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_5->addWidget(label);

        seedEntry = new QLineEdit(layoutWidget);
        seedEntry->setObjectName(QString::fromUtf8("seedEntry"));

        horizontalLayout_5->addWidget(seedEntry);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_6->addWidget(label_3);

        flexValueBox = new QSpinBox(layoutWidget);
        flexValueBox->setObjectName(QString::fromUtf8("flexValueBox"));
        flexValueBox->setMinimum(-1000);
        flexValueBox->setMaximum(1000);
        flexValueBox->setValue(10);

        horizontalLayout_6->addWidget(flexValueBox);

        flexValueHalfLabel = new QLabel(layoutWidget);
        flexValueHalfLabel->setObjectName(QString::fromUtf8("flexValueHalfLabel"));

        horizontalLayout_6->addWidget(flexValueHalfLabel);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_7->addWidget(label_5);

        searchMinBox = new QSpinBox(layoutWidget);
        searchMinBox->setObjectName(QString::fromUtf8("searchMinBox"));
        searchMinBox->setMinimumSize(QSize(60, 0));
        searchMinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        searchMinBox->setMaximum(10000000);

        horizontalLayout_7->addWidget(searchMinBox);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_7->addWidget(label_4);

        searchMaxBox = new QSpinBox(layoutWidget);
        searchMaxBox->setObjectName(QString::fromUtf8("searchMaxBox"));
        searchMaxBox->setMinimumSize(QSize(60, 0));
        searchMaxBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        searchMaxBox->setMinimum(1);
        searchMaxBox->setMaximum(10000001);
        searchMaxBox->setSingleStep(1);
        searchMaxBox->setValue(10000);

        horizontalLayout_7->addWidget(searchMaxBox);

        palHzBox_2 = new QComboBox(layoutWidget);
        palHzBox_2->addItem(QString());
        palHzBox_2->addItem(QString());
        palHzBox_2->addItem(QString());
        palHzBox_2->setObjectName(QString::fromUtf8("palHzBox_2"));
        palHzBox_2->setEnabled(false);

        horizontalLayout_7->addWidget(palHzBox_2);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);

        arbTargetBox = new QSpinBox(layoutWidget);
        arbTargetBox->setObjectName(QString::fromUtf8("arbTargetBox"));
        arbTargetBox->setMinimum(1);
        arbTargetBox->setMaximum(1000);
        arbTargetBox->setValue(10);

        horizontalLayout_4->addWidget(arbTargetBox);


        verticalLayout_2->addLayout(horizontalLayout_4);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(100, 80, 357, 42));
        gameHorizLayout = new QHBoxLayout(layoutWidget1);
        gameHorizLayout->setObjectName(QString::fromUtf8("gameHorizLayout"));
        gameHorizLayout->setContentsMargins(0, 0, 0, 0);
        coloRadio = new QRadioButton(layoutWidget1);
        coloRadio->setObjectName(QString::fromUtf8("coloRadio"));
        coloRadio->setChecked(true);

        gameHorizLayout->addWidget(coloRadio);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        galesRadio = new QRadioButton(layoutWidget1);
        galesRadio->setObjectName(QString::fromUtf8("galesRadio"));

        horizontalLayout_8->addWidget(galesRadio);

        emu5CheckBox = new QCheckBox(layoutWidget1);
        emu5CheckBox->setObjectName(QString::fromUtf8("emu5CheckBox"));
        emu5CheckBox->setEnabled(false);

        horizontalLayout_8->addWidget(emu5CheckBox);


        gameHorizLayout->addLayout(horizontalLayout_8);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(100, 130, 358, 51));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        ntscuRadio = new QRadioButton(layoutWidget2);
        ntscuRadio->setObjectName(QString::fromUtf8("ntscuRadio"));
        ntscuRadio->setChecked(true);

        horizontalLayout_2->addWidget(ntscuRadio);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        palRadio = new QRadioButton(layoutWidget2);
        palRadio->setObjectName(QString::fromUtf8("palRadio"));

        horizontalLayout_3->addWidget(palRadio);

        palHzBox = new QComboBox(layoutWidget2);
        palHzBox->addItem(QString());
        palHzBox->addItem(QString());
        palHzBox->setObjectName(QString::fromUtf8("palHzBox"));
        palHzBox->setEnabled(false);

        horizontalLayout_3->addWidget(palHzBox);


        horizontalLayout_2->addLayout(horizontalLayout_3);

        ntscjRadio = new QRadioButton(layoutWidget2);
        ntscjRadio->setObjectName(QString::fromUtf8("ntscjRadio"));

        horizontalLayout_2->addWidget(ntscjRadio);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 838, 29));
        menuSettings = new QMenu(menubar);
        menuSettings->setObjectName(QString::fromUtf8("menuSettings"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuExit = new QMenu(menubar);
        menuExit->setObjectName(QString::fromUtf8("menuExit"));
        menuGithub = new QMenu(menubar);
        menuGithub->setObjectName(QString::fromUtf8("menuGithub"));
        menuLog = new QMenu(menubar);
        menuLog->setObjectName(QString::fromUtf8("menuLog"));
        MainWindow->setMenuBar(menubar);
        QWidget::setTabOrder(pushButton, seedEntry);
        QWidget::setTabOrder(seedEntry, arbTargetBox);
        QWidget::setTabOrder(arbTargetBox, outTable);
        QWidget::setTabOrder(outTable, slowerButton);
        QWidget::setTabOrder(slowerButton, fasterButton);
        QWidget::setTabOrder(fasterButton, seeInputButton);

        menubar->addAction(menuSettings->menuAction());
        menubar->addAction(menuLog->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menubar->addAction(menuGithub->menuAction());
        menubar->addAction(menuExit->menuAction());
        menuSettings->addAction(actionHotkeys);
        menuSettings->addAction(actionSounds);
        menuSettings->addAction(actionTimer);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionHotkeys->setText(QCoreApplication::translate("MainWindow", "Hotkeys", nullptr));
        actionSounds->setText(QCoreApplication::translate("MainWindow", "Sounds", nullptr));
        actionTimer->setText(QCoreApplication::translate("MainWindow", "Timer", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "START", nullptr));
        statusLabel->setText(QCoreApplication::translate("MainWindow", "STATUS", nullptr));
        TotalTimeLabel->setText(QCoreApplication::translate("MainWindow", "TOTAL REMAINING:", nullptr));
        localTimeLabel->setText(QCoreApplication::translate("MainWindow", "Next blink:", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Blinks", nullptr));
        seeInputButton->setText(QCoreApplication::translate("MainWindow", "^ See inputs", nullptr));
        increaseBlinksButton->setText(QCoreApplication::translate("MainWindow", "Add 10 more blinks", nullptr));
        slowerButton->setText(QCoreApplication::translate("MainWindow", "\342\206\220  Slower", nullptr));
        fasterButton->setText(QCoreApplication::translate("MainWindow", "Faster \342\206\222", nullptr));
        nudgeOffsetLabel->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Input Seed:", nullptr));
        seedEntry->setText(QCoreApplication::translate("MainWindow", "DEADBEEF", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "input forgiveness (frames)", nullptr));
        flexValueHalfLabel->setText(QCoreApplication::translate("MainWindow", "+- 5f", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Search from:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "~", nullptr));
        palHzBox_2->setItemText(0, QCoreApplication::translate("MainWindow", "Advances", nullptr));
        palHzBox_2->setItemText(1, QCoreApplication::translate("MainWindow", "Visual Frames", nullptr));
        palHzBox_2->setItemText(2, QCoreApplication::translate("MainWindow", "Blinks", nullptr));

        label_2->setText(QCoreApplication::translate("MainWindow", "Target:", nullptr));
        coloRadio->setText(QCoreApplication::translate("MainWindow", "Colosseum", nullptr));
        galesRadio->setText(QCoreApplication::translate("MainWindow", "Gales", nullptr));
        emu5CheckBox->setText(QCoreApplication::translate("MainWindow", "Dolphin 5.0?", nullptr));
        ntscuRadio->setText(QCoreApplication::translate("MainWindow", "NTSC-U", nullptr));
        palRadio->setText(QCoreApplication::translate("MainWindow", "PAL", nullptr));
        palHzBox->setItemText(0, QCoreApplication::translate("MainWindow", "60hz", nullptr));
        palHzBox->setItemText(1, QCoreApplication::translate("MainWindow", "50hz", nullptr));

        ntscjRadio->setText(QCoreApplication::translate("MainWindow", "NTSC-J", nullptr));
        menuSettings->setTitle(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
        menuExit->setTitle(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        menuGithub->setTitle(QCoreApplication::translate("MainWindow", "GitHub", nullptr));
        menuLog->setTitle(QCoreApplication::translate("MainWindow", "Log", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
