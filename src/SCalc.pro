#-------------------------------------------------
#
# Copyright (C) 2016 Satakshi Computing and Electronic Laboratories,. <http://scel.satakshi.in>
# Purnendu Kumar <purnenduk90@gmail.com>
# Project created by QtCreator 2016-09-10T00:31:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SCalc
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

RC_FILE = SCalc.rc


QMAKE_DOCS = Bengine.qdocconfig
