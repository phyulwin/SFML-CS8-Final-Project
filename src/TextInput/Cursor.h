//
// Created by Kelly Lwin on 3/14/2023.
//

#ifndef SFML_TEMPLATE_CURSOR_H
#define SFML_TEMPLATE_CURSOR_H
#include <iostream>
#include <SFML\Graphics.hpp>

#include "../GUI_Component.h"
#include "../States.h"

class Cursor: public GUI_Component
{
private:
    sf::Text text;
    sf::Font font;
    sf::Clock clock;
public:
    Cursor();
    void setPosition(const sf::Vector2f& position);
    void setCharSize(int size);
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    //implement virtual functions
    Snapshot* getSnapshot() override;
    void applySnapshot(const Snapshot& snapshot) override;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif //SFML_TEMPLATE_CURSOR_H
