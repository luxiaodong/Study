#-------------------------------------------------
#
# Project created by QtCreator 2013-08-21T10:57:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = algorithm
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    src/GTest.cpp \
    src/GSort.cpp \
    src/GGridCoord.cpp \
    src/GAStar.cpp

HEADERS  += mainwindow.h \
    src/GTest.h \
    src/GSort.h \
    src/GGridCoord.h \
    src/GAStar.h

FORMS    += mainwindow.ui
