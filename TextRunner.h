#ifndef __TEXTRUNNER_H__
#define __TEXTRUNNER_H__

#include "TestCase.h"
#include "TestRunner.h"

template<class T> class TextRunner : public StdOutTestReporter, public TestRunner
{
public:
    TextRunner() {};
    virtual ~TextRunner() {};


    virtual void preTest(TestCase* test)
    {
       // call our super class preTest first
       TestRunner::preTest(test);
        *this << "Running test: " << test->getTestName() << "\n";
        *this << "==============";
        for (size_t l = 0; l < test->getTestName().size(); l++)
        {
            *this << "=";
        }
        *this << "\n";
    }
    
    virtual void reportPass(TestCase* test)
    {
        // first, report our success to our base class
        TestRunner::reportPass(test);
        
        // provide some output to the user on the success
        *this << "Test PASSED" << "\n\n";
    };
     
    virtual void reportFail(TestCase* test)
    {
        // report the test not passing to our base class
        TestRunner::reportFail(test);
        
        // now provide some output to the user
        *this << "Test FAILED" << "\n\n";
    };
    
    virtual void reportFailure(TestCase* test)
    {
         // report the test failing because of an unexpected exception
         TestRunner::reportFailure(test);
         
         // now provide the user some output on this
        *this << "[Unexpected exception caused test to fail]" << "\n";
        *this << "Test FAILED" << "\n\n";
    }
    
    virtual void reportResults()
    {
        *this << "\n" << "Test execution summary:" << "\n";
        *this << getPassedTest() << " tests passed" << "\n";    
        *this << getFailedTest() << " tests failed" << "\n";    
        *this << getFailures() << " test had failures (i.e. failed to execute)" << "\n";    

        if ((getFailedTest() > 0) || (getFailures() > 0))
        {
            *this << "\n" << "TEST FAILED!!!" << "\n";
        }
        else
        {
            *this << "\n" << "TEST PASSED!!!" << "\n";
        }
    }


    virtual TestSuite getTests()
    {
         return T::suite();
    }
    
    
private:
};


#endif

