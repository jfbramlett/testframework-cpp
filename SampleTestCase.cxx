#include "SampleTestCase.h"
#include "Test.h"
#include <vector>

using namespace std;

//-------------------------------------------------------------------
// Constructor - initialize what tests should be run
SampleTestCase::SampleTestCase(string testName)
    : TestCase(testName)
{
}

//-------------------------------------------------------------------
// Destructor
SampleTestCase::~SampleTestCase(void)
{
}

//-------------------------------------------------------------------
// Defines the set of tests to run
TestSuite SampleTestCase::suite()
{
    TestSuite tests;

    // create a vector of tests to run - each test is created by wrapping it in our
    // test template and defining a function pointer to the test to run. The second
    // parameter is a "friendly" name that will be displayed when this test is run
    tests.push_back(new Test<SampleTestCase>(&SampleTestCase::test1, "Test Description 1"));
    tests.push_back(new Test<SampleTestCase>(&SampleTestCase::test2, "Test Description 2"));

    return tests;
}

//-------------------------------------------------------------------
// Set-up routine, perform any initialization needed by the test
void SampleTestCase::setUp()
{
}

//-------------------------------------------------------------------
// Some test
void SampleTestCase::test1() throw (TestFail)
{
    // perform some test functions - to verify the results use the assert
    // methods to perform validations in the test. The asserts are used
    // to trigger success and failures within the tests. You can also
    // provide a descriptive message describing the condition around
    // the assert failing
    assertTrue("Test 1 should have passed!", true);
}

//-------------------------------------------------------------------
// Some test
void SampleTestCase::test2() throw (TestFail)
{
    assertTrue("Test 2 should have passed");
}
