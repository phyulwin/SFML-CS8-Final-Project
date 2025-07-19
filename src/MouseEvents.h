//
// Created by Kelly Lwin on 3/9/2023.
//

#ifndef SFML_TEMPLATE_MOUSEEVENTS_H
#define SFML_TEMPLATE_MOUSEEVENTS_H
#include <iostream>
#include <SFML\Graphics.hpp>

class MouseEvents {
private:

public:
    template<class T>
    static bool isHover(const T& Obj, const sf::RenderWindow &window );
    template<class T>
    static bool isClicked(const T& Obj, const sf::RenderWindow &window );
    template<class T>
    static bool isNotClicked(const T& Obj, const sf::RenderWindow &window );

/*
    // returns true if the mouse clicks on the object
    static bool mouseClicked(T& object, sf::RenderWindow& window);

    // returns true if the mouse clicks anywhere in the window
    static bool mouseClicked( sf::RenderWindow& window, sf::Event event);

    // returns true if the mouse has been double clicked
    static bool mouseDoubleClicked();

    //returns true if the mouse has been triple clicked
    static bool mouseTripleClicked();

    // returns if the object has been clicked and the mouse has dragged over the object
    static bool draggedOver(T& object, sf::RenderWindow& window, sf::Event event);

    // returns tru if the mouse is hovered over the object
    static bool hovered(T& object, sf::RenderWindow& window);*/
};
#include "MouseEvents.cpp"
#endif //SFML_TEMPLATE_MOUSEEVENTS_H
