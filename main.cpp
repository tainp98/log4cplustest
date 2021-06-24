#include <log4cplus/configurator.h>
#include <log4cplus/initializer.h>
#include <iostream>
#include "Class1.h"
using namespace log4cplus;

int
main()
{
    // Initialization and deinitialization.
    log4cplus::Initializer initializer;
    PropertyConfigurator::doConfigure(LOG4CPLUS_TEXT("log.properties"));

    Class1 a;
    a.run();
    return 0;
}
