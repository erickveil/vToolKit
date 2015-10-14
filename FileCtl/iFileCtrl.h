//
// Created by fac on 8/25/15.
//

#include <string>
#include <vector>

#ifndef CLOG_IFILECTRL_H
#define CLOG_IFILECTRL_H

using namespace std;

namespace vStdTools {

    /**
     * A file interface for reading and writing.
     * Ideal for text files. Might need extension for other types of files.
     */
    class iFileCtrl {
    public:

        /**
         * appendLine()
         *
         * @param string line : A line of text to append to the end of a file.
         */
        virtual void appendLine(string line) = 0;

        /**
         * overwriteFile()
         *
         * Truncates a file and overwrites its contents.
         *
         * @param string contents : The new contents of the file.
         */
        virtual void overwriteFile(string contents) = 0;

        /**
         * readFileToString()
         *
         * @return string : The data of the file, cast to a string.
         */
        virtual string readFileToString() = 0;

        /**
         * readFileToStringList
         *
         * @return vector<string> : A list of lines split on a delimiter that
         * depends on the type of file.
         */
        virtual vector<string> readFileToStringList() = 0;

        /**
         * getFilePath()
         *
         * @return string : The file path passed to the constructor that
         * identifies this file.
         */
        virtual string getFilePath() = 0;

    };
}


#endif //CLOG_IFILECTRL_H
