#-------------------------------------------------
#
# Project created by QtCreator 2013-08-22T20:58:39
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = Demo
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    src/GTest.cpp \
    src/GSort.cpp \
    src/GGridCoord.cpp \
    src/GAStar.cpp \
    src/GTree.cpp

HEADERS += \
    src/GTest.h \
    src/GSort.h \
    src/GGridCoord.h \
    src/GAStar.h \
    src/GTree.h
