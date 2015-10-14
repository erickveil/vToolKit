#ifndef IFLATFILERECORD
#define IFLATFILERECORD

#include <QString>

#include "iflatfilefield.h"


namespace vToolKit{

    class IFlatFileRecord
    {
    public:
        virtual ~IFlatFileRecord() = 0;
        virtual IFlatFileField * getField(QString field_name) = 0;
        virtual void setField(IFlatFileField &field) = 0;
        virtual bool isNull() = 0;
    };

}

#endif // IFLATFILERECORD

