//
// Created by Kelly Lwin on 3/24/2023.
//

#ifndef SFML_TEMPLATE_DROPDOWN_MENU_H
#define SFML_TEMPLATE_DROPDOWN_MENU_H
#include <iostream>
#include <iterator>
#include <list>
#include <SFML\Graphics.hpp>

#include "ItemList.h"
#include "InputBox.h"

#include "../States.h"

class Dropdown_Menu: public sf::Drawable, public States {
private:
    std::string selected;
public:
    InputBox inputBox;
    ItemList list;

//    bool showlist = false;
public:
    Item begin() {return list.begin();}
    Item end() {return list.end();}

    Dropdown_Menu();
    Dropdown_Menu(const std::string& menuName);

    Item& getListItem(const int& index);
    std::vector<sf::FloatRect> getItemGlobalBounds() {
        return list.getItemGlobalBounds();
    }

    void addItem(const Item& item);
    void addItem(const std::string& item);
    void setPosition(const sf::Vector2f& pos);

    void changeTextColor(const sf::Color& color);

    float getBoxWidth() const;
    void resize(const sf::Vector2f size);
    void resize(const float& x, const float& y);

    void itemEventHandler(sf::RenderWindow& window, sf::Event event);
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();

    void setInputBoxName(const std::string& boxName);

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //SFML_TEMPLATE_DROPDOWN_MENU_H
