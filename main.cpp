/**
 * @file main.cpp
 * @brief This file contains the main function that initializes the graphical interface and handles user interactions.
 */

#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

#include "Interface.h" // Include the Interface class definition

/**
 * @brief The main entry point of the application.
 * @return An integer indicating the exit status of the application.
 */
int main() {
    srand((unsigned) time(NULL)); // Seed the random number generator

    // Create a window with specified dimensions and title
    sf::RenderWindow window(sf::VideoMode(1500, 844, 32), "Window Desktop");
    window.setFramerateLimit(60); // Set the maximum framerate for the window

    Interface interface; // Create an instance of the Interface class

    // Save sample test files to the interface
    interface.saveFile("Quick-Notes", "Math equation.txt", "1+2=4");
    interface.saveFile("Quick-Notes", "English.txt", "I am an Apple.");

    // Add sample deleted files to the interface
    interface.addDeletedFile("Hello World.txt", "hello world");
    interface.addDeletedFile("Empty Note.txt", "no data");

    // Main loop for handling events and updating the interface
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close(); // Close the window if the close event is triggered
            }
            interface.addEventHandler(window, event); // Handle events for the interface
        }
        
        interface.update(); // Update the interface

        window.clear(sf::Color::Black); // Clear the window with a black background
        window.draw(interface); // Draw the interface components
        window.display(); // Display the contents of the window
    }
    
    return 0; // Return 0 to indicate successful program execution
}
