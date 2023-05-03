//
// Created by Kelly Lwin on 4/24/2023.
//

#ifndef SFML_TEMPLATE_APP_WINDOW_H
#define SFML_TEMPLATE_APP_WINDOW_H
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Icon.h"
#include "Font.h"

class App_Window: public sf::Drawable {
private:
    sf::Texture background;
    sf::Sprite appBackground;

    sf::Text appName;
    sf::Font font;

    void setupCloseButton();
    void setupBackground();

    void updatePositions();
public:
    sf::RectangleShape closeButton;

    App_Window();
    App_Window(std::string appNameStr);

    void setAppName(const std::string& name);

    sf::Vector2f getPosition() const;
    void setPosition(const sf::Vector2f& pos);
    void setScale(const sf::Vector2f& scale);
protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //SFML_TEMPLATE_APP_WINDOW_H
