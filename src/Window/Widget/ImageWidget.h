/*
 * ImageWidget.h
 *
 *  Created on: 9 nov. 2018
 *      Author: PyJaC++
 */

#ifndef SRC_WINDOW_WIDGET_IMAGEWIDGET_H_
#define SRC_WINDOW_WIDGET_IMAGEWIDGET_H_

#include "Dimention.h"
#include "Widget.h"

namespace sf
{
class Sprite;
class Texture;
} /* namespace sf */

namespace ta
{

class ImageWidget: public Widget
{
public:
    ImageWidget(Widget *parent = 0);
    ImageWidget(sf::Texture* texture, Widget *parent = 0);
    virtual ~ImageWidget();

    virtual void draw(sf::RenderWindow* win) override;

    virtual void setDimention(Dimention<int>) override;

    void setTexture(sf::Texture* texture);

    sf::Sprite* sprite() const;

private:
    void createSprite();

    sf::Sprite *m_sprite;
};

} /* namespace ta */

#endif /* SRC_WINDOW_WIDGET_IMAGEWIDGET_H_ */
