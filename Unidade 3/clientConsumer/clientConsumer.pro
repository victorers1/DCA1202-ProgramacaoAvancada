#-------------------------------------------------
#
# Project created by QtCreator 2017-06-14T07:10:59
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = clientConsumer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    plotter.cpp

HEADERS  += mainwindow.h \
    plotter.h

FORMS    += mainwindow.ui
