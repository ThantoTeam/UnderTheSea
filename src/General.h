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
}  // namespace general



}  // namespace ta


#endif
