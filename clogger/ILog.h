#ifndef ILOG_H
#define ILOG_H


#include <exception>
#include <string>

#include "toolkitmacros.h"
#include "qxexception.h"
using namespace std;

namespace vToolKit{

    /**
     * @brief The ILog class
     * Interface for logging.
     */
    class ILog {
    public:
        virtual ~ILog() {}

        /**
         * Creates an INFO level log entry.
         *
         * Info level logs are for user readable log entries.
         * They should avoid internal and technical details and include human
         * readable information that would be useful to a user.
         *
         * @param string func : The calling method name. Gcc compilers can
         * use __PRETTY_FUNCTION__.
         * @param int line : The line this method is called from. Gcc
         * compilers can use __LINE__.
         * @param string msg : The entry to add to the log.
         */
        virtual void logInfo(string func, int line, string msg) = 0;

        /**
         * Creates an INFO level log entry.
         **
         * Info level logs are for user readable log entries.
         * They should avoid internal and technical details and include human
         * readable information that would be useful to a user.
         *
         * @param string func : The calling method name. Gcc compilers can
         * use __PRETTY_FUNCTION__.
         * @param int line : The line this method is called from. Gcc
         * compilers can use __LINE__.
         * @param QString msg : The entry to add to the log.
         */
        virtual void logInfo(string func, int line, QString msg) = 0;

        /**
         * Creates a DEBUG level log entry.
         *
         * Debug level log entries print to the log, even in a release version.
         * This level of log is used for developers to ensure that both
         * development and releses are running as expected.
         *
         * @param string func : The calling method name. Gcc compilers can
         * use __PRETTY_FUNCTION__.
         * @param int line : The line this method is called from. Gcc
         * compilers can use __LINE__.
         * @param string msg : The entry to add to the log.
         */
        virtual void logDebug(string func, int line, string msg) = 0;

        /**
         * Creates a DEBUG level log entry.
         *
         * Debug level log entries print to the log, even in a release version.
         * This level of log is used for developers to ensure that both
         * development and releses are running as expected.
         *
         * @param string func : The calling method name. Gcc compilers can
         * use __PRETTY_FUNCTION__.
         * @param int line : The line this method is called from. Gcc
         * compilers can use __LINE__.
         * @param QString msg : The entry to add to the log.
         */
        virtual void logDebug(string func, int line, QString msg) = 0;

        /**
         * Creates a WARN level log entry.
         *
         * Warn level log entries are for non fatal errors or problems.
         * To be used when a problem occurs but the program is able to handle
         * it and continue as normal.
         * Warning provide developers clues as to why someting might not be
         * behaving as expected, though everything still "works".
         * In warnings, explain both the problem, and the steps the program
         * has taken to handle the problem.
         *
         * @param string func : The calling method name. Gcc compilers can
         * use __PRETTY_FUNCTION__.
         * @param int line : The line this method is called from. Gcc
         * compilers can use __LINE__.
         * @param string msg : The entry to add to the log.
         */
        virtual void logWarn(string func, int line, string msg) = 0;

        /**
         * Creates a WARN level log entry.
         *
         * Warn level log entries are for non fatal errors or problems.
         * To be used when a problem occurs but the program is able to handle
         * it and continue as normal.
         * Warning provide developers clues as to why someting might not be
         * behaving as expected, though everything still "works".
         * In warnings, explain both the problem, and the steps the program
         * has taken to handle the problem.
         *
         * @param string func : The calling method name. Gcc compilers can
         * use __PRETTY_FUNCTION__.
         * @param int line : The line this method is called from. Gcc
         * compilers can use __LINE__.
         * @param QString msg : The entry to add to the log.
         */
        virtual void logWarn(string func, int line, QString msg) = 0;

        /**
         * Creates an ERROR level log entry.
         *
         * Errors are problems that can't be handled by the program.
         * Often they throw an exception.
         *
         * @param string func : The calling method name. Gcc compilers can
         * use __PRETTY_FUNCTION__.
         * @param int line : The line this method is called from. Gcc
         * compilers can use __LINE__.
         * @param exception ex : The exception for this error. The log entry
         * will be obtained from exception::what().
         */
        virtual void logError(string func, int line, exception ex) = 0;

        /**
         * Creates an ERROR level log entry.
         *
         * Errors are problems that can't be handled by the program.
         * Often they throw an exception.
         *
         * @param string func : The calling method name. Gcc compilers can
         * use __PRETTY_FUNCTION__.
         * @param int line : The line this method is called from. Gcc
         * compilers can use __LINE__.
         * @param string msg : The entry to add to the log.
         */
        virtual void logError(string func, int line, string msg) = 0;

        /**
         * Creates an ERROR level log entry.
         *
         * Errors are problems that can't be handled by the program.
         * Often they throw an exception.
         *
         * @param string func : The calling method name. Gcc compilers can
         * use __PRETTY_FUNCTION__.
         * @param int line : The line this method is called from. Gcc
         * compilers can use __LINE__.
         * @param QString msg : The entry to add to the log.
         */
        virtual void logError(string func, int line, QString msg) = 0;

        /**
         * Creates an ERROR level log entry.
         *
         * Errors are problems that can't be handled by the program.
         * Often they throw an exception.
         *
         * @param exception ex : The exception for this error. The log entry
         * will be obtained from exception::what().
         */
        virtual void logError(QxException ex) = 0;

        /**
         * Creates a FATAL level log entry.
         *
         * Fatal log entries describe events that stop the function of the
         * program.
         * Fatal errors most often take the form of exceptions that have been
         * allowed to bubble all the way up to main, to be caught by the
         * topmost level catch block, where this logging takes place.
         *
         * @param string func : The calling method name. Gcc compilers can
         * use __PRETTY_FUNCTION__.
         * @param int line : The line this method is called from. Gcc
         * compilers can use __LINE__.
         * @param exception ex : The exception for this error. The log entry
         * will be obtained from exception::what().
         */
        virtual void logFatal(string func, int line, exception ex) = 0;

        /**
         * Creates a FATAL level log entry.
         *
         * Fatal log entries describe events that stop the function of the
         * program.
         * Fatal errors most often take the form of exceptions that have been
         * allowed to bubble all the way up to main, to be caught by the
         * topmost level catch block, where this logging takes place.
         *
         * @param string func : The calling method name. Gcc compilers can
         * use __PRETTY_FUNCTION__.
         * @param int line : The line this method is called from. Gcc
         * compilers can use __LINE__.
         * @param string msg : The entry to add to the log.
         */
        virtual void logFatal(string func, int line, string msg) = 0;

        /**
         * Creates a FATAL level log entry.
         *
         * Fatal log entries describe events that stop the function of the
         * program.
         * Fatal errors most often take the form of exceptions that have been
         * allowed to bubble all the way up to main, to be caught by the
         * topmost level catch block, where this logging takes place.
         *
         * @param string func : The calling method name. Gcc compilers can
         * use __PRETTY_FUNCTION__.
         * @param int line : The line this method is called from. Gcc
         * compilers can use __LINE__.
         * @param QString msg : The entry to add to the log.
         */
        virtual void logFatal(string func, int line, QString msg) = 0;

        /**
         * Creates a FATAL level log entry.
         *
         * Fatal log entries describe events that stop the function of the
         * program.
         * Fatal errors most often take the form of exceptions that have been
         * allowed to bubble all the way up to main, to be caught by the
         * topmost level catch block, where this logging takes place.
         *
         * @param exception ex : The exception for this error. The log entry
         * will be obtained from exception::what().
         */
        virtual void logFatal(QxException ex) = 0;

        /**
         * @brief logTrace
         * Creates a TRACE level log entry.
         *
         * Trace log entries usually are logged immediately after any ERROR or
         * FATAL log entry. Rarely do they occur after WARN or DEBUG, and never
         * follow any other entry.
         *
         * If they occur on their own, it can be difficult to understand the
         * reason for the trace. The best bet is to call for a logTrace only
         * from within logError or logFatal method definitions.
         *
         * This version of logTrace will generate its own implementation of a
         * backtrace. Likely obtained using gcc compiling libraries:
         *
         * http://www.gnu.org/software/libc/manual/html_node/Backtraces.html
         */
        virtual void logTrace() = 0;

        /**
         * @brief logCustom
         * Allows logging of any arbitrary level
         *
         * @param level
         * @param func
         * @param line
         * @param msg
         */
        virtual void logCustom(QString level, string func, int line,
                               QString msg) = 0;

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

#endif // ILOG_H

