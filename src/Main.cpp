#include <SFML/Window/VideoMode.hpp>
#include <cstdlib>
#include <iostream>

#include "General.h"
#include "Window/CustomPanel/MainMenu.h"
#include "Window/TextureLoader.h"
#include "Window/Window.h"

int main()
{
    std::cout << ta::general::testFileExist("null") << std::endl;
    std::cout << ta::general::testFileExist(DEFAULT_TEXTURE) << std::endl;

    return 0;
    ta::Window *win = new ta::Window(sf::VideoMode(200, 200), "Test");
    
    ta::MainMenu *mainMenu = new ta::MainMenu();
    win->changePanel(mainMenu);
    
    win->run();
    
    delete win;
    return EXIT_SUCCESS;
}
