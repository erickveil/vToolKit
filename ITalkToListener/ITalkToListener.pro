#-------------------------------------------------
#
# Project created by QtCreator 2015-10-21T09:22:29
#
#-------------------------------------------------

QT       -= gui
QT += network

TARGET = ITalkToListener
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    synchronoussocketclient.cpp \
    ../ExtendedException/qxexception.cpp \
    ../ExtendedException/qxfatalexception.cpp \
    ../clogger/fileLog.cpp

HEADERS += italktolistener.h \
    synchronoussocketclient.h \
    ../ExtendedException/qxexception.h \
    ../ExtendedException/qxfatalexception.h \
    ../clogger/fileLog.h \
    ../clogger/iLog.h \
    ../clogger/nulllog.h \
    ../toolkitmacros.h \
    ../FileCtl/IReadWriteFile.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

QMAKE_CXXFLAGS += -std=c++11
INCLUDEPATH += \
    ../\
    ../ExtendedException \
    ../clogger \
    ../FileCtl

