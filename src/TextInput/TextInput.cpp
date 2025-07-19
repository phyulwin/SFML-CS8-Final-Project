//
// Created by Kelly Lwin on 3/14/2023.
//

#include "TextInput.h"

TextInput::TextInput() {
    setUpTyping();
}

void TextInput::changeFont() {
    textBox.changeFont();
}

void TextInput::changeTextColor() {
    textBox.changeTextColor();
}

void TextInput::changeTextSize() {
    textBox.changeTextSize();
}

void TextInput::setUpTyping() {
    //typing.textPosition(textBox.getBoxPosition());
}

void TextInput::setBoxSize(const sf::Vector2f &size) {
    textBox.setBoxSize(size);
}

void TextInput::setLabel(const std::string &str) {
    textBox.setLabel(str);
}

void TextInput::setLabelSize(const unsigned int &size) {
    textBox.setLabelSize(size);
}

void TextInput::setLabelMargin(const int (&)[4]) {

}

void TextInput::setPosition(const sf::Vector2f &position) {
    textBox.setPosition(position);
}

void TextInput::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    textBox.addEventHandler(window, event);
}

void TextInput::update() {
    textBox.update();
}

void TextInput::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(textBox);
}
