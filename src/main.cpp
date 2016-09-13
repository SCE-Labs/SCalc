/*!-------------------------------------------------
*
* Copyright (C) 2016 Satakshi Computing and Electronic Laboratories,. <http://scel.satakshi.in>
* Purnendu Kumar <purnenduk90@gmail.com>
* Project created by QtCreator 2016-09-10T00:31:45
*
*-------------------------------------------------*/
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
