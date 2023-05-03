//
// Created by Kelly Lwin on 4/28/2023.
//

#include "RecycleBinInterface.h"

void RecycleBinInterface::reposition() {
    sf::Vector2f pos = recyclebin.appWindow.getPosition();
    deletedFiles.setPosition({pos.x+50, pos.y+100});
    deletedFiles.reposition();
}

void RecycleBinInterface::setupButton() {
    recoverButton.setButtonText("Recover File");
    recoverButton.setSize({200, 50});

    sf::Vector2f pos = recyclebin.appWindow.getPosition();
    recoverButton.setPosition({pos.x+50, pos.y+600});
    recoverButton.setColor(sf::Color::Green);
}

void RecycleBinInterface::createApp() {
    recyclebin.setAppName("Recycle Bin");
    recyclebin.setAppIcon(RECYCLE_BIN);
    recyclebin.setPosition({50, 350});
    recyclebin.setWindowPosition({400, 90});

    deletedFiles.folder.setFileName("Old Files");
    deletedFiles.folder.disableStates(HIDDEN);
}

Folder* RecycleBinInterface::recoverFile() {
    if(!deletedFiles.empty()) {
        Folder *temp = new Folder;
        for(int i=0; i<deletedFiles.fileCount(); ++i) {
            //find the file to be recovered and remove it from the vector
            if(deletedFiles.children[i]->folder.checkState(IS_SELECTED)
               && !deletedFiles.children[i]->checkState(HIDDEN)) {
                temp->folder.setFileName(deletedFiles.children[i]->folder.getFileName());
                temp->folder.setFileData(deletedFiles.children[i]->folder.getFileData());
                //return the file and its data
//            std::cout << deletedFiles.children[i]->folder.getFileName() << std::endl;
                deletedFiles.children.erase(deletedFiles.children.begin()+i);
            }
        }
        return temp;
    }
}

void RecycleBinInterface::addDeletedFile(const File &file) {
    deletedFiles.addFile(file);
}

RecycleBinInterface::RecycleBinInterface() {
    createApp();
    disableStates(HIDDEN);
    setupButton();
}

void RecycleBinInterface::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    recyclebin.addEventHandler(window, event);
    if(recyclebin.appRunning) {
        deletedFiles.addEventHandler(window, event);
        reposition();
        recoverButton.addEventHandler(window, event);
    } //out of loop app not running
}

void RecycleBinInterface::update() {
    recyclebin.update();
    if(recyclebin.appRunning) {
        deletedFiles.update();
        recoverButton.update();
    }
}

void RecycleBinInterface::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(recyclebin);
    if(recyclebin.appRunning) {
        target.draw(this->recyclebin.appWindow);
        target.draw(this->recoverButton);
        target.draw(this->deletedFiles);
        //draw the list of deleted files
        if(!deletedFiles.empty()) {
            for(int i=0; i<deletedFiles.fileCount(); ++i) {
                target.draw(*deletedFiles.children[i]);
            }
        } //draw deleted files
    }
}
