#include "qxfatalexception.h"

namespace vToolKit{

    QxFatalException::QxFatalException(const char* method, int line, QString what_arg)
    throw() : runtime_error(what_arg.toStdString())
    {
        _method=method;
        _line=line;
    }

    QxFatalException::QxFatalException(QString method, int line, QString what_arg)
    throw() : runtime_error(what_arg.toStdString())
    {
        _method=method;
        _line=line;
    }

    QxFatalException::~QxFatalException() throw()
    {

    }

    QString QxFatalException::method() const
    {
        return _method;
    }

    int QxFatalException::line() const
    {
        return _line;
    }
}

