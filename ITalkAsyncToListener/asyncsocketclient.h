#ifndef ASYNCSOCKETCLIENT_H
#define ASYNCSOCKETCLIENT_H

#include <QObject>
#include <QThread>

#include "iLog.h"
#include "italktolistener.h"
#include "italkasynctolistener.h"

namespace vToolKit{

    class AsyncSocketClient
            : public QObject
            , public ITalkAsyncToListener
    {
        Q_OBJECT
    public:
        AsyncSocketClient(QObject *parent = 0);
        ~AsyncSocketClient() override;

        /**
         * @brief initClient
         *
         * @param log iLog : Responsible for logging in this class.
         * @param id QString : A unique identifier for this worker. That way,
         * if multiple threads of similar tasks are started, the slot can
         * decide what to do with the data when the response is emitted on a
         * signal.
         * @param client ITalkToListener : Should already have initClient()
         * called on it already.
         * @param msg QByteArray : The message to send to the listener.
         */
        void initClient(iLog *log, QString id, ITalkToListener *client,
                        QByteArray msg) override;

        void startWorker() override;
        bool isNull() override;

    public slots:
        void eventThreadStart() override;
        void eventThreadFinished() override;

    signals:
        void finishedTalking(QString id, QByteArray response);

    private:
        iLog *_log;
        QString _worker_id;
        ITalkToListener *_client;
        QByteArray _msg;
        QThread _thread;
        void _sendMessage();
        void _validateInitCalled();
    };

}

#endif // ASYNCSOCKETCLIENT_H
