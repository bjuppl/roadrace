#-------------------------------------------------
#
# Project created by QtCreator 2016-02-29T14:33:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = road_race
TEMPLATE = app


SOURCES += main.cpp\
        roadrace.cpp \
    network.cpp

HEADERS  += roadrace.h \
    network.h

FORMS    += roadrace.ui

CONFIG += c++11

