#ifndef NULLLOG_H
#define NULLLOG_H

#include "testLog.h"

namespace vToolKit{

    class NullLog : public testLog
    {
    public:
        bool isNull() override { return true; }
    };

}

#endif // NULLLOG_H
