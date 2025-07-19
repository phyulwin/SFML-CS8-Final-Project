//
// Created by Kelly Lwin on 3/24/2023.
//

#ifndef SFML_TEMPLATE_FONT_H
#define SFML_TEMPLATE_FONT_H
#include <iostream>
#include <SFML\Graphics.hpp>

enum FontList {
    MONOGRAM,
    OPENSANSBOLD,
    LASTFONT
};

class Font {
    sf::Font font;
public:
    sf::Font getFont() {
        try{
            font.loadFromFile("Fonts/monogram.ttf");
        }
        catch(const std::string& str) {
            std::cout << str << std::endl;
            exit(10);
        }
        return font;
    }

    sf::Font getFont(FontList fontName) {
        try {
            switch (fontName) {
                case MONOGRAM:
                    font.loadFromFile("Fonts/monogram.ttf");
                    break;
                case OPENSANSBOLD:
                    font.loadFromFile("Fonts/opensansboldfont.ttf");
                    break;
                default:
                    font.loadFromFile("Fonts/opensansboldfont.ttf");
            }
        }
        catch(const std::string& str) {
            std::cout << str << std::endl;
            exit(10);
        }
        return font;
    }

    //default sf text obj visuals
    void setupSfText(sf::Text& sfTextObj, const FontList& fontName) {
        sfTextObj.setFont(getFont(fontName));
        sfTextObj.setFillColor(sf::Color::Black);
        sfTextObj.setCharacterSize(30);
    }
};

#endif //SFML_TEMPLATE_FONT_H
