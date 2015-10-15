#ifndef CLOG_ILOG_H
#define CLOG_ILOG_H

//
// Created by fac on 8/19/15.
//

#include <exception>
#include <string>

#include "toolkitmacros.h"
#include "qxexception.h"
using namespace std;

namespace vToolKit{

    /**
     * Interface for logging classes.
     */
    class iLog {

    public:

        virtual ~iLog() {}

        /**
         * @param string func : The calling method name. Gcc compilers can
         * use __PRETTY_FUNCTION__.
         * @param int line : The line this method is called from. Gcc
         * compilers can use __LINE__.
         * @param string msg : The entry to add to the log.
         */
        virtual void logInfo(string func, int line, string msg) = 0;
        virtual void logInfo(string func, int line, QString msg) = 0;

        /**
         * @param string func : The calling method name. Gcc compilers can
         * use __PRETTY_FUNCTION__.
         * @param int line : The line this method is called from. Gcc
         * compilers can use __LINE__.
         * @param string msg : The entry to add to the log.
         */
        virtual void logDebug(string func, int line, string msg) = 0;
        virtual void logDebug(string func, int line, QString msg) = 0;

        /**
         * @param string func : The calling method name. Gcc compilers can
         * use __PRETTY_FUNCTION__.
         * @param int line : The line this method is called from. Gcc
         * compilers can use __LINE__.
         * @param string msg : The entry to add to the log.
         */
        virtual void logWarn(string func, int line, string msg) = 0;
        virtual void logWarn(string func, int line, QString msg) = 0;

        /**
         * @param string func : The calling method name. Gcc compilers can
         * use __PRETTY_FUNCTION__.
         * @param int line : The line this method is called from. Gcc
         * compilers can use __LINE__.
         * @param exception ex : The exception for this error. The log entry
         * will be obtained from exception::what().
         */
        virtual void logError(string func, int line, exception ex) = 0;

        /**
         * @param string func : The calling method name. Gcc compilers can
         * use __PRETTY_FUNCTION__.
         * @param int line : The line this method is called from. Gcc
         * compilers can use __LINE__.
         * @param string msg : The entry to add to the log.
         */
        virtual void logError(string func, int line, string msg) = 0;
        virtual void logError(string func, int line, QString msg) = 0;
        virtual void logError(QxException ex) = 0;

        /**
         * @param string func : The calling method name. Gcc compilers can
         * use __PRETTY_FUNCTION__.
         * @param int line : The line this method is called from. Gcc
         * compilers can use __LINE__.
         * @param exception ex : The exception for this error. The log entry
         * will be obtained from exception::what().
         */
        virtual void logFatal(string func, int line, exception ex) = 0;

        /**
         * @param string func : The calling method name. Gcc compilers can
         * use __PRETTY_FUNCTION__.
         * @param int line : The line this method is called from. Gcc
         * compilers can use __LINE__.
         * @param string msg : The entry to add to the log.
         */
        virtual void logFatal(string func, int line, string msg) = 0;
        virtual void logFatal(string func, int line, QString msg) = 0;
        virtual void logFatal(QxException ex) = 0;

        /**
         * @brief isNull
         *
         * Null logs are instantiated inside default constructors and null
         * classes.
         *
         * They will not log anything.
         *
         * @return will return true on this function.
         * All other log classes will return false.
         */
        virtual bool isNull() = 0;
    };

}


#endif //CLOG_ILOG_H
