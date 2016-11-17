#ifndef CLOG_FILELOG_H
#define CLOG_FILELOG_H

//
// Created by fac on 8/19/15.
//
#include <execinfo.h>

#include <fstream>
#include <iostream>
#include <unistd.h>
#include <QString>

#include "ILog.h"
#include "IReadWriteFile.h"


using namespace std;
namespace vToolKit
{

    /**
     * Standard implementation for logging methods' interfaces.
     */
    class fileLog : public  ILog {

    public:
        /**
         * @param iFileCtrl log_file : interface for the log file itself.
         * Setting the log file's path to "" will force logging to stdlog and
         * stderr streams instead of a file.
         */
        fileLog(IReadWriteFile *log_file);

        /**
         * Without a parameter, logs default to stder.
         */
        fileLog();

        /**
         * @param string func : The calling method name. Gcc compilers can
         * use __PRETTY_FUNCTION__.
         * @param int line : The line this method is called from. Gcc
         * compilers can use __LINE__.
         * @param string msg : The entry to add to the log.
         */
        void logInfo(string func, int line, string msg) override;
        void logInfo(string func, int line, QString msg) override;

        /**
         * @param string func : The calling method name. Gcc compilers can
         * use __PRETTY_FUNCTION__.
         * @param int line : The line this method is called from. Gcc
         * compilers can use __LINE__.
         * @param string msg : The entry to add to the log.
         */
        void logDebug(string func, int line, string msg) override;
        void logDebug(string func, int line, QString msg) override;

        /**
         * @param string func : The calling method name. Gcc compilers can
         * use __PRETTY_FUNCTION__.
         * @param int line : The line this method is called from. Gcc
         * compilers can use __LINE__.
         * @param string msg : The entry to add to the log.
         */
        void logWarn(string func, int line, string msg) override;
        void logWarn(string func, int line, QString msg) override;

        /**
         * @param string func : The calling method name. Gcc compilers can
         * use __PRETTY_FUNCTION__.
         * @param int line : The line this method is called from. Gcc
         * compilers can use __LINE__.
         * @param exception ex : The exception for this error. The log entry
         * will be obtained from exception::what().
         */
        void logError(string func, int line, exception ex) override;

        /**
         * @param string func : The calling method name. Gcc compilers can
         * use __PRETTY_FUNCTION__.
         * @param int line : The line this method is called from. Gcc
         * compilers can use __LINE__.
         * @param string msg : The entry to add to the log.
         */
        void logError(string func, int line, string msg) override;
        void logError(string func, int line, QString msg) override;
        void logError(QxException ex) override;

        /**
         * @param string func : The calling method name. Gcc compilers can
         * use __PRETTY_FUNCTION__.
         * @param int line : The line this method is called from. Gcc
         * compilers can use __LINE__.
         * @param exception ex : The exception for this error. The log entry
         * will be obtained from exception::what().
         */
        void logFatal(string func, int line, exception ex) override;

        /**
         * @param string func : The calling method name. Gcc compilers can
         * use __PRETTY_FUNCTION__.
         * @param int line : The line this method is called from. Gcc
         * compilers can use __LINE__.
         * @param string msg : The entry to add to the log.
         */
        void logFatal(string func, int line, string msg) override;
        void logFatal(string func, int line, QString msg) override;
        void logFatal(QxException ex) override;

        void logTrace() override;

        void logCustom(QString level, string func, int line, QString msg) override;

        bool isNull() override { return false;}

    private:

        IReadWriteFile *_log_file;

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
