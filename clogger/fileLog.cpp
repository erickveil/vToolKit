//
// Created by fac on 8/19/15.
//

#include <sstream>
#include "fileLog.h"

namespace vToolKit{
    fileLog::fileLog() {
    }

    void fileLog::logInfo(string func, int line, string msg) {
        string log_line=_buildLogLine("INFO", func, line, msg);
        _logLog(log_line);
    }

    void fileLog::logDebug(string func, int line, string msg) {
        string log_line=_buildLogLine("DEBUG", func, line, msg);
        _logLog(log_line);
    }

    void fileLog::logWarn(string func, int line, string msg) {
        string log_line=_buildLogLine("WARN", func, line, msg);
        _logErr(log_line);
    }

    void fileLog::logError(string func, int line, exception ex) {
        string log_line=_buildLogLine("ERROR", func, line, ex);
        _logErr(log_line);
    }

    void fileLog::logError(string func, int line, string msg) {
        string log_line=_buildLogLine("ERROR",func,line,msg);
        _logErr(log_line);
    }

    void fileLog::logFatal(string func, int line, exception ex) {
        string log_line=_buildLogLine("FATAL", func, line, ex);
        _logErr(log_line);
    }

    void fileLog::logFatal(string func, int line, string msg) {
        string log_line=_buildLogLine("FATAL", func, line, msg);
        _logErr(log_line);
    }

    void fileLog::_logLog(string log_line) {
        if(_isLogfileSet()) _writeToLogFile(log_line);
        else _writeToStdLog(log_line);
    }

    void fileLog::_logErr(string log_line) {
        if(_isLogfileSet()) _writeToLogFile(log_line);
        else _writeToStdErr(log_line);
    }

    void fileLog::_writeToLogFile(string log_line) {
        _log_file->appendLine(log_line);
    }

    void fileLog::_writeToStdLog(string log_line) {
        clog << log_line << endl;
    }

    void fileLog::_writeToStdErr(string log_line) {
        cerr << log_line << endl;
    }

    bool fileLog::_isLogfileSet() {
        return (_log_file->getFilePath() != "");
    }

    string fileLog::_buildLogLine(string level, string func, int line,
                                           string msg) {
        string timestamp = _getTimeStamp();
        string pid = _getPid();
        string s_line = _intToString(line);
        //Non-printing ASCII record separator
        char record_end = 30;

        ostringstream ss;
        ss << level << " | " << timestamp << " | " << pid << " | " << func << " | "
             << s_line << " | " << msg << record_end;
        return ss.str();
    }

    string fileLog::_buildLogLine(string level, string func, int line,
                                             exception ex) {
        string msg = ex.what();
        return _buildLogLine(level, func, line, msg);
    }

    string fileLog::_getTimeStamp() {

        time_t time_obj;
        struct tm *time_pointer;
        time_obj = time(NULL);
        time_pointer = localtime(&time_obj);
        size_t max_size = 32;
        char timestamp[max_size];
        const char * format = "%FT%T";
        size_t result = strftime(timestamp, max_size, format, time_pointer);
        bool time_unknown = (result == 0);
        string error_time = "Timestamp error";

        if(time_unknown) return error_time;
        else return string(timestamp);
    }

    string fileLog::_getPid()
    {
        int pid=getpid();
        string s_pid=_intToString(pid);
        return s_pid;
    }

    string fileLog::_intToString(int number)
    {
        ostringstream ss;
        ss<< number;
        return ss.str();
    }

    fileLog::fileLog(iFileCtrl *log_file) {
        _log_file=log_file;
    }

}
