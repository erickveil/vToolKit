#include "logfilerecord.h"


namespace vQtTools{

    LogFileRecord::LogFileRecord()
    {
        _initNullRecord();
        // TODO: Define a null log (singleton?)
        NullLog nlog;
        _log=nlog;
    }

    // TODO: Include iLogger library
    LogFileRecord::LogFileRecord(QString record_str, iLog log)
    {
        initRecord(record_str, log);
    }

    void LogFileRecord::initRecord(QString record_str, iLog log)
    {
        _initNullRecord();
        _record_str=record_str;
        _log=log;
    }

    LogFileRecord::~LogFileRecord()
    {
        delete _level;
        delete _timestamp;
        delete _pid;
        delete _method;
        delete _line;
        delete _message;
    }

    IFlatFileField *LogFileRecord::getField(QString field_name)
    {
        const char * me=__PRETTY_FUNCTION__;
        QString msg;

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

    void LogFileRecord::setField(IFlatFileField &field)
    {
        const char * me=__PRETTY_FUNCTION__;

        if(field.name()=="level") _level=&field;
        else if(field.name()=="timestamp") _timestamp=&field;
        else if(field.name()=="pid") _pid=&field;
        else if(field.name()=="method") _method=&field;
        else if(field.name()=="line") _line=&field;
        else if(field.name()=="message") _message=&field;
        else{
            QString msg="Attempt to edit non log field: "+field.name()
                    +" with value: "+field.value();
            throw QxException(me,__LINE__,msg);
        }
    }

    bool LogFileRecord::isNull()
    {
        return _level->isNull()
                || _timestamp->isNull()
                || _pid->isNull()
                || _method->isNull()
                || _line->isNull()
                || _message->isNull();
    }

    void LogFileRecord::_initNullRecord()
    {
        _level=new LogFileField;
        _timesamp=new LogFileField;
        _pid=new LogFileField;
        _method=new LogFileField;
        _line=new LogFileField;
        _message=new LogFileField;
    }

    void LogFileRecord::_constructRecordFromString()
    {
        QString field_delim="|";
        QStringList record_list=_record_str.split(field_delim);

        // TODO: trim list entries.

        if(record_list.size()!=6){
            QString msg="When building log record, 6 fields required. "
                    +record_list.size()+" fields provided.";
            _log.warningLog(_PRETTY_FUNCTION_,_LINE_,msg);
        }

        // TODO: Test what happens if we use QStringList::at on a field that does not exist.
        // maybe throw on <6 entries, and warn on >6.

        _level=new LogFileField( "level", record_list.at(0) );
        _timestamp=new LogFileField( "timestamp", record_list.at(1) );
        _pid=new LogFileField( "pid", record_list.at(2) );
        _method=new LogFileField( "method", record_list.at(3) );
        _line=new LogFileField( "line", record_list.at(4) );
        _message=_buildLongMessage(record_list);
    }

    LogFileRecord *LogFileRecord::_buildLongMessage(
            QStringList full_record_list)
    {
        if(full_record_list.size<6) return new LogFileField;

        QString msg_value="";
        int i;
        for(i=5; i<full_record_list.size(); ++i){
            msg_value+=(full_record_list.at(i)+" ");
        }

        return new LogFileRecord("message", msg_value);
    }
}

