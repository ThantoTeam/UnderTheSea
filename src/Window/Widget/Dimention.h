/*
 * Dimention.h
 *
 *  Created on: 29 oct. 2018
 *      Author: antonin
 */

#ifndef SRC_WIDGET_DIMENTION_H_
#define SRC_WIDGET_DIMENTION_H_

namespace ta
{

template<typename T>
struct Dimention
{
	int width;
	int height;
};

Dimention<int> dimention(int x, int y);
Dimention<float> dimention(float x, float y);


} /* namespace ta */

#endif /* SRC_WIDGET_DIMENTION_H_ */
