/*
 * MainMenu.h
 *
 *  Created on: 4 nov. 2018
 *      Author: antonin
 */

#ifndef SRC_WINDOW_CUSTOMPANEL_MAINMENU_H_
#define SRC_WINDOW_CUSTOMPANEL_MAINMENU_H_

#include "../Panel.h"

namespace ta {

class MainMenu: public Panel {
public:
	MainMenu();
	virtual ~MainMenu();

	virtual void setup();
};

} /* namespace ta */

#endif /* SRC_WINDOW_CUSTOMPANEL_MAINMENU_H_ */
