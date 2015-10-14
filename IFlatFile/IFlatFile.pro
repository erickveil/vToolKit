#-------------------------------------------------
#
# Project created by QtCreator 2015-10-12T13:01:29
#
#-------------------------------------------------

QT       -= gui

TARGET = IFlatFile
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    logfilefield.cpp \
    logfilerecord.cpp

HEADERS += iflatfile.h \
    iflatfilefield.h \
    iflatfilerecord.h \
    logfilefield.h \
    logfilerecord.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

QMAKE_CXXFLAGS += -std=c++11

INCLUDEPATH += ./lib/ExtendedException
LIBS += ../../lib/ExtendedException/libExtendedException.a

