/*!-------------------------------------------------
*
* Copyright (C) 2016 Satakshi Computing and Electronic Laboratories,. <http://scel.satakshi.in>
* Purnendu Kumar <purnenduk90@gmail.com>
* Project created by QtCreator 2016-09-10T00:31:45
*
*-------------------------------------------------*/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void operationSelected();
    void digitSelected();
    void calculate();
    void setGeo();


private:
//*****************************************************************************************
//Type Declaration
//****************************************************************************************
    QLabel *Display;
    QLabel *previousDisplay;
    QPushButton *op_button[9];
    QPushButton *num_button[11];
};

#endif // MAINWINDOW_H
