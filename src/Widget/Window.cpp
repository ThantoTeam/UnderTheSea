/*
 * Window.cpp
 *
 *  Created on: 29 oct. 2018
 *      Author: antonin
 */

#include "Window.h"

#include <SFML/Graphics/RenderWindow.hpp>

namespace ta {

Window::Window(Widget *panel) :
		RenderWindow(sf::VideoMode(250, 250), "An application"),
		m_currentPanel(
				panel) {
}

Window::Window(sf::VideoMode mode, sf::String title, Widget *panel) :
		RenderWindow(mode, title), m_currentPanel(panel) {
	
}

Window::~Window() {
	deleteCurrentPanel();
}

Widget * Window::currentPanel() {
	return m_currentPanel;
}

void Window::changePanel(Widget* panel) {
	deleteCurrentPanel();

	m_currentPanel = panel;
}

bool Window::deleteCurrentPanel() {
	if (m_currentPanel != 0) {
		delete m_currentPanel;
		m_currentPanel = 0;

		return true;
	}

	return false;
}

void Window::update() {

	if (m_currentPanel == 0)
		return;
	
	this->clear();
	
}

} /* namespace ta */
