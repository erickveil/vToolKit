#!/bin/bash

# A script to be run after building in Qt creator.
# It gathers the necessary headder files and copies them into the library
# directory, then cleans out the *.o files and old Makefile.

cp -v *.h bin/Release/
cp -v */*.h bin/Release/
rm -v bin/Release/*.o
rm -v bin/Release/Makefile

