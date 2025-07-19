//
// Created by Kelly Lwin on 3/19/2023.
//

#ifndef SFML_TEMPLATE_LETTER_H
#define SFML_TEMPLATE_LETTER_H
#include <SFML\Graphics.hpp>
class Letter: public sf::Text {
private:
    sf::Font font;
public:
    Letter() {
        font.loadFromFile("Fonts/monogram.ttf");
        setFillColor(sf::Color::Black);
        setFont(font);
    }
    explicit Letter(const char& letter) {
        font.loadFromFile("Fonts/monogram.ttf");
        setFillColor(sf::Color::Black);
        setFont(font);
        setString(letter);
    }
    Letter(const sf::Font& font) {
        setFont(font);
    }
};
#endif //SFML_TEMPLATE_LETTER_H
