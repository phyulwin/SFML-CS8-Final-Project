//
// Created by Kelly Lwin on 3/19/2023.
//

#ifndef SFML_TEMPLATE_MULTITEXT_H
#define SFML_TEMPLATE_MULTITEXT_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include "Letter.h"

#include <string>
#include "../States.h"

class MultiText : public sf::Drawable ,public States {
private:
    Letter cursor;
    sf::Font font;
    sf::Vector2f position = {30,30};
    int CharSize = 30;
    sf::Color color = sf::Color::Black;

public:
    std::list<Letter> letterList;

    typedef std::list<Letter>::iterator iterator;
    typedef std::list<Letter>::const_iterator const_iterator;

    MultiText();

    void setFont(const sf::Font& font);
    void setColor(const sf::Color &color);

    void setCharSize(const int size);
    int getCharSize() const;

    std::list<Letter> getLetterList() const;

    sf::Vector2f getPosition();
    void setPosition(sf::Vector2f position);
    sf::FloatRect getGlobalBounds();

    bool empty() const;
    void addLetter(char letter);
    void addLetter(std::string letter);

    void backSpace();

    std::string getString();
    void setString(const std::string& string);

    unsigned int getSize();
    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    //MultiText& operator=(const MultiText& multiText);
};
#endif //SFML_TEMPLATE_MULTITEXT_H
