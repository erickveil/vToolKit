#ifndef SYNCHRONOUSSOCKETCLIENT_H
#define SYNCHRONOUSSOCKETCLIENT_H

#include <cstring>

#include <QHostAddress>
#include <QTcpSocket>

#include "iLog.h"
#include "italktolistener.h"
#include "nulllog.h"
#include "qxexception.h"


namespace vToolKit{

    /**
     * @brief The SynchronousSocketClient class
     *
     * Communicates with a socket listener and waits for a response.
     * Responses are collected as bytes, with no regard whether or not they
     * translate to newlines or null characters, and cast on return.
     */
    class SynchronousSocketClient : public ITalkToListener
    {
    public:
        SynchronousSocketClient(iLog *log, QHostAddress host, int port,
                                int timeout_ms);
        ~SynchronousSocketClient() override;

        QString sendAndReceive(QString msg) override;
        QByteArray sendAndReceive(QByteArray msg) override;
        char * sendAndReceive(char* msg, int msg_len) override;
        bool isNull() override;

    private:
        iLog *_log;
        QHostAddress _socket_address;
        int _port;
        int _timeout_ms;
        QByteArray _outbox;
        QByteArray _response;
        QTcpSocket _resource;

        void _validateHostAddress();
        void _sendData();
        QByteArray _receiveResponse();
        int _waitForInput();
        void _readBytesFromSocket(int bytes_available);
        void _doSendAndRecieve();
        void _clearBuffers();
        void _validateFullAddress();
        QString _getLogableData();

    };

}

#endif // SYNCHRONOUSSOCKETCLIENT_H
