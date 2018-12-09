/*
 * Panel.h
 *
 *  Created on: 7 nov. 2018
 *      Author: antonin
 */

#ifndef SRC_WINDOW_PANEL_H_
#define SRC_WINDOW_PANEL_H_

#include "Widget/Widget.h"

namespace ta
{
class Window;
} /* namespace ta */

namespace ta {

class Panel: public Widget {
public:
	virtual void setup(Window *win) = 0; // just add setup methode
};

} /* namespace ta */

#endif /* SRC_WINDOW_PANEL_H_ */
