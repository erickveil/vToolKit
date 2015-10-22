#-------------------------------------------------
#
# Project created by QtCreator 2015-10-22T08:30:11
#
#-------------------------------------------------

QT       -= gui
QT += network

TARGET = ITalkAsyncToListener
TEMPLATE = lib
CONFIG += staticlib

SOURCES += italkasynctolistener.cpp \
    irunconcurrent.cpp \
    asyncsocketclient.cpp \
    ../ITalkToListener/synchronoussocketclient.cpp

HEADERS += italkasynctolistener.h \
    irunconcurrent.h \
    asyncsocketclient.h \
    ../clogger/iLog.h \
    ../ITalkToListener/italktolistener.h \
    ../ITalkToListener/synchronoussocketclient.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

INCLUDEPATH +=\
    ../\
    ../clogger\
    ../ExtendedException\
    ../ITalkToListener\

QMAKE_CXXFLAGS += -std=c++11
