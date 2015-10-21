#include "synchronoussocketclient.h"


namespace vToolKit{


    SynchronousSocketClient::SynchronousSocketClient()
    {
        _log=new NullLog;
    }

    SynchronousSocketClient::SynchronousSocketClient(iLog *log)
    {
        _log=log;
    }

    SynchronousSocketClient::~SynchronousSocketClient()
    {
        if(_resource.isOpen()) _resource.close();
        if(_log->isNull()) delete _log;
    }

    void SynchronousSocketClient::initClient(iLog *log)
    {
        _log=log;
    }

    void SynchronousSocketClient::setConnectInfo(QString full_address,
                                                 int timeout_ms)
    {
        _provided_address=full_address;
        _validateFullAddress();

        _setHostAddress();
        _setPort();

        _timeout_ms=timeout_ms;
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
        return _socket_address.isNull();
    }

    void SynchronousSocketClient::_validateAddressParameter()
    {
        bool is_valid=(
                QAbstractSocket::IPv4Protocol==_socket_address.protocol()
                || QAbstractSocket::IPv6Protocol==_socket_address.protocol());

        if(is_valid) return;

        QString err_msg=QString("Socket address is not valid. ")
                +"Provided address is: "+_provided_address;
        throw QxException(__PRETTY_FUNCTION__,__LINE__,err_msg);
    }

    void SynchronousSocketClient::_sendData()
    {
        if(_outbox.isEmpty()) return;
        QString me=__PRETTY_FUNCTION__;
        QString throw_msg;

        _validateConnectInfoSet();
        _resource.connectToHost( _socket_address, _port );
        bool is_connected=_resource.waitForConnected(_timeout_ms);

        if(!is_connected){
            throw_msg=QString("Failed to connect to host: ")
                    +_socket_address.toString()+" port: "+QString::number(_port)
                    +" timeout: "+QString::number(_timeout_ms)+" ms. "
                    +_resource.errorString();
            throw QxException(me,__LINE__,throw_msg);
        }

        bool is_success=(_resource.write(_outbox)!=-1);
        bool is_timeout=!_resource.waitForBytesWritten(_timeout_ms);

        if(is_timeout){
            throw_msg=QString("Socket write timed out: ")
                    +_provided_address+" messge: "+_outbox
                    +" timeout: "+QString::number(_timeout_ms)+" ms "
                    +_resource.errorString();
            throw QxException(me,__LINE__,throw_msg);

        }

        if(!is_success){
            throw_msg=QString("Failed to write to host: ")
                    +_provided_address+" messge: "+_outbox
                    +" "+_resource.errorString();
            throw QxException(me,__LINE__,throw_msg);
        }

        QString debug=QString("Sent: <<")+_outbox+">> to: "
                +_provided_address+" hex: "+_outbox.toHex();
        _log->logDebug(__PRETTY_FUNCTION__,__LINE__,debug);
    }

    void SynchronousSocketClient::_validateConnectInfoSet()
    {
        if(!isNull()) return;
        QString msg=QString("Attempting to connect to a socket without first ")
                +"calling setConnectInfo()";
        throw QxException(__PRETTY_FUNCTION__,__LINE__,msg);
    }

    QByteArray SynchronousSocketClient::_receiveResponse()
    {
        int bytes_available=_waitForInput();
        if(bytes_available > 0) _readBytesFromSocket(bytes_available);

        QString debug=QString("Received: <<")+_response+">> From: "
                +_provided_address+" hex: "+_response.toHex();
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

    void SynchronousSocketClient::_validateFullAddress()
    {
        QStringList split_addy=_provided_address.split(":");
        if(split_addy.size()==2) return;
        QString msg=QString("Provided address format is bad. Should be in ")
                +"the 'host:port' form. Address: "
                +_provided_address;
        throw QxException(__PRETTY_FUNCTION__,__LINE__,msg);
    }

    void SynchronousSocketClient::_setHostAddress()
    {
        QStringList split_addy=_provided_address.split(":");
        _socket_address.setAddress(split_addy.at(0));
        _validateAddressParameter();
    }

    void SynchronousSocketClient::_setPort()
    {
        QStringList split_addy=_provided_address.split(":");
        bool is_converted;
        _port=split_addy.at(1).toInt(&is_converted);
        if(is_converted) return;
        QString msg=QString("Port is invalid: ")+split_addy.at(1)
                +" from provided address: "+_provided_address;
        throw QxException(__PRETTY_FUNCTION__,__LINE__,msg);
    }








}
