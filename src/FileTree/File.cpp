//
// Created by Kelly Lwin on 4/20/2023.
//

#include "File.h"

void File::setFileDrawing() {
    Font::defaultFont(fileName_, font, fileName);

    background.setSize({500, 40});
    background.setFillColor(sf::Color::Transparent);

    Icon2::setFolderIcon(icon, texture, FILE_);
}

File::File(): File("Untitled", "") {

}

File::File(std::string fileName, std::string fileData): fileName(fileName), fileData(fileData) {
    setFileDrawing();
    enableState(HIDDEN);
}

std::string File::getFileName() const {
    return fileName_.getString();
}

std::string File::getFileData() const {
    return fileData;
}

void File::setFileName(const std::string &name) {
    this->fileName = name;
    fileName_.setString(fileName);
}

void File::setFileData(const std::string &data) {
    this->fileData = data;
}

sf::Vector2f File::getPosition() const {
    return background.getPosition();
}

void File::setPosition(const sf::Vector2f &pos) {
    background.setPosition(pos);
    icon.setPosition({background.getPosition().x, background.getPosition().y});
    fileName_.setPosition({background.getPosition().x+50, background.getPosition().y});
}

void File::addEventHandler(sf::RenderWindow &window, sf::Event event) {
//    if(MouseEvents::isHover(background, window)) {
//        background.setFillColor(sf::Color::Blue);
//    }
//    else if(checkState(IS_SELECTED)) {
//        background.setFillColor(sf::Color::Blue);
//    }
//    else {
//        background.setFillColor(sf::Color::Transparent);
//    }
    if(MouseEvents::isNotClicked(background, window)) {
        disableStates(IS_SELECTED);
    }
}

void File::update() {
    if(checkState(IS_SELECTED) && !checkState(IS_FOLDER)) {
        background.setFillColor(sf::Color::Blue);
    } else {
        background.setFillColor(sf::Color::Transparent);
    }
}

void File::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if(!checkState(HIDDEN)) {
        target.draw(background);
        target.draw(fileName_);
        target.draw(icon);
    }
//    target.draw(background);
//    target.draw(fileName_);
//    target.draw(icon);
}

/*
File::File() : File("Untitled") {};
File::File(std::string fileName) : fileName(fileName) {
    this->filepath = headDirectory+fileName;
    std::ofstream newfile(filepath);
}

void File::setFileName(const std::string &newFileName) {
    this->fileName = newFileName;
    this->filepath = headDirectory+newFileName;
}

void File::renameFile(const std::string &newFileName) {
    setFileName(newFileName);
}

std::string File::getFileName() const {
    return this->fileName;
}

void File::writeToFile(const std::string& text) {
    save(text, this->filepath);
}

//void File::createFile(const std::string& fileName) {
//    this->fileName = fileName;
//    file.open(headDirectory+fileName,std::ios::out);
//    if(!file) {throw "Cannot create file.";}
//    file.close();
//}

void File::save(std::string text, std::string filepath) {
    std::ofstream out;
    out.open(filepath);
    out << text;
    out.close();
}

void File::load(std::string text, std::string filepath) {
    std::ifstream fin;
    fin.open(filepath);
    if(fin.fail()) {throw "Could not find file";}
    std::string fileData;
    fin >> fileData;
    text = fileData;
    fin.close();
} */