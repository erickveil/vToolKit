#ifndef ITALKASYNCTOLISTENER_H
#define ITALKASYNCTOLISTENER_H

#include "ILog.h"
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
         * Allows access to the ITalkToListener interface that is being
         * asynchronously handled.
         *
         * @brief client
         * @return
         */
        virtual ITalkToListener *client() = 0;

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
