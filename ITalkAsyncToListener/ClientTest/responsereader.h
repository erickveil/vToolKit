#ifndef RESPONSEREADER_H
#define RESPONSEREADER_H

#include <QObject>
#include <QDebug>
#include <asyncsocketclient.h>

using namespace vToolKit;

    class ResponseReader : public QObject
    {
        Q_OBJECT
    public:
        ResponseReader(AsyncSocketClient *async_client, QObject *parent = 0 );
        ~ResponseReader();

    signals:

    public slots:
        void eventSocketResponse(QString id, QByteArray msg);
    };


#endif // RESPONSEREADER_H
