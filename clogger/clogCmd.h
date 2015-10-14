//
// Created by fac on 8/21/15.
//

#include <fstream>
#include <getopt.h>
#include <iostream>
#include <sstream>
#include <string>

#include "fileLog.h"
#include "version.h"

using namespace std;
using namespace vStdTools;

#ifndef CLOG_CLOGCMD_H
#define CLOG_CLOGCMD_H

/**
 * clogger namespace
 *
 * Used exclusively for the clogger command-line program.
 * Not for use as included clogger library in other C++ programs.
 */
namespace clog {

    enum log_level { INFO, DEBUG, WARN, ERROR, FATAL };

    /**
     * Defines data that gets passed to the various clogger methods.
     * The struct allows defining the data and returning one object to pass
     * around and reference.
     */
    struct EntryData {
        string method = "";
        int line = -1;
        string out_file = "";
        log_level level = INFO;
    };

    /**
     * Defines methods called from main in the clogger command-line program.
     */
    class clogCmd {

    public:

        /**
         * Prints help text to stdout.
         */
        void usage();

        /**
         * Converts a string to an int.
         *
         * This is a special string to int method. It is intended for
         * positive numbers, as a -1 will result from an error.
         *
         * todo: LineNumber might want to be its own type.
         *
         * @param string number : The input number as a string.
         * @return int : The input number, converted to an integer. Returns
         * -1 if the value can't be converted.
         */
        int stringToLineNumber(string number);

        string getMessageFromStdIn();
        /**
         * Parses the command-line options and constructs the EntryData object.
         *
         * @param int argc
         * @param char **argv
         * @return EntryData
         */
        EntryData getDataFromOptions(int argc, char *argv[]);

        /**
         * @param EntryData data
         * @param string msg
         */
        void writeToLog(EntryData data, string msg);


    private:

        bool _iterateOptions(int &short_option, int argc, char **argv,
                             EntryData &data);
    };
}


#endif //CLOG_CLOGCMD_H
