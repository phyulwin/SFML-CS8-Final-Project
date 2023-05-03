//
// Created by Kelly Lwin on 4/20/2023.
//

#ifndef SFML_TEMPLATE_ICON_H
#define SFML_TEMPLATE_ICON_H
#include <iostream>
#include <SFML/Graphics.hpp>

enum IconEnum {
    COMPUTER,
    FOLDER,
    TXT_FILE,
    RECYCLE_BIN,
    NOTEPAD,
    LAST_ICON
};

class Icon {
public:
    static std::string returnIcon(IconEnum iconEnum) {
        switch(iconEnum) {
            case COMPUTER: return "Assets/Icons/computer.png";
            case FOLDER: return "Assets/Icons/file.png";
            case TXT_FILE: return "Assets/Icons/text file.png";
            case RECYCLE_BIN: return "Assets/Icons/recycle bin.png";
            case NOTEPAD: return "Assets/Icons/notepad.png";
            default: return "";
        }
    }

};

#endif //SFML_TEMPLATE_ICON_H
