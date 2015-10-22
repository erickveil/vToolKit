#ifndef ITALKASYNCTOLISTENER_H
#define ITALKASYNCTOLISTENER_H

#include "iLog.h"
#include "italktolistener.h"


namespace vToolKit{

    /**
     * @brief The ITalkAsyncToListener class
     *
     * Provided an ITalkToListener interface, executes that interface and
     * allows continuation of the current thread, emitting a signal when the
     * exchange is complete.
     */
    class ITalkAsyncToListener
    {
    public:
        virtual ~ITalkAsyncToListener() {}

        virtual void initClient(iLog *log, QString id, ITalkToListener *client,
                                QByteArray msg) = 0;
        virtual void startWorker() = 0;
        virtual bool isNull() = 0;

    public slots:
        virtual void eventThreadStart() = 0;
        virtual void eventThreadFinished() = 0;

    signals:
        /**
         * @brief finishedTalking
         *
         * Signal to be emitted when the query is complete.
         *
         * Seems to only work if overridden in the child class.
         *
         * @param id QString : An id to identify the thread/worker who is
         * responding, in case there are a lot of similar querries going out
         * at once.
         * @param response
         */
        void finishedTalking(QString id, QByteArray response);
    };


}

//using namespace vToolKit;
//Q_DECLARE_INTERFACE(ITalkAsyncToListener, "ITalkAsyncToListener")

#endif // ITALKASYNCTOLISTENER_H
