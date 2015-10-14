#include <iostream>
#include "TextFile.h"

using namespace std;
using namespace vStdTools;

int main() {
    cout<<"This is a test."<<endl;
    TextFile file_obj("testfile.txt");

    cout<<"starting:"<<endl;
    file_obj.overwriteFile("Marry had a little lamb.");
    cout<<file_obj.readFileToString()<<endl;

    cout<<"adding line:"<<endl;
    file_obj.appendLine("Whose fleece was white as snow.");
    cout<<file_obj.readFileToString()<<endl;

    cout<<"overwriting:"<<endl;
    file_obj.overwriteFile("This is a new poem.");
    cout<<file_obj.readFileToString()<<endl;

    cout<<"adding a new line:"<<endl;
    file_obj.appendLine("This is the second line.");
    cout<<"adding a blank line:"<<endl;
    file_obj.appendLine("\n");
    vector<string> line_list=file_obj.readFileToStringList();

    cout<<"Number of lines read back: "<<line_list.size()<<endl;
    int i;
    for (i=0;i<line_list.size();++i){
        cout<<line_list.at(i)<<endl;
    }
    cout<<"Done."<<endl;

    return 0;
}