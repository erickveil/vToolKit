#ifndef ITALKASYNCTOLISTENER_H
#define ITALKASYNCTOLISTENER_H


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
    ITalkAsyncToListener();
};

#endif // ITALKASYNCTOLISTENER_H
