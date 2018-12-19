/*
 * ImageWidget.h
 *
 *  Created on: 9 nov. 2018
 *      Author: antonin
 */

#ifndef SRC_WINDOW_WIDGET_IMAGEWIDGET_H_
#define SRC_WINDOW_WIDGET_IMAGEWIDGET_H_

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <string>

#include "Widget.h"

namespace ta
{

class ImageWidget: public Widget
{
public:
    ImageWidget(Widget *parent = 0);
    ImageWidget(sf::Texture *texture, Widget *parent = 0);
    virtual ~ImageWidget();

    virtual void draw(sf::RenderWindow* win) override;

    void setTexture(sf::Texture *texture);
    void setAutoResize(const bool &autoResize);

    sf::Texture* texture() const;
    sf::Sprite* sprite() const;
    bool autoResize();

private:
    void createSprite();

    sf::Texture *m_texture;
    sf::Sprite *m_sprite;

    bool m_autoResize;
};

} /* namespace ta */

#endif /* SRC_WINDOW_WIDGET_IMAGEWIDGET_H_ */
