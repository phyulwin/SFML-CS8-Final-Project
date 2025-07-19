//
// Created by Kelly Lwin on 5/2/2023.
//

#ifndef SFML_TEMPLATE_COMPUTER_H
#define SFML_TEMPLATE_COMPUTER_H
#include "../HelperClass.h"
#include "../FileTree/Folder.h"

class Computer: public sf::Drawable {
private:
    sf::Vector2f qnPos, slPos, cnPos; //remember original positions
    void setUpButton(Button& button, const std::string& buttonText);
public:
    Folder quicknotes, shoppinglist, contacts;
    std::vector<File> files; //that are not in folders

    Button deleteButton, openButton, saveButton;
    void createDefaultFolders();
    void setButtonPosition(const sf::Vector2f& windowPos);

    void reposition();
public:
    Computer();

    void setFoldersPosition(const sf::Vector2f& pos);
    void saveFile2Folder(const std::string& fileName, const std::string& fileData);
    void saveFile(const std::string& folderName, const std::string& fileName, const std::string& fileData);
    void removeFile(const std::string& fileName);

    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //SFML_TEMPLATE_COMPUTER_H
