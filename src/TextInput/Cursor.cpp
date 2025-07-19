//
// Created by Kelly Lwin on 3/19/2023.
//
#include "Cursor.h"
Cursor::Cursor()
{
    text.setString("|");
    font.loadFromFile("Fonts/monogram.ttf");
    text.setFont(font);
    text.setFillColor(sf::Color::Black);
    disableStates(HIDDEN);
}

void Cursor::setPosition(const sf::Vector2f& position)
{
    text.setPosition(position);
}

void Cursor::setCharSize(int size)
{
    text.setCharacterSize(size);
}

void Cursor::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    if(!checkState(HIDDEN))
        target.draw(text);
}

void Cursor::addEventHandler(sf::RenderWindow &window, sf::Event event)
{

}

void Cursor::update()
{
    if(clock.getElapsedTime().asSeconds() > 0.5)
    {
        toggleState(HIDDEN);
        clock.restart();
    }

}

Snapshot *Cursor::getSnapshot()
{
    return nullptr;
}

void Cursor::applySnapshot(const Snapshot& snapshot)
{

}