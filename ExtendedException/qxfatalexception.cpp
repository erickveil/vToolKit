#include "qxfatalexception.h"

namespace vToolKit{

    QxFatalException::QxFatalException(const char* method, int line, QString what_arg)
    throw() : runtime_error(what_arg.toStdString())
    {
        _method=method;
        _line=line;
        _generateTrace();
    }

    QxFatalException::QxFatalException(QString method, int line, QString what_arg)
    throw() : runtime_error(what_arg.toStdString())
    {
        _method=method;
        _line=line;
        _generateTrace();
    }

    QxFatalException::~QxFatalException() throw()
    {
    }

    QString QxFatalException::method() const
    {
        return _method;
    }

    QString QxFatalException::trace() const
    {
        return _trace;
    }

    int QxFatalException::line() const
    {
        return _line;
    }

    void QxFatalException::_generateTrace()
    {
        // generate backtrace
        void *array[200];
        size_t size;
        char **strings;
        size_t i;

        size = backtrace(array, 200);
        strings = backtrace_symbols(array, size);

        _trace = "";
        QString delim = "\n";
        for (i=0; i < size; ++i) {
            _trace += (delim + strings[i]);
        }

        free(strings);
    }
}

