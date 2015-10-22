#ifndef ITALKASYNCTOLISTENER_H
#define ITALKASYNCTOLISTENER_H

#include "iLog.h"
#include "italktolistener.h"
#include "irunconcurrent.h"


namespace vToolKit{

    /**
     * @brief The ITalkAsyncToListener class
     *
     * Provided an ITalkToListener interface, executes that interface and
     * allows continuation of the current thread, emitting a signal when the
     * exchange is complete.
     */
    class ITalkAsyncToListener : public IRunConcurrent
    {
    public:
        virtual ~ITalkAsyncToListener() {}

        /**
         * @brief initClient
         *
         * Initializes the class with the data necessary to start its job.
         *
         * @param log iLog : Responsible for logging.
         * @param id QString : Provide an id for the thread/worker. This id is
         * emitted with the qurey result and helps a connected slot to decide
         * which thread/worker returned the data.
         * @param client ITalkToListener : The worker class to be assigned to
         * the thread.
         * @param msg QByteArray : The query string or data to be sent over the
         * socket.
         */
        virtual void initClient(iLog *log, QString id, ITalkToListener *client,
                                QByteArray msg) = 0;

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

#endif // ITALKASYNCTOLISTENER_H
