//
// Created by Kelly Lwin on 3/24/2023.
//

#include "ItemList.h"

int ItemList::getSize() {
    return listSize;
}

Item& ItemList::getListItem(const int &index) {
    auto iter = list.begin();
    int count = 0;
    while(iter!=list.end() && count != index) {
        ++iter, ++count;
    }
    return *iter;
}

void ItemList::alignListItems() {
    auto iter = list.begin();

    //get position of box x and y
    float x = 100; //TODO - should be first item x
    float y = 100; //TODO - should be first item y

    while(iter != list.end()) {
        //vertically align
        //same x position
        iter->setPosition({x, y});
        y += (iter->getBoxHeight() + 1);
        iter++;
    }
}

void ItemList::alignListItems(float &x, float &y) {
    auto iter = list.begin();

    while(iter != list.end()) {
        //vertically align
        //same x position
        iter->setPosition({x, y});
        y += (iter->getBoxHeight() + 1);
        iter++;
    }
}

bool ItemList::empty() const {
    return list.empty();
}

Item ItemList::top() const {
    return *list.begin();
}

void ItemList::push(const Item &listItem) {
    list.push_back(listItem);
    listSize++;
}

void ItemList::push(const std::string &listItem) {
    list.emplace_back(listItem);
    listSize++;
}

void ItemList::changeTextColor(const sf::Color &color) {
    for(Item& item: list) {
        item.changeTextColor(color);
    }
}

void ItemList::setPosition(float x, float y) {
    alignListItems(x, y);
}

void ItemList::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    for(Item& item: list) {
        if(MouseEvents::isHover(item, window)) {
            item.changeBoxColor(sf::Color::Blue);
            item.changeCharSize(35);
        } else{
            item.changeBoxColor(sf::Color::Black);
            item.changeCharSize(30);
        }
        if(MouseEvents::isClicked(item, window)) {
            //std::cout << item.getString() << std::endl; //for testing
            return; //hides the list
        }
    }
}

void ItemList::addEventHandler(sf::RenderWindow &window, sf::Event event, std::string &string) {
    for(Item& item: list) {
        if(MouseEvents::isHover(item, window)) {
            item.changeBoxColor(sf::Color::Blue);
            item.changeCharSize(35);
        } else{
            item.changeBoxColor(sf::Color::Black);
            item.changeCharSize(30);
        }
        if(MouseEvents::isClicked(item, window)) {
            string = item.getString();
            return; //hides the list
        }
    }
}

void ItemList::update() {

}

void ItemList::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    //draw the list if it's not hidden
    if(!checkState(HIDDEN)) {
        auto iter = list.begin();
        while(iter != list.end()) {
            target.draw(*iter);
            iter++;
        }
    }
}
