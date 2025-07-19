//
// Created by Kelly Lwin on 3/24/2023.
//

#ifndef SFML_TEMPLATE_ITEMLIST_H
#define SFML_TEMPLATE_ITEMLIST_H
#include <list>
#include <iterator>

#include "Item.h"
#include "../States.h"

class ItemList: public sf::Drawable, public States {
public:
    std::list<Item> list;
private:
    int listSize = 0;
    int getSize(); //returns list size

    void alignListItems();
    void alignListItems(float& x, float& y);
    std::vector<sf::FloatRect> itemGlobalBounds;
public:
    std::list<Item>::iterator iterator;
    Item begin() {iterator = list.begin(); return *iterator;}
    Item end() {iterator = list.end(); return *iterator;}

    bool empty() const;
    Item top() const;
    Item& getListItem(const int& index);

    std::vector<sf::FloatRect> getItemGlobalBounds() {
        auto iter = list.begin();
        while(iter!=list.end()) {
            itemGlobalBounds.push_back((*iter).getGlobalBounds());
            ++iter;
        }
        return itemGlobalBounds;
    }

    void push(const Item& listItem);
    void push(const std::string& listItem);

    void setPosition(float x, float y);
    void changeTextColor(const sf::Color& color);

    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void addEventHandler(sf::RenderWindow& window, sf::Event event, std::string& string);
    void update();
protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //SFML_TEMPLATE_ITEMLIST_H
