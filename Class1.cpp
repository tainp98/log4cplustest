#include "Class1.h"
Class1::Class1()
{

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
    Log logger("Class2", Log::LogLevel::INFO);
    Logger mylog = logger.getLogger();

    LOG4CPLUS_TRACE(mylog, LOG4CPLUS_TEXT("printMessages()"));
    LOG4CPLUS_DEBUG(mylog, LOG4CPLUS_TEXT("This is a DEBUG message"));
    LOG4CPLUS_INFO(mylog, LOG4CPLUS_TEXT("This is a INFO message"));
    LOG4CPLUS_WARN(mylog, LOG4CPLUS_TEXT("This is a WARN message"));
    LOG4CPLUS_ERROR(mylog, LOG4CPLUS_TEXT("This is a ERROR message"));
    LOG4CPLUS_FATAL(mylog, LOG4CPLUS_TEXT("This is a FATAL message"));

    mylog.shutdown();


}
