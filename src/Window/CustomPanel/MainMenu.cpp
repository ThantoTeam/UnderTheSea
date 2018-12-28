/*
 * MainMenu.cpp
 *
 *  Created on: 4 nov. 2018
 *      Author: antonin
 */

#include "MainMenu.h"

#include <SFML/Graphics/Rect.hpp>

#include "../TextureLoader.h"
#include "../Widget/ImageWidget.h"
#include "../Window.h"


namespace ta
{

MainMenu::MainMenu()
{
    m_parent = 0;
}

MainMenu::~MainMenu()
{
    // deload texture
}  



void MainMenu::setup(Window *window)
{
    // load texture
    //background
    window->textureLoader()->loadTextureFromFile(
            "image/MainMenu/background.jpg", sf::IntRect(),
            "MainMenuBackground");

    ImageWidget *img = new ImageWidget(
            window->textureLoader()->getTexture("MainMenuBackground"),
            this);
    
    img->Widget::setDimention(700, 500);
    
}

} /* namespace ta */
