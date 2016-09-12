#include "mainwindow.h"
#include <QApplication>

#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //************************************************************************************************
    //Basic Window
    //************************************************************************************************
    w.showMaximized();//show maximized initially
    w.setFixedSize(300,400);//fixed sixe
    w.move(QApplication::desktop()->screen()->rect().center()-w.rect().center());//opens app in center
    w.show();

    return a.exec();
}
