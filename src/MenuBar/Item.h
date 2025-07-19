//
// Created by Kelly Lwin on 3/24/2023.
//

#ifndef SFML_TEMPLATE_ITEM_H
#define SFML_TEMPLATE_ITEM_H
#include <iostream>
#include <string>
#include <SFML\Graphics.hpp>

#include "../MouseEvents.h"

class Item: public sf::Drawable {
private:
    sf::Font font;
    const sf::Color black = sf::Color::Black;
    const sf::Color white = sf::Color::White;
    const sf::Color red = sf::Color::Red;
    const sf::Color blue = sf::Color::Blue;

    const unsigned int charSize = 30;
private:
    bool clickable = true;
private:
    std::string itemName;
    sf::Text itemName_;

    sf::RectangleShape box;

    void setupSfText();
public:
    Item();
    Item(const std::string& itemName);

    std::string getString() const;

    void changeTextColor(const sf::Color& color) {
        itemName_.setFillColor(color);
    }
    void setPosition(const sf::Vector2f& pos);

    void setBoxSize(const float& x, const float& y);
    void setBoxSize(const sf::Vector2f& boxSize);
    float getBoxHeight() const;
    float getBoxWidth() const;

    sf::FloatRect getGlobalBounds() const;

    //if the item is first in the list, show outline
    void showBoxOutline();
    void showBoxOutline(const float& thickness);
    void showBoxOutline(const float& thickness, const sf::Color& color);

    void changeBoxColor(); //change box color when hovered
    void changeBoxColor(const sf::Color& color);

    void changeCharSize(const unsigned int& charSize);
    void setItemText(const std::string& itemText);

    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
public:
    void turnOffClickable() {
        clickable = false;
    }
    void turnOnClickable() {
        clickable = true;
    }
    void toggleClickable() {
        if(clickable) {
            clickable = false;
        } else {
            clickable = true;
        }
    }
protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};

#endif //SFML_TEMPLATE_ITEM_H
//Item - This is a simple item in the list, it should consist of a simple box with the item name centered.