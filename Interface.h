//
// Created by Kelly Lwin on 4/24/2023.
//

#ifndef SFML_TEMPLATE_INTERFACE_H
#define SFML_TEMPLATE_INTERFACE_H
#include <map>
#include <iostream>
#include "Wallpaper.h"

#include "Apps.h"
#include "App_Window.h"

#include "Notepad/NotepadInterface.h"
#include "Computer/ComputerInterface.h"
#include "RecycleBin/RecycleBinInterface.h"

class Interface: public sf::Drawable {
private:
    Wallpaper wallpaper;
public:
    RecycleBinInterface recyclebin;
    NotepadInterface notepad;
    ComputerInterface computer;
public:
    Interface();

    void openFile(const std::string& fileName, const std::string& fileData);
    void saveFile(const std::string& folderName, const std::string& fileName, const std::string& fileData);
    void recoverFile(const std::string& fileName, const std::string& fileData);
    void deleteFile(const std::string& fileName, const std::string& fileData);
    void addDeletedFile(const std::string& fileName, const std::string& fileData);

    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //SFML_TEMPLATE_INTERFACE_H
