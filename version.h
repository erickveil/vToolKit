#ifndef VERSION_H
#define VERSION_H

/**
 *
 * version.h
 * Erick Veil
 * 2015-10-07
 *
 * Sets the project version.
 *
 * To set the version, edit this file's values for VERSION_MAJOR and
 * VERSION_MINOR.
 *
 * Then, run setversion.sh to automaticaly set VERSION_COMMIT "821c6bc"
 * current commit hash.
 *
 * Do this before each build.
 *
 **/

#include <string>
#include <iostream>

using namespace std;

#define VERSION_MAJOR 1
#define VERSION_MINOR 1
#define VERSION_COMMIT "821c6bc"


namespace vToolKit{

    string getVersion();

}

#endif // VERSION_H
