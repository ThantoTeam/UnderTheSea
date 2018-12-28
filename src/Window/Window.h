/*
 * Window.h
 *
 *  Created on: 29 oct. 2018
 *      Author: antonin
 */

#ifndef SRC_WIDGET_WINDOW_H_
#define SRC_WIDGET_WINDOW_H_

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/System/String.hpp>

#include "TextureLoader.h"

#define FRAMERATE_LIMIT 60

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
    
    void update();
    
    void run();
    void stopRun();
    
    void loadTexture();
    
    TextureLoader* textureLoader();
    
private:
    
    void testEvent(sf::Event);
    
    bool m_stopRun;
    

    sf::View m_view;
    
    Panel *m_currentPanel;

    TextureLoader *m_textureLoader;
};

} /* namespace ta */

#endif /* SRC_WIDGET_WINDOW_H_ */
