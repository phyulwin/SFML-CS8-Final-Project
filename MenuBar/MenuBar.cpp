//
// Created by Kelly Lwin on 3/25/2023.
//

#include "MenuBar.h"

MenuBar::MenuBar() {

}

void MenuBar::creatMenu(const Menu &menu) {
    menuList.emplace_back(menu);
    alignHorizontally();
}

void MenuBar::addMenuItem(std::string &menuName, const Item &item) {
    if(!menuList.empty()) {
        for(Menu& menu: menuList) {
            if(strCompare(menu.menuName_, menuName)) {
                menu.addMenuItem(item);
                return; //only add to one menu
            }
        }
    }
    alignHorizontally();
}

sf::Vector2f MenuBar::getPostion() const {
    return menuBarPos;
}

void MenuBar::setPosition(const sf::Vector2f &position) {
    menuBarPos = position;
    alignHorizontally();
}

void MenuBar::changeTextColor(const sf::Color &color) {
    if(!menuList.empty()) {
        for(Menu& menu: menuList) {
            menu.changeTextColor(color);
        }
    }
}

void MenuBar::changeBoxColor(const sf::Color &color) {
    if(!menuList.empty()) {
        for(Menu& menu: menuList) {
            menu.changeBoxColor(color);
        }
    }
}

void MenuBar::alignHorizontally() {
    //increment x position by the size of input box
    float x = menuBarPos.x;
    //same vertical postion on window
    if(!menuList.empty()) {
        for(Menu& menu: menuList) {
            menu.setPos({x, menuBarPos.y});
            x += menu.getBoxWidth();
        }
    }
}

void MenuBar::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(!menuList.empty()) {
        for(Menu& menu: menuList) {
            menu.addEventHandler(window, event);
        }
    }
}

void MenuBar::update() {

}

void MenuBar::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if(!menuList.empty()) {
        for(const Menu& menu: menuList) {
            target.draw(menu);
        }
    }
}
