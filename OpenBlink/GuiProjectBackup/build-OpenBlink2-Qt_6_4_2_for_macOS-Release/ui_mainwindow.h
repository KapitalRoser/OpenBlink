/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
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
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *InputsFrame;
    QFrame *platformFrame;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *gameHorizLayout;
    QLabel *label_7;
    QComboBox *gameBox;
    QHBoxLayout *regionHorzLayout;
    QLabel *label_8;
    QComboBox *regionBox;
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
    QHBoxLayout *centerLayout;
    QFrame *seedQFrame;
    QHBoxLayout *horizontalLayout_2;
    QLabel *seedLabelEntry;
    QLineEdit *seedEntry;
    QPushButton *pasteButton;
    QWidget *targetSeedLayoutWidget;
    QHBoxLayout *targetSeedLayout;
    QFrame *targetSeedQFrame;
    QHBoxLayout *horizontalLayout_4;
    QLabel *targetSeedLabelEntry;
    QLineEdit *targetSeedEntry;
    QPushButton *targetPasteButton;
    QPushButton *targetSeedSearchButton;
    QFrame *statusFrame;
    QVBoxLayout *verticalLayout_4;
    QLabel *statusLabel;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *startButton;
    QPushButton *copyButton;
    QFrame *timerFrame;
    QGridLayout *gridLayout;
    QPushButton *slowerButtonX5;
    QPushButton *slowerButton;
    QLabel *nudgeOffsetLabel;
    QPushButton *fasterButton;
    QPushButton *fasterButtonX5;
    QLabel *localTimeLabel;
    QLabel *TotalTimeLabel;
    QLabel *nudgeMSLabel;
    QFrame *blinkTableFrame;
    QVBoxLayout *verticalLayout;
    QLabel *label_9;
    QPushButton *seeInputButton;
    QFrame *frame;
    QTableWidget *outTable;
    QPushButton *increaseBlinksButton;
    QHBoxLayout *arbTargetLayout;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_2;
    QSpinBox *arbTargetBox;
    QSpacerItem *horizontalSpacer_3;
    QMenuBar *menubar;
    QMenu *menuSettings;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(747, 717);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamilies({QString::fromUtf8(".Apple Color Emoji UI")});
        MainWindow->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resfix1/eye6.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setAutoFillBackground(false);
        actionHotkeys = new QAction(MainWindow);
        actionHotkeys->setObjectName("actionHotkeys");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Century Gothic")});
        actionHotkeys->setFont(font1);
        actionSounds = new QAction(MainWindow);
        actionSounds->setObjectName("actionSounds");
        actionSounds->setFont(font1);
        actionTimer = new QAction(MainWindow);
        actionTimer->setObjectName("actionTimer");
        actionTimer->setFont(font1);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy1);
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setSpacing(25);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(20, 20, 20, 20);
        InputsFrame = new QVBoxLayout();
        InputsFrame->setSpacing(15);
        InputsFrame->setObjectName("InputsFrame");
        platformFrame = new QFrame(centralwidget);
        platformFrame->setObjectName("platformFrame");
        platformFrame->setStyleSheet(QString::fromUtf8("\n"
"*{border: 5px solid white;\n"
"color: black;\n"
"background-color: white;\n"
"border-radius: 20px;\n"
"}\n"
"QFrame QLabel:disabled{\n"
"color:grey;\n"
"font-weight:normal;\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(platformFrame);
        verticalLayout_3->setObjectName("verticalLayout_3");
        gameHorizLayout = new QHBoxLayout();
        gameHorizLayout->setObjectName("gameHorizLayout");
        label_7 = new QLabel(platformFrame);
        label_7->setObjectName("label_7");
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy2);
        label_7->setMinimumSize(QSize(74, 0));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Century Gothic")});
        font2.setPointSize(11);
        font2.setBold(true);
        font2.setItalic(false);
        label_7->setFont(font2);

        gameHorizLayout->addWidget(label_7);

        gameBox = new QComboBox(platformFrame);
        gameBox->addItem(QString());
        gameBox->addItem(QString());
        gameBox->addItem(QString());
        gameBox->setObjectName("gameBox");
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Century Gothic")});
        font3.setPointSize(11);
        font3.setBold(false);
        font3.setItalic(false);
        gameBox->setFont(font3);
        gameBox->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"border: 2px solid #828282;\n"
"padding-left: 15px;\n"
"padding-top:10px;\n"
"padding-bottom:10px;\n"
"border-radius: 10px;\n"
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
"QComboBox:disabled{\n"
"color:grey;\n"
"border-color:lightgrey;\n"
"}"));

        gameHorizLayout->addWidget(gameBox);


        verticalLayout_3->addLayout(gameHorizLayout);

        regionHorzLayout = new QHBoxLayout();
        regionHorzLayout->setObjectName("regionHorzLayout");
        label_8 = new QLabel(platformFrame);
        label_8->setObjectName("label_8");
        sizePolicy2.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy2);
        label_8->setFont(font2);

        regionHorzLayout->addWidget(label_8);

        regionBox = new QComboBox(platformFrame);
        regionBox->addItem(QString());
        regionBox->addItem(QString());
        regionBox->addItem(QString());
        regionBox->addItem(QString());
        regionBox->setObjectName("regionBox");
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Century Gothic")});
        font4.setPointSize(11);
        regionBox->setFont(font4);
        regionBox->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"border: 2px solid #828282;\n"
"padding-left: 15px;\n"
"padding-top:10px;\n"
"padding-bottom:10px;\n"
"border-radius:10px;\n"
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
"QComboBox:disabled{\n"
"color:grey;\n"
"border-color:lightgrey;\n"
"}"));

        regionHorzLayout->addWidget(regionBox);


        verticalLayout_3->addLayout(regionHorzLayout);


        InputsFrame->addWidget(platformFrame);

        paramsFrame = new QFrame(centralwidget);
        paramsFrame->setObjectName("paramsFrame");
        paramsFrame->setStyleSheet(QString::fromUtf8("*{\n"
"border: 5px solid white;\n"
"color: black;\n"
"background-color: white;\n"
"border-radius: 20px;\n"
"}\n"
"QFrame QLabel:disabled{\n"
"color:grey;\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(paramsFrame);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_3 = new QLabel(paramsFrame);
        label_3->setObjectName("label_3");
        label_3->setFont(font1);

        horizontalLayout_6->addWidget(label_3);

        flexValueBox = new QSpinBox(paramsFrame);
        flexValueBox->setObjectName("flexValueBox");
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Century Gothic")});
        font5.setPointSize(9);
        font5.setBold(false);
        font5.setItalic(false);
        flexValueBox->setFont(font5);
        flexValueBox->setStyleSheet(QString::fromUtf8("QSpinBox{\n"
"border: 2px solid #828282;\n"
"font: 9pt \"Century Gothic\";\n"
"border-radius: 10px;\n"
"padding-left: 5px;\n"
"padding-top:5px;\n"
"padding-bottom:5px;\n"
"}\n"
"\n"
"QSpinBox::up-button{\n"
"image: url(:/resfix1/arrow2.jpg);\n"
"width: 10px;\n"
"height:10px;\n"
"padding-right: 10px;\n"
"padding-top: 5px;\n"
"padding-bottom:5px;\n"
"}\n"
"QSpinBox::down-button{\n"
"image: url(:/resfix1/arrow1.jpg);\n"
"width: 10px;\n"
"height:10px;\n"
"padding-right: 10px;\n"
"padding-top: 5px;\n"
"padding-bottom:5px;\n"
"}\n"
"QSpinBox:disabled{\n"
"color:grey;\n"
"border-color: lightgrey;\n"
"}"));
        flexValueBox->setMinimum(-1000);
        flexValueBox->setMaximum(1000);
        flexValueBox->setValue(20);

        horizontalLayout_6->addWidget(flexValueBox);

        flexValueHalfLabel = new QLabel(paramsFrame);
        flexValueHalfLabel->setObjectName("flexValueHalfLabel");
        flexValueHalfLabel->setFont(font1);

        horizontalLayout_6->addWidget(flexValueHalfLabel);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setContentsMargins(0, -1, 0, -1);
        label_5 = new QLabel(paramsFrame);
        label_5->setObjectName("label_5");
        label_5->setFont(font1);

        horizontalLayout_7->addWidget(label_5);

        searchMinBox = new QSpinBox(paramsFrame);
        searchMinBox->setObjectName("searchMinBox");
        searchMinBox->setMinimumSize(QSize(60, 0));
        searchMinBox->setFont(font1);
        searchMinBox->setStyleSheet(QString::fromUtf8("QSpinBox{\n"
"border: 2px solid #828282;\n"
"border-radius: 10px;\n"
"padding-left: 2px;\n"
"padding-top:2px;\n"
"padding-bottom:2px;\n"
"}\n"
"QSpinBox:disabled{\n"
"color:grey;\n"
"border-color:lightgrey;\n"
"}"));
        searchMinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        searchMinBox->setMaximum(10000000);

        horizontalLayout_7->addWidget(searchMinBox);

        label_4 = new QLabel(paramsFrame);
        label_4->setObjectName("label_4");
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setMaximumSize(QSize(35, 16777215));
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label_4);

        searchMaxBox = new QSpinBox(paramsFrame);
        searchMaxBox->setObjectName("searchMaxBox");
        searchMaxBox->setMinimumSize(QSize(60, 0));
        searchMaxBox->setFont(font1);
        searchMaxBox->setStyleSheet(QString::fromUtf8("QSpinBox{\n"
"border: 2px solid #828282;\n"
"border-radius: 10px;\n"
"padding-left: 2px;\n"
"padding-top:2px;\n"
"padding-bottom:2px;\n"
"}\n"
"QSpinBox:disabled{\n"
"color:grey;\n"
"border-color:lightgrey;\n"
"}"));
        searchMaxBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        searchMaxBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        searchMaxBox->setMinimum(1);
        searchMaxBox->setMaximum(10000001);
        searchMaxBox->setSingleStep(1);
        searchMaxBox->setValue(10000);

        horizontalLayout_7->addWidget(searchMaxBox);

        label = new QLabel(paramsFrame);
        label->setObjectName("label");
        label->setFont(font1);

        horizontalLayout_7->addWidget(label);


        verticalLayout_2->addLayout(horizontalLayout_7);


        InputsFrame->addWidget(paramsFrame);

        centerLayout = new QHBoxLayout();
        centerLayout->setObjectName("centerLayout");
        seedQFrame = new QFrame(centralwidget);
        seedQFrame->setObjectName("seedQFrame");
        sizePolicy1.setHeightForWidth(seedQFrame->sizePolicy().hasHeightForWidth());
        seedQFrame->setSizePolicy(sizePolicy1);
        seedQFrame->setMaximumSize(QSize(16777215, 16777215));
        seedQFrame->setStyleSheet(QString::fromUtf8("\n"
"*{\n"
"color: black;\n"
"background-color: white;\n"
"border-radius: 20px;\n"
"}\n"
"*:disabled{\n"
"color:grey;\n"
"font-weight:normal;}\n"
"QLineEdit:disabled{color:grey;}"));
        seedQFrame->setFrameShape(QFrame::StyledPanel);
        seedQFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(seedQFrame);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(20, 0, 0, 0);
        seedLabelEntry = new QLabel(seedQFrame);
        seedLabelEntry->setObjectName("seedLabelEntry");
        sizePolicy2.setHeightForWidth(seedLabelEntry->sizePolicy().hasHeightForWidth());
        seedLabelEntry->setSizePolicy(sizePolicy2);
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Century Gothic")});
        font6.setPointSize(11);
        font6.setBold(true);
        font6.setKerning(false);
        seedLabelEntry->setFont(font6);

        horizontalLayout_2->addWidget(seedLabelEntry);

        seedEntry = new QLineEdit(seedQFrame);
        seedEntry->setObjectName("seedEntry");
        sizePolicy2.setHeightForWidth(seedEntry->sizePolicy().hasHeightForWidth());
        seedEntry->setSizePolicy(sizePolicy2);
        seedEntry->setMaximumSize(QSize(100, 16777215));
        QFont font7;
        font7.setFamilies({QString::fromUtf8("Segoe UI")});
        font7.setPointSize(11);
        seedEntry->setFont(font7);
        seedEntry->setStyleSheet(QString::fromUtf8("padding:10px;"));
        seedEntry->setMaxLength(8);
        seedEntry->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(seedEntry);

        pasteButton = new QPushButton(seedQFrame);
        pasteButton->setObjectName("pasteButton");
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pasteButton->sizePolicy().hasHeightForWidth());
        pasteButton->setSizePolicy(sizePolicy3);
        pasteButton->setMinimumSize(QSize(0, 0));
        pasteButton->setMaximumSize(QSize(600, 100));
        QFont font8;
        font8.setFamilies({QString::fromUtf8("Century Gothic")});
        font8.setPointSize(9);
        font8.setBold(true);
        font8.setItalic(false);
        pasteButton->setFont(font8);
        pasteButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color: #004080;\n"
"font: 9pt \"Century Gothic\";\n"
"color: white;\n"
"font-weight: bold;\n"
"border-radius:0px;\n"
"border-top-right-radius:20px;\n"
"border-bottom-right-radius:20px;\n"
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

        horizontalLayout_2->addWidget(pasteButton);

        horizontalLayout_2->setStretch(0, 5);
        horizontalLayout_2->setStretch(1, 5);

        centerLayout->addWidget(seedQFrame);


        InputsFrame->addLayout(centerLayout);

        targetSeedLayoutWidget = new QWidget(centralwidget);
        targetSeedLayoutWidget->setObjectName("targetSeedLayoutWidget");
        targetSeedLayout = new QHBoxLayout(targetSeedLayoutWidget);
        targetSeedLayout->setObjectName("targetSeedLayout");
        targetSeedLayout->setContentsMargins(0, 0, 0, 5);
        targetSeedQFrame = new QFrame(targetSeedLayoutWidget);
        targetSeedQFrame->setObjectName("targetSeedQFrame");
        targetSeedQFrame->setEnabled(true);
        sizePolicy1.setHeightForWidth(targetSeedQFrame->sizePolicy().hasHeightForWidth());
        targetSeedQFrame->setSizePolicy(sizePolicy1);
        targetSeedQFrame->setMaximumSize(QSize(16777215, 16777215));
        targetSeedQFrame->setStyleSheet(QString::fromUtf8("\n"
"*{\n"
"color: black;\n"
"background-color: white;\n"
"border-radius: 20px;\n"
"}\n"
"*:disabled{\n"
"color:grey;\n"
"font-weight:normal;}\n"
"QLineEdit:disabled{color:grey;}"));
        targetSeedQFrame->setFrameShape(QFrame::StyledPanel);
        targetSeedQFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(targetSeedQFrame);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(20, 0, 0, 0);
        targetSeedLabelEntry = new QLabel(targetSeedQFrame);
        targetSeedLabelEntry->setObjectName("targetSeedLabelEntry");
        sizePolicy2.setHeightForWidth(targetSeedLabelEntry->sizePolicy().hasHeightForWidth());
        targetSeedLabelEntry->setSizePolicy(sizePolicy2);
        targetSeedLabelEntry->setFont(font6);

        horizontalLayout_4->addWidget(targetSeedLabelEntry);

        targetSeedEntry = new QLineEdit(targetSeedQFrame);
        targetSeedEntry->setObjectName("targetSeedEntry");
        sizePolicy2.setHeightForWidth(targetSeedEntry->sizePolicy().hasHeightForWidth());
        targetSeedEntry->setSizePolicy(sizePolicy2);
        targetSeedEntry->setMaximumSize(QSize(100, 16777215));
        targetSeedEntry->setFont(font7);
        targetSeedEntry->setStyleSheet(QString::fromUtf8("padding:10px;"));
        targetSeedEntry->setMaxLength(10);
        targetSeedEntry->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        targetSeedEntry->setReadOnly(false);

        horizontalLayout_4->addWidget(targetSeedEntry);

        targetPasteButton = new QPushButton(targetSeedQFrame);
        targetPasteButton->setObjectName("targetPasteButton");
        sizePolicy3.setHeightForWidth(targetPasteButton->sizePolicy().hasHeightForWidth());
        targetPasteButton->setSizePolicy(sizePolicy3);
        targetPasteButton->setMinimumSize(QSize(0, 0));
        targetPasteButton->setMaximumSize(QSize(600, 100));
        targetPasteButton->setFont(font8);
        targetPasteButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color: #004080;\n"
"font: 9pt \"Century Gothic\";\n"
"color: white;\n"
"font-weight: bold;\n"
"border-radius:0px;\n"
"border-top-right-radius:20px;\n"
"border-bottom-right-radius:20px;\n"
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

        horizontalLayout_4->addWidget(targetPasteButton);

        horizontalLayout_4->setStretch(0, 5);
        horizontalLayout_4->setStretch(1, 5);
        horizontalLayout_4->setStretch(2, 2);

        targetSeedLayout->addWidget(targetSeedQFrame);

        targetSeedSearchButton = new QPushButton(targetSeedLayoutWidget);
        targetSeedSearchButton->setObjectName("targetSeedSearchButton");
        targetSeedSearchButton->setEnabled(false);
        sizePolicy1.setHeightForWidth(targetSeedSearchButton->sizePolicy().hasHeightForWidth());
        targetSeedSearchButton->setSizePolicy(sizePolicy1);
        targetSeedSearchButton->setMaximumSize(QSize(16777215, 42));
        targetSeedSearchButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color: #004080;\n"
"font: 9pt \"Century Gothic\";\n"
"color: white;\n"
"font-weight: bold;\n"
"border-radius:20px;\n"
"padding: 15px;\n"
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

        targetSeedLayout->addWidget(targetSeedSearchButton);


        InputsFrame->addWidget(targetSeedLayoutWidget);

        statusFrame = new QFrame(centralwidget);
        statusFrame->setObjectName("statusFrame");
        statusFrame->setFont(font1);
        statusFrame->setStyleSheet(QString::fromUtf8("color: black;\n"
"background-color: white;\n"
"border-radius: 20px;\n"
""));
        statusFrame->setFrameShape(QFrame::StyledPanel);
        statusFrame->setFrameShadow(QFrame::Plain);
        statusFrame->setLineWidth(20);
        statusFrame->setMidLineWidth(3);
        verticalLayout_4 = new QVBoxLayout(statusFrame);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        statusLabel = new QLabel(statusFrame);
        statusLabel->setObjectName("statusLabel");
        QFont font9;
        font9.setFamilies({QString::fromUtf8("Century Gothic")});
        font9.setPointSize(11);
        font9.setBold(true);
        statusLabel->setFont(font9);
        statusLabel->setAlignment(Qt::AlignCenter);
        statusLabel->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        verticalLayout_4->addWidget(statusLabel);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(10);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setSizeConstraint(QLayout::SetFixedSize);
        startButton = new QPushButton(statusFrame);
        startButton->setObjectName("startButton");
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(startButton->sizePolicy().hasHeightForWidth());
        startButton->setSizePolicy(sizePolicy4);
        startButton->setFont(font2);
        startButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: #004080;\n"
"font: 11pt \"Century Gothic\";\n"
"color: white;\n"
"font-weight: bold;\n"
"border-radius:0px;\n"
"border-bottom-right-radius:20px;\n"
"border-bottom-left-radius:20px;\n"
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

        horizontalLayout_5->addWidget(startButton);

        copyButton = new QPushButton(statusFrame);
        copyButton->setObjectName("copyButton");
        sizePolicy4.setHeightForWidth(copyButton->sizePolicy().hasHeightForWidth());
        copyButton->setSizePolicy(sizePolicy4);
        copyButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: #004080;\n"
"font: 11pt \"Century Gothic\";\n"
"color: white;\n"
"font-weight: bold;\n"
"border-radius:0px;\n"
"border-bottom-left-radius:20px;\n"
"border-bottom-right-radius:20px;\n"
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

        horizontalLayout_5->addWidget(copyButton);

        horizontalLayout_5->setStretch(0, 8);
        horizontalLayout_5->setStretch(1, 3);

        verticalLayout_4->addLayout(horizontalLayout_5);


        InputsFrame->addWidget(statusFrame);

        timerFrame = new QFrame(centralwidget);
        timerFrame->setObjectName("timerFrame");
        timerFrame->setEnabled(false);
        sizePolicy.setHeightForWidth(timerFrame->sizePolicy().hasHeightForWidth());
        timerFrame->setSizePolicy(sizePolicy);
        timerFrame->setAutoFillBackground(false);
        timerFrame->setStyleSheet(QString::fromUtf8("*{border: 5px solid white;\n"
"font: \"Century Gothic\";\n"
"color: black;\n"
"background-color: white;\n"
"border-radius: 20px;\n"
"}\n"
"QFrame:disabled{\n"
"color:grey;\n"
"}"));
        timerFrame->setFrameShape(QFrame::StyledPanel);
        timerFrame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(timerFrame);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName("gridLayout");
        slowerButtonX5 = new QPushButton(timerFrame);
        slowerButtonX5->setObjectName("slowerButtonX5");
        sizePolicy.setHeightForWidth(slowerButtonX5->sizePolicy().hasHeightForWidth());
        slowerButtonX5->setSizePolicy(sizePolicy);
        slowerButtonX5->setMinimumSize(QSize(90, 0));
        slowerButtonX5->setFont(font8);
        slowerButtonX5->setStyleSheet(QString::fromUtf8("QPushButton{background-color: #004080;\n"
"font: 9pt \"Century Gothic\";\n"
"color: white;\n"
"font-weight: bold;\n"
"border-radius:18px;\n"
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

        gridLayout->addWidget(slowerButtonX5, 2, 0, 1, 1);

        slowerButton = new QPushButton(timerFrame);
        slowerButton->setObjectName("slowerButton");
        sizePolicy.setHeightForWidth(slowerButton->sizePolicy().hasHeightForWidth());
        slowerButton->setSizePolicy(sizePolicy);
        slowerButton->setMinimumSize(QSize(90, 0));
        slowerButton->setFont(font8);
        slowerButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color: #004080;\n"
"font: 9pt \"Century Gothic\";\n"
"color: white;\n"
"font-weight: bold;\n"
"border-radius:18px;\n"
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

        gridLayout->addWidget(slowerButton, 2, 1, 1, 1);

        nudgeOffsetLabel = new QLabel(timerFrame);
        nudgeOffsetLabel->setObjectName("nudgeOffsetLabel");
        sizePolicy.setHeightForWidth(nudgeOffsetLabel->sizePolicy().hasHeightForWidth());
        nudgeOffsetLabel->setSizePolicy(sizePolicy);
        nudgeOffsetLabel->setMinimumSize(QSize(40, 0));
        QFont font10;
        font10.setFamilies({QString::fromUtf8("Century Gothic")});
        font10.setBold(false);
        font10.setItalic(false);
        nudgeOffsetLabel->setFont(font10);
        nudgeOffsetLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(nudgeOffsetLabel, 2, 2, 1, 1);

        fasterButton = new QPushButton(timerFrame);
        fasterButton->setObjectName("fasterButton");
        sizePolicy.setHeightForWidth(fasterButton->sizePolicy().hasHeightForWidth());
        fasterButton->setSizePolicy(sizePolicy);
        fasterButton->setMinimumSize(QSize(85, 0));
        fasterButton->setFont(font8);
        fasterButton->setAutoFillBackground(false);
        fasterButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color: #004080;\n"
"font: 9pt \"Century Gothic\";\n"
"color: white;\n"
"font-weight: bold;\n"
"border-radius:18px;\n"
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

        gridLayout->addWidget(fasterButton, 2, 3, 1, 1);

        fasterButtonX5 = new QPushButton(timerFrame);
        fasterButtonX5->setObjectName("fasterButtonX5");
        sizePolicy.setHeightForWidth(fasterButtonX5->sizePolicy().hasHeightForWidth());
        fasterButtonX5->setSizePolicy(sizePolicy);
        fasterButtonX5->setMinimumSize(QSize(70, 0));
        fasterButtonX5->setFont(font8);
        fasterButtonX5->setAutoFillBackground(false);
        fasterButtonX5->setStyleSheet(QString::fromUtf8("QPushButton{background-color: #004080;\n"
"font: 9pt \"Century Gothic\";\n"
"color: white;\n"
"font-weight: bold;\n"
"border-radius:18px;\n"
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

        gridLayout->addWidget(fasterButtonX5, 2, 4, 1, 1);

        localTimeLabel = new QLabel(timerFrame);
        localTimeLabel->setObjectName("localTimeLabel");
        localTimeLabel->setFont(font10);

        gridLayout->addWidget(localTimeLabel, 1, 0, 1, 5);

        TotalTimeLabel = new QLabel(timerFrame);
        TotalTimeLabel->setObjectName("TotalTimeLabel");
        TotalTimeLabel->setFont(font3);

        gridLayout->addWidget(TotalTimeLabel, 0, 0, 1, 3);

        nudgeMSLabel = new QLabel(timerFrame);
        nudgeMSLabel->setObjectName("nudgeMSLabel");
        nudgeMSLabel->setFont(font10);
        nudgeMSLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(nudgeMSLabel, 0, 3, 1, 2);


        InputsFrame->addWidget(timerFrame);

        InputsFrame->setStretch(0, 3);
        InputsFrame->setStretch(1, 3);
        InputsFrame->setStretch(4, 3);
        InputsFrame->setStretch(5, 5);

        horizontalLayout->addLayout(InputsFrame);

        blinkTableFrame = new QFrame(centralwidget);
        blinkTableFrame->setObjectName("blinkTableFrame");
        sizePolicy.setHeightForWidth(blinkTableFrame->sizePolicy().hasHeightForWidth());
        blinkTableFrame->setSizePolicy(sizePolicy);
        blinkTableFrame->setMinimumSize(QSize(240, 0));
        blinkTableFrame->setFont(font1);
        blinkTableFrame->setStyleSheet(QString::fromUtf8("color: black;\n"
"background-color: white;\n"
"border-radius: 20px;\n"
""));
        blinkTableFrame->setFrameShape(QFrame::StyledPanel);
        blinkTableFrame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(blinkTableFrame);
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(20, 15, 20, 17);
        label_9 = new QLabel(blinkTableFrame);
        label_9->setObjectName("label_9");
        QFont font11;
        font11.setFamilies({QString::fromUtf8("Century Gothic")});
        font11.setPointSize(14);
        font11.setBold(true);
        label_9->setFont(font11);

        verticalLayout->addWidget(label_9);

        seeInputButton = new QPushButton(blinkTableFrame);
        seeInputButton->setObjectName("seeInputButton");
        seeInputButton->setEnabled(false);
        sizePolicy.setHeightForWidth(seeInputButton->sizePolicy().hasHeightForWidth());
        seeInputButton->setSizePolicy(sizePolicy);
        seeInputButton->setMinimumSize(QSize(210, 40));
        seeInputButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color: #004080;\n"
"font: 9pt \"Century Gothic\";\n"
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

        verticalLayout->addWidget(seeInputButton);

        frame = new QFrame(blinkTableFrame);
        frame->setObjectName("frame");
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setMinimumSize(QSize(0, 465));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        frame->setLineWidth(0);
        outTable = new QTableWidget(frame);
        outTable->setObjectName("outTable");
        outTable->setGeometry(QRect(15, 9, 210, 451));
        sizePolicy1.setHeightForWidth(outTable->sizePolicy().hasHeightForWidth());
        outTable->setSizePolicy(sizePolicy1);
        outTable->setFrameShape(QFrame::NoFrame);
        outTable->setFrameShadow(QFrame::Plain);
        outTable->setLineWidth(0);
        outTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        outTable->setSelectionBehavior(QAbstractItemView::SelectItems);
        outTable->setWordWrap(false);
        outTable->setCornerButtonEnabled(false);
        outTable->horizontalHeader()->setVisible(true);

        verticalLayout->addWidget(frame);

        increaseBlinksButton = new QPushButton(blinkTableFrame);
        increaseBlinksButton->setObjectName("increaseBlinksButton");
        increaseBlinksButton->setEnabled(false);
        sizePolicy4.setHeightForWidth(increaseBlinksButton->sizePolicy().hasHeightForWidth());
        increaseBlinksButton->setSizePolicy(sizePolicy4);
        increaseBlinksButton->setMinimumSize(QSize(0, 40));
        increaseBlinksButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color: #004080;\n"
"font: 9pt \"Century Gothic\";\n"
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

        verticalLayout->addWidget(increaseBlinksButton);

        arbTargetLayout = new QHBoxLayout();
        arbTargetLayout->setObjectName("arbTargetLayout");
        arbTargetLayout->setContentsMargins(-1, -1, 0, -1);
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        arbTargetLayout->addItem(horizontalSpacer_4);

        label_2 = new QLabel(blinkTableFrame);
        label_2->setObjectName("label_2");
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("QLabel:disabled{\n"
"color:grey;\n"
"}"));
        label_2->setAlignment(Qt::AlignCenter);

        arbTargetLayout->addWidget(label_2);

        arbTargetBox = new QSpinBox(blinkTableFrame);
        arbTargetBox->setObjectName("arbTargetBox");
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(arbTargetBox->sizePolicy().hasHeightForWidth());
        arbTargetBox->setSizePolicy(sizePolicy5);
        arbTargetBox->setMinimumSize(QSize(0, 30));
        QFont font12;
        font12.setFamilies({QString::fromUtf8("Century Gothic")});
        font12.setPointSize(9);
        arbTargetBox->setFont(font12);
        arbTargetBox->setStyleSheet(QString::fromUtf8("QSpinBox{\n"
"border: 2px solid #828282;\n"
"border-radius: 10px;\n"
"}\n"
"\n"
"QSpinBox::up-button{\n"
"image: url(:/resfix1/arrow2.jpg);\n"
"width: 12px;\n"
"height:12px;\n"
"padding-right: 5px;\n"
"padding-top:2px;\n"
"}\n"
"QSpinBox::down-button{\n"
"image: url(:/resfix1/arrow1.jpg);\n"
"width: 12px;\n"
"height:12px;\n"
"padding-right: 5px;\n"
"padding-bottom:2px;\n"
"}\n"
"QSpinBox:disabled{\n"
"color:grey;\n"
"border-color: lightgrey;\n"
"}"));
        arbTargetBox->setAlignment(Qt::AlignCenter);
        arbTargetBox->setMinimum(1);
        arbTargetBox->setMaximum(2147483647);
        arbTargetBox->setValue(15);

        arbTargetLayout->addWidget(arbTargetBox);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        arbTargetLayout->addItem(horizontalSpacer_3);

        arbTargetLayout->setStretch(1, 1);
        arbTargetLayout->setStretch(2, 2);

        verticalLayout->addLayout(arbTargetLayout);

        verticalLayout->setStretch(0, 2);
        verticalLayout->setStretch(1, 2);
        verticalLayout->setStretch(3, 6);
        verticalLayout->setStretch(4, 2);

        horizontalLayout->addWidget(blinkTableFrame);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 747, 24));
        menuSettings = new QMenu(menubar);
        menuSettings->setObjectName("menuSettings");
        MainWindow->setMenuBar(menubar);
        QWidget::setTabOrder(seedEntry, arbTargetBox);
        QWidget::setTabOrder(arbTargetBox, seeInputButton);

        menubar->addAction(menuSettings->menuAction());
        menuSettings->addAction(actionHotkeys);
        menuSettings->addAction(actionSounds);
        menuSettings->addAction(actionTimer);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "OpenBlink", nullptr));
        actionHotkeys->setText(QCoreApplication::translate("MainWindow", "Hotkeys", nullptr));
        actionSounds->setText(QCoreApplication::translate("MainWindow", "Sounds", nullptr));
        actionTimer->setText(QCoreApplication::translate("MainWindow", "Timer", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Game:", nullptr));
        gameBox->setItemText(0, QCoreApplication::translate("MainWindow", "Colosseum", nullptr));
        gameBox->setItemText(1, QCoreApplication::translate("MainWindow", "XD", nullptr));
        gameBox->setItemText(2, QCoreApplication::translate("MainWindow", "XD (Dolphin 5.0)", nullptr));

        label_8->setText(QCoreApplication::translate("MainWindow", "Region:", nullptr));
        regionBox->setItemText(0, QCoreApplication::translate("MainWindow", "NTSC-U (NA)", nullptr));
        regionBox->setItemText(1, QCoreApplication::translate("MainWindow", "PAL - 60Hz (EU)", nullptr));
        regionBox->setItemText(2, QCoreApplication::translate("MainWindow", "PAL - 50Hz", nullptr));
        regionBox->setItemText(3, QCoreApplication::translate("MainWindow", "NTSC-J (JP)", nullptr));

        label_3->setText(QCoreApplication::translate("MainWindow", "Input forgiveness (frames)", nullptr));
        flexValueHalfLabel->setText(QCoreApplication::translate("MainWindow", "+- 10f", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Search from:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "~", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Advances", nullptr));
        seedLabelEntry->setText(QCoreApplication::translate("MainWindow", "Starting Seed:", nullptr));
        seedEntry->setText(QCoreApplication::translate("MainWindow", "DEADBEEF", nullptr));
        pasteButton->setText(QCoreApplication::translate("MainWindow", "Paste", nullptr));
        targetSeedLabelEntry->setText(QCoreApplication::translate("MainWindow", "Target Seed:", nullptr));
        targetSeedEntry->setText(QCoreApplication::translate("MainWindow", "(optional)", nullptr));
        targetPasteButton->setText(QCoreApplication::translate("MainWindow", "Paste", nullptr));
        targetSeedSearchButton->setText(QCoreApplication::translate("MainWindow", "Search \360\237\224\216\357\270\216", nullptr));
        statusLabel->setText(QCoreApplication::translate("MainWindow", "STATUS", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "START", nullptr));
        copyButton->setText(QCoreApplication::translate("MainWindow", "Copy", nullptr));
        slowerButtonX5->setText(QCoreApplication::translate("MainWindow", "\342\206\220  +5", nullptr));
        slowerButton->setText(QCoreApplication::translate("MainWindow", "\342\206\220  Slower", nullptr));
        nudgeOffsetLabel->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        fasterButton->setText(QCoreApplication::translate("MainWindow", "Faster \342\206\222", nullptr));
        fasterButtonX5->setText(QCoreApplication::translate("MainWindow", "-5 \342\206\222", nullptr));
        localTimeLabel->setText(QCoreApplication::translate("MainWindow", "Next blink:", nullptr));
        TotalTimeLabel->setText(QCoreApplication::translate("MainWindow", "TIME REMAINING:", nullptr));
        nudgeMSLabel->setText(QCoreApplication::translate("MainWindow", "+0f", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Blinks", nullptr));
        seeInputButton->setText(QCoreApplication::translate("MainWindow", "\342\206\221 See inputs", nullptr));
        increaseBlinksButton->setText(QCoreApplication::translate("MainWindow", "Add 10 more blinks", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Target:", nullptr));
        menuSettings->setTitle(QCoreApplication::translate("MainWindow", "Settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
