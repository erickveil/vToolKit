#include "asyncsocketclient.h"

namespace vToolKit{

    AsyncSocketClient::AsyncSocketClient(QObject *parent)
        : QObject(parent)
    {
        connect (
                    &_thread, SIGNAL( started() ),
                    this, SLOT( eventThreadStart() )
                    );
        connect (
                    &_thread, SIGNAL( finished() ),
                    this, SLOT( eventThreadFinished() )
                    );
    }

    AsyncSocketClient::~AsyncSocketClient()
    {
        _thread.exit();
        _thread.wait();
    }

    void AsyncSocketClient::initClient(iLog *log, QString id,
                                       ITalkToListener *client, QByteArray msg)
    {
        _log=log;
        _worker_id=id;
        _client=client;
        _msg=msg;

        _client->moveToThread(&_thread);
    }

    void AsyncSocketClient::startWorker()
    {
        _validateInitCalled();
        _thread.start();
    }

    bool AsyncSocketClient::isNull()
    {
        return _client->isNull();
    }

    void AsyncSocketClient::eventThreadStart()
    {
        _sendMessage();
    }

    void AsyncSocketClient::eventThreadFinished()
    {

    }

    void AsyncSocketClient::_sendMessage()
    {
        QByteArray response=_client->sendAndReceive(_msg);
        emit finishedTalking(_worker_id, response);
        _thread.exit();
    }

    void AsyncSocketClient::_validateInitCalled()
    {
        if(!isNull()) return;
        QString msg="Attempt to start async client without initializing.";
        throw QxException(__PRETTY_FUNCTION__,__LINE__,msg);
    }

}
