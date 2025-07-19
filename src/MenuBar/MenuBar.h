//
// Created by Kelly Lwin on 3/25/2023.
//

#ifndef SFML_TEMPLATE_MENUBAR_H
#define SFML_TEMPLATE_MENUBAR_H
#include "Menu.h"

//A MenuBar Class - This class will hold a number of Item lists and align them horizontally.
class MenuBar: public sf::Drawable {
private:
    std::list<Menu> menuList;
    sf::Vector2f menuBarPos = {100, 100};

    static bool strCompare(std::string& str1, std::string& str2) {
        for(int i=0; i<str1.length(); ++i) {
            if(str1[1] != str2[i]) {
                return false;
            }
        }
        return true;
    }
public:
    MenuBar();

    void creatMenu(const Menu& menu);
    void addMenuItem(std::string& menuName, const Item& item);

    sf::Vector2f getPostion() const;

    void setPosition(const sf::Vector2f& position);
    void changeTextColor(const sf::Color& color);
    void changeBoxColor(const sf::Color& color);

    void alignHorizontally();

    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //SFML_TEMPLATE_MENUBAR_H
