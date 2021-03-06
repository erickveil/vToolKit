#-------------------------------------------------
#
# Project created by QtCreator 2015-10-12T11:25:24
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = UnitTest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    ../qxfatalexception.cpp \
    ../qxexception.cpp \
    ../backtraceresultrecord.cpp \
    ../symbolrecord.cpp \
    ../symboltable.cpp

INCLUDEPATH += ../

HEADERS += \
    ../extendedexception_global.h \
    ../qxfatalexception.h \
    ../qxexception.h \
    ../backtraceresultrecord.h \
    ../symbolrecord.h \
    ../symboltable.h

