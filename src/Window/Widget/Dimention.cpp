/*
 * Dimention.cpp
 *
 *  Created on: 29 oct. 2018
 *      Author: antonin
 */

#include "Dimention.h"

namespace ta
{

Dimention<int> dimention(int width, int height)
{
	Dimention<int> dim;

	dim.width = width;
	dim.height = height;

	return dim;
}

Dimention<float> dimention(float width, float height)
{
	Dimention<float> dim;

	dim.width = width;
	dim.height = height;

	return dim;
}

}  // namespace ta


