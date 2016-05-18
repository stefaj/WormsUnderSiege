#-------------------------------------------------
#
# Project created by QtCreator 2016-05-06T08:38:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = wormies
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    worm.cpp \
    turnmanager.cpp \
    keyboardmanager.cpp \
    gun.cpp \
    map.cpp

HEADERS  += mainwindow.h \
    worm.h \
    turnmanager.h \
    keyboardmanager.h \
    gun.h \
    map.h

FORMS    += mainwindow.ui

RESOURCES += \
    resies.qrc
