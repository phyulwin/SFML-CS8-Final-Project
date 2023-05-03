//
// Created by Kelly Lwin on 3/30/2023.
//

#ifndef SFML_TEMPLATE_BACKGROUND_H
#define SFML_TEMPLATE_BACKGROUND_H
#include <iostream>
#include <SFML/Graphics.hpp>

//software frame
class Background:public sf::Drawable {
private:
    //color codes
    const sf::Color darkBlue = {86, 119, 231};
    //const sf::Color lightBlue = {160};
private:
    sf::Text softwareName;
    sf::Sprite softwareIcon;
    sf::RectangleShape background;
protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //SFML_TEMPLATE_BACKGROUND_H
