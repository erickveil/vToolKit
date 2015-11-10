#ifndef QXFATALEXCEPTION_H
#define QXFATALEXCEPTION_H

#include <stdexcept>
#include <QString>

namespace vToolKit{

    /**
     * @brief The QxFatalException class
     *
     * A Qt based exception, used for topmost level failures that end the
     * program.
     */
    class QxFatalException : public std::runtime_error
    {
    public:
        QxFatalException(const char* method, int line, QString what_arg) throw();
        QxFatalException(QString method, int line, QString what_arg) throw();
        ~QxFatalException() throw();
        QString method() const;
        int line() const;

    private:
        int _line;
        QString _method;
    };

   }
#endif // QXFATALEXCEPTION_H
