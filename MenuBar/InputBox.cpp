//
// Created by Kelly Lwin on 3/24/2023.
//

#include "InputBox.h"

InputBox::InputBox(): InputBox("") {

}

InputBox::InputBox(const std::string &firstItem_) {
    firstItem.setItemText(firstItem_);
    firstItem.showBoxOutline();
}

void InputBox::changeItem(const std::string &newItem) {
    firstItem.setItemText(newItem);
}

void InputBox::changeBoxColor(const sf::Color &color) {
    firstItem.changeBoxColor(color);
}

void InputBox::changeTextColor(const sf::Color &color) {
    firstItem.changeTextColor(color);
}

float InputBox::getBoxWidth() const {
    return firstItem.getBoxWidth();
}

void InputBox::setBoxPos(const sf::Vector2f &pos) {
    firstItem.setPosition(pos);
}

void InputBox::resizeBox(const sf::Vector2f &size) {
    firstItem.setBoxSize(size);
}

sf::FloatRect InputBox::getGlobalBounds() const {
    return firstItem.getGlobalBounds();
}

void InputBox::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(firstItem);
}
