/*
 * Window.h
 *
 *  Created on: 29 oct. 2018
 *      Author: antonin
 */

#ifndef SRC_WIDGET_WINDOW_H_
#define SRC_WIDGET_WINDOW_H_

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/System/String.hpp>
#include <vector>

namespace ta
{ 
class Panel;
} /* namespace ta */

namespace ta
{ 
class Widget;
} /* namespace ta */

namespace ta
{ 



class Window: public sf::RenderWindow
{
public:
	Window(Panel *panel = 0);
	Window(sf::VideoMode mode, sf::String title, Panel *panel = 0);
	
	virtual ~Window();	
	
	Panel *currentPanel();
	
	void changePanel(Panel * panel);
	bool deleteCurrentPanel();
	
	void addTexture(const sf::Texture *texture);
	void removeTexture(sf::Texture *texture);
	
	void update();
	
	void run();
	void stopRun();
	
private:
	
	bool m_stopRun;
	
	sf::View m_view;
	
	Panel *m_currentPanel;
	
	std::vector<sf::Texture> listTexture;
};

} /* namespace ta */

#endif /* SRC_WIDGET_WINDOW_H_ */
