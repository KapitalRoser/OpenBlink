#include "mainwindow.h"

#include <QApplication>
#include <QTranslator>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //replace this with setting in settings.txt to be read and loaded the first time. Saves on having multiple builds.
    //command in terminal in qt: lupdate -pro ... and -ts ...
    QTranslator t;
    t.load(":/resfix1/jpn.qm");
    a.installTranslator(&t);

    QCoreApplication::setAttribute(Qt::AA_DontUseNativeMenuBar);
    MainWindow w;
    w.show();
    return a.exec();
}
