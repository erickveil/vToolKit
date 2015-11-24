#ifndef ITALKTOLISTENER_H
#define ITALKTOLISTENER_H

#include <QString>
#include <QByteArray>
#include <QObject>


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
    class ITalkToListener : public QObject
    {

    public:
        virtual ~ITalkToListener() {}

        virtual QString sendAndReceive(QString msg) = 0;
        virtual QByteArray sendAndReceive(QByteArray msg) = 0;
        virtual char * sendAndReceive(char * msg, int msg_len) = 0;
        virtual bool isNull() = 0;

        /**
         * Provides an identifier for the client, based off of its connection
         * information.
         *
         * For example: A socket client might return an ip:port string.
         * A pipe might return the pipe name. A file might return a file name.
         * A database might return a table name.
         *
         * @brief getIdentifier
         * @return The identifier for the object that is controlled by this
         * interface. There is no guarantee that this identifier is unique.
         */
        virtual QString getIdentifier() const;

    };

}

#endif // ITALKTOLISTENER_H
