//
// Created by Kelly Lwin on 3/19/2023.
//

#include "TextBox.h"

TextBox::TextBox() {
    defaultSetUp();
}

void TextBox::changeFont() {
    typing.changeFont();
}

void TextBox::changeTextColor() {
    typing.changeTextColor();
}

void TextBox::changeTextSize() {
    typing.changeTextSize();
}

void TextBox::setBoxBesideLabel() {
    std::string labelLength = label.getString();
    float x = label.getPosition().x + label.getLocalBounds().width + 10;
    float y = label.getPosition().y;
    box.setPosition(x, y);
}

void TextBox::setBoxUnderLabel() {
    std::string labelLength = label.getString();
    float x = label.getPosition().x;
    float y = label.getPosition().y + label.getLocalBounds().height + 10;
    box.setPosition(x, y);
}

void TextBox::defaultSetUp() {
    typing.setCharSize(charSize);
    cursor.setCharSize(35);

    setBoxColor(sf::Color::White);
    setBoxSize({400, 50});
//    setBoxSize({static_cast<float>(typing.getCharSize())*40,static_cast<float>(typing.getCharSize())+5});
    setMarginColor(sf::Color::Red);
    setLabelMargin(5);

    font.loadFromFile("Fonts/monogram.ttf");
    label.setFont(font);
    label.setFillColor(black);
    label.setString(labelText);

    typing.setPosition(defaultPos);
    cursor.setPosition(box.getPosition());
}

//LABEL FUNCTIONS
void TextBox::setLabel(const std::string &string) {
    label.setString(string);
}

void TextBox::setLabelColor(const sf::Color &color) {
    label.setFillColor(color);
}

void TextBox::setLabelSize(const unsigned int &size) {
    label.setCharacterSize(size);
}

void TextBox::setLabelMargin(const float &margin) {
    box.setOutlineThickness(margin);
}

sf::Vector2f TextBox::getPosition() const {
    return label.getPosition();
}

void TextBox::setPosition(const sf::Vector2f &position) {
    //set label position
    label.setPosition(position);
    //set box position in relative to label position
    if(boxUnderLabel) {
        setBoxUnderLabel();
    } else {
        setBoxBesideLabel();
    }
    typing.setPosition(box.getPosition());
    cursor.setPosition(box.getPosition());
}

//BOX FUNCTIONS
void TextBox::setBoxColor(const sf::Color &color) {
    box.setFillColor(color);
}


void TextBox::setBoxSize(const sf::Vector2f &size) {
    box.setSize(size);
}

void TextBox::setMarginColor(const sf::Color &color) {
    box.setOutlineColor(color);
}

sf::Vector2f TextBox::getBoxPosition() const {
    return box.getPosition();
}

void TextBox::setBoxPosition(const sf::Vector2f &position) {
    box.setPosition(position);
}

void TextBox::setBoxPosition(const float &x, const float &y) {
    setBoxPosition(sf::Vector2f(x, y));
}

void TextBox::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    typing.addEventHandler(window,event);
    if(!typing.empty()) {
        cursor.setPosition({typing.getPosition().x + typing.getCharSize()/3,typing.getPosition().y});
    }
    if(MouseEvents::isClicked(box, window)) {
        boxClicked = true;
    }
    if(MouseEvents::isNotClicked(box, window)) {
        boxClicked = false;
    }
}

void TextBox::update() {
    typing.update();
    cursor.update();
}

Snapshot *TextBox::getSnapshot() {
    return nullptr;
}

void TextBox::applySnapshot(const Snapshot& snapshot) {

}

void TextBox::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    //draw the text box first
    target.draw(box);
    target.draw(label);
    //then draw the typing and cursor
    target.draw(typing);
    //only draw the cursor if the box is clicked
    if(boxClicked) {
        target.draw(cursor);
    }
}
