#ifndef LOGFILERECORD_H
#define LOGFILERECORD_H

#include <qxexception.h>
#include <QStringList>

#include "iflatfilerecord.h"
#include "logfilefield.h"
#include "iLog.h"


namespace vToolKit{

    class LogFileRecord : public IFlatFileRecord
    {
    public:
        LogFileRecord();
        LogFileRecord(QString record_str, iLog &log);
        void initRecord(QString record_str, iLog &log);
        ~LogFileRecord() override;
        IFlatFileField * getField(QString field_name) override;
        void setField(IFlatFileField &field) override;
        bool isNull() override;

    private:
        IFlatFileField *_level;
        IFlatFileField *_timestamp;
        IFlatFileField *_pid;
        IFlatFileField *_method;
        IFlatFileField *_line;
        IFlatFileField *_message;
        QString _record_str;
        iLog *_log;

        void _initNullRecord();
        void _constructRecordFromString();
        LogFileField *_buildLongMessage(QStringList full_record_list);
    };

}

#endif // LOGFILERECORD_H
