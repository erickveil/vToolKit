#ifndef CLOG_ILOG_H
#define CLOG_ILOG_H

//
// Created by fac on 8/19/15.
//

#include <exception>
#include <string>

#include "toolkitmacros.h"
#include "qxexception.h"
#include "ILog.h"
using namespace std;

namespace vToolKit{

    /**
     * Depreciated, do not use. Use ILog instead.
     *
     * This interface was in use, but does not follow the naming convention
     * for interfaces. Use ILog in your projects, as this interface will
     * eventually be removed.
     */
    class iLog : public ILog {

    public:

        virtual ~iLog() {}
        virtual void logInfo(string func, int line, string msg) = 0;
        virtual void logInfo(string func, int line, QString msg) = 0;
        virtual void logDebug(string func, int line, string msg) = 0;
        virtual void logDebug(string func, int line, QString msg) = 0;
        virtual void logWarn(string func, int line, string msg) = 0;
        virtual void logWarn(string func, int line, QString msg) = 0;
        virtual void logError(string func, int line, exception ex) = 0;
        virtual void logError(string func, int line, string msg) = 0;
        virtual void logError(string func, int line, QString msg) = 0;
        virtual void logError(QxException ex) = 0;
        virtual void logFatal(string func, int line, exception ex) = 0;
        virtual void logFatal(string func, int line, string msg) = 0;
        virtual void logFatal(string func, int line, QString msg) = 0;
        virtual void logFatal(QxException ex) = 0;
        virtual bool isNull() = 0;
    };

}


#endif //CLOG_ILOG_H
