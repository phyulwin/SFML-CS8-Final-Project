//
// Created by Kelly Lwin on 3/24/2023.
//
#include "Item.h"
Item::Item(): Item("") {

}

Item::Item(const std::string& itemName) : itemName(itemName) {
    itemName_.setString(itemName);
    setupSfText();
}

std::string Item::getString() const {
    return itemName;
}

void Item::setPosition(const sf::Vector2f &pos) {
//    itemName_.setPosition(pos);
    box.setPosition(pos);
    itemName_.setPosition({box.getPosition().x+5, box.getPosition().y});
}

void Item::setupSfText() {
    font.loadFromFile("Fonts/monogram.ttf");
    itemName_.setFont(font);
    itemName_.setFillColor(white);
    itemName_.setCharacterSize(charSize);

    setBoxSize(200, 50);
    box.setFillColor(black);
    box.setOutlineColor(sf::Color::Green);

    itemName_.setPosition(50, 50);
    box.setPosition(50, 50);
}

void Item::setBoxSize(const float &x, const float &y) {
    setBoxSize({x, y});
}

void Item::setBoxSize(const sf::Vector2f &boxSize) {
    box.setSize(boxSize);
}

float Item::getBoxHeight() const {
    return box.getSize().y;
}

float Item::getBoxWidth() const {
    return box.getSize().x;
}

sf::FloatRect Item::getGlobalBounds() const {
    return box.getGlobalBounds();
}

void Item::showBoxOutline() {
    showBoxOutline(1);
}

void Item::showBoxOutline(const float &thickness) {
    box.setOutlineThickness(thickness);
    box.setOutlineColor(red); //default color is red
}

void Item::showBoxOutline(const float &thickness, const sf::Color &color) {
    box.setOutlineThickness(thickness);
    box.setOutlineColor(color);
}

void Item::changeBoxColor() {
    box.setFillColor(blue);
}

void Item::changeBoxColor(const sf::Color &color) {
    box.setFillColor(color);
}

void Item::changeCharSize(const unsigned int &charSize) {
    itemName_.setCharacterSize(charSize);
}

void Item::setItemText(const std::string &itemText) {
    itemName_.setString(itemText);
}

void Item::addEventHandler(sf::RenderWindow &window, sf::Event event) {

}

void Item::update() {

}

void Item::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if(clickable) {
        target.draw(box);
        target.draw(itemName_);
    }
}

