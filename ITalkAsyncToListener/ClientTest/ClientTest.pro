#-------------------------------------------------
#
# Project created by QtCreator 2015-10-22T13:58:51
#
#-------------------------------------------------

QT       += core
QT += network

QT       -= gui

TARGET = ClientTest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    ../asyncsocketclient.cpp \
    ../../clogger/fileLog.cpp \
    ../../FileCtl/TextFile.cpp \
    ../../ITalkToListener/synchronoussocketclient.cpp \
    ../../ExtendedException/qxexception.cpp \
    ../../ExtendedException/qxfatalexception.cpp \
    responsereader.cpp

INCLUDEPATH +=\
    ../\
    ../../\
    ../../clogger\
    ../../ExtendedException\
    ../../ITalkToListener\
    ../../FileCtl/\

QMAKE_CXXFLAGS += -std=c++11

HEADERS += \
    ../asyncsocketclient.h \
    ../../clogger/fileLog.h \
    ../../clogger/iLog.h \
    ../../FileCtl/IReadWriteFile.h \
    ../../FileCtl/TextFile.h \
    ../../ITalkToListener/italktolistener.h \
    ../../ITalkToListener/synchronoussocketclient.h \
    ../../ExtendedException/qxexception.h \
    ../../ExtendedException/qxfatalexception.h \
    responsereader.h
