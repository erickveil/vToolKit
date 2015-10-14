#-------------------------------------------------
#
# Project created by QtCreator 2015-10-09T11:00:00
#
#-------------------------------------------------

QT       -= gui

TARGET = ExtendedException
TEMPLATE = lib

CONFIG += staticlib

DEFINES += EXTENDEDEXCEPTION_LIBRARY

SOURCES += qxexception.cpp \
    qxfatalexception.cpp

HEADERS += qxexception.h\
    qxfatalexception.h \
    version.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
