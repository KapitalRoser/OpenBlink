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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
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
    QFrame *paramsFrame;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_3;
    QSpinBox *flexValueBox;
    QLabel *flexValueHalfLabel;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QSpinBox *searchMinBox;
    QLabel *label_4;
    QSpinBox *searchMaxBox;
    QLabel *label;
    QLabel *LogoLabel;
    QFrame *statusFrame;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *statusBox;
    QLabel *statusLabel;
    QPushButton *startButton;
    QFrame *seedQFrame;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_5;
    QLabel *seedLabelEntry;
    QLineEdit *seedEntry;
    QPushButton *pushButton;
    QFrame *timerFrame;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *slowerButton;
    QLabel *nudgeOffsetLabel;
    QPushButton *fasterButton;
    QLabel *localTimeLabel;
    QSpacerItem *horizontalSpacer;
    QLabel *nudgeOffsetLabel_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *TotalTimeLabel;
    QFrame *blinkTableFrame;
    QVBoxLayout *verticalLayout;
    QLabel *label_9;
    QPushButton *seeInputButton;
    QTableWidget *outTable;
    QPushButton *increaseBlinksButton;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QSpinBox *arbTargetBox;
    QSpacerItem *horizontalSpacer_3;
    QFrame *platformFrame;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *gameHorizLayout;
    QLabel *label_7;
    QComboBox *gameBox;
    QHBoxLayout *regionHorzLayout;
    QLabel *label_8;
    QComboBox *regionBox;
    QMenuBar *menubar;
    QMenu *menuSettings;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1248, 756);
        QFont font;
        font.setFamilies({QString::fromUtf8("Century Gothic")});
        MainWindow->setFont(font);
        MainWindow->setAutoFillBackground(false);
        actionHotkeys = new QAction(MainWindow);
        actionHotkeys->setObjectName(QString::fromUtf8("actionHotkeys"));
        actionHotkeys->setFont(font);
        actionSounds = new QAction(MainWindow);
        actionSounds->setObjectName(QString::fromUtf8("actionSounds"));
        actionSounds->setFont(font);
        actionTimer = new QAction(MainWindow);
        actionTimer->setObjectName(QString::fromUtf8("actionTimer"));
        actionTimer->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        paramsFrame = new QFrame(centralwidget);
        paramsFrame->setObjectName(QString::fromUtf8("paramsFrame"));
        paramsFrame->setGeometry(QRect(820, 340, 436, 311));
        paramsFrame->setStyleSheet(QString::fromUtf8("border: 5px solid white;\n"
"color: black;\n"
"background-color: white;\n"
"border-radius: 20px;\n"
""));
        verticalLayout_2 = new QVBoxLayout(paramsFrame);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_3 = new QLabel(paramsFrame);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_6->addWidget(label_3);

        flexValueBox = new QSpinBox(paramsFrame);
        flexValueBox->setObjectName(QString::fromUtf8("flexValueBox"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(flexValueBox->sizePolicy().hasHeightForWidth());
        flexValueBox->setSizePolicy(sizePolicy);
        flexValueBox->setStyleSheet(QString::fromUtf8("QSpinBox{\n"
"border: 2px solid #828282;\n"
"padding-left: 15px;\n"
"padding-top:5px;\n"
"padding-bottom:5px;\n"
"}\n"
"\n"
"QSpinBox::up-button{\n"
"image: url(:/resfix1/arrow2.jpg);\n"
"width: 14px;\n"
"height:14px;\n"
"padding-right: 10px;\n"
"padding-top: 5px;\n"
"padding-bottom:5px;\n"
"}\n"
"QSpinBox::down-button{\n"
"image: url(:/resfix1/arrow1.jpg);\n"
"width: 14px;\n"
"height:14px;\n"
"padding-right: 10px;\n"
"padding-top: 5px;\n"
"padding-bottom:5px;\n"
"}"));
        flexValueBox->setMinimum(-1000);
        flexValueBox->setMaximum(1000);
        flexValueBox->setValue(10);

        horizontalLayout_6->addWidget(flexValueBox);

        flexValueHalfLabel = new QLabel(paramsFrame);
        flexValueHalfLabel->setObjectName(QString::fromUtf8("flexValueHalfLabel"));

        horizontalLayout_6->addWidget(flexValueHalfLabel);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_5 = new QLabel(paramsFrame);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_7->addWidget(label_5);

        searchMinBox = new QSpinBox(paramsFrame);
        searchMinBox->setObjectName(QString::fromUtf8("searchMinBox"));
        searchMinBox->setMinimumSize(QSize(60, 0));
        searchMinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        searchMinBox->setMaximum(10000000);

        horizontalLayout_7->addWidget(searchMinBox);

        label_4 = new QLabel(paramsFrame);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_7->addWidget(label_4);

        searchMaxBox = new QSpinBox(paramsFrame);
        searchMaxBox->setObjectName(QString::fromUtf8("searchMaxBox"));
        searchMaxBox->setMinimumSize(QSize(60, 0));
        searchMaxBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        searchMaxBox->setMinimum(1);
        searchMaxBox->setMaximum(10000001);
        searchMaxBox->setSingleStep(1);
        searchMaxBox->setValue(10000);

        horizontalLayout_7->addWidget(searchMaxBox);

        label = new QLabel(paramsFrame);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_7->addWidget(label);


        verticalLayout_2->addLayout(horizontalLayout_7);

        LogoLabel = new QLabel(centralwidget);
        LogoLabel->setObjectName(QString::fromUtf8("LogoLabel"));
        LogoLabel->setGeometry(QRect(110, 50, 141, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Century Gothic")});
        font1.setPointSize(14);
        font1.setBold(true);
        LogoLabel->setFont(font1);
        statusFrame = new QFrame(centralwidget);
        statusFrame->setObjectName(QString::fromUtf8("statusFrame"));
        statusFrame->setGeometry(QRect(100, 370, 321, 121));
        statusFrame->setFont(font);
        statusFrame->setStyleSheet(QString::fromUtf8("border: 5px solid white;\n"
"color: black;\n"
"background-color: white;\n"
"border-radius: 20px;\n"
""));
        statusFrame->setFrameShape(QFrame::StyledPanel);
        statusFrame->setFrameShadow(QFrame::Plain);
        statusFrame->setLineWidth(20);
        statusFrame->setMidLineWidth(3);
        verticalLayoutWidget_2 = new QWidget(statusFrame);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(0, 0, 321, 121));
        statusBox = new QVBoxLayout(verticalLayoutWidget_2);
        statusBox->setSpacing(0);
        statusBox->setObjectName(QString::fromUtf8("statusBox"));
        statusBox->setContentsMargins(0, 0, 0, 0);
        statusLabel = new QLabel(verticalLayoutWidget_2);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));
        statusLabel->setFont(font);
        statusLabel->setAlignment(Qt::AlignCenter);
        statusLabel->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        statusBox->addWidget(statusLabel);

        startButton = new QPushButton(verticalLayoutWidget_2);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(startButton->sizePolicy().hasHeightForWidth());
        startButton->setSizePolicy(sizePolicy1);
        startButton->setFont(font);
        startButton->setStyleSheet(QString::fromUtf8("background-color: #e0e0e0;\n"
"color: black;\n"
"border: 5px solid #e0e0e0;\n"
"border-radius: 0px;\n"
"border-bottom-right-radius: 15px;\n"
"border-bottom-left-radius: 15px;"));

        statusBox->addWidget(startButton);

        seedQFrame = new QFrame(centralwidget);
        seedQFrame->setObjectName(QString::fromUtf8("seedQFrame"));
        seedQFrame->setGeometry(QRect(100, 290, 321, 61));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(seedQFrame->sizePolicy().hasHeightForWidth());
        seedQFrame->setSizePolicy(sizePolicy2);
        seedQFrame->setStyleSheet(QString::fromUtf8("border: 5px solid white;\n"
"color: black;\n"
"background-color: white;\n"
"border-radius: 20px;\n"
""));
        seedQFrame->setFrameShape(QFrame::StyledPanel);
        seedQFrame->setFrameShadow(QFrame::Raised);
        layoutWidget = new QWidget(seedQFrame);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 321, 61));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        seedLabelEntry = new QLabel(layoutWidget);
        seedLabelEntry->setObjectName(QString::fromUtf8("seedLabelEntry"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(seedLabelEntry->sizePolicy().hasHeightForWidth());
        seedLabelEntry->setSizePolicy(sizePolicy3);
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Century Gothic")});
        font2.setBold(false);
        font2.setKerning(false);
        seedLabelEntry->setFont(font2);

        horizontalLayout_5->addWidget(seedLabelEntry);

        seedEntry = new QLineEdit(layoutWidget);
        seedEntry->setObjectName(QString::fromUtf8("seedEntry"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(seedEntry->sizePolicy().hasHeightForWidth());
        seedEntry->setSizePolicy(sizePolicy4);
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Segoe UI")});
        seedEntry->setFont(font3);
        seedEntry->setStyleSheet(QString::fromUtf8("padding:10px;"));
        seedEntry->setMaxLength(8);
        seedEntry->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(seedEntry);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy5);
        pushButton->setMinimumSize(QSize(0, 0));
        pushButton->setMaximumSize(QSize(600, 100));
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("background-color: #e0e0e0;\n"
"color: black;\n"
"border: 5px solid #e0e0e0;\n"
"border-radius: 0px;\n"
"border-bottom-right-radius: 15px;\n"
"border-top-right-radius: 15px;"));

        horizontalLayout_5->addWidget(pushButton);

        timerFrame = new QFrame(centralwidget);
        timerFrame->setObjectName(QString::fromUtf8("timerFrame"));
        timerFrame->setGeometry(QRect(100, 520, 321, 191));
        timerFrame->setStyleSheet(QString::fromUtf8("border: 5px solid white;\n"
"font: 9pt \"Century Gothic\";\n"
"color: black;\n"
"background-color: white;\n"
"border-radius: 20px;\n"
""));
        timerFrame->setFrameShape(QFrame::StyledPanel);
        timerFrame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(timerFrame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(5, -1, 5, -1);
        slowerButton = new QPushButton(timerFrame);
        slowerButton->setObjectName(QString::fromUtf8("slowerButton"));
        slowerButton->setEnabled(false);
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(slowerButton->sizePolicy().hasHeightForWidth());
        slowerButton->setSizePolicy(sizePolicy6);
        slowerButton->setMinimumSize(QSize(115, 0));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Century Gothic")});
        font4.setPointSize(9);
        font4.setBold(false);
        font4.setItalic(false);
        slowerButton->setFont(font4);
        slowerButton->setStyleSheet(QString::fromUtf8("background-color: #e0e0e0;\n"
"font: 9pt \"Century Gothic\";\n"
"color: black;\n"
"border: 5px solid #e0e0e0;"));

        horizontalLayout->addWidget(slowerButton);

        nudgeOffsetLabel = new QLabel(timerFrame);
        nudgeOffsetLabel->setObjectName(QString::fromUtf8("nudgeOffsetLabel"));
        QSizePolicy sizePolicy7(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(nudgeOffsetLabel->sizePolicy().hasHeightForWidth());
        nudgeOffsetLabel->setSizePolicy(sizePolicy7);
        nudgeOffsetLabel->setMinimumSize(QSize(40, 0));
        nudgeOffsetLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(nudgeOffsetLabel);

        fasterButton = new QPushButton(timerFrame);
        fasterButton->setObjectName(QString::fromUtf8("fasterButton"));
        fasterButton->setEnabled(false);
        sizePolicy6.setHeightForWidth(fasterButton->sizePolicy().hasHeightForWidth());
        fasterButton->setSizePolicy(sizePolicy6);
        fasterButton->setMinimumSize(QSize(115, 0));
        fasterButton->setFont(font4);
        fasterButton->setAutoFillBackground(false);
        fasterButton->setStyleSheet(QString::fromUtf8("background-color: #e0e0e0;\n"
"font: 9pt \"Century Gothic\";\n"
"color: black;\n"
"border: 5px solid #e0e0e0;"));

        horizontalLayout->addWidget(fasterButton);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 4);

        localTimeLabel = new QLabel(timerFrame);
        localTimeLabel->setObjectName(QString::fromUtf8("localTimeLabel"));

        gridLayout->addWidget(localTimeLabel, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);

        nudgeOffsetLabel_2 = new QLabel(timerFrame);
        nudgeOffsetLabel_2->setObjectName(QString::fromUtf8("nudgeOffsetLabel_2"));
        nudgeOffsetLabel_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(nudgeOffsetLabel_2, 0, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 3, 1, 1);

        TotalTimeLabel = new QLabel(timerFrame);
        TotalTimeLabel->setObjectName(QString::fromUtf8("TotalTimeLabel"));

        gridLayout->addWidget(TotalTimeLabel, 0, 0, 1, 1);

        blinkTableFrame = new QFrame(centralwidget);
        blinkTableFrame->setObjectName(QString::fromUtf8("blinkTableFrame"));
        blinkTableFrame->setGeometry(QRect(560, 20, 292, 681));
        blinkTableFrame->setFont(font);
        blinkTableFrame->setStyleSheet(QString::fromUtf8("border: 5px solid white;\n"
"color: black;\n"
"background-color: white;\n"
"border-radius: 20px;\n"
""));
        blinkTableFrame->setFrameShape(QFrame::StyledPanel);
        blinkTableFrame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(blinkTableFrame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_9 = new QLabel(blinkTableFrame);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font1);

        verticalLayout->addWidget(label_9);

        seeInputButton = new QPushButton(blinkTableFrame);
        seeInputButton->setObjectName(QString::fromUtf8("seeInputButton"));
        seeInputButton->setEnabled(false);
        sizePolicy.setHeightForWidth(seeInputButton->sizePolicy().hasHeightForWidth());
        seeInputButton->setSizePolicy(sizePolicy);
        seeInputButton->setMinimumSize(QSize(0, 40));
        seeInputButton->setStyleSheet(QString::fromUtf8("background-color: #e0e0e0;\n"
"font: 9pt \"Century Gothic\";\n"
"color: black;\n"
"border: 5px solid #e0e0e0;\n"
"border-radius: 15px;"));

        verticalLayout->addWidget(seeInputButton);

        outTable = new QTableWidget(blinkTableFrame);
        outTable->setObjectName(QString::fromUtf8("outTable"));

        verticalLayout->addWidget(outTable);

        increaseBlinksButton = new QPushButton(blinkTableFrame);
        increaseBlinksButton->setObjectName(QString::fromUtf8("increaseBlinksButton"));
        sizePolicy1.setHeightForWidth(increaseBlinksButton->sizePolicy().hasHeightForWidth());
        increaseBlinksButton->setSizePolicy(sizePolicy1);
        increaseBlinksButton->setMinimumSize(QSize(0, 40));
        increaseBlinksButton->setStyleSheet(QString::fromUtf8("background-color: #e0e0e0;\n"
"font: 9pt \"Century Gothic\";\n"
"color: black;\n"
"border: 5px solid #e0e0e0;\n"
"border-radius: 20px;"));

        verticalLayout->addWidget(increaseBlinksButton);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, -1, 0, -1);
        label_2 = new QLabel(blinkTableFrame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_2);

        arbTargetBox = new QSpinBox(blinkTableFrame);
        arbTargetBox->setObjectName(QString::fromUtf8("arbTargetBox"));
        sizePolicy1.setHeightForWidth(arbTargetBox->sizePolicy().hasHeightForWidth());
        arbTargetBox->setSizePolicy(sizePolicy1);
        arbTargetBox->setMinimumSize(QSize(0, 0));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Century Gothic")});
        font5.setPointSize(9);
        arbTargetBox->setFont(font5);
        arbTargetBox->setStyleSheet(QString::fromUtf8("border: 2px solid #828282;\n"
"border-radius: 14px;\n"
"padding:5px;"));
        arbTargetBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        arbTargetBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        arbTargetBox->setMinimum(1);
        arbTargetBox->setMaximum(1000);
        arbTargetBox->setValue(10);

        horizontalLayout_4->addWidget(arbTargetBox);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 2);
        horizontalLayout_4->setStretch(2, 3);

        verticalLayout->addLayout(horizontalLayout_4);

        platformFrame = new QFrame(centralwidget);
        platformFrame->setObjectName(QString::fromUtf8("platformFrame"));
        platformFrame->setGeometry(QRect(870, 80, 311, 261));
        platformFrame->setStyleSheet(QString::fromUtf8("border: 5px solid white;\n"
"font: 9pt \"Century Gothic\";\n"
"color: black;\n"
"background-color: white;\n"
"border-radius: 20px;\n"
""));
        verticalLayout_3 = new QVBoxLayout(platformFrame);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        gameHorizLayout = new QHBoxLayout();
        gameHorizLayout->setObjectName(QString::fromUtf8("gameHorizLayout"));
        label_7 = new QLabel(platformFrame);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QSizePolicy sizePolicy8(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy8);

        gameHorizLayout->addWidget(label_7);

        gameBox = new QComboBox(platformFrame);
        gameBox->addItem(QString());
        gameBox->addItem(QString());
        gameBox->addItem(QString());
        gameBox->setObjectName(QString::fromUtf8("gameBox"));
        gameBox->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"border: 2px solid #828282;\n"
"padding-left: 15px;\n"
"padding-top:10px;\n"
"padding-bottom:10px;\n"
"}\n"
"QComboBox::drop-down{\n"
"border: 0px;\n"
"}\n"
"QComboBox::down-arrow{\n"
"image: url(:/resfix1/arrow1.jpg);\n"
"width: 28px;\n"
"height:28px;\n"
"padding-right: 40px;\n"
"}\n"
"QComboBox QAbstractItemView{\n"
"	border: 2px solid #828282;\n"
"}"));

        gameHorizLayout->addWidget(gameBox);


        verticalLayout_3->addLayout(gameHorizLayout);

        regionHorzLayout = new QHBoxLayout();
        regionHorzLayout->setObjectName(QString::fromUtf8("regionHorzLayout"));
        label_8 = new QLabel(platformFrame);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy8.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy8);

        regionHorzLayout->addWidget(label_8);

        regionBox = new QComboBox(platformFrame);
        regionBox->addItem(QString());
        regionBox->addItem(QString());
        regionBox->addItem(QString());
        regionBox->addItem(QString());
        regionBox->setObjectName(QString::fromUtf8("regionBox"));
        regionBox->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"border: 2px solid #828282;\n"
"padding-left: 15px;\n"
"padding-top:10px;\n"
"padding-bottom:10px;\n"
"}\n"
"QComboBox::drop-down{\n"
"border: 0px;\n"
"}\n"
"QComboBox::down-arrow{\n"
"image: url(:/resfix1/arrow1.jpg);\n"
"width: 28px;\n"
"height:28px;\n"
"padding-right: 40px;\n"
"}\n"
"QComboBox QAbstractItemView{\n"
"	border: 2px solid #828282;\n"
"}"));

        regionHorzLayout->addWidget(regionBox);


        verticalLayout_3->addLayout(regionHorzLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1248, 27));
        menuSettings = new QMenu(menubar);
        menuSettings->setObjectName(QString::fromUtf8("menuSettings"));
        MainWindow->setMenuBar(menubar);
        QWidget::setTabOrder(startButton, seedEntry);
        QWidget::setTabOrder(seedEntry, arbTargetBox);
        QWidget::setTabOrder(arbTargetBox, outTable);
        QWidget::setTabOrder(outTable, seeInputButton);

        menubar->addAction(menuSettings->menuAction());
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
        label_3->setText(QCoreApplication::translate("MainWindow", "Input forgiveness (frames)", nullptr));
        flexValueHalfLabel->setText(QCoreApplication::translate("MainWindow", "+- 5f", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Search from:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "~", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Advances", nullptr));
        LogoLabel->setText(QCoreApplication::translate("MainWindow", "OpenBlink", nullptr));
        statusLabel->setText(QCoreApplication::translate("MainWindow", "STATUS", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "START", nullptr));
        seedLabelEntry->setText(QCoreApplication::translate("MainWindow", "Seed:", nullptr));
        seedEntry->setText(QCoreApplication::translate("MainWindow", "DEADBEEF", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Paste", nullptr));
        slowerButton->setText(QCoreApplication::translate("MainWindow", "\342\206\220  Slower", nullptr));
        nudgeOffsetLabel->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        fasterButton->setText(QCoreApplication::translate("MainWindow", "Faster \342\206\222", nullptr));
        localTimeLabel->setText(QCoreApplication::translate("MainWindow", "Next blink:", nullptr));
        nudgeOffsetLabel_2->setText(QCoreApplication::translate("MainWindow", "+0f", nullptr));
        TotalTimeLabel->setText(QCoreApplication::translate("MainWindow", "TIME REMAINING:", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Blinks", nullptr));
        seeInputButton->setText(QCoreApplication::translate("MainWindow", "\342\206\221 See inputs", nullptr));
        increaseBlinksButton->setText(QCoreApplication::translate("MainWindow", "Add 10 more blinks", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Target:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Game:", nullptr));
        gameBox->setItemText(0, QCoreApplication::translate("MainWindow", "Colosseum", nullptr));
        gameBox->setItemText(1, QCoreApplication::translate("MainWindow", "XD", nullptr));
        gameBox->setItemText(2, QCoreApplication::translate("MainWindow", "XD (Dolphin 5.0)", nullptr));

        label_8->setText(QCoreApplication::translate("MainWindow", "Region:", nullptr));
        regionBox->setItemText(0, QCoreApplication::translate("MainWindow", "NTSC-U (NA)", nullptr));
        regionBox->setItemText(1, QCoreApplication::translate("MainWindow", "PAL - 60Hz (EU)", nullptr));
        regionBox->setItemText(2, QCoreApplication::translate("MainWindow", "PAL - 50Hz", nullptr));
        regionBox->setItemText(3, QCoreApplication::translate("MainWindow", "NTSC-J (JP)", nullptr));

        menuSettings->setTitle(QCoreApplication::translate("MainWindow", "Settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
