#ifndef __TESTRUNNER_H__
#define __TESTRUNNER_H__

#include "TestCase.h"

class TestRunner
{
public:
    TestRunner();    
    virtual ~TestRunner();

    void run();
         
    virtual void preTest(TestCase* test);
   
    void runTest(TestCase* test);
 
    virtual void postTest(TestCase* test);
       
    virtual void reportPass(TestCase* test);
     
    virtual void reportFail(TestCase* test);
    
    virtual void reportFailure(TestCase* test);
    
    short getPassedTest();
    short getFailedTest();
    short getFailures();
    
    virtual void reportResults() = 0;
    virtual TestSuite getTests() = 0;
   

protected:
    short m_passedTests;
    short m_failedTests;
    short m_failures;
};


#endif

