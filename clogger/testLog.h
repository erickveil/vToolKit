//
// Created by fac on 8/19/15.
//

#include "iLog.h"

#ifndef CLOG_TESTLOG_H
#define CLOG_TESTLOG_H

namespace vStdTools {

    /**
     * Provides implementation blanks for unit tests.
     *
     * Methods will do nothing so that logging does not interfere with testing.
     */
    class testLog : public iLog {

    public:
        void logInfo(string func, int line, string msg);

        void logDebug(string func, int line, string msg);

        void logWarn(string func, int line, string msg);

        void logError(string func, int line, exception ex);

        void logError(string func, int line, string msg);

        void logFatal(string func, int line, exception ex);

        void logFatal(string func, int line, string msg);

    };

}


#endif //CLOG_TESTLOG_H
