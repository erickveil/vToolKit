#ifndef QXEXCEPTION_H
#define QXEXCEPTION_H


#include "qxfatalexception.h"

using namespace std;


namespace vToolKit{

    /**
     * @brief The QxException class
     *
     * A Qt based exception that captures the method name and line where thrown.
     *
     */
    class QxException: public QxFatalException
    {

    public:
        QxException(const char* method, int line, QString what_arg);
        QxException(QString method, int line, QString what_arg);
        ~QxException() throw();
    };
}

#endif // QXEXCEPTION_H
