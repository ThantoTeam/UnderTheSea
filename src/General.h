/*
 * General.h
 *
 *  Created on: 9 déc. 2018
 *      Author: PyJaC++
 */
#ifndef GENERAL_H_
#define GENERAL_H_

#include <string>

namespace ta
{
namespace log
{

void log(std::string msg);
void warm(std::string msg);
void error(std::string msg);

}  // namespace log

namespace general
{
std::string getCurrentStringTime();

bool testFileExist(std::string filePath);

template<typename T>
/* return a map of a number
 * \param var: the var to convert
 * \param varMin: the min of var
 * \param varMax: the max of var
 * \param outputMin: the min of output
 * \param outputMax: the max of output */
T map(T var, T varMin, T varMax, T outputMin, T outputMax)
{
    return (T) ((var - varMin) / (double) (varMax - varMin)
            * (outputMax - outputMin) + outputMin);
}
}  // namespace general



}  // namespace ta


#endif
