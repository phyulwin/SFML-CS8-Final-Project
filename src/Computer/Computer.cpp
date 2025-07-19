//
// Created by Kelly Lwin on 5/2/2023.
//

#include "Computer.h"

void Computer::setUpButton(Button &button, const std::string& buttonText) {
    button.setButtonText(buttonText);
    button.setSize({150, 50});
    button.setColor(sf::Color::Green);
}

void Computer::setButtonPosition(const sf::Vector2f& windowPos) {
    setUpButton(deleteButton, "Delete File");
    deleteButton.setPosition({windowPos.x+50, windowPos.y+600});

    setUpButton(openButton, "Open File");
    openButton.setPosition({windowPos.x+300, windowPos.y+600});

    setUpButton(saveButton, "Save File");
    saveButton.setPosition({windowPos.x+550, windowPos.y+600});
}

void Computer::createDefaultFolders() {
    quicknotes.setFolderName("Quick-Notes");
    shoppinglist.setFolderName("New-Files");
    contacts.setFolderName("Recovered Files");

    quicknotes.folder.disableStates(HIDDEN);
    shoppinglist.folder.disableStates(HIDDEN);
    contacts.folder.disableStates(HIDDEN);
}

Computer::Computer() {
    createDefaultFolders();
}

void Computer::setFoldersPosition(const sf::Vector2f& pos) {
    this->qnPos = pos;
    this->slPos = {pos.x, pos.y+50};
    this->cnPos = {pos.x, pos.y+100};
    quicknotes.setPosition(qnPos);
    shoppinglist.setPosition(slPos);
    contacts.setPosition(cnPos);
}

void Computer::saveFile2Folder(const std::string &fileName, const std::string &fileData) {
    if(quicknotes.checkState(IS_OPENED)) {
        quicknotes.addFile(File(fileName, fileData));
    }
    else if(shoppinglist.checkState(IS_OPENED)) {
        shoppinglist.addFile(File(fileName, fileData));
    }
    else {
        files.emplace_back(File(fileName, fileData));
    }
}

void Computer::saveFile(const std::string &folderName, const std::string &fileName, const std::string &fileData) {
    if(quicknotes.folderName==folderName) {
        quicknotes.addFile(File(fileName, fileData));
    }
    else if(shoppinglist.folderName==folderName) {
        shoppinglist.addFile(File(fileName, fileData));
    }
    else if(contacts.folderName==folderName) {
        contacts.addFile(File(fileName, fileData));
    }
    //else just create a file and draw on screen
}

void Computer::removeFile(const std::string &fileName) {
    quicknotes.removeFile(fileName);
    shoppinglist.removeFile(fileName);
    contacts.removeFile(fileName);
}

void Computer::reposition() {
    float temp = 0;
    if(quicknotes.checkState(IS_OPENED)) {
        temp += quicknotes.getContentHeight();
    }
    shoppinglist.setPosition({slPos.x, slPos.y+temp});
    //relocate contacts
    if(shoppinglist.checkState(IS_OPENED)) {
        temp += shoppinglist.getContentHeight();
    }
    contacts.setPosition({cnPos.x, cnPos.y+temp});
}

void Computer::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    quicknotes.addEventHandler(window, event);
    shoppinglist.addEventHandler(window, event);
    contacts.addEventHandler(window, event);

    deleteButton.addEventHandler(window, event);
    openButton.addEventHandler(window, event);
    saveButton.addEventHandler(window, event);
    //quick notes
    if(MouseEvents::isClicked(quicknotes, window)) {
        quicknotes.enableState(IS_OPENED);
        shoppinglist.disableStates(IS_OPENED);
        contacts.disableStates(IS_OPENED);
    }
    //shopping list
    if(MouseEvents::isClicked(shoppinglist, window)) {
        shoppinglist.enableState(IS_OPENED);
        quicknotes.disableStates(IS_OPENED);
        contacts.disableStates(IS_OPENED);
    }
    //contacts - recycled files
    if(MouseEvents::isClicked(contacts, window)) {
        contacts.enableState(IS_OPENED);
        quicknotes.disableStates(IS_OPENED);
        shoppinglist.disableStates(IS_OPENED);
    }
    reposition();
    //select files from the computer
    for(int i=0; i<quicknotes.children.size(); ++i) {
        if(MouseEvents::isClicked(quicknotes.children[i]->folder, window)) {
            quicknotes.children[i]->enableState(IS_SELECTED);
        }
    }
    for(int i=0; i<shoppinglist.children.size(); ++i) {
        if(MouseEvents::isClicked(shoppinglist.children[i]->folder, window)) {
            shoppinglist.children[i]->enableState(IS_SELECTED);
        }
    }
    for(int i=0; i<contacts.children.size(); ++i) {
        if(MouseEvents::isClicked(contacts.children[i]->folder, window)) {
            contacts.children[i]->enableState(IS_SELECTED);
        }
    }
}

void Computer::update() {
    quicknotes.update();
    shoppinglist.update();
    contacts.update();

    quicknotes.reposition();
    shoppinglist.reposition();
    contacts.reposition();

    //buttons
    deleteButton.update();
    openButton.update();
    saveButton.update();

    if(!quicknotes.checkState(IS_OPENED)) {
        quicknotes.hideAllFile();
    }
    if(!shoppinglist.checkState(IS_OPENED)) {
        shoppinglist.hideAllFile();
    }
    if(!contacts.checkState(IS_OPENED)) {
        contacts.hideAllFile();
    }
}

void Computer::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(quicknotes);
    target.draw(shoppinglist);
    target.draw(contacts);

    target.draw(deleteButton);
    target.draw(openButton);
    target.draw(saveButton);

    if(!quicknotes.empty()) {
        for(int i=0; i<quicknotes.fileCount(); ++i) {
            target.draw(*quicknotes.children[i]);
        }
    }
    if(!shoppinglist.empty()) {
        for(int i=0; i<shoppinglist.fileCount(); ++i) {
            target.draw(*shoppinglist.children[i]);
        }
    }
    if(!contacts.empty()) {
        for(int i=0; i<contacts.fileCount(); ++i) {
            target.draw(*contacts.children[i]);
        }
    }
}

