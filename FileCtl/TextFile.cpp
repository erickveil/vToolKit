//
// Created by fac on 8/25/15.
//

#include "TextFile.h"

vStdTools::TextFile::TextFile(string file_path) {
    _file_path=file_path;
}

void vStdTools::TextFile::appendLine(string line){
    _writeFile(ios_base::app, line);
}

// source:
// http://www.cplusplus.com/forum/general/1796/
bool vStdTools::TextFile::_isFileExists() {
    ifstream ifs(getFilePath());
    if(ifs){
        ifs.close();
        return true;
    }
    return false;
}

bool vStdTools::TextFile::_isFileWriteable() {
    struct stat buf;
    int status;
    string path=getFilePath();
    status=stat(path.c_str(),&buf);
    return status==0;
}

void vStdTools::TextFile::_createFile() {
    string path=getFilePath();
    ofstream new_file(path);
    new_file << endl;
}

string vStdTools::TextFile::getFilePath() {
    return _file_path;
}

void vStdTools::TextFile::overwriteFile(string contents) {
    _writeFile(ios_base::trunc, contents);
}

void vStdTools::TextFile::_writeFile(ios_base::openmode mode, string content) {
    ofstream file_obj;
    file_obj.open(getFilePath(), mode);
    file_obj << content << endl;
    file_obj.close();
}

string vStdTools::TextFile::readFileToString() {
    ifstream file_stream(getFilePath());
    stringstream buffer;
    buffer << file_stream.rdbuf();
    return buffer.str();
}

vector<string> vStdTools::TextFile::readFileToStringList() {
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

vector<string> &vStdTools::TextFile::_split_string(string &s, char delim,
                                                  vector<string> &container)
{
    stringstream ss(s);
    string line;
    while(getline(ss,line,delim)) {
        container.push_back(line);
    }
    return container;
}
