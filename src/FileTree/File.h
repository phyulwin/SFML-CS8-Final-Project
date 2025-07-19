//
// Created by Kelly Lwin on 4/20/2023.
//

#ifndef SFML_TEMPLATE_FILE_H
#define SFML_TEMPLATE_FILE_H
#include <iostream>
#include <string>
#include <fstream>

#include "FileIcons.h"
#include "../States.h"
#include "../Font.h"
#include "../MouseEvents.h"

class File: public States, public sf::Drawable {
private:
    std::string fileName;
    std::string fileData; //data

    sf::Text fileName_;
    sf::Font font;

    sf::Sprite icon;
    sf::Texture texture;

    sf::RectangleShape background;
    void setFileDrawing();
public:
    File();
    File(std::string fileName, std::string fileData);

    void changeToFileIcon() {Icon2::setFolderIcon(icon, texture, FILE_);}
    void changeToFolderIcon() {Icon2::setFolderIcon(icon, texture, FOLDER_);}

    std::string getFileName() const;
    std::string getFileData() const;
    void setFileName(const std::string& name);
    void setFileData(const std::string& data);

    sf::Vector2f getPosition() const;
    void setPosition(const sf::Vector2f& pos);

    sf::FloatRect getGlobalBounds() const {return background.getGlobalBounds();}
public:
    void addEventHandler(sf::RenderWindow &window, sf::Event event);
    void update();
protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
/*
private:
    std::string headDirectory = "TextFiles/";

    std::fstream file;
    std::string fileName;
    std::string filepath;

    void setFileName(const std::string& newFileName);
public:
    File();
    File(std::string fileName);

    std::string getFileName() const;
    void renameFile(const std::string& newFileName);

    void writeToFile(const std::string& text);

//    void createFile(const std::string& fileName);
    void save(std::string text, std::string filepath);
    void load(std::string text, std::string filepath); */
};


#endif //SFML_TEMPLATE_FILE_H
