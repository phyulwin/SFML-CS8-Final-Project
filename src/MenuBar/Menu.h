//
// Created by Kelly Lwin on 3/25/2023.
//

#ifndef SFML_TEMPLATE_MENU_H
#define SFML_TEMPLATE_MENU_H
#include <vector>
#include "../States.h"
#include "Dropdown_Menu.h"

class Menu: public sf::Drawable {
private:
    Dropdown_Menu list;
    sf::Vector2f pos = {100, 100}; //default position on screen
    States state;
public:
    std::string menuName_ = "Menu";

    bool isShown() {return !state.checkState(HIDDEN);}

    Item begin() {return list.begin();}
    Item end() {return list.end();}
    Item& getListItem(const int& index);
    Dropdown_Menu getList() {return this->list;}
    std::vector<sf::FloatRect> getItemGlobalBounds() {
        return list.getItemGlobalBounds();
    }

    Menu();
    Menu(const Item& menuTitle);
    Menu(const std::string& menuTitle);
    void setMenuTittle(const std::string& menuTitle);

    void changeTextColor(const sf::Color& color);
    void changeBoxColor(const sf::Color& color);

    void addMenuItem(const Item& item);
    void addMenuItem(const std::string& item);

//    template<typename T>
//    void addMenuItems(const std::vector<T>& items);

    Dropdown_Menu getMenu() const;
    sf::Vector2f getPos() const;

    float getBoxWidth() const;
    void setPos(const sf::Vector2f& position);

    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};

#endif //SFML_TEMPLATE_MENU_H
