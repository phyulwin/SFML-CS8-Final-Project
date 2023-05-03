//
// Created by Kelly Lwin on 3/19/2023.
//

#ifndef SFML_TEMPLATE_TEXTBOX_H
#define SFML_TEMPLATE_TEXTBOX_H
#include <iostream>
#include <SFML\Graphics.hpp>

#include "../MouseEvents.h"
#include "../GUI_Component.h"

#include "Typing.h"
#include "Cursor.h"

class TextBox: public GUI_Component, public MouseEvents {
private:
    Typing typing;
    Cursor cursor;

    sf::RectangleShape box;
    sf::Text label;

    std::string labelText;
    unsigned int charSize = 30;
    sf::Font font;
    sf::Color black = sf::Color::Black;

    sf::Vector2f defaultPos = {50, 50};
    //is box under label
    bool boxUnderLabel = false;

    bool boxClicked = false;
public:
    TextBox();
    TextBox(const std::string& labelText) : labelText(labelText) {};

    void changeFont();
    void changeTextColor();
    void changeTextSize();

    void setBoxBesideLabel();
    void setBoxUnderLabel();

    //label
    void defaultSetUp();

    void setLabel(const std::string& string);
    void setLabelColor(const sf::Color& color);
    void setLabelSize(const unsigned int& size);
    void setLabelMargin(const float& margin);

    sf::Vector2f getPosition() const;
    void setPosition(const sf::Vector2f& position);

    std::string getString() {return typing.getString();}
    void setString(const std::string& newText) {typing.setString(newText);}
    //box
    void setBoxColor(const sf::Color& color);
    void setBoxSize(const sf::Vector2f& size);
    void setMarginColor(const sf::Color& color);

    sf::Vector2f getBoxPosition() const;
    void setBoxPosition(const sf::Vector2f& position);
    void setBoxPosition(const float& x, const float& y);

    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();

    Snapshot* getSnapshot();
    void applySnapshot(const Snapshot& snapshot);
protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //SFML_TEMPLATE_TEXTBOX_H
