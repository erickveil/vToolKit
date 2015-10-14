//
// Created by fac on 8/25/15.
//
#include <cxxtest/TestSuite.h>
#include "../StdFile.h"

using namespace vStdTools;

class ClogTests : public CxxTest::TestSuite
{
public:
    void testAddition( void )
    {
        TS_ASSERT(1 + 1 > 1);
        TS_ASSERT_EQUALS(1 + 1, 2);
    }

    void test_StdFile_isFileExists( void )
    {
        // todo: Can't seem to resolve vtable issue.
        StdFile target("/home/fac/no_file.txt");
        //bool actual = target._isFileExists();
        //TS_ASSERT(actual);
    }
};


