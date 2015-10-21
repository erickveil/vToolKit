#ifndef ITALKTOLISTENER_H
#define ITALKTOLISTENER_H

#include <QString>
#include <QByteArray>


namespace vToolKit{

    /**
     * @brief The ITalkToListener class
     *
     * Interface for socket clients, or any other client that delivers data to a
     * process that is somehow listening, and might
     * respond. Could be a socket, or a pipe, or a file; Whatever you might
     * use to transfer data between two processes.
     *
     * Since the responses are returned, an ITalkToListener based class is
     * unlikely to be concurrent if a response is expected.
     */
    class ITalkToListener
    {

    public:
        ITalkToListener();
        virtual ~ITalkToListener() {}

        virtual void init(iLog &log) = 0;
        virtual void setConnectInfo(QString full_address, int timeout_ms) = 0;
        virtual QString sendAndReceive(QString msg) = 0;
        virtual QByteArray sendAndReceive(QByteArray msg) = 0;
        virtual char * sendAndReceive(char * msg, int msg_len) = 0;
        virtual bool isNull() = 0;

    };

}

#endif // ITALKTOLISTENER_H
