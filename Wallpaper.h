//
// Created by Kelly Lwin on 3/30/2023.
//

#ifndef SFML_TEMPLATE_WALLPAPER_H
#define SFML_TEMPLATE_WALLPAPER_H
#include <SFML/Graphics.hpp>

class Wallpaper: public sf::Sprite {
private:
    sf::Sprite sprite;
    sf::Texture texture;
    void loadWallpaperPng() {
        if(!texture.loadFromFile("Assets/pink wallpaper.png")) {
            exit(10);
        }
    }
public:
    Wallpaper() {
        loadWallpaperPng();
        setTexture(texture);
        setOrigin(0, 0);
    }
};

#endif //SFML_TEMPLATE_WALLPAPER_H
