/*
 * Widget.cpp
 *
 *  Created on: 23 oct. 2018
 *      Author: PyJaC++
 */

#include "Widget.h"

#include <stddef.h>
#include <iterator>

#include "../../General.h"


namespace ta {

Widget::Widget(Widget* parent, bool isDisable) :
        m_disable(isDisable)
{
    if (parent != NULL && parent != 0)
    {
        parent->addChild(this);

        m_parent = parent;
    }

    m_dimention.width = 0;
    m_dimention.height = 0;

    m_position = sf::Vector2f(0, 0);
}

Widget::Widget(Dimention<int> dim, Widget* parent, bool isDisable) :
        m_dimention(dim), m_disable(isDisable)
{
    if (parent != NULL && parent != 0)
    {
        parent->addChild(this);

        m_parent = parent;
    }

    setDimention(dim);

}

Widget::Widget(sf::Vector2<float> pos, Dimention<int> dim, Widget *parent,
        bool isDisable) :
        m_parent(parent), m_disable(isDisable)
{
    if (parent != 0)
    {
        parent->addChild(this);
    }

    setDimention(dim);
    setPosition(pos);
}

Widget::~Widget()
{
    if (m_parent != 0)
        m_parent->removeChild(this);
    
    deleteAllChilds();
}

void Widget::addChild(Widget *child)
{
    m_listChild.push_back(child);
}

void Widget::removeChild(Widget *child)
{

    for (std::vector<Widget*>::iterator it = m_listChild.begin();
            it != m_listChild.end(); ++it)
    {

        if (child == *it)
        {
            m_listChild.erase(it);
            return;
        }

    }
    
}

void Widget::deleteAllChilds()
{
    while (m_listChild.size() > 0)
    {
        delete m_listChild.at(0);
    }
}

void Widget::draw(sf::RenderWindow *win)
{
}

void Widget::onEvent(const sf::Event &event)
{
    for (Widget* currentWidget : m_listChild)
    {
        currentWidget->onEvent(event);
    }
}

void Widget::drawAllChild(sf::RenderWindow *win)
{
    draw(win);

    for (Widget* currentWidget : m_listChild)
    { 
        currentWidget->drawAllChild(win);
    }
}

bool Widget::setPosition(float x, float y)
{ 
    return setPosition(sf::Vector2f(x, y));
}

bool Widget::setPosition(sf::Vector2<float> pos)
{ 
    bool returnBool = true;
    
    m_position = pos;
    
    if (m_parent != 0)
    {
        // test if x pis too small or to big
        if (pos.x < m_parent->position().x)
        {
            returnBool = false;
            m_position.x = m_parent->position().x;
        } else if (pos.x + m_dimention.width
                > m_parent->position().x + m_parent->dimention().width)
        {
            returnBool = false;
            m_position.x = m_parent->m_dimention.width - m_dimention.width
                    + m_parent->position().x;
        }
        // idem but for y
        if (pos.y < m_parent->position().y)
        {
            returnBool = false;
            m_position.y = m_parent->position().y;
        }
        else if (pos.y + m_dimention.height
                > m_parent->position().y + m_parent->dimention().height)
        {
            returnBool = false;
            m_position.y = m_parent->m_dimention.height - m_dimention.height
                    + m_parent->position().y;
        }
    }

    return returnBool;
}

bool Widget::move(int x, int y)
{
    return setPosition(x + m_position.x, y + m_position.y);
}

void Widget::setDimention(int width, int height)
{
    Dimention<int> dim;
    
    dim.width = width;
    dim.height = height;
    
    setDimention(dim);
}

void Widget::setDimention(Dimention<int> dim)
{
    if (dim.height == 0 && dim.width == 0)
    {
        if (m_parent != 0)
        {
            dim = m_parent->dimention();
        }
    }
    m_dimention = dim;
}

sf::Vector2<float> Widget::position() const
{
    return m_position;
}

Dimention<int> Widget::dimention() const
{
    return m_dimention;
}

void Widget::setDisable(bool disable)
{
    m_disable = disable;

    for (Widget* currentWidget : m_listChild)
    {
        currentWidget->setDisable(disable);
    }
}

bool Widget::isDisable() const
{
    return m_disable;
}

} /* namespace Thanto */
