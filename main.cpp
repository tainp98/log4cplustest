#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/configurator.h>
#include <log4cplus/initializer.h>
//#include <log4judpappender.h>
//#include <log4cplus/appender.h>
//#include <log4cplus/loggingmacros.h>
#include <consoleappender.h>
#include <fileappender.h>
#include <socketappender.h>
#include <tstring.h>
#include <iostream>
#include "Class1.h"
using namespace log4cplus;

int
main()
{
    // Initialization and deinitialization.
    log4cplus::Initializer initializer;

//    log4cplus::BasicConfigurator config;
//    config.configure();

//    log4cplus::Logger logger = log4cplus::Logger::getInstance(
//        LOG4CPLUS_TEXT("test"));
//    logger.setLogLevel(log4cplus::INFO_LOG_LEVEL);
//    LOG4CPLUS_DEBUG(logger, LOG4CPLUS_TEXT("Hello, World!"));

        //Initialize with the Initializer class
//    log4cplus::Initializer initializer;
//    log4cplus::Appender;

        //Step 1: Create ConsoleAppender

//    log4cplus::SharedAppenderPtr appender(new log4cplus::ConsoleAppender());

//        //Step 2: Set the name and output format of Appender (SimpleLayout)
//    appender->setName(LOG4CPLUS_TEXT("console"));
//    tstring pattern = LOG4CPLUS_TEXT("%D{%y-%m-%d %H:%M:%S,%Q} [%t] %-5p %c{2} - %m [%l]%n");
//    appender->setLayout(std::unique_ptr<log4cplus::Layout>(new PatternLayout(pattern)));
////    appender->setLayout(std::unique_ptr<log4cplus::Layout>(new log4cplus::SimpleLayout));

//    // create FileAppender
//    tstring fileName = LOG4CPLUS_TEXT("mylog.log");
//    log4cplus::SharedAppenderPtr fileAppender(new log4cplus::FileAppender(fileName, std::ios_base::app));
//    fileAppender->setName(LOG4CPLUS_TEXT("file"));

//    fileAppender->setLayout(std::unique_ptr<log4cplus::Layout>(new PatternLayout(pattern)));

        //Step 3: Obtain a Logger instance and set its log output level threshold
    // log to Server
//    log4cplus::SharedAppenderPtr server(new SocketAppender(LOG4CPLUS_TEXT("1272.21.100.164"), 8977, LOG4CPLUS_TEXT("test")));
//    server->setName(LOG4CPLUS_TEXT("logserver"));
//    log4cplus::Logger logger = log4cplus::Logger::getInstance(LOG4CPLUS_TEXT ("MAIN"));
//    logger.setLogLevel(log4cplus::INFO_LOG_LEVEL);

//        //Step 4: Add ConsoleAppender to Logger instance
//    logger.addAppender(server);

    PropertyConfigurator::doConfigure(LOG4CPLUS_TEXT("log.properties"));
    Logger logger_root = Logger::getRoot();
    Logger myroot = Logger::getInstance("myroot");
    SharedAppenderPtr console = myroot.getAppender(LOG4CPLUS_TEXT("STDOUT"));
//    LOG4CPLUS_TRACE(logger, LOG4CPLUS_TEXT("printMessages()"));
//    LOG4CPLUS_DEBUG(logger, LOG4CPLUS_TEXT("This is a DEBUG message"));
//    LOG4CPLUS_INFO(logger, LOG4CPLUS_TEXT("This is a INFO message"));
//    LOG4CPLUS_WARN(logger, LOG4CPLUS_TEXT("This is a WARN message"));
//    LOG4CPLUS_ERROR(logger, LOG4CPLUS_TEXT("This is a ERROR message"));
//    LOG4CPLUS_FATAL(logger, LOG4CPLUS_TEXT("This is a FATAL message"));
    Logger log2 = Logger::getInstance("test2");

    //Logger logger = Logger::getInstance(LOG4CPLUS_TEXT("test1"));
    log2.addAppender(console);

    Logger log1 = Logger::getInstance("test1");
    log1.addAppender(console);
    std::cout << myroot.getAppender(LOG4CPLUS_TEXT("STDOUT")) << "\n";
//    log4cplus::SharedAppenderPtr console =  log1.getAppender(LOG4CPLUS_TEXT("STDOUT"));
//    log1.addAppender(console);

    LOG4CPLUS_TRACE(log1, LOG4CPLUS_TEXT("printMessages()"));
    LOG4CPLUS_DEBUG(log1, LOG4CPLUS_TEXT("This is a DEBUG message"));
    LOG4CPLUS_INFO(log1, LOG4CPLUS_TEXT("This is a INFO message"));
    LOG4CPLUS_WARN(log1, LOG4CPLUS_TEXT("This is a WARN message"));
    LOG4CPLUS_ERROR(log1, LOG4CPLUS_TEXT("This is a ERROR message"));
    LOG4CPLUS_FATAL(log1, LOG4CPLUS_TEXT("This is a FATAL message"));




    LOG4CPLUS_TRACE(log2, LOG4CPLUS_TEXT("printMessages()"));
    LOG4CPLUS_DEBUG(log2, LOG4CPLUS_TEXT("This is a DEBUG message"));
    LOG4CPLUS_INFO(log2, LOG4CPLUS_TEXT("This is a INFO message"));
    LOG4CPLUS_WARN(log2, LOG4CPLUS_TEXT("This is a WARN message"));
    LOG4CPLUS_ERROR(log2, LOG4CPLUS_TEXT("This is a ERROR message"));
    LOG4CPLUS_FATAL(log2, LOG4CPLUS_TEXT("This is a FATAL message"));

//        Step 5: Use a macro to output the log
//    LOG4CPLUS_WARN(logger, LOG4CPLUS_TEXT("test logserver"));
//    Class1 a;
//    a.run();
    return 0;
}
