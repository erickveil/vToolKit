#ifndef QXFATALEXCEPTION_H
#define QXFATALEXCEPTION_H

#include <execinfo.h>
#include <stdexcept>

#include <QString>

#include "backtraceresultrecord.h"
#include "symboltable.h"

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

    /**
     * @brief trace
     *
     * Note: If for some reason the program name cannot be obtained through
     * QCoreApplication, then the trace will only consist of a list of hex
     * addresses. You can still use these addresses to look up symbols
     * manually with `nm`, but it sucks.
     *
     * The traces will contain an array number, the address, and the method
     * name.
     * If we need to, we can also easily add in the library name and/or path
     * by modifying this method's implementation.
     *
     * @return A string showing the stack trace from the exception to the
     * starting call.
     */
    QString trace() const;

    int line() const;

 private:
    void _generateTrace();

};

}  // vToolKit
#endif  // QXFATALEXCEPTION_H
