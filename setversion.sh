#!/bin/bash

# setversion.sh
# 
# Sets the version for the project, based on the commit.
#
# Erick Veil
# 2015-10-07
#
# This script is to be run prior to qmake. It modifies version.h by getting the
# project commit and changing the preprocessor constant value.

BUILD=$(git rev-parse --short HEAD)
sed -i "s/VERSION_COMMIT.*$/VERSION_COMMIT \"${BUILD}\"/" version.h
sed -i "s/string build.*$/string build=\"${BUILD}\";/" version.cpp

