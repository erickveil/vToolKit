#-------------------------------------------------
#
# Project created by QtCreator 2015-10-14T11:42:36
#
#-------------------------------------------------

QT       -= gui

TARGET = vToolKit
TEMPLATE = lib
CONFIG += staticlib

SOURCES += vtoolkit.cpp

HEADERS += vtoolkit.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
