#include <SFML/Window/VideoMode.hpp>
#include <cstdlib>
#include <iostream>

#include "General.h"
#include "Window/CustomPanel/MainMenu.h"
#include "Window/TextureLoader.h"
#include "Window/Window.h"

int main()
{
    ta::Window *win = new ta::Window(
            sf::VideoMode(700, 500), "Under The Sea");
    
    ta::MainMenu *mainMenu = new ta::MainMenu();
    win->changePanel(mainMenu);
    
    win->run();
    
    delete win;
    return EXIT_SUCCESS;
}
