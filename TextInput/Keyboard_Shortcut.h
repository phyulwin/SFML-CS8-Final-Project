//
// Created by Kelly Lwin on 3/9/2023.
//

#ifndef SFML_TEMPLATE_KEYBOARD_SHORTCUT_H
#define SFML_TEMPLATE_KEYBOARD_SHORTCUT_H
#include <SFML\Graphics.hpp>

class Keyboard_Shortcut {
public:
    static bool isUndo(sf::RenderWindow &window, sf::Event event);
};

#endif //SFML_TEMPLATE_KEYBOARD_SHORTCUT_H
