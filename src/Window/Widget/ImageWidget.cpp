/*
 * ImageWidget.cpp
 *
 *  Created on: 9 nov. 2018
 *      Author: antonin
 */

#include "ImageWidget.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

namespace ta
{

ImageWidget::ImageWidget(Widget *parent) :
        Widget(parent)
{
    createSprite();
}

ImageWidget::ImageWidget(sf::Texture* texture, Widget *parent) :
        Widget(parent)
{
    createSprite();

    setTexture(texture);
}

ImageWidget::~ImageWidget()
{
    m_sprite->setTexture(sf::Texture(), true);

    delete m_sprite;
}

void ImageWidget::createSprite()
{
    m_sprite = new sf::Sprite();
}

void ImageWidget::draw(sf::RenderWindow *win)
{
    win->draw(*m_sprite);
}

void ImageWidget::setDimention(Dimention<int> dim)
{
    m_sprite->setScale(dim.width / m_sprite->getLocalBounds().width,
            dim.height / m_sprite->getLocalBounds().height);
}

void ImageWidget::setTexture(sf::Texture* texture)
{
    m_sprite->setTexture(*texture);
}

sf::Sprite *ImageWidget::sprite() const
{
    return m_sprite;
}

} /* namespace ta */
