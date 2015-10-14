//
// Created by fac on 8/19/15.
//

#include "iLog.h"

#ifndef CLOG_TESTLOG_H
#define CLOG_TESTLOG_H

namespace vToolKit{

    /**
     * Provides implementation blanks for unit tests.
     *
     * Methods will do nothing so that logging does not interfere with testing.
     */
    class testLog : public iLog {

    public:
        void logInfo(string func, int line, string msg) override;

        void logInfo(string func, int line, QString msg) override;

        void logDebug(string func, int line, string msg) override;

        void logDebug(string func, int line, QString msg) override;

        void logWarn(string func, int line, string msg) override;

        void logWarn(string func, int line, QString msg) override;

        void logError(string func, int line, exception ex) override;

        void logError(string func, int line, string msg) override;

        void logError(string func, int line, QString msg) override;

        void logError(QxException ex) override;

        void logFatal(string func, int line, exception ex) override;

        void logFatal(string func, int line, string msg) override;

        void logFatal(string func, int line, QString msg) override;

        void logFatal(QxException ex) override;

    };

}


#endif //CLOG_TESTLOG_H
