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
    utils.cpp \
    gui.cpp \
    levelmanager.cpp \
    squarelabel.cpp \
    cheater.cpp \
    multiplayer.cpp

    

HEADERS  += roadrace.h \
            network.h \
            gamemodel.h\
            highscore.h \
    square.h \
    gamefile.h \
    player.h \
    utils.h \
    gui.h \
    levelmanager.h \
    squarelabel.h \
    cheater.h \
    multiplayer.h
    


FORMS    += roadrace.ui \
    cheater.ui \
    multiplayer.ui

CONFIG += c++11

RESOURCES += resources.qrc
QT += xml
DISTFILES += \
    single-player.rr

