//
// Created by fac on 10/7/15.
//

#include "version.h"

string vToolKit::getVersion() {
    string build="c32fb52";
    if(build.compare(VERSION_COMMIT)!=0){
        cerr<<"WARNING: Build version "<<build
           <<" does not match headder version "<<VERSION_COMMIT<<endl;
    }
    return to_string(VERSION_MAJOR)+"."+to_string(VERSION_MINOR)+"."
            +string(VERSION_COMMIT);
}

