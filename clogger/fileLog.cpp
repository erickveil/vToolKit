//
// Created by fac on 8/19/15.
//

#include <sstream>
#include "fileLog.h"

vStdTools::fileLog::fileLog() {
}

void vStdTools::fileLog::logInfo(string func, int line, string msg) {
    string log_line=_buildLogLine("INFO", func, line, msg);
    _logLog(log_line);
}

void vStdTools::fileLog::logDebug(string func, int line, string msg) {
    string log_line=_buildLogLine("DEBUG", func, line, msg);
    _logLog(log_line);
}

void vStdTools::fileLog::logWarn(string func, int line, string msg) {
    string log_line=_buildLogLine("WARN", func, line, msg);
    _logErr(log_line);
}

void vStdTools::fileLog::logError(string func, int line, exception ex) {
    string log_line=_buildLogLine("ERROR", func, line, ex);
    _logErr(log_line);
}

void vStdTools::fileLog::logError(string func, int line, string msg) {
    string log_line=_buildLogLine("ERROR",func,line,msg);
    _logErr(log_line);
}

void vStdTools::fileLog::logFatal(string func, int line, exception ex) {
    string log_line=_buildLogLine("FATAL", func, line, ex);
    _logErr(log_line);
}

void vStdTools::fileLog::logFatal(string func, int line, string msg) {
    string log_line=_buildLogLine("FATAL", func, line, msg);
    _logErr(log_line);
}

void vStdTools::fileLog::_logLog(string log_line) {
    if(_isLogfileSet()) _writeToLogFile(log_line);
    else _writeToStdLog(log_line);
}

void vStdTools::fileLog::_logErr(string log_line) {
    if(_isLogfileSet()) _writeToLogFile(log_line);
    else _writeToStdErr(log_line);
}

void vStdTools::fileLog::_writeToLogFile(string log_line) {
    _log_file->writeLine(log_line);
}

void vStdTools::fileLog::_writeToStdLog(string log_line) {
    clog << log_line << endl;
}

void vStdTools::fileLog::_writeToStdErr(string log_line) {
    cerr << log_line << endl;
}

bool vStdTools::fileLog::_isLogfileSet() {
    return (_log_file->getFilePath() != "");
}

string vStdTools::fileLog::_buildLogLine(string level, string func, int line,
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

string vStdTools::fileLog::_buildLogLine(string level, string func, int line,
                                         exception ex) {
    string msg = ex.what();
    return _buildLogLine(level, func, line, msg);
}

string vStdTools::fileLog::_getTimeStamp() {

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

string vStdTools::fileLog::_getPid()
{
    // Implementation depends on operating system.
#if(OS_FLAG==UNIX)
    int pid=getpid();
    string s_pid=_intToString(pid);
    return s_pid;
#elif (OS_FLAG==WIN)
    return to_string(GetCurrentProcessId());
#else
    return "NULL";
#endif
}

string vStdTools::fileLog::_intToString(int number)
{
    ostringstream ss;
    ss<< number;
    return ss.str();
}

vStdTools::fileLog::fileLog(vStdTools::iFileCtrl *log_file) {
    _log_file=log_file;
}
