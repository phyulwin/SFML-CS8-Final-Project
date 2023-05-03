//
// Created by Kelly Lwin on 4/24/2023.
//

#ifndef SFML_TEMPLATE_FONT_H
#define SFML_TEMPLATE_FONT_H
#include <iostream>
#include<cstdlib>
#include <SFML/Graphics.hpp>

enum fontEnum {
    DECALOTYPEBLACK,
    MONOGRAM,
    NAIVE,
    OPENSANSBOLD,
    SEGOE_UI,
    SEGOE_UI_BOLD,
    SEGOE_UI_BOLD_ITALIC,
    SEGOE_UI_ITALIC,
    LAST_FONT
};

class Font {
public:
    static void setRandomFont(sf::Font& font) {
        srand((unsigned) time(NULL));
        auto random = fontEnum(rand() % 10);
        font.loadFromFile(loadFont(random));
    }

    static std::string loadFont(const fontEnum& fontEnum) {
        switch(fontEnum) {
            case DECALOTYPEBLACK: return "Fonts/decalotypeblack.ttf";
            case MONOGRAM: return "Fonts/monogram.ttf";
            case NAIVE: return "Fonts/Naive.ttf";
            case OPENSANSBOLD: return "Fonts/opensansboldfont.ttf";
            case SEGOE_UI: return "Fonts/Segoe UI.ttf";
            case SEGOE_UI_BOLD: return "Fonts/Segoe UI Bold.ttf";
            case SEGOE_UI_BOLD_ITALIC: return "Fonts/Segoe UI Bold Italic.ttf";
            case SEGOE_UI_ITALIC: return "Fonts/Segoe UI Italic.ttf";
            default: return "Fonts/opensansboldfont.ttf";
        }
    }

    static void defaultFont(sf::Text& text, sf::Font& font, const std::string& textStr) {
        text.setString(textStr);
        font.loadFromFile(loadFont(MONOGRAM));
        text.setFont(font);
        text.setFillColor(sf::Color::Black);
        text.setCharacterSize(30);
    }
};


#endif //SFML_TEMPLATE_FONT_H
