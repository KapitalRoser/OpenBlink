#include "mainwindow.h"

#include <QApplication>
#include <QTranslator>
#include <QPushButton> //needed to prevent pointer errors with the msgbox buttons


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setAttribute(Qt::AA_DontUseNativeMenuBar);

    QTranslator t;
    t.load(":/resfix1/jpn.qm");

    QMessageBox tsBox;
    tsBox.setIcon(QMessageBox::Question);
    tsBox.setText("Langauge: | 言語:");
    QPushButton *EngButton = tsBox.addButton("English",QMessageBox::AcceptRole);
    QPushButton *JpnButton = tsBox.addButton("日本語",QMessageBox::AcceptRole);
    tsBox.exec();
    if (tsBox.clickedButton() == JpnButton){
        a.installTranslator(&t);
        //ADD TO SETTINGS FILE TO SAVE USER A CLICK
        //ADD TO SETTINGS MENU FOR USER TO CHANGE LATER IF THEY NEED TO
    }


    //Thread setup here?

    MainWindow w;
    w.show();
    return a.exec();
}
