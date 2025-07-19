//
// Created by Kelly Lwin on 3/19/2023.
//

#ifndef SFML_TEMPLATE_TYPING_H
#define SFML_TEMPLATE_TYPING_H
#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\Window\Keyboard.hpp>

#include "MultiText.h"
#include "Keyboard_Shortcut.h"

#include "TypingSnapshot.h"
#include "../Font.h"

class Typing: public sf::Drawable {
private:
    MultiText text;
    sf::Text textedType;
    TypingSnapshot snapshot;

    std::string textTypeStr = "";
    unsigned int charSize = 30;
    sf::Font font;
private:
    void setupDefaultsVisuals(); //visuals
    sf::Color getRandomColor();
public:
    Typing();

    bool empty() const;

    int getCharSize() const;
    std::string getString() {return text.getString();}
    void setString(const std::string& newText) {text.setString(newText);}
    sf::Vector2f getPosition() const;

    void changeFont();
    void changeTextColor();
    void changeTextSize();

    void setCharSize(const int& size);
    void setPosition(const sf::Vector2f& pos);

    //visuals
    void textColor(const sf::Color& color);
    void textSize(const unsigned int& size);
    void textFont(const sf::Font& textFont);
    //void textPosition(const sf::Vector2f& pos);

    //change visuals
    static void changeColor(std::list<Letter>::iterator start, std::list<Letter>::iterator end, sf::Color color);
    static void checkKeyword(std::list<Letter>::iterator start, std::list<Letter>::iterator end);
    static bool isOperator(const char& element);
    static bool isNumber(const std::string& str);
    //
    void update();
    void addEventHandler(sf::RenderWindow& window, sf::Event event);

    //snapshots
    void getSnapshot();
    void applySnapshot();

protected:
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};


#endif //SFML_TEMPLATE_TYPING_H
