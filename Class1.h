#ifndef CLASS1_H
#define CLASS1_H
#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/configurator.h>
#include <log4cplus/initializer.h>
#include <consoleappender.h>
#include <fileappender.h>
//#include <tstring.h>
#include <tstring.h>
#include <iostream>

using namespace log4cplus;

class Class1
{
public:
    Class1();
    void run();


private:
    void initLog();
    log4cplus::Logger logger;
//    log4cplus::tstring pattern;

};

#endif // CLASS1_H
