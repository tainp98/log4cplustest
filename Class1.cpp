#include "Class1.h"
Class1::Class1()
{
    initLog();

}
void Class1::initLog(){
    logger = log4cplus::Logger::getInstance("Class1");
    logger.setLogLevel(log4cplus::INFO_LOG_LEVEL);

    log4cplus::SharedAppenderPtr console(new log4cplus::ConsoleAppender());
    console->setName(LOG4CPLUS_TEXT("console"));
    log4cplus::tstring pattern = LOG4CPLUS_TEXT("%D{%y-%m-%d %H-%M-%S,%Q} [%t] %-5p %c - %m [%l]%n");
    console->setLayout(std::unique_ptr<log4cplus::Layout>(new log4cplus::PatternLayout(pattern)));

    logger.addAppender(console);
}
void Class1::run(){
    std::cout << "running Class1 .... \n";
    LOG4CPLUS_INFO(logger, LOG4CPLUS_TEXT("running info"));
    Logger log2 = Logger::getInstance("test2");
    log2.setLogLevel(log4cplus::TRACE_LOG_LEVEL);
    //Logger logger = Logger::getInstance(LOG4CPLUS_TEXT("test1"));

    Logger log1 = Logger::getInstance("test1");
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

}
