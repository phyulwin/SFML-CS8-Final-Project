#include <iostream>
#include <cstdlib>
#include <SFML\Graphics.hpp>

#include "Interface.h"

int main() {
    srand((unsigned) time(NULL));

    sf::RenderWindow window(sf::VideoMode(1500, 844, 32), "Window Desktop");
    window.setFramerateLimit(60);

    Interface interface;
    //save sample test files
    interface.saveFile("Quick-Notes", "Math equation.txt", "1+2=4");
    interface.saveFile("Quick-Notes", "English.txt", "I am an Apple.");
    //save sample deleted files
    interface.addDeletedFile("Hello World.txt", "hello world");
    interface.addDeletedFile("Empty Note.txt", "no data");

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
            interface.addEventHandler(window, event);
        }
        interface.update();

        window.clear(sf::Color::Black);
        window.draw(interface);
        window.display();
    }
    return 0;
}
