#include "asyncsocketclient.h"

namespace vToolKit{

    AsyncSocketClient::AsyncSocketClient(iLog *log, QString id,
                                         ITalkToListener *client,
                                         QByteArray msg, QObject *parent)
    {
        _log=log;
        _worker_id=id;
        _client=client;
        _msg=msg;
        _is_connected=false;
    }

    AsyncSocketClient::~AsyncSocketClient()
    {
        _thread.exit();
        _thread.wait();
    }

    void AsyncSocketClient::startWorker()
    {
        _lazyConnectSlots();
        _client->moveToThread(&_thread);
        _thread.start();
    }

    bool AsyncSocketClient::isNull()
    {
        return false;
    }

    void AsyncSocketClient::eventThreadStart()
    {
        _sendMessage();
    }

    void AsyncSocketClient::eventThreadFinished()
    {

    }
    ITalkToListener *AsyncSocketClient::client()
    {
        return _client;
    }
    
    void AsyncSocketClient::_sendMessage()
    {
        QByteArray response=_client->sendAndReceive(_msg);
        emit finishedTalking(_worker_id, response);
        _thread.exit();
    }

    void AsyncSocketClient::_lazyConnectSlots()
    {
        if(_is_connected) return;
        connect (
                    &_thread, SIGNAL( started() ),
                    this, SLOT( eventThreadStart() )
                    );
        connect (
                    &_thread, SIGNAL( finished() ),
                    this, SLOT( eventThreadFinished() )
                    );
        _is_connected=true;
    }

}
