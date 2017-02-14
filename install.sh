#!/bin/bash

# A script to be run after building in Qt creator.
# It gathers the necessary headder files and copies them into the library
# directory, then cleans out the *.o files and old Makefile.

./setversion.sh
git diff

# clear out build directory
mkdir -v bin/Release
rm -v bin/Release/*

# collect headders
cp -v *.h bin/Release/
cp -v */*.h bin/Release/

# build binary library
PROJECT_ROOT=$(pwd)
cd bin/Release/
pwd

PRO_FILE=${PROJECT_ROOT}/vToolKit.pro
/usr/lib64/qt5/bin/qmake -Wall ${PRO_FILE}
/usr/bin/make


# remove build files
rm -v *.o
rm -v makefile
rm -v Makefile






