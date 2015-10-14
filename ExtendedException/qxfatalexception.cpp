#include "qxfatalexception.h"

namespace vToolKit{

QxFatalException::QxFatalException(const char *method, int line,
                                   QString what_arg)
    : QxException(method, line, what_arg) {  }

QxFatalException::QxFatalException(QString method, int line, QString what_arg)
    : QxException(method, line, what_arg) {  }

QxFatalException::~QxFatalException() throw() {  }
}

