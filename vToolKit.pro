#-------------------------------------------------
#
# Project created by QtCreator 2015-10-14T11:42:36
#
#-------------------------------------------------

QT       -= gui
QT += network

TARGET = vToolKit
TEMPLATE = lib
CONFIG += staticlib
QMAKE_CXXFLAGS += -rdynamic

SOURCES += \
    ExtendedException/qxfatalexception.cpp \
    ExtendedException/qxexception.cpp \
    IFlatFile/logfilerecord.cpp \
    FileCtl/TextFile.cpp \
    clogger/fileLog.cpp \
    IFlatFile/logfile.cpp \
    version.cpp \
    ITalkToListener/synchronoussocketclient.cpp \
    ITalkAsyncToListener/asyncsocketclient.cpp \
    ExtendedException/backtraceresultrecord.cpp \
    ExtendedException/symbolrecord.cpp \
    ExtendedException/symboltable.cpp

HEADERS += \
    ExtendedException/qxfatalexception.h \
    ExtendedException/qxexception.h \
    IFlatFile/iflatfilerecord.h \
    IFlatFile/iflatfile.h \
    IFlatFile/logfilerecord.h \
    FileCtl/TextFile.h \
    clogger/testLog.h \
    clogger/fileLog.h \
    FileCtl/IReadWriteFile.h \
    clogger/nulllog.h \
    IFlatFile/logfile.h \
    version.h \
    toolkitmacros.h \
    ITalkToListener/synchronoussocketclient.h \
    ITalkAsyncToListener/asyncsocketclient.h \
    ITalkAsyncToListener/irunconcurrent.h \
    ITalkAsyncToListener/italkasynctolistener.h \
    ITalkToListener/italktolistener.h \
    clogger/ILog.h \
    ExtendedException/backtraceresultrecord.h \
    ExtendedException/symbolrecord.h \
    ExtendedException/symboltable.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

INCLUDEPATH += ./clogger \
    ./ExtendedException \
    ./FileCtl \
    ./IFlatFile \
    ./ITalkToListener \
    ./ITalkAsyncToListener

QMAKE_CXXFLAGS += -std=c++11

