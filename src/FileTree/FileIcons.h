//
// Created by Kelly Lwin on 5/1/2023.
//

#ifndef SFML_TEMPLATE_FILEICONS_H
#define SFML_TEMPLATE_FILEICONS_H
#include <SFML/Graphics.hpp>

enum iconEnum {
    FOLDER_, FILE_
};

class Icon2 {
public:
    static void setFolderIcon(sf::Sprite& sprite, sf::Texture& texture, const iconEnum& type) {
        switch (type) {
            case FOLDER_: texture.loadFromFile("FileTree/Assets/folder.png"); break;
            case FILE_: texture.loadFromFile("FileTree/Assets/file.png"); break;
        }
        sprite.setTexture(texture);
        sprite.setScale({0.07, 0.07});
    }
};
#endif //SFML_TEMPLATE_FILEICONS_H
