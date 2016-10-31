#include "SampleTestCase.h"
#include "TextRunner.h"


int main(int argc, char** argv) 
{
    TextRunner<SampleTestCase> runner;

    runner.run();
}
