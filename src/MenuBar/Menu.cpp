//
// Created by Kelly Lwin on 3/25/2023.
//

#include "Menu.h"

Menu::Menu() {
    list.setInputBoxName(menuName_);
//    list.setPosition(pos);
}

Menu::Menu(const Item &menuTitle) {
    list.setInputBoxName(menuTitle.getString());
//    list.setPosition(pos);
}

Menu::Menu(const std::string &menuTitle) {
    list.setInputBoxName(menuTitle);
//    list.setPosition(pos);
}

void Menu::setMenuTittle(const std::string &menuTitle) {
    menuName_ = menuTitle;
    list.setInputBoxName(menuTitle);
}

void Menu::changeTextColor(const sf::Color &color) {
    list.changeTextColor(color);
}

void Menu::changeBoxColor(const sf::Color &color) {
    list.inputBox.changeBoxColor(color);
}

void Menu::addMenuItem(const Item &item) {
    list.addItem(item);
}

void Menu::addMenuItem(const std::string &item) {
    list.addItem(item);
}

//template<typename T>
//void Menu::addMenuItems(const std::vector<T> &items) {
//    for(const Item& item: items) {
//        list.addItem(item);
//    }
//}

Item& Menu::getListItem(const int &index) {
    return list.getListItem(index);
}

Dropdown_Menu Menu::getMenu() const {
    return list;
}

sf::Vector2f Menu::getPos() const {
    return pos;
}

float Menu::getBoxWidth() const {
    return list.getBoxWidth();
}

void Menu::setPos(const sf::Vector2f &position) {
    list.setPosition(position);
}

void Menu::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    list.addEventHandler(window, event);
}

void Menu::update() {
    list.update();
    if(!list.checkState(HIDDEN)) {
        state.disableStates(HIDDEN);
    } else {
        state.enableState(HIDDEN);
    }
}

void Menu::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(list);
}
