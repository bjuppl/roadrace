#-------------------------------------------------
#
# Project created by QtCreator 2016-02-29T14:33:53
#
#-------------------------------------------------

QT       += core gui widgets network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = road_race
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        roadrace.cpp \
        network.cpp \
        gamemodel.cpp\
        highscore.cpp \
    square.cpp \
    gamefile.cpp \
    player.cpp \
    utils.cpp

HEADERS  += roadrace.h \
            network.h \
            gamemodel.h\
            highscore.h \
    square.h \
    gamefile.h \
    player.h \
    utils.h


FORMS    += roadrace.ui

CONFIG += c++11

