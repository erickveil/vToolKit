#include "logfilerecord.h"


namespace vToolKit{

    LogFileRecord::LogFileRecord()
    {
        _initNullRecord();
        _log=new NullLog;
    }

    LogFileRecord::LogFileRecord(QString record_str, ILog &log)
    {
        initRecord(record_str, log);
    }

    void LogFileRecord::initRecord(QString record_str, ILog &log)
    {
        _initNullRecord();
        _record_str=record_str;
        _log=&log;
    }

    LogFileRecord::~LogFileRecord()
    {
        if(_log->isNull()) delete _log;
    }

    QString LogFileRecord::getField(QString field_name)
    {
        const char * me=__PRETTY_FUNCTION__;
        QString msg;

        // validate record is set
        bool is_constructed_with_string=(isNull() && !_record_str.isNull());
        if(is_constructed_with_string) _constructRecordFromString();

        if(field_name=="level") return _level;
        else if(field_name=="timestamp") return _timestamp;
        else if(field_name=="pid") return _pid;
        else if(field_name=="method") return _method;
        else if(field_name=="line") return _line;
        else if(field_name=="message") return _message;
        else{
            msg="Unrecognized log field queried: "+field_name;
            throw QxException(me,__LINE__,msg);
        }
    }

    void LogFileRecord::setField(QString field_name, QString field_val)
    {
        const char * me=__PRETTY_FUNCTION__;

        if(field_name=="level") _level=field_val;
        else if(field_name=="timestamp") _timestamp=field_val;
        else if(field_name=="pid") _pid=field_val;
        else if(field_name=="method") _method=field_val;
        else if(field_name=="line") _line=field_val;
        else if(field_name=="message") _message=field_val;
        else{
            QString msg="Attempt to edit non log field: "+field_name
                    +" with value: "+field_val;
            throw QxException(me,__LINE__,msg);
        }
    }

    bool LogFileRecord::isNull()
    {
        return _level.isNull()
                || _timestamp.isNull()
                || _pid.isNull()
                || _method.isNull()
                || _line.isNull()
                || _message.isNull();
    }

    void LogFileRecord::_initNullRecord()
    {
    }

    void LogFileRecord::_constructRecordFromString()
    {
        // TODO: validate record string set.

        QString field_delim="|";
        QStringList record_list=_record_str.split(field_delim);

        // TODO: trim list entries.

        if(record_list.size()!=6){
            QString msg=QString("When building log record, 6 fields required. ")
                    +record_list.size()+" fields provided.";
            _log->logWarn(__PRETTY_FUNCTION__,__LINE__,msg.toStdString());
        }

        // TODO: Test what happens if we use QStringList::at on a field that does not exist.
        // maybe throw on <6 entries, and warn on >6.

        _level=record_list.at(0);
        _timestamp=record_list.at(1);
        _pid=record_list.at(2);
        _method=record_list.at(3);
        _line=record_list.at(4);
        _message=_buildLongMessage(record_list);
    }

    QString LogFileRecord::_buildLongMessage(
            QStringList full_record_list)
    {
        if(full_record_list.size()<6) return "";

        QString msg_value="";
        int i;
        for(i=5; i<full_record_list.size(); ++i){
            msg_value+=(full_record_list.at(i)+" ");
        }

        return msg_value;
    }
}

