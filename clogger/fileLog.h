//
// Created by fac on 8/19/15.
//

#include <fstream>
#include <iostream>

#include "iLog.h"
#include "iFileCtrl.h"

// todo: a build flags file might be a more appropriate place for these defines.
#define UNIX 0
#define WIN 1
// todo: Win build remains untested.
// Set operating system compile flag here.
#define OS_FLAG UNIX

// Operating system specific libraries determined by OS_FLAG setting.
#if (OS_FLAG==UNIX)
// http://pubs.opengroup.org/onlinepubs/7908799/xsh/unistd.h.html
#include <unistd.h>

#elif (OS_FLAG==WIN)
// https://en.wikipedia.org/wiki/Windows.h
#include <windows.h>

#endif

using namespace std;

#ifndef CLOG_FILELOG_H
#define CLOG_FILELOG_H

namespace vStdTools
{

    /**
     * Standard implementation for logging methods' interfaces.
     */
    class fileLog : public  iLog {

    public:
        /**
         * @param iFileCtrl log_file : interface for the log file itself.
         * Setting the log file's path to "" will force logging to stdlog and
         * stderr streams instead of a file.
         */
        explicit fileLog(iFileCtrl *log_file);

        /**
         * Without a parameter, logs default to stder.
         */
        explicit fileLog();

        /**
         * @param string func : The calling method name. Gcc compilers can
         * use __PRETTY_FUNCTION__.
         * @param int line : The line this method is called from. Gcc
         * compilers can use __LINE__.
         * @param string msg : The entry to add to the log.
         */
        void logInfo(string func, int line, string msg);

        /**
         * @param string func : The calling method name. Gcc compilers can
         * use __PRETTY_FUNCTION__.
         * @param int line : The line this method is called from. Gcc
         * compilers can use __LINE__.
         * @param string msg : The entry to add to the log.
         */
        void logDebug(string func, int line, string msg);

        /**
         * @param string func : The calling method name. Gcc compilers can
         * use __PRETTY_FUNCTION__.
         * @param int line : The line this method is called from. Gcc
         * compilers can use __LINE__.
         * @param string msg : The entry to add to the log.
         */
        void logWarn(string func, int line, string msg);

        /**
         * @param string func : The calling method name. Gcc compilers can
         * use __PRETTY_FUNCTION__.
         * @param int line : The line this method is called from. Gcc
         * compilers can use __LINE__.
         * @param exception ex : The exception for this error. The log entry
         * will be obtained from exception::what().
         */
        void logError(string func, int line, exception ex);

        /**
         * @param string func : The calling method name. Gcc compilers can
         * use __PRETTY_FUNCTION__.
         * @param int line : The line this method is called from. Gcc
         * compilers can use __LINE__.
         * @param string msg : The entry to add to the log.
         */
        void logError(string func, int line, string msg);

        /**
         * @param string func : The calling method name. Gcc compilers can
         * use __PRETTY_FUNCTION__.
         * @param int line : The line this method is called from. Gcc
         * compilers can use __LINE__.
         * @param exception ex : The exception for this error. The log entry
         * will be obtained from exception::what().
         */
        void logFatal(string func, int line, exception ex);

        /**
         * @param string func : The calling method name. Gcc compilers can
         * use __PRETTY_FUNCTION__.
         * @param int line : The line this method is called from. Gcc
         * compilers can use __LINE__.
         * @param string msg : The entry to add to the log.
         */
        void logFatal(string func, int line, string msg);

    private:

        iFileCtrl *_log_file;

        bool _isLogfileSet();

        void _logLog(string log_line);

        void _logErr(string log_line);

        string _buildLogLine(string level, string func, int line, string msg);

        string _buildLogLine(string level, string func, int line, exception ex);

        void _writeToLogFile(string log_line);

        void _writeToStdLog(string log_line);

        void _writeToStdErr(string log_line);

        // todo: these belong in a different tool box.
        string _getTimeStamp();

        string _getPid();

        string _intToString(int number);
    };
}

#endif //CLOG_FILELOG_H
