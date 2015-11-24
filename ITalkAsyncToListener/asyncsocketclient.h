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
        /**
         * @brief AsyncSocketClient
         *
         * @param log iLog : Responsible for logging in this class.
         * @param id QString : A unique identifier for this worker. That way,
         * if multiple threads of similar tasks are started, the slot can
         * decide what to do with the data when the response is emitted on a
         * signal.
         * @param client ITalkToListener : Should already have initClient()
         * called on it already.
         * @param msg QByteArray : The message to send to the listener.
         * @param parent
         */
        AsyncSocketClient(iLog *log, QString id, ITalkToListener *client,
                          QByteArray msg, QObject *parent = 0);
        ~AsyncSocketClient() override;
        void startWorker() override;
        bool isNull() override;

        ITalkToListener *client() const override;

    public slots:
        void eventThreadStart() override;
        void eventThreadFinished() override;

    signals:
        void finishedTalking(QString id, QByteArray response);

    private:
        iLog *_log;
        QString _worker_id;
        // todo: getter needed - ITalkAsyncToListener
        ITalkToListener *_client;

        QByteArray _msg;
        QThread _thread;
        bool _is_connected;
        void _sendMessage();
        void _lazyConnectSlots();
    };

}

#endif // ASYNCSOCKETCLIENT_H
