#ifndef SYNCHRONOUSSOCKETCLIENT_H
#define SYNCHRONOUSSOCKETCLIENT_H

#include <cstring>

#include <QHostAddress>
#include <QTcpSocket>
#include <QUrl>

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
        SynchronousSocketClient();
        SynchronousSocketClient(iLog &log);
        ~SynchronousSocketClient() override;

        void init(iLog &log);
        /**
         * @brief setConnectInfo
         *
         * @param full_address QString : Provide the full socket address in
         * IPv4 format, with the port separated with a colon.
         * ie: 127.0.0.1:50000
         */
        void setConnectInfo(QString full_address, int timeout_ms) override;
        QString sendAndReceive(QString msg) override;
        QByteArray sendAndReceive(QByteArray msg) override;
        char * sendAndReceive(char* msg, int msg_len) override;
        bool isNull() override;

    private:
        QUrl _socket_address;
        QTcpSocket _resource;
        int _timeout_ms;
        QByteArray _outbox;
        QByteArray _response;
        iLog *_log;

        void _validateAddressParameter();
        void _sendData();
        void _validateConnectInfoSet();
        QByteArray _receiveResponse();
        int _waitForInput();
        void _readBytesFromSocket(int bytes_available);
        void _doSendAndRecieve();
        void _clearBuffers();

    };

}

#endif // SYNCHRONOUSSOCKETCLIENT_H
