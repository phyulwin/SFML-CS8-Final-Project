//
// Created by Kelly Lwin on 4/23/2023.
//

#ifndef SFML_TEMPLATE_APPS_H
#define SFML_TEMPLATE_APPS_H
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Icon.h"
#include "Font.h"
#include "MouseEvents.h"

#include "App_Window.h"

class Apps: public sf::Drawable {
private:
    sf::Texture texture;
    sf::Sprite icon;

    std::string appName;
    sf::Text appName_;
    sf::Font font;

    void appNameSetup(const std::string& name);
    void iconSetup(const IconEnum& iconEnum);
    void defaultSetup(const std::string& name, const IconEnum& iconEnum);
public:
    App_Window appWindow;
    bool appRunning = false;

    Apps(): Apps("", COMPUTER) {}; //default constructor
    explicit Apps(const std::string& appName, const IconEnum& iconEnum);

    void setAppName(const std::string& name);
    void setAppIcon(const IconEnum& iconEnum);
    sf::Vector2f getPosition() const;
    void setPosition(const sf::Vector2f& pos);

    void setWindowPosition(const sf::Vector2f& pos);

    void addEventHandler(sf::RenderWindow& window, sf::Event);
    void addEventHandler(sf::RenderWindow& window, sf::Event, void (*f)());
    void update();
protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};
#endif //SFML_TEMPLATE_APPS_H
