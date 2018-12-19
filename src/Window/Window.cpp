/*
 * Window.cpp
 *
 *  Created on: 29 oct. 2018
 *      Author: antonin
 */

#include "Window.h"

#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <iostream>

#include "Panel.h"

namespace ta
{

Window::Window(Panel *panel) :
        RenderWindow(sf::VideoMode(250, 250), "An application")
{
    changePanel(panel);

    m_view = getDefaultView();
}

Window::Window(sf::VideoMode mode, sf::String title, Panel *panel) :
        RenderWindow(mode, title)
{
    changePanel(panel);

    m_view = getDefaultView(); // to correct resize
}

Window::~Window()
{
    deleteCurrentPanel();
}

Panel * Window::currentPanel()
{
    return m_currentPanel;
}

void Window::changePanel(Panel* panel)
{
    deleteCurrentPanel();

    if (panel != 0) {
        m_currentPanel = panel;

        m_currentPanel->setup(this);
    }
}

bool Window::deleteCurrentPanel()
{
    if (m_currentPanel != 0)
    { 
        delete m_currentPanel;
        m_currentPanel = 0;

        return true;
    }

    return false;
}

void Window::addTexture(const sf::Texture *texture)
{
    listTexture.push_back(*texture);
}

void Window::removeTexture(sf::Texture *texture)
{
//    TODO: remove texture
//    for (std::vector<sf::Texture>::iterator it = listTexture.begin();
//            it != listTexture.end(); it++)
//    {
//        if (*it == *texture)
//        {
//            listTexture.erase(it);
//        }
//    }
}

void Window::update()
{
    
    if (m_currentPanel == 0)
        return;
    
    clear();
    m_currentPanel->drawAllChild(this);
    display();
    
}

void Window::run()
{
    m_stopRun = false;

    while (isOpen())
    {

        if (m_stopRun)
        {
            break;
        }
        
        sf::Event event;
        while (pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                close();
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                std::cout << event.mouseButton.x << "x " << event.mouseButton.y
                        << "y" << std::endl;
            }
    }
    update();
    }
}

void Window::stopRun()
{
    m_stopRun = true;
}

} /* namespace ta */
