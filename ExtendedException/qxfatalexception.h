#ifndef QXFATALEXCEPTION_H
#define QXFATALEXCEPTION_H

#include <execinfo.h>
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
    QString _method;
    QString _trace;
    int _line;

 public:
    QxFatalException(const char* method, int line, QString what_arg) throw();
    QxFatalException(QString method, int line, QString what_arg) throw();
    ~QxFatalException() throw();
    QString method() const;
    QString trace() const;
    int line() const;

 private:
    void _generateTrace();
};

}  // vToolKit
#endif  // QXFATALEXCEPTION_H
