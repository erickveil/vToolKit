#-------------------------------------------------
#
# Project created by QtCreator 2015-10-21T13:59:41
#
#-------------------------------------------------

QT       += core
QT       -= gui
QT += network

TARGET = SocketTest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    ../synchronoussocketclient.cpp \
    ../../clogger/fileLog.cpp \
    ../../ExtendedException/qxexception.cpp \
    ../../ExtendedException/qxfatalexception.cpp \
    ../../FileCtl/TextFile.cpp

INCLUDEPATH += \
    ../\
    ../../\
    ../../clogger\
    ../../FileCtl\
    ../../ExtendedException\

QMAKE_CXXFLAGS += -std=c++11

HEADERS += \
    ../italktolistener.h \
    ../synchronoussocketclient.h \
    ../../clogger/fileLog.h \
    ../../clogger/iLog.h \
    ../../clogger/nulllog.h \
    ../../ExtendedException/qxexception.h \
    ../../ExtendedException/qxfatalexception.h \
    ../../FileCtl/IReadWriteFile.h \
    ../../FileCtl/TextFile.h
