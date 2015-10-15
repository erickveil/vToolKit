#ifndef CLOG_TESTLOG_H
#define CLOG_TESTLOG_H

//
// Created by fac on 8/19/15.
//

#include "iLog.h"

namespace vToolKit{

    /**
     * Provides implementation blanks for unit tests.
     *
     * Methods will do nothing so that logging does not interfere with testing.
     */
    class testLog : public iLog {

    public:
        void logInfo(string func, int line, string msg) override {
            UNUSED(func);
            UNUSED(line);
            UNUSED(msg);
        }

        void logInfo(string func, int line, QString msg) override {
            UNUSED(func);
            UNUSED(line);
            UNUSED(msg);
        }

        void logDebug(string func, int line, string msg) override {
            UNUSED(func);
            UNUSED(line);
            UNUSED(msg);
        }

        void logDebug(string func, int line, QString msg) override {
            UNUSED(func);
            UNUSED(line);
            UNUSED(msg);
        }

        void logWarn(string func, int line, string msg) override {
            UNUSED(func);
            UNUSED(line);
            UNUSED(msg);
        }

        void logWarn(string func, int line, QString msg) override {
            UNUSED(func);
            UNUSED(line);
            UNUSED(msg);
        }

        void logError(string func, int line, exception ex) override {
            UNUSED(func);
            UNUSED(line);
            UNUSED(ex);
        }

        void logError(string func, int line, string msg) override {
            UNUSED(func);
            UNUSED(line);
            UNUSED(msg);
        }

        void logError(string func, int line, QString msg) override {
            UNUSED(func);
            UNUSED(line);
            UNUSED(msg);
        }

        void logError(QxException ex) override {
            UNUSED(ex);
        }

        void logFatal(string func, int line, exception ex) override {
            UNUSED(func);
            UNUSED(line);
            UNUSED(ex);
        }

        void logFatal(string func, int line, string msg) override {
            UNUSED(func);
            UNUSED(line);
            UNUSED(msg);
        }

        void logFatal(string func, int line, QString msg) override {
            UNUSED(func);
            UNUSED(line);
            UNUSED(msg);
        }

        void logFatal(QxException ex) override { UNUSED(ex); }

        bool isNull() override { return false; }

    };

}


#endif //CLOG_TESTLOG_H
