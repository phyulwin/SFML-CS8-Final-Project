//
// Created by Kelly Lwin on 4/20/2023.
//

#ifndef SFML_TEMPLATE_FOLDER_H
#define SFML_TEMPLATE_FOLDER_H
#include <vector>
#include <string>
#include "File.h"

class Folder: public sf::Drawable, public States {
public:
    std::string(folderName);
    File folder;
    std::vector<Folder*> children;
//    int click = 0;

    void reposition();
    void printFileNames();
public:
    Folder();
    Folder(const std::string& folderName);

    bool empty() const {return children.empty();}

    int fileCount() const {return children.size();}
    float getContentHeight(); //returns the total height of folder and all its contents

    void setFolderName(const std::string& name);

    void addFile(const File& file);
    void addFile(const std::string& fileName);
    void addFile(const std::string& fileName, const std::string& fileData);
    void removeFile(const std::string& fileName);
    void hideAllFile();

    Folder* getSelected() const;
    std::basic_string<char> getChildName(const int& index) const {return children[index]->folder.getFileName();}
    std::basic_string<char> getChildData(const int& index) const {return children[index]->folder.getFileData();}
    void deselectFile();

    sf::Vector2f getPosition() const;
    void setPosition(const sf::Vector2f& pos);


    sf::FloatRect getGlobalBounds() const {return folder.getGlobalBounds();}
public:
    void addEventHandler(sf::RenderWindow &window, sf::Event event);
    void update();
protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    /*
    std::string folderName;
    std::vector<std::string> files;
public:
    Folder();
    Folder(const std::string& folderName);

    int getSize() const;
    void addFile(const File& file);
    void deleteFile(const File& file);
    //check if file already exists, cannot have same file name
    bool fileExists(const std::string& fileName); */

};


#endif //SFML_TEMPLATE_FOLDER_H
