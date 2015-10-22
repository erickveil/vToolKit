#include "responsereader.h"


ResponseReader::ResponseReader(AsyncSocketClient *async_client, QObject *parent)
    : QObject(parent)
{
    connect (
                async_client, SIGNAL( finishedTalking(QString,QByteArray) ),
                this, SLOT( eventSocketResponse(QString, QByteArray) )
                );

}

ResponseReader::~ResponseReader()
{

}

void ResponseReader::eventSocketResponse(QString id, QByteArray msg)
{
    qDebug()<<"ID: "<<id<<" Msg: "<<msg;
    exit(EXIT_SUCCESS);
}

