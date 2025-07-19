//
// Created by Kelly Lwin on 4/25/2023.
//

#ifndef SFML_TEMPLATE_HELPERCLASS_H
#define SFML_TEMPLATE_HELPERCLASS_H
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Font.h"
#include "States.h"
#include "MouseEvents.h"

class PhonyButton: public sf::RectangleShape, public States {
private:

public:
    PhonyButton() {
        setSize({150, 50});
        setFillColor(sf::Color::Transparent);
        setPosition({100, 100});
    }
};

class Button: public sf::Drawable {
private:
    sf::RectangleShape box;
    sf::Text buttonText;
    std::string string="Button";
    sf::Font font;
public:
    Button() {
        setSize({100, 50});
        setColor({sf::Color::Blue});
        Font::defaultFont(buttonText, font, string);
    }

    void setPosition(const sf::Vector2f& pos) {
        box.setPosition(pos);
        buttonText.setPosition({pos.x+10, pos.y});
    }
    void setSize(const sf::Vector2f& size) {box.setSize(size);}
    void setColor(const sf::Color& color) {box.setFillColor(color);}

    void setButtonText(const std::string& text) {
        string = text;
        buttonText.setString(string);
    }

    sf::FloatRect getGlobalBounds() const {
        return box.getGlobalBounds();
    }

    void addEventHandler(sf::RenderWindow& window, sf::Event event) {
        if(MouseEvents::isClicked(box, window)) {
            setColor(sf::Color::Red);
        }
        if(MouseEvents::isNotClicked(box, window)) {
            setColor(sf::Color::Green);
        }
    }
    void update() {
    }
protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override {
        target.draw(this->box);
        target.draw(buttonText);
    }
};

#endif //SFML_TEMPLATE_HELPERCLASS_H
