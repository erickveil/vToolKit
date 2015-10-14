#ifndef LOGFILEFIELD_H
#define LOGFILEFIELD_H

#include "iflatfilefield.h"


namespace vToolKit{

    class LogFileField : public IFlatFileField
    {
    public:
        LogFileField();
        LogFileField(QString new_name, QString value);
        ~LogFileField() override;

        QString value() override;
        void value(QString val) override;
        QString name() override;
        void name(QString new_name) override;
        bool isNull() override;

    private:
        QString _name;
        QString _value;
    };

}

#endif // LOGFILEFIELD_H
