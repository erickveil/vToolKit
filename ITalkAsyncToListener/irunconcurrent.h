#ifndef IRUNCONCURRENT
#define IRUNCONCURRENT

#include <QThread>


namespace vToolKit{

    /**
     * @brief The IRunConcurrent class
     *
     * Interface for concurrent operations.
     *
     * This interface should be inherited by other interfaces which intend to
     * perform a more specific concurrent operation.
     * Eg: An Asynchronous Socket Client or an Asynchronous Database Querry.
     *
     * This interface removes the need to connect signals and slots to control
     * your concurrent operation. Just override the eventThread start and stop
     * slots with calls to your logic.
     *
     * Worker classes must be derived from QObject in order that they inherit
     * QObject::moveToThread().
     *
     * Once instantiated, just initChild(), then startThread().
     *
     * You will still need to lock any shared variables if using them.
     */
    class IRunConcurrent : public QObject
    {
    public:
        /**
         * @brief ~IRunConcurrent
         *
         * Calls an QThread::exit() and QThread::wait() on
         * IRunConcurrent::_thread if it is still running.
         */
        virtual ~IRunConcurrent() {}

        /**
         * @brief startThread
         *
         * Simply invokes QThread::start() on the thread, which begins
         * the operation.
         *
         * The class should be first initialized with a worker class and
         * any other necessary data, using a class-specific initializer.
         */
        virtual void startWorker() = 0;

        /**
         * @brief isNull
         *
         * The class is null if it has not yet been initialized.
         *
         * A good test of null is if the worker class has not been
         * assigned and returns true on isNull.
         *
         * @return bool : True if this is a null object.
         */
        virtual bool isNull() = 0;

    public slots:
        /**
         * @brief eventThreadStart
         *
         * Override this method with a call to begin the operation that is to
         * occur on the new thread.
         * When the operation concludes, be sure to call QThread::exit(), and
         * QThread()::wait().
         */
        virtual void eventThreadStart() = 0;

        /**
         * @brief eventThreadFinished
         *
         * Override this method with anything that should happen when the
         * thread exits.
         *
         * Often, it will be an empty method.
         */
        virtual void eventThreadFinished() = 0;

    };
}

#endif // IRUNCONCURRENT

