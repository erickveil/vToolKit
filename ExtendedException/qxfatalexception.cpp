#include "qxfatalexception.h"

namespace vQtTools{

QxFatalException::QxFatalException(const char *method, int line,
                                   QString what_arg)
    : QxException(method, line, what_arg) {  }

QxFatalException::QxFatalException(QString method, int line, QString what_arg)
    : QxException(method, line, what_arg) {  }

QxFatalException::~QxFatalException() throw() {  }
}

