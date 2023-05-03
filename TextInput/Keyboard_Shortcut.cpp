//
// Created by Kelly Lwin on 3/9/2023.
//
//#ifndef SFML_TEMPLATE_KEYBOARD_SHORTCUT_CPP
//#define SFML_TEMPLATE_KEYBOARD_SHORTCUT_CPP

#include "Keyboard_Shortcut.h"
bool Keyboard_Shortcut::isUndo(sf::RenderWindow &window, sf::Event event) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LControl) &&
        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z)) {
        return true;
    }
    return false;
}
//#endif //SFML_TEMPLATE_KEYBOARD_SHORTCUT_CPP

