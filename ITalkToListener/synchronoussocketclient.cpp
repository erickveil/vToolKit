#include "synchronoussocketclient.h"


namespace vToolKit{

    SynchronousSocketClient::SynchronousSocketClient(iLog *log,
                                                     QHostAddress host,
                                                     int port, int timeout_ms)
    {
        _log=log;
        _socket_address=host;
        _port=port;
        _timeout_ms=timeout_ms;
    }

    SynchronousSocketClient::~SynchronousSocketClient()
    {
        if(_resource.isOpen()) _resource.close();
        if(_log->isNull()) delete _log;
    }

    QString SynchronousSocketClient::sendAndReceive(QString msg)
    {
        _clearBuffers();
        _outbox.append(msg);
        _doSendAndRecieve();
        return _response;
    }

    QByteArray SynchronousSocketClient::sendAndReceive(QByteArray msg)
    {
        _clearBuffers();
        _outbox.append(msg);
        _doSendAndRecieve();
        return _response;
    }

    char *SynchronousSocketClient::sendAndReceive(char *msg, int msg_len)
    {
        _clearBuffers();
        _outbox.append(msg, msg_len);
        _doSendAndRecieve();
        return _response.data();
    }

    bool SynchronousSocketClient::isNull()
    {
        return false;
    }

    QString SynchronousSocketClient::getIdentifier() const
    {
        return QString(_socket_address.toString())+":"+QString::number(_port);
    }
    
    void SynchronousSocketClient::_validateHostAddress()
    {
        bool is_valid=(
                    QAbstractSocket::IPv4Protocol==_socket_address.protocol()
                    || QAbstractSocket::IPv6Protocol==_socket_address.protocol());

        if(is_valid) return;

        QString err_msg=QString("Host address is not valid. ")
                +"Provided address is: "+_socket_address.toString();
        throw QxException(__PRETTY_FUNCTION__,__LINE__,err_msg);
    }

    void SynchronousSocketClient::_sendData()
    {
        if(_outbox.isEmpty()) return;
        QString me=__PRETTY_FUNCTION__;
        QString throw_msg;

        _validateHostAddress();
        _resource.connectToHost( _socket_address, _port );
        bool is_connected=_resource.waitForConnected(_timeout_ms);

        if(!is_connected){
            throw_msg=QString("Failed to connect to host: ")
                    +_getLogableData()
                    +_resource.errorString();
            throw QxException(me,__LINE__,throw_msg);
        }

        bool is_success=(_resource.write(_outbox)!=-1);
        bool is_timeout=!_resource.waitForBytesWritten(_timeout_ms);

        if(is_timeout){
            throw_msg=QString("Socket write timed out: ")
                    +_getLogableData()
                    +_resource.errorString();
            throw QxException(me,__LINE__,throw_msg);

        }

        if(!is_success){
            throw_msg=QString("Failed to write to host: ")
                    +_getLogableData()
                    +_resource.errorString();
            throw QxException(me,__LINE__,throw_msg);
        }

        QString debug=QString("Sent: <<")+_outbox+">> To: "
                +_socket_address.toString()+":"+QString::number(_port)
                +" hex: "+_outbox.toHex();
        _log->logDebug(__PRETTY_FUNCTION__,__LINE__,debug);
    }

    QByteArray SynchronousSocketClient::_receiveResponse()
    {
        int bytes_available=_waitForInput();
        if(bytes_available > 0) _readBytesFromSocket(bytes_available);

        QString debug=QString("Received: <<")+_response+">> From: "
                +_socket_address.toString()+":"+QString::number(_port)
                +" hex: "+_response.toHex();
        _log->logDebug(__PRETTY_FUNCTION__,__LINE__,debug);

        return _response;
    }

    int SynchronousSocketClient::_waitForInput()
    {
        int bytes_available=-1;

        if(_resource.waitForReadyRead(_timeout_ms)) {
            bytes_available=_resource.bytesAvailable();
        }

        return bytes_available;
    }

    void SynchronousSocketClient::_readBytesFromSocket(int bytes_available)
    {
        int bytes_read=0;
        bool end_of_stream=false;

        while( (bytes_read < bytes_available) && (!end_of_stream) ){
            char ch;
            int new_byte=_resource.read(&ch, sizeof(ch));
            if(new_byte==sizeof(ch)) {
                ++bytes_read;
                _response.append(ch);
            }
            else{ end_of_stream=true; }
        }
    }

    void SynchronousSocketClient::_doSendAndRecieve()
    {
        _sendData();
        _receiveResponse();
        _resource.close();
    }

    void SynchronousSocketClient::_clearBuffers()
    {
        _outbox.clear();
        _response.clear();
    }

    QString SynchronousSocketClient::_getLogableData()
    {
        return QString(" Host: ")+_socket_address.toString()+" Port: "
                +QString::number(_port)+" Timeout: "
                +QString::number(_timeout_ms)+"ms Message: "+_outbox+" (hex: "
                +_outbox.toHex()+") ";
    }

}
