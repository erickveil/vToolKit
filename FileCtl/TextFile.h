//
// Created by fac on 8/25/15.
//

#include <fstream>
#include <iostream>
#include <string>
#include <sys/stat.h>
#include <sstream>
#include <vector>

#ifndef CLOG_STDFILE_H
#define CLOG_STDFILE_H

#include "IReadWriteFile.h"

using namespace std;


namespace vToolKit{

    /**
     * A Linux only, standard library, bare-bones file interface.
     */
    class TextFile : public IReadWriteFile {
    public:

        TextFile(string file_path);

        /**
         * appendLine()
         *
         * Appended lines end in a newline.
         *
         * @param string line : A line of text to append to the end of a file.
         */
        void appendLine(string line) override;

        /**
         * overwriteFile()
         *
         * Truncates a file and overwrites its contents.
         *
         * @param string contents : The new contents of the file.
         */
        void overwriteFile(string contents) override;

        /**
         * readFileToString()
         *
         * @return string : The data of the file, cast to a string.
         */
        string readFileToString() override;

        /**
         * readFileToStringList
         *
         * Empty lines take up an empty element in the list.
         *
         * @return vector<string> : A list of lines split on newline.
         */
        vector<string> readFileToStringList() override;

        /**
         * getFilePath()
         *
         * @return string : The file path passed to the constructor that
         * identifies this file.
         */
        string getFilePath() override;

    private:
        string _file_path;
        bool _isFileExists();
        bool _isFileWriteable();
        void _createFile();
        void _writeFile(ios_base::openmode mode, string content);
        vector<string> &_split_string(string &s, char delim,
                                      vector<string> &container);
    };
}


#endif //CLOG_STDFILE_H
