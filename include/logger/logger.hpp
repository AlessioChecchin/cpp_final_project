/**
 * Stream overload template.
 * 
 * @author Jacopo Toniolo
 */
#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <iostream>
#include <fstream>
#include "logger/logger.h"

namespace prj
{

template <typename T>
logger& operator<<(logger& log, const T& obj)
{
    // Send log to log.txt.
    if(log.file_.is_open())
        log.file_ << obj;
    
    // Flush.
    log.file_.flush();

    // Send log to standard output.
    std::cout << obj;

    return log;
}

} // prj

#endif // LOGGER_HPP