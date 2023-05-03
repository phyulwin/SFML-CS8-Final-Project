//
// Created by Kelly Lwin on 4/24/2023.
//

#include "App_Window.h"

App_Window::App_Window(): App_Window("My Files") {

}

App_Window::App_Window(std::string appNameStr) {
    Font::defaultFont(appName, font, appNameStr);

    setupBackground();
    setupCloseButton();
}

void App_Window::updatePositions() {
    float x = appBackground.getPosition().x + 10;
    float y = appBackground.getPosition().y + 5;
    appName.setPosition({x, y});

    x += 700, y += 10;
    closeButton.setPosition({x, y});
}

void App_Window::setAppName(const std::string &name) {
    appName.setString(name);
    appName.setFillColor(sf::Color::White);
}

sf::Vector2f App_Window::getPosition() const {
    return appBackground.getPosition();
}

void App_Window::setPosition(const sf::Vector2f &pos) {
    appBackground.setPosition(pos);
    updatePositions();
}

void App_Window::setupBackground() {
    background.loadFromFile("Assets/app_window.png");
    appBackground.setTexture(background);
    setScale({0.7, 0.7});
}

void App_Window::setupCloseButton() {
    closeButton.setSize({30, 30});
    closeButton.setFillColor(sf::Color::Transparent);
    updatePositions();
}

void App_Window::setScale(const sf::Vector2f &scale) {
    appBackground.setScale(scale);
}

void App_Window::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(appBackground);
    target.draw(appName);
    target.draw(closeButton);
}
