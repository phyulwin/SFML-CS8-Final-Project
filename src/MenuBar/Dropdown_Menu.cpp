//
// Created by Kelly Lwin on 3/24/2023.
//

#include "Dropdown_Menu.h"

Dropdown_Menu::Dropdown_Menu() {

}

Dropdown_Menu::Dropdown_Menu(const std::string &menuName) {
    inputBox.changeItem(menuName);
}

Item& Dropdown_Menu::getListItem(const int &index) {
    return list.getListItem(index);
}

void Dropdown_Menu::addItem(const Item &item) {
    list.push(item);
}

void Dropdown_Menu::addItem(const std::string &item) {
    list.push(item);
}

void Dropdown_Menu::setPosition(const sf::Vector2f &pos) {
    inputBox.setBoxPos(pos);
    list.setPosition(pos.x, pos.y+50);
}

void Dropdown_Menu::changeTextColor(const sf::Color &color) {
    list.changeTextColor(color);
    inputBox.changeTextColor(color);
}

float Dropdown_Menu::getBoxWidth() const {
    return inputBox.getBoxWidth();
}

void Dropdown_Menu::resize(const sf::Vector2f size) {
    inputBox.resizeBox(size);
}

void Dropdown_Menu::resize(const float &x, const float &y) {
    resize({x, y});
}

void Dropdown_Menu::itemEventHandler(sf::RenderWindow &window, sf::Event event) {
//    //when an item is clicked, display in the input box
    for(Item& item: list.list) {
        if(MouseEvents::isClicked(item, window)) {
            if(inputBox.canChangeItem) {
                inputBox.changeItem(item.getString());
                inputBox.canChangeItem = false;
            }
            disableStates(HIDDEN);
            list.enableState(HIDDEN);
        }
    }
}

void Dropdown_Menu::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    list.addEventHandler(window, event);

    if(MouseEvents::isClicked(inputBox, window)) {
        disableStates(HIDDEN);
        list.disableStates(HIDDEN);
        inputBox.changeBoxColor(sf::Color::Blue);
//        inputBox.canChangeItem = true;
    }
    if(MouseEvents::isNotClicked(inputBox, window)) {
        enableState(HIDDEN);
        list.enableState(HIDDEN);
        inputBox.changeBoxColor(sf::Color::Black);
    }
//    itemEventHandler(window, event);
    for(Item& item: list.list) {
        if(MouseEvents::isClicked(item, window)) {
            inputBox.changeBoxColor(sf::Color::Black);
            enableState(HIDDEN);
            list.enableState(HIDDEN);
        }
    }
}

void Dropdown_Menu::update() {
    list.update();
}

void Dropdown_Menu::setInputBoxName(const std::string &boxName) {
    inputBox.changeItem(boxName);
}

void Dropdown_Menu::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(inputBox);
//    if(showlist) {
//        target.draw(list);
//    }
    if(!checkState(HIDDEN)) {
        target.draw(list);
    }
}

