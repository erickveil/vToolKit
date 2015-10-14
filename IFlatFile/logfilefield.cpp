#include "logfilefield.h"

namespace vToolKit{

    LogFileField::LogFileField()
    {

    }

    LogFileField::LogFileField(QString new_name, QString value)
    {
        _name=new_name;
        _value=value;
    }

    LogFileField::~LogFileField()
    {

    }

    QString LogFileField::value()
    {
        return _value;
    }

    void LogFileField::value(QString val)
    {
        _value=val;
    }

    QString LogFileField::name()
    {
        return _name;
    }

    void LogFileField::name(QString new_name)
    {
        _name=new_name;
    }

    bool LogFileField::isNull()
    {
        return (name().isNull());
    }

}

