/*
 * ImageWidget.cpp
 *
 *  Created on: 9 nov. 2018
 *      Author: antonin
 */

#include "ImageWidget.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>

namespace ta
{

ImageWidget::ImageWidget(Widget *parent) :
		Widget(parent), m_texture(0), m_autoResize(false)
{
	createSprite();
}

ImageWidget::ImageWidget(sf::Texture *texture, Widget *parent) :
		Widget(parent), m_texture(texture), m_autoResize(false)
{
	createSprite();
}

ImageWidget::~ImageWidget()
{
	this->~Widget();
	
	delete m_sprite;
}

void ImageWidget::createSprite()
{
	m_sprite = new sf::Sprite();

	m_sprite->setTexture(*m_texture);
}

void ImageWidget::draw(sf::RenderWindow *win)
{
	win->draw(*m_sprite);
}

void ImageWidget::setTexture(sf::Texture *texture)
{
	m_texture = texture;
}

void ImageWidget::setAutoResize(const bool &autoResize)
{
	m_autoResize = autoResize;
}

sf::Texture *ImageWidget::texture() const
{
	return m_texture;
}

sf::Sprite *ImageWidget::sprite() const
{
	return m_sprite;
}

bool ImageWidget::autoResize()
{
	return m_autoResize;
}

} /* namespace ta */
