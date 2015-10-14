#ifndef IFLATFILEFIELD
#define IFLATFILEFIELD

#include <QString>

namespace vToolKit{



    class IFlatFileField
    {
    public:
        virtual ~IFlatFileField() = 0;

        virtual QString value() = 0;
        virtual void value(QString val) = 0;
        virtual QString name() = 0;
        virtual void name(QString new_name) = 0;
        virtual bool isNull() = 0;
    };

}
#endif // IFLATFILEFIELD

