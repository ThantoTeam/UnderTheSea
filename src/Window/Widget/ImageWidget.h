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
	ImageWidget(sf::Texture *texture);
	virtual ~ImageWidget();

	virtual void draw(sf::RenderWindow* win) override;

	void setTexture(sf::Texture *texture);

	sf::Texture* texture() const;
	sf::Sprite* sprite() const;

private:
	void createSprite();

	sf::Texture *m_texture;
	sf::Sprite *m_sprite;
};

} /* namespace ta */

#endif /* SRC_WINDOW_WIDGET_IMAGEWIDGET_H_ */
