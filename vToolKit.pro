#-------------------------------------------------
#
# Project created by QtCreator 2015-10-14T11:42:36
#
#-------------------------------------------------

QT       -= gui

TARGET = vToolKit
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    ExtendedException/qxfatalexception.cpp \
    ExtendedException/qxexception.cpp \
    IFlatFile/logfilefield.cpp \
    IFlatFile/logfilerecord.cpp \
    FileCtl/TextFile.cpp \
    clogger/fileLog.cpp

HEADERS += \
    clogger/iLog.h \
    ExtendedException/qxfatalexception.h \
    ExtendedException/qxexception.h \
    IFlatFile/iflatfilerecord.h \
    IFlatFile/iflatfilefield.h \
    IFlatFile/logfilefield.h \
    IFlatFile/iflatfile.h \
    IFlatFile/logfilerecord.h \
    FileCtl/TextFile.h \
    clogger/testLog.h \
    clogger/fileLog.h \
    FileCtl/IReadWriteFile.h \
    clogger/nulllog.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

INCLUDEPATH += ./clogger \
    ./ExtendedException \
    ./FileCtl \
    ./IFlatFile \

QMAKE_CXXFLAGS += -std=c++11

