#include <SFML/Window/VideoMode.hpp>
#include <cstdlib>

#include "Window/CustomPanel/MainMenu.h"
#include "Window/Window.h"

int main()
{
    ta::Window *win = new ta::Window(sf::VideoMode(200, 200), "Test");
    ta::MainMenu *panel = new ta::MainMenu();
    win->changePanel(panel);

    
    win->run();
    
    delete win;
    return EXIT_SUCCESS;
}
