//
// Created by Kelly Lwin on 4/24/2023.
//
#include "Apps.h"
void Apps::appNameSetup(const std::string& name) {
    appName = name;
    Font::defaultFont(appName_, font, appName);
    appWindow.setAppName(appName_.getString());
}
void Apps::iconSetup(const IconEnum& iconEnum) {
    texture.loadFromFile(Icon::returnIcon(iconEnum));
    icon.setTexture(texture);
    icon.setScale({0.07, 0.07});
}
void Apps::defaultSetup(const std::string& name, const IconEnum& iconEnum) {
    iconSetup(iconEnum);
    appNameSetup(name);
}

Apps::Apps(const std::string& appName, const IconEnum& iconEnum): appName(appName) {
    defaultSetup(appName, iconEnum);
}

void Apps::setAppName(const std::string &name) {
    appNameSetup(name);
}

void Apps::setAppIcon(const IconEnum &iconEnum) {
    iconSetup(iconEnum);
}

sf::Vector2f Apps::getPosition() const {
    return appWindow.getPosition();
}

void Apps::setPosition(const sf::Vector2f& pos) {
    icon.setPosition(pos);
    float temp = icon.getPosition().y + 70;
    appName_.setPosition({icon.getPosition().x, temp});
}

void Apps::setWindowPosition(const sf::Vector2f& pos) {
    appWindow.setPosition(pos);
}

void Apps::addEventHandler(sf::RenderWindow &window, sf::Event) {
    if(MouseEvents::isClicked(this->icon, window)) {
        appRunning = true;
    }
    if(MouseEvents::isClicked(appWindow.closeButton, window)) {
        appRunning = false;
    }
}

void Apps::addEventHandler(sf::RenderWindow& window, sf::Event, void (*f)()) {
    if(MouseEvents::isClicked(this->icon, window)) {
        (*f)();
        appRunning = true;
    }
    if(MouseEvents::isClicked(appWindow.closeButton, window)) {
        appRunning = false;
    }
}

void Apps::update() {}

void Apps::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(this->icon);
    target.draw(this->appName_);
}