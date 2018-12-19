/*
 * General.cpp
 *
 *  Created on: 9 déc. 2018
 *      Author: PyJaC++
 */

#include "General.h"

#include <bits/types/time_t.h>
#include <ctime>
#include <iostream>

#define LENGHT_REPONSE_TIME_STRING 9
#define TIME_STRING_FORMAT "%T"

namespace ta
{
namespace log
{

void log(std::string msg)
{
    std::cout << "log " << "[" << getCurrentStringTime() << "]: " << msg
            << std::endl;
}

void warm(std::string msg)
{
    std::cout << "WARM " << "[" << getCurrentStringTime() << "]: " << msg
            << std::endl;
}

void error(std::string msg)
{
    std::cerr << "ERROR " << "[" << getCurrentStringTime() << "]: " << msg
            << std::endl;
}

}  // namespace log

std::string getCurrentStringTime()
{

    time_t rawtime;

    std::time(&rawtime);
    std::tm *localTime = std::localtime(&rawtime); 

    char reponse[LENGHT_REPONSE_TIME_STRING];
    
    std::strftime(reponse, sizeof(reponse), TIME_STRING_FORMAT, localTime);
    
    return std::string(reponse);
}

}  // namespace ta

