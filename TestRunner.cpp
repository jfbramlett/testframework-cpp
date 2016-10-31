#include "TestRunner.h"

TestRunner::TestRunner() 
{
    m_passedTests = 0;
    m_failedTests = 0;
    m_failures = 0;
}
    
TestRunner::~TestRunner() 
{
}

void TestRunner::run()
{
    // get our tests to run
    TestSuite tests = getTests();
    for (TestSuite::iterator it = tests.begin(); it != tests.end(); it++)
    {
        preTest(*it);
        runTest(*it);           
        postTest(*it);
     }
        
     reportResults();
}

void TestRunner::preTest(TestCase* test)
{
}
   
void TestRunner::runTest(TestCase* test)
{
    try 
    {
        test->run();
        reportPass(test);
    }
    catch (TestFail failure)
    {
        reportFail(test);
    }
    catch (...)
    {
            reportFailure(test);
    }
}

void TestRunner::postTest(TestCase* test)
{
}
       
void TestRunner::reportPass(TestCase* test)
{
    m_passedTests++;
}
    
void TestRunner::reportFail(TestCase* test)
{
    m_failedTests++;
}

void TestRunner::reportFailure(TestCase* test)
{
    m_failures++;
}
    
short TestRunner::getPassedTest() 
{ 
    return m_passedTests;
}

short TestRunner::getFailedTest() 
{ 
    return m_failedTests; 
}

short TestRunner::getFailures() 
{ 
    return m_failures; 
}
    
