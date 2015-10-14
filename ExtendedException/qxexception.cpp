#include "qxexception.h"

namespace vQtTools{

    QxException::QxException(const char* method, int line, QString what_arg)
    throw() : runtime_error(what_arg.toStdString())
    {
        _method=method;
        _line=line;
    }

    QxException::QxException(QString method, int line, QString what_arg)
    throw() : runtime_error(what_arg.toStdString())
    {
        _method=method;
        _line=line;
    }

    QxException::~QxException() throw()
    {

    }

    QString QxException::method() const
    {
        return _method;
    }

    int QxException::line() const
    {
        return _line;
    }

}
