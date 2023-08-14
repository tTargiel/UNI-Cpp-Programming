#include "mainwindow.h"

#include <QApplication>

// Tomasz Targiel
// Lista 9

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
