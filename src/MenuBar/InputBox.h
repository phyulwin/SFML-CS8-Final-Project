//
// Created by Kelly Lwin on 3/24/2023.
//

#ifndef SFML_TEMPLATE_INPUTBOX_H
#define SFML_TEMPLATE_INPUTBOX_H
#include "Item.h"

class InputBox: public sf::Drawable {
private:
    Item firstItem;
public:
    bool canChangeItem = false;
public:
    InputBox();
    InputBox(const std::string& firstItem_);

    void changeItem(const std::string& newItem);
    void changeBoxColor(const sf::Color& color);
    void changeTextColor(const sf::Color& color);

    float getBoxWidth() const;
    void setBoxPos(const sf::Vector2f& pos);
    void resizeBox(const sf::Vector2f& size);

    sf::FloatRect getGlobalBounds() const;
protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};

#endif //SFML_TEMPLATE_INPUTBOX_H
