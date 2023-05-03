//
// Created by Kelly Lwin on 4/28/2023.
//

#include "ComputerInterface.h"

ComputerInterface::ComputerInterface() {
    createApp();
    disableStates(HIDDEN);
}

void ComputerInterface::createApp() {
    computer.setAppName("My Computer");
    computer.setAppIcon(COMPUTER);
    computer.setPosition({50, 50});
    computer.setWindowPosition({350, 70});

    sf::Vector2f temp = computer.appWindow.getPosition();
    myComputer.setFoldersPosition({temp.x+50, temp.y+80});

    myComputer.setButtonPosition(temp);
}

Folder* ComputerInterface::getSelectedFile() const {
    Folder* temp = new Folder;
    std::string name, data;
    //return the selected files from the three folders
    for(int i=0; i<myComputer.quicknotes.fileCount(); ++i) {
        if(myComputer.quicknotes.children[i]->checkState(IS_SELECTED)) {
            name = myComputer.quicknotes.getChildName(i);
            data = myComputer.quicknotes.getChildData(i);
        }
        else if(myComputer.shoppinglist.children[i]->checkState(IS_SELECTED)) {
            name = myComputer.shoppinglist.getChildName(i);
            data = myComputer.shoppinglist.getChildData(i);
        }
        else if(myComputer.contacts.children[i]->checkState(IS_SELECTED)) {
            name = myComputer.contacts.getChildName(i);
            data = myComputer.contacts.getChildData(i);
        }
    }
    temp->folder.setFileName(name);
    temp->folder.setFileData(data);
    return temp;
}

void ComputerInterface::deselectFile() {
    myComputer.quicknotes.deselectFile();
    myComputer.shoppinglist.deselectFile();
    myComputer.contacts.deselectFile();
}

void ComputerInterface::deleteFileFromFolder(const std::string &fileName) {
    myComputer.removeFile(fileName);
}

void ComputerInterface::saveFile(const std::string& folderName, const std::string &fileName, const std::string &fileData) {
    myComputer.saveFile(folderName, fileName, fileData);
}

void ComputerInterface::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    computer.addEventHandler(window, event);
    myComputer.addEventHandler(window, event);
}

void ComputerInterface::update() {
    computer.update();
    myComputer.update();
}

void ComputerInterface::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(computer);
    if(computer.appRunning) {
        target.draw(this->computer.appWindow);
        target.draw(this->myComputer);
    }
}
