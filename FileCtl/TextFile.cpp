//
// Created by fac on 8/25/15.
//

#include "TextFile.h"

namespace vToolKit{

    TextFile::TextFile(string file_path) {
        _file_path=file_path;
    }

    void TextFile::appendLine(string line){
        _writeFile(ios_base::app, line);
    }

    // source:
    // http://www.cplusplus.com/forum/general/1796/
    bool TextFile::_isFileExists() {
        ifstream ifs(getFilePath());
        if(ifs){
            ifs.close();
            return true;
        }
        return false;
    }

    bool TextFile::_isFileWriteable() {
        struct stat buf;
        int status;
        string path=getFilePath();
        status=stat(path.c_str(),&buf);
        return status==0;
    }

    void TextFile::_createFile() {
        string path=getFilePath();
        ofstream new_file(path);
        new_file << endl;
    }

    string TextFile::getFilePath() {
        return _file_path;
    }

    void TextFile::overwriteFile(string contents) {
        _writeFile(ios_base::trunc, contents);
    }

    void TextFile::_writeFile(ios_base::openmode mode, string content) {
        ofstream file_obj;
        file_obj.open(getFilePath(), mode);
        file_obj << content << endl;
        file_obj.close();
    }

    string TextFile::readFileToString() {
        ifstream file_stream(getFilePath());
        stringstream buffer;
        buffer << file_stream.rdbuf();
        return buffer.str();
    }

    vector<string> TextFile::readFileToStringList() {
        string file_contents=readFileToString();
        vector<string> line_list;
        /* TODO: A log file class extends iFileCtl, and uses this class, overriding
         * this method, and splitting an the record separator instead.
         * Or, should I inherit this class, reusing a private implementation of
         * this method that takes the separator as an argument?
         */
        _split_string(file_contents, '\n', line_list);
        return line_list;
    }

    vector<string> & TextFile::_split_string(string &s, char delim,
                                                      vector<string> &container)
    {
        stringstream ss(s);
        string line;
        while(getline(ss,line,delim)) {
            container.push_back(line);
        }
        return container;
    }

}
