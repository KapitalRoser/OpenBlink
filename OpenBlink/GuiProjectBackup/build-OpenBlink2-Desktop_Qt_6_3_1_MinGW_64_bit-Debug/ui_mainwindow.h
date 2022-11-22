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
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *BodyHoriz;
    QVBoxLayout *verticalLayout_5;
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
    QFrame *statusFrame;
    QVBoxLayout *verticalLayout_4;
    QLabel *statusLabel;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *startButton;
    QPushButton *copyButton;
    QFrame *timerFrame;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *slowerButton;
    QLabel *nudgeOffsetLabel;
    QPushButton *fasterButton;
    QLabel *nudgeMSLabel;
    QLabel *TotalTimeLabel;
    QLabel *localTimeLabel;
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
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(700, 729);
        QFont font;
        font.setFamilies({QString::fromUtf8("Century Gothic")});
        MainWindow->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resfix1/eye6.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
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
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 10, 661, 687));
        BodyHoriz = new QHBoxLayout(horizontalLayoutWidget);
        BodyHoriz->setSpacing(20);
        BodyHoriz->setObjectName(QString::fromUtf8("BodyHoriz"));
        BodyHoriz->setContentsMargins(10, 10, 10, 10);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(20);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        platformFrame = new QFrame(horizontalLayoutWidget);
        platformFrame->setObjectName(QString::fromUtf8("platformFrame"));
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
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        gameHorizLayout = new QHBoxLayout();
        gameHorizLayout->setObjectName(QString::fromUtf8("gameHorizLayout"));
        label_7 = new QLabel(platformFrame);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        label_7->setMinimumSize(QSize(74, 0));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Century Gothic")});
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setItalic(false);
        label_7->setFont(font1);

        gameHorizLayout->addWidget(label_7);

        gameBox = new QComboBox(platformFrame);
        gameBox->addItem(QString());
        gameBox->addItem(QString());
        gameBox->addItem(QString());
        gameBox->setObjectName(QString::fromUtf8("gameBox"));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Century Gothic")});
        font2.setPointSize(11);
        font2.setBold(false);
        font2.setItalic(false);
        gameBox->setFont(font2);
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
        regionHorzLayout->setObjectName(QString::fromUtf8("regionHorzLayout"));
        label_8 = new QLabel(platformFrame);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy);
        label_8->setFont(font1);

        regionHorzLayout->addWidget(label_8);

        regionBox = new QComboBox(platformFrame);
        regionBox->addItem(QString());
        regionBox->addItem(QString());
        regionBox->addItem(QString());
        regionBox->addItem(QString());
        regionBox->setObjectName(QString::fromUtf8("regionBox"));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Century Gothic")});
        font3.setPointSize(11);
        regionBox->setFont(font3);
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


        verticalLayout_5->addWidget(platformFrame);

        paramsFrame = new QFrame(horizontalLayoutWidget);
        paramsFrame->setObjectName(QString::fromUtf8("paramsFrame"));
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
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_3 = new QLabel(paramsFrame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        horizontalLayout_6->addWidget(label_3);

        flexValueBox = new QSpinBox(paramsFrame);
        flexValueBox->setObjectName(QString::fromUtf8("flexValueBox"));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Century Gothic")});
        font4.setPointSize(9);
        font4.setBold(false);
        flexValueBox->setFont(font4);
        flexValueBox->setStyleSheet(QString::fromUtf8("QSpinBox{\n"
"border: 2px solid #828282;\n"
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
        flexValueHalfLabel->setObjectName(QString::fromUtf8("flexValueHalfLabel"));
        flexValueHalfLabel->setFont(font);

        horizontalLayout_6->addWidget(flexValueHalfLabel);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, -1, 0, -1);
        label_5 = new QLabel(paramsFrame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        horizontalLayout_7->addWidget(label_5);

        searchMinBox = new QSpinBox(paramsFrame);
        searchMinBox->setObjectName(QString::fromUtf8("searchMinBox"));
        searchMinBox->setMinimumSize(QSize(60, 0));
        searchMinBox->setFont(font);
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
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(label_4);

        searchMaxBox = new QSpinBox(paramsFrame);
        searchMaxBox->setObjectName(QString::fromUtf8("searchMaxBox"));
        searchMaxBox->setMinimumSize(QSize(60, 0));
        searchMaxBox->setFont(font);
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
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        horizontalLayout_7->addWidget(label);


        verticalLayout_2->addLayout(horizontalLayout_7);


        verticalLayout_5->addWidget(paramsFrame);

        centerLayout = new QHBoxLayout();
        centerLayout->setObjectName(QString::fromUtf8("centerLayout"));
        seedQFrame = new QFrame(horizontalLayoutWidget);
        seedQFrame->setObjectName(QString::fromUtf8("seedQFrame"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(seedQFrame->sizePolicy().hasHeightForWidth());
        seedQFrame->setSizePolicy(sizePolicy2);
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
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(26, 0, 0, 0);
        seedLabelEntry = new QLabel(seedQFrame);
        seedLabelEntry->setObjectName(QString::fromUtf8("seedLabelEntry"));
        sizePolicy.setHeightForWidth(seedLabelEntry->sizePolicy().hasHeightForWidth());
        seedLabelEntry->setSizePolicy(sizePolicy);
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Century Gothic")});
        font5.setPointSize(11);
        font5.setBold(true);
        font5.setKerning(false);
        seedLabelEntry->setFont(font5);

        horizontalLayout_2->addWidget(seedLabelEntry);

        seedEntry = new QLineEdit(seedQFrame);
        seedEntry->setObjectName(QString::fromUtf8("seedEntry"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(seedEntry->sizePolicy().hasHeightForWidth());
        seedEntry->setSizePolicy(sizePolicy3);
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Segoe UI")});
        font6.setPointSize(11);
        seedEntry->setFont(font6);
        seedEntry->setStyleSheet(QString::fromUtf8("padding:10px;"));
        seedEntry->setMaxLength(8);
        seedEntry->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(seedEntry);

        pasteButton = new QPushButton(seedQFrame);
        pasteButton->setObjectName(QString::fromUtf8("pasteButton"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(pasteButton->sizePolicy().hasHeightForWidth());
        pasteButton->setSizePolicy(sizePolicy4);
        pasteButton->setMinimumSize(QSize(0, 0));
        pasteButton->setMaximumSize(QSize(600, 100));
        QFont font7;
        font7.setFamilies({QString::fromUtf8("Century Gothic")});
        font7.setPointSize(9);
        font7.setBold(true);
        font7.setItalic(false);
        pasteButton->setFont(font7);
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
        horizontalLayout_2->setStretch(2, 2);

        centerLayout->addWidget(seedQFrame);


        verticalLayout_5->addLayout(centerLayout);

        statusFrame = new QFrame(horizontalLayoutWidget);
        statusFrame->setObjectName(QString::fromUtf8("statusFrame"));
        statusFrame->setFont(font);
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
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        statusLabel = new QLabel(statusFrame);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));
        QFont font8;
        font8.setFamilies({QString::fromUtf8("Century Gothic")});
        font8.setPointSize(11);
        font8.setBold(true);
        statusLabel->setFont(font8);
        statusLabel->setAlignment(Qt::AlignCenter);
        statusLabel->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        verticalLayout_4->addWidget(statusLabel);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(10);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setSizeConstraint(QLayout::SetFixedSize);
        startButton = new QPushButton(statusFrame);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        sizePolicy1.setHeightForWidth(startButton->sizePolicy().hasHeightForWidth());
        startButton->setSizePolicy(sizePolicy1);
        startButton->setFont(font1);
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
        copyButton->setObjectName(QString::fromUtf8("copyButton"));
        sizePolicy1.setHeightForWidth(copyButton->sizePolicy().hasHeightForWidth());
        copyButton->setSizePolicy(sizePolicy1);
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


        verticalLayout_5->addWidget(statusFrame);

        timerFrame = new QFrame(horizontalLayoutWidget);
        timerFrame->setObjectName(QString::fromUtf8("timerFrame"));
        timerFrame->setEnabled(false);
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
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        slowerButton = new QPushButton(timerFrame);
        slowerButton->setObjectName(QString::fromUtf8("slowerButton"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(slowerButton->sizePolicy().hasHeightForWidth());
        slowerButton->setSizePolicy(sizePolicy5);
        slowerButton->setMinimumSize(QSize(115, 0));
        slowerButton->setFont(font7);
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

        horizontalLayout->addWidget(slowerButton);

        nudgeOffsetLabel = new QLabel(timerFrame);
        nudgeOffsetLabel->setObjectName(QString::fromUtf8("nudgeOffsetLabel"));
        sizePolicy5.setHeightForWidth(nudgeOffsetLabel->sizePolicy().hasHeightForWidth());
        nudgeOffsetLabel->setSizePolicy(sizePolicy5);
        nudgeOffsetLabel->setMinimumSize(QSize(40, 0));
        QFont font9;
        font9.setFamilies({QString::fromUtf8("Century Gothic")});
        font9.setBold(false);
        font9.setItalic(false);
        nudgeOffsetLabel->setFont(font9);
        nudgeOffsetLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(nudgeOffsetLabel);

        fasterButton = new QPushButton(timerFrame);
        fasterButton->setObjectName(QString::fromUtf8("fasterButton"));
        sizePolicy5.setHeightForWidth(fasterButton->sizePolicy().hasHeightForWidth());
        fasterButton->setSizePolicy(sizePolicy5);
        fasterButton->setMinimumSize(QSize(115, 0));
        fasterButton->setFont(font7);
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

        horizontalLayout->addWidget(fasterButton);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 3);

        nudgeMSLabel = new QLabel(timerFrame);
        nudgeMSLabel->setObjectName(QString::fromUtf8("nudgeMSLabel"));
        nudgeMSLabel->setFont(font9);
        nudgeMSLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(nudgeMSLabel, 0, 2, 1, 1);

        TotalTimeLabel = new QLabel(timerFrame);
        TotalTimeLabel->setObjectName(QString::fromUtf8("TotalTimeLabel"));
        TotalTimeLabel->setFont(font2);

        gridLayout->addWidget(TotalTimeLabel, 0, 0, 1, 1);

        localTimeLabel = new QLabel(timerFrame);
        localTimeLabel->setObjectName(QString::fromUtf8("localTimeLabel"));
        localTimeLabel->setFont(font9);

        gridLayout->addWidget(localTimeLabel, 1, 0, 1, 1);


        verticalLayout_5->addWidget(timerFrame);

        verticalLayout_5->setStretch(0, 2);
        verticalLayout_5->setStretch(1, 2);
        verticalLayout_5->setStretch(3, 2);
        verticalLayout_5->setStretch(4, 3);

        BodyHoriz->addLayout(verticalLayout_5);

        blinkTableFrame = new QFrame(horizontalLayoutWidget);
        blinkTableFrame->setObjectName(QString::fromUtf8("blinkTableFrame"));
        sizePolicy.setHeightForWidth(blinkTableFrame->sizePolicy().hasHeightForWidth());
        blinkTableFrame->setSizePolicy(sizePolicy);
        blinkTableFrame->setMinimumSize(QSize(240, 0));
        blinkTableFrame->setFont(font);
        blinkTableFrame->setStyleSheet(QString::fromUtf8("color: black;\n"
"background-color: white;\n"
"border-radius: 20px;\n"
""));
        blinkTableFrame->setFrameShape(QFrame::StyledPanel);
        blinkTableFrame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(blinkTableFrame);
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(20, 15, 20, 17);
        label_9 = new QLabel(blinkTableFrame);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        QFont font10;
        font10.setFamilies({QString::fromUtf8("Century Gothic")});
        font10.setPointSize(14);
        font10.setBold(true);
        label_9->setFont(font10);

        verticalLayout->addWidget(label_9);

        seeInputButton = new QPushButton(blinkTableFrame);
        seeInputButton->setObjectName(QString::fromUtf8("seeInputButton"));
        seeInputButton->setEnabled(false);
        QSizePolicy sizePolicy6(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(seeInputButton->sizePolicy().hasHeightForWidth());
        seeInputButton->setSizePolicy(sizePolicy6);
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
        frame->setObjectName(QString::fromUtf8("frame"));
        sizePolicy5.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy5);
        frame->setMinimumSize(QSize(0, 465));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        frame->setLineWidth(0);
        outTable = new QTableWidget(frame);
        outTable->setObjectName(QString::fromUtf8("outTable"));
        outTable->setGeometry(QRect(0, 9, 210, 451));
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
        increaseBlinksButton->setObjectName(QString::fromUtf8("increaseBlinksButton"));
        increaseBlinksButton->setEnabled(false);
        sizePolicy1.setHeightForWidth(increaseBlinksButton->sizePolicy().hasHeightForWidth());
        increaseBlinksButton->setSizePolicy(sizePolicy1);
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
        arbTargetLayout->setObjectName(QString::fromUtf8("arbTargetLayout"));
        arbTargetLayout->setContentsMargins(-1, -1, 0, -1);
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        arbTargetLayout->addItem(horizontalSpacer_4);

        label_2 = new QLabel(blinkTableFrame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("QLabel:disabled{\n"
"color:grey;\n"
"}"));
        label_2->setAlignment(Qt::AlignCenter);

        arbTargetLayout->addWidget(label_2);

        arbTargetBox = new QSpinBox(blinkTableFrame);
        arbTargetBox->setObjectName(QString::fromUtf8("arbTargetBox"));
        QSizePolicy sizePolicy7(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(arbTargetBox->sizePolicy().hasHeightForWidth());
        arbTargetBox->setSizePolicy(sizePolicy7);
        arbTargetBox->setMinimumSize(QSize(0, 30));
        QFont font11;
        font11.setFamilies({QString::fromUtf8("Century Gothic")});
        font11.setPointSize(9);
        arbTargetBox->setFont(font11);
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
        arbTargetBox->setMaximum(1000);
        arbTargetBox->setValue(15);

        arbTargetLayout->addWidget(arbTargetBox);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        arbTargetLayout->addItem(horizontalSpacer_3);

        arbTargetLayout->setStretch(1, 1);
        arbTargetLayout->setStretch(2, 2);

        verticalLayout->addLayout(arbTargetLayout);


        BodyHoriz->addWidget(blinkTableFrame);

        BodyHoriz->setStretch(0, 1);
        BodyHoriz->setStretch(1, 3);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 700, 27));
        menuSettings = new QMenu(menubar);
        menuSettings->setObjectName(QString::fromUtf8("menuSettings"));
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
        seedLabelEntry->setText(QCoreApplication::translate("MainWindow", "Seed:", nullptr));
        seedEntry->setText(QCoreApplication::translate("MainWindow", "DEADBEEF", nullptr));
        pasteButton->setText(QCoreApplication::translate("MainWindow", "Paste", nullptr));
        statusLabel->setText(QCoreApplication::translate("MainWindow", "STATUS", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "START", nullptr));
        copyButton->setText(QCoreApplication::translate("MainWindow", "Copy", nullptr));
        slowerButton->setText(QCoreApplication::translate("MainWindow", "\342\206\220  Slower", nullptr));
        nudgeOffsetLabel->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        fasterButton->setText(QCoreApplication::translate("MainWindow", "Faster \342\206\222", nullptr));
        nudgeMSLabel->setText(QCoreApplication::translate("MainWindow", "+0f", nullptr));
        TotalTimeLabel->setText(QCoreApplication::translate("MainWindow", "TIME REMAINING:", nullptr));
        localTimeLabel->setText(QCoreApplication::translate("MainWindow", "Next blink:", nullptr));
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
