#ifndef QXEXCEPTION_H
#define QXEXCEPTION_H

#include <stdexcept>
#include <QString>

using namespace std;

namespace vQtTools{

    /**
     * @brief The QxException class
     *
     * A Qt based exception that captures the method name and line where thrown.
     *
     */
    class QxException: public runtime_error
    {

    public:
        QxException(const char* method, int line, QString what_arg) throw();
        QxException(QString method, int line, QString what_arg) throw();
        ~QxException() throw();
        QString method() const;
        int line() const;

    private:
        int _line;
        QString _method;
    };
}

#endif // QXEXCEPTION_H
