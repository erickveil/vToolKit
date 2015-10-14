//
// Created by fac on 8/19/15.
//

#include <exception>
#include <string>

#ifndef CLOG_ILOG_H
#define CLOG_ILOG_H

using namespace std;

/**
 * Namespaces follow naming convention:
 * v        Erick Veil developed namespace
 * Std      Standard libraries only (eg: No Qt)
 * Tools    General tools for common use.
 */
namespace vStdTools {

    /**
     * Interface for logging classes.
     */
    class iLog {

    public:

        /**
         * @param string func : The calling method name. Gcc compilers can
         * use __PRETTY_FUNCTION__.
         * @param int line : The line this method is called from. Gcc
         * compilers can use __LINE__.
         * @param string msg : The entry to add to the log.
         */
        virtual void logInfo(string func, int line, string msg) = 0;

        /**
         * @param string func : The calling method name. Gcc compilers can
         * use __PRETTY_FUNCTION__.
         * @param int line : The line this method is called from. Gcc
         * compilers can use __LINE__.
         * @param string msg : The entry to add to the log.
         */
        virtual void logDebug(string func, int line, string msg) = 0;

        /**
         * @param string func : The calling method name. Gcc compilers can
         * use __PRETTY_FUNCTION__.
         * @param int line : The line this method is called from. Gcc
         * compilers can use __LINE__.
         * @param string msg : The entry to add to the log.
         */
        virtual void logWarn(string func, int line, string msg) = 0;

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
    };

}


#endif //CLOG_ILOG_H
