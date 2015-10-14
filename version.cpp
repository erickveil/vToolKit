//
// Created by fac on 10/7/15.
//

#include "version.h"

string vVersion::getVersion() {
    return to_string(VERSION_MAJOR)+"."+to_string(VERSION_MINOR)+"."
            +string(VERSION_COMMIT);
}

