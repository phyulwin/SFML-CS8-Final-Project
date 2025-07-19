//
// Created by Kelly Lwin on 3/14/2023.
//

#ifndef SFML_TEMPLATE_TEXTINPUT_H
#define SFML_TEMPLATE_TEXTINPUT_H
#include <iostream>
#include <SFML\Graphics.hpp>

#include "TextBox.h"
#include "Typing.h"

class TextInput: public sf::Drawable {
public:
    TextBox textBox;
public:
    TextInput();
    //
    void changeFont();
    void changeTextColor();
    void changeTextSize();

    void setUpTyping();

    //label functions
    void setBoxSize(const sf::Vector2f& size);
    void setLabel(const std::string& str);
    void setLabelSize(const unsigned int& size);
    typedef int dimensions[4];
    void setLabelMargin(const dimensions& margins);
    void setPosition(const sf::Vector2f& position);

    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};

#endif //SFML_TEMPLATE_TEXTINPUT_H
