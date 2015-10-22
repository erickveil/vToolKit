#ifndef LOGFILERECORD_H
#define LOGFILERECORD_H

#include <qxexception.h>
#include <QStringList>

#include "iflatfilerecord.h"
#include "iLog.h"


namespace vToolKit{

    class LogFileRecord : public IFlatFileRecord
    {
    public:
        LogFileRecord();
        LogFileRecord(QString record_str, iLog &log);
        ~LogFileRecord() override;

        void initRecord(QString record_str, iLog &log);
        QString getField(QString field_name) override;
        void setField(QString field_name, QString field_val) override;
        bool isNull() override;

    private:
        QString _level;
        QString _timestamp;
        QString _pid;
        QString _method;
        QString _line;
        QString _message;

        QString _record_str;
        iLog *_log;

        void _initNullRecord();
        void _constructRecordFromString();
        QString _buildLongMessage(QStringList full_record_list);
    };

}

#endif // LOGFILERECORD_H
