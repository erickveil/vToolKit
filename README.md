ToolKit
====

A collection of commonly used interfaces.
Qt required.

Project structure:
----

The main vToolKit project is found in the root directory of the repo.
If built from QtCreator, it will build a static library for use.

bin is the target directory for the build, though it might be different on your
machine, as the build directory is defined outside of the repo.

Several sub-directories are found in the project root.
Each of these directories is a sub project.
Each subproject has their own independent library build and *.pro file.
This allows you to build just one component (aka a logger or exceptions) if
that's whay you want.

Inside of these sub-directories might be other project directories. These will
either be unit tests for the sub-project, or a special project file that makes
exclusive use of the library.

An example sub project is in the clogger directory: The clogger project level
build will create a static library. Going into the sub-direcotry, you will find
a project that uses the clogger library to create a command-line clogger
program that allows you to use the logging abilities directly on a linux
command line wihtout including in a C++ program.

For the most part, you will use QtCreator to build directly from the root
project in this repo and generate a static library to use in your C++ programs.

Preparing to Build
----

First you will want to open vToolKit.pro in QtCreator and let it import the
project.

You will then want to change the build directory:

Close the project completely, then open in vim vToolKit.pro.user, which should
have been generated when you opened the project in QtCreator.

Locate and edit the 2 build paths in the file:
/path/to/project/root/bin/Release
and
/path/to/project/root/bin/Debug

The build path must be here for the install.sh script to work.

Save and close vToolKit.pro.user.

Main Project Build
----

First, run setversion.sh. This script will update the version headder for the
library with a unique value for the current build.

Make sure you clean out the build directory of old headders:
```
rm /path/to/project/root/bin/Release/*
```
Alternatively, running install.sh will clean it out at this point, and make
sure you have the current headders in place.

Then open the file vToolKit.pro in QtCreator and build.

Verify that your vToolKit.a file is located in
/path/to/project/root/bin/Release/*

Run install.sh

This script will remove *.o files and other junk, then copy header files into
the release directory.

You can then copy the library into your main project:
```
cp -r /path/to/vTookKit/root/bin/Release \
/path/to/your/main/project/lib/vToolKit
```

You may need to `rm -r /path/to/your/main/project/lib/vToolKit` before you do
the copy, if you are replacing an old version.

Eventually, I will figure out how the execute arbitrary code from targets in
Qt's pro files like I would from a Makefile, and this process will become
simpler.

Version
---

The library version is tracked in version.h. The major and minor version
numbers are manually edited, while the build version is set using the
setversion.sh script.

A special function vToolKit::version() is provided to be used in your unit
tests. It compares the version numbers in version.h with the version numbers
that are compiled into the library. This is helpful for making sure that your
project's library headders match the actual compiled library.

At this time, for the version method to work, you will need to hand edit the
major and minor version numbers in version.cpp to match the ones in version.h.
The build number in version.cpp is handled by setversion.sh.




