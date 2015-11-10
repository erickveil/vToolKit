#include "qxexception.h"

namespace vToolKit{

    QxException::QxException(const char *method, int line, QString what_arg)
        : QxFatalException(method, line, what_arg) {  }

    QxException::QxException(QString method, int line, QString what_arg)
        : QxFatalException(method, line, what_arg) {  }

    QxException::~QxException() throw() {  }


}
