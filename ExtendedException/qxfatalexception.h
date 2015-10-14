#ifndef QXFATALEXCEPTION_H
#define QXFATALEXCEPTION_H

#include "qxexception.h"

namespace vQtTools{

    /**
     * @brief The QxFatalException class
     *
     * A Qt based exception, used for topmost level failures that end the
     * program.
     */
    class QxFatalException : public QxException
    {
    public:
        QxFatalException(const char* method, int line, QString what_arg);
        QxFatalException(QString method, int line, QString what_arg);
        ~QxFatalException() throw();
    };

   }
#endif // QXFATALEXCEPTION_H
