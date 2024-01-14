/**
 * @author Jacopo Toniolo
 */

#include "logger/logger.h"
#include "iostream"
#include <iostream>

namespace prj
{

logger::logger(){
    file_.open("log.txt");
    if(!file_.is_open())
    {
        throw std::runtime_error("Could not open the log file");
    }
}

logger& logger::get_logger()    
{
    static logger logger_;
    return logger_;
}

logger::~logger()
{
    file_.close();
}

/**
 * Necessary to allow std::endl concatenation.
*/
logger& operator<<(logger& log, std::ostream& (*f)(std::ostream&))
{
    log << "\n";
    return log;
}

} // prj.