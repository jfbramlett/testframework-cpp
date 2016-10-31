#ifndef __SAMPLETESTCASE_H__
#define __SAMPLETESTCASE_H__

#include "TestCase.h"
#include <string>

using namespace std;

class SampleTestCase : public TestCase
{
public:
    SampleTestCase(string name);
    virtual ~SampleTestCase(void);

    // define our test method
    void test1() throw (TestFail);
    void test2() throw (TestFail);

    void setUp();

    static TestSuite suite();


protected:
};


#endif

