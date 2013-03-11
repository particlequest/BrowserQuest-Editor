#-------------------------------------------------
#
# Project created by QtCreator 2013-03-10T13:14:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BrowserQuest-Editor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    project.cpp \
    spritesheet.cpp \
    animation.cpp

HEADERS  += mainwindow.h \
    project.h \
    spritesheet.h \
    animation.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc
