#ifndef IFLATFILERECORD
#define IFLATFILERECORD

#include <QString>

#include "nulllog.h"


namespace vToolKit{

    class IFlatFileRecord
    {
    public:
        virtual ~IFlatFileRecord() = 0;
        virtual QString getField(QString field_name) = 0;
        virtual void setField(QString field_name, QString field_val) = 0;
        virtual bool isNull() = 0;
    };

}

#endif // IFLATFILERECORD

