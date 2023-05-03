//
// Created by Kelly Lwin on 4/24/2023.
//

#include "Interface.h"

void Interface::openFile(const std::string &fileName, const std::string &fileData) {
    notepad.notepadApp.openFile(fileName, fileData);
}

void Interface::saveFile(const std::string &folderName, const std::string &fileName, const std::string &fileData) {
    computer.saveFile(folderName, fileName, fileData);
}

void Interface::recoverFile(const std::string &fileName, const std::string &fileData) {
    computer.saveFile("Recovered Files", fileName, fileData);
}

void Interface::addDeletedFile(const std::string &fileName, const std::string &fileData) {
    recyclebin.addDeletedFile(File(fileName, fileData));
}

void Interface::deleteFile(const std::string &fileName, const std::string &fileData) {
    recyclebin.addDeletedFile(File(fileName, fileData));
    computer.deleteFileFromFolder(fileName);
    computer.deselectFile();
}

Interface::Interface() {

}

void Interface::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    computer.addEventHandler(window, event);
    notepad.addEventHandler(window, event);
    recyclebin.addEventHandler(window, event);

    if(notepad.notepad.appRunning) {
        //if open is clicked, open computer and show folders and files
        if(!notepad.notepadApp.open.checkState(HIDDEN) &&
           MouseEvents::isClicked(notepad.notepadApp.open, window)) {
            computer.computer.appRunning = true;
            notepad.notepad.appRunning = false;
        }
        if(!notepad.notepadApp.save.checkState(HIDDEN) &&
           MouseEvents::isClicked(notepad.notepadApp.save, window)) {
            std::string temp = notepad.notepadApp.getUserInput();
            std::string fileName = notepad.notepadApp.getFileName();

            notepad.notepad.appRunning = false;
            computer.computer.appRunning = true;
            computer.myComputer.saveFile2Folder(temp, fileName);
        }
    }
    //TODO - ERROR CANNOT OPEN A FILE FROM COMPUTER
    //TODO - ERROR DELETE FILE DOES NOT WORK
    if(computer.computer.appRunning) {
        //open a file from the computer
        if(MouseEvents::isClicked(computer.myComputer.openButton, window)) {
            //get file contents and file data and set string
            Folder* file = computer.getSelectedFile();
            std::string filename_ = file->folder.getFileName();
            std::string filedata_ = file->folder.getFileData();

            computer.deselectFile();
            computer.computer.appRunning = false;
            notepad.notepad.appRunning = true;
            openFile(filename_, filedata_);
        }
        //delete a file from the computer
        if(MouseEvents::isClicked(computer.myComputer.deleteButton, window)) {
            Folder* file = computer.getSelectedFile();
            std::string filename_ = file->folder.getFileName();
            std::string filedata_ = file->folder.getFileData();
            deleteFile(filename_, filedata_);

            recyclebin.recyclebin.appRunning = true;
            computer.computer.appRunning = false;
        }
    }

    //recovers a file
    if(recyclebin.recyclebin.appRunning) {
        if(MouseEvents::isClicked(recyclebin.recoverButton, window)) {
            if(!recyclebin.deletedFiles.empty()) {
                Folder* file = new Folder;
                file = recyclebin.recoverFile();
                recoverFile(file->folder.getFileName(), file->folder.getFileData());
                recyclebin.recyclebin.appRunning = false;
                computer.computer.appRunning = true; //show recovered file in directory
            }
        }
    }
}

void Interface::update() {
    computer.update();
    notepad.update();
    recyclebin.update();
}

void Interface::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(this->wallpaper);

    target.draw(notepad);
    target.draw(computer);
    target.draw(recyclebin);
}
