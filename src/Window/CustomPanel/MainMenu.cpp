/*
 * MainMenu.cpp
 *
 *  Created on: 4 nov. 2018
 *      Author: antonin
 */

#include "MainMenu.h"

#include <iostream>

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
    this->~Widget();
}  



void MainMenu::setup(Window *window)
{
    //background
//    window->addTexture(&texture);
//    new ImageWidget(&texture, this);
}

} /* namespace ta */
