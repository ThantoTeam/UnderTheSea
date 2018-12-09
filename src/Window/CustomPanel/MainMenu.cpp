/*
 * MainMenu.cpp
 *
 *  Created on: 4 nov. 2018
 *      Author: antonin
 */

#include "MainMenu.h"

#include <iostream>

#include "../Texture.h"
#include "../Widget/ImageWidget.h"
#include "../Window.h"


namespace ta
{

MainMenu::MainMenu()
{
}

MainMenu::~MainMenu()
{
}  



void MainMenu::setup(Window *window)
{
	//background
	sf::Texture texture = Texture::loadTextureFromFile(
			"assets/image/MainMenu/background.jpg");
	window->addTexture(&texture);
	new ImageWidget(&texture, this);
}

} /* namespace ta */
