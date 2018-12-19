#include <SFML/Window/VideoMode.hpp>
#include <cstdlib>

#include "Window/CustomPanel/MainMenu.h"
#include "Window/Window.h"

int main()
{
    ta::Window *win = new ta::Window(sf::VideoMode(200, 200), "Test");
    
    ta::MainMenu *mainMenu = new ta::MainMenu();
    win->changePanel(mainMenu);
    
    win->run();
    
    delete win;
    return EXIT_SUCCESS;
}
