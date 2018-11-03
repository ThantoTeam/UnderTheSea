/*
 * Window.h
 *
 *  Created on: 29 oct. 2018
 *      Author: antonin
 */

#ifndef SRC_WIDGET_WINDOW_H_
#define SRC_WIDGET_WINDOW_H_

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/String.hpp>

namespace ta {
class Widget;
} /* namespace ta */

namespace ta {

class Window: public sf::RenderWindow {
public:
	Window(Widget *panel = 0);
	Window(sf::VideoMode mode, sf::String title, Widget *panel = 0);
	
	virtual ~Window();	
	
	Widget *currentPanel();
	
	void changePanel(Widget * panel);
	bool deleteCurrentPanel();
	
	void update();
	
	void run();
	void stopRun();
	
private:
	
	bool m_stopRun;
	
	Widget *m_currentPanel;
};

} /* namespace ta */

#endif /* SRC_WIDGET_WINDOW_H_ */
