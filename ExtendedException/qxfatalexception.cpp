#include "qxfatalexception.h"

namespace vToolKit{

    QxFatalException::QxFatalException(const char* method, int line,
                                       QString what_arg)
    throw() : runtime_error(what_arg.toStdString())
    {
        _method=method;
        _line=line;
        _generateTrace();
    }

    QxFatalException::QxFatalException(QString method, int line,
                                       QString what_arg)
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
        void *array[200];
        size_t size;
        char **raw_trace_strings;
        size_t i;

        size = backtrace(array, 200);
        raw_trace_strings = backtrace_symbols(array, size);

        _trace = "Stack Trace:";
        QString delim = "\n";
        QList<BackTraceResultRecord> record_list;
        auto prog = QFileInfo(QCoreApplication::applicationFilePath())
                .fileName();
        SymbolTable symbol_table(prog);
        symbol_table.initSymbolTable();

        // each line in the raw trace
        for (i=0; i < size; ++i) {
            // create a clean trace and add it to the list
            BackTraceResultRecord record(raw_trace_strings[i], symbol_table);
            record_list.append(record);
            QString trace_string = QString("[") + QString::number(i) + "] "
                    + record.getHexRecordAddress() + " "
                    + record.getMethodName();
            _trace += (delim + trace_string);
        }

        free(raw_trace_strings);
    }
}

