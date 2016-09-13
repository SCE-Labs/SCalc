/*!-------------------------------------------------
*
* Copyright (C) 2016 Satakshi Computing and Electronic Laboratories,. <http://scel.satakshi.in>
* Purnendu Kumar <purnenduk90@gmail.com>
* Project created by QtCreator 2016-09-10T00:31:45
*
*-------------------------------------------------*/
#include "mainwindow.h"
#include <QtCore/QCoreApplication>
#include <QtCore/qmath.h>

QString value="", total="", calculation="";
double fnum,snum;
bool addBool=false, subBool=false, mulBool=false, divBool=false, powBool=false, perBool=false, invBool=false;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    Display = new QLabel("0",this);
    Display -> setGeometry(QRect(QPoint(50,75),QSize(100,25)));
    Display->setFrameStyle(QFrame::Panel | QFrame::Sunken);

    previousDisplay = new QLabel("0",this);
    previousDisplay -> setGeometry(QRect(QPoint(50,50),QSize(200,25)));
    previousDisplay->setFrameStyle(QFrame::Panel | QFrame::Sunken);

    for (int i=0; i<9; i++){
        QString operation[]= {"C", "=", "+", "-", "*", "/", "^", "%", "inv"};
        op_button[i] = new QPushButton(operation[i], this);
        if (i==1){
            connect(op_button[i], SIGNAL(released()), this, SLOT(calculate()) );
        }

        else{
            connect(op_button[i], SIGNAL(released()), this, SLOT(operationSelected()) );
        }

    }

    for (int i=0; i<11; i++){
        QString digit=QString::number(i);
        if (i!=10){
            num_button[i] = new QPushButton(digit, this);
        }
        else{
            num_button[i] = new QPushButton(".", this);
        }
        connect(num_button[i], SIGNAL(released()), this, SLOT(digitSelected()) );
    }

    setGeo();
}

void MainWindow::operationSelected(){
    QPushButton *op_button =(QPushButton *)sender();
    fnum=value.toDouble();
    calculation=value;
    value="";
    Display->setText(value);

    if (op_button->text() == "C"){
        value="";
        total="";
        calculation="";
        fnum=0;
        snum=0;
    }

    if (op_button->text() == "+"){
        calculation = calculation + "+";
        addBool=true;
    }

    if (op_button->text() == "-"){
        calculation = calculation + "-";
        subBool=true;
    }

    if (op_button->text() == "*"){
        calculation = calculation + "*";
        mulBool=true;
    }

    if (op_button->text() == "/"){
        calculation = calculation + "/";
        divBool=true;
    }
    if (op_button->text() == "^"){
        calculation = calculation + "^";
        powBool=true;
    }

    if (op_button->text() == "%"){
        calculation = calculation + "%";
        perBool=true;
    }

    if (op_button->text() == "inv"){
        calculation = calculation + "(inv) ";
        invBool=true;
        calculate();
    }

    previousDisplay->setText(calculation);
}

void MainWindow::digitSelected(){
    QPushButton *num_button =(QPushButton *)sender();
    value += QString(num_button->text());
    Display -> setText(value);

}

void MainWindow::calculate(){
    snum=value.toDouble();
    calculation = calculation+value;
    if (addBool){
        total=QString::number(fnum+snum);
        addBool=false;
    }
    if (subBool){
        total=QString::number(fnum-snum);
        subBool=false;
    }
    if (mulBool){
        total=QString::number(fnum*snum);
        mulBool=false;
    }
    if (divBool){
        total=QString::number(fnum/snum);
        divBool=false;
    }
    if (powBool){
        total=QString::number(qPow(fnum,snum));
        powBool=false;
    }
    if (perBool){
        total=QString::number((fnum/snum)*100);
        perBool=false;
    }
    if (invBool){
        total=QString::number(1/fnum);
        invBool=false;
    }
    Display->setText(total);
    previousDisplay->setText(calculation);
    value=total;
}


void MainWindow::setGeo(){
        num_button[0]->setGeometry(QRect(QPoint(50,300),QSize(50,50)));//zero in bottom left corner (0,0)
        num_button[1]->setGeometry(QRect(QPoint(50,250),QSize(50,50)));//one , (0,1)
        num_button[2]->setGeometry(QRect(QPoint(100,250),QSize(50,50)));//two , (1,1)
        num_button[3]->setGeometry(QRect(QPoint(150,250),QSize(50,50)));//three , (2,1)
        num_button[4]->setGeometry(QRect(QPoint(50,200),QSize(50,50)));//four , (0,2)
        num_button[5]->setGeometry(QRect(QPoint(100,200),QSize(50,50)));//five , (1,2)
        num_button[6]->setGeometry(QRect(QPoint(150,200),QSize(50,50)));//six , (2,2)
        num_button[7]->setGeometry(QRect(QPoint(50,150),QSize(50,50)));//seven , (0,3)
        num_button[8]->setGeometry(QRect(QPoint(100,150),QSize(50,50)));//eight , (1,3)
        num_button[9]->setGeometry(QRect(QPoint(150,150),QSize(50,50)));//nine , (2,3)
        num_button[10]->setGeometry(QRect(QPoint(100,300),QSize(50,50)));//decimal, rignt side of zero (1,0)
        op_button[0]->setGeometry(QRect(QPoint(150,75),QSize(100,25)));//clear, below labels right corner
        op_button[1]->setGeometry(QRect(QPoint(150,300),QSize(100,50)));//calculate, bottom right corner (2,0) (3,0)
        op_button[2]->setGeometry(QRect(QPoint(200,250),QSize(50,50)));//addition,  (3,1)
        op_button[3]->setGeometry(QRect(QPoint(200,200),QSize(50,50)));//subtraction,  (3,2)
        op_button[4]->setGeometry(QRect(QPoint(200,150),QSize(50,50)));//multiply,  (3,3)
        op_button[5]->setGeometry(QRect(QPoint(200,100),QSize(50,50)));//divide,  (4,3)
        op_button[6]->setGeometry(QRect(QPoint(100,100),QSize(50,50)));//square-root,  (4,1)
        op_button[7]->setGeometry(QRect(QPoint(150,100),QSize(50,50)));//percentage,  (4,2)
        op_button[8]->setGeometry(QRect(QPoint(50,100),QSize(50,50)));//invert,  (4,0)
}


MainWindow::~MainWindow()
{

}
