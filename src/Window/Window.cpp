/*
 * Window.cpp
 *
 *  Created on: 29 oct. 2018
 *      Author: antonin
 */

#include "Window.h"

#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>

#include "Widget/Widget.h"

namespace ta {

Window::Window(Widget *panel) :
		RenderWindow(sf::VideoMode(250, 250), "An application") {
			changePanel(panel);
}

Window::Window(sf::VideoMode mode, sf::String title, Widget *panel) :
		RenderWindow(mode, title) {
	changePanel(panel);
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
	
	clear();
	m_currentPanel->drawAllChild(*this);
	display();
	
}

void Window::run() {
	m_stopRun = false;

	while (isOpen()) {

		if (m_stopRun) {
			break;
		}
		
		sf::Event event;
		while (pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				close();
			}
	}
	update();
	}
}

void Window::stopRun() {
	m_stopRun = true;
}

} /* namespace ta */
