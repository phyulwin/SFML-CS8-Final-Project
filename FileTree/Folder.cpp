//
// Created by Kelly Lwin on 4/20/2023.
//

#include "Folder.h"

Folder::Folder(): Folder("Untitled") {

}

Folder::Folder(const std::string &folderName): folderName(folderName) {
    folder.changeToFolderIcon();
    folder.setFileName(folderName);
//    folder.disableStates(HIDDEN);
}

void Folder::removeFile(const std::string &fileName) {
    if(!children.empty()) {
        for(int i=0; i<children.size(); ++i) {
            if(children[i]->folder.getFileName()==fileName) {
                children.erase(children.begin()+i);
            }
        }
    }
}

float Folder::getContentHeight() {
//    float height = getGlobalBounds().height;
    float height = 0;
    for(int i=0; i<fileCount(); ++i) {
        height += getGlobalBounds().height;
    }
    return height;
}

void Folder::setFolderName(const std::string &name) {
    folderName = name;
    folder.setFileName(name);
}

void Folder::addFile(const File &file) {
    addFile(file.getFileName(), file.getFileData());
}

void Folder::addFile(const std::string &fileName, const std::string &fileData) {
    Folder* child = new Folder;
    child->folder.setFileName(fileName);
    child->folder.setFileData(fileData);
    children.push_back(child);
}

void Folder::addFile(const std::string &fileName) {
    Folder* child = new Folder;
    child->folder.setFileName(fileName);
    child->folder.setFileData("");
    children.push_back(child);
}

void Folder::reposition() {
    float x = folder.getPosition().x + 50;
    float y = folder.getPosition().y + folder.getGlobalBounds().height;
    for(int i=0; i<children.size(); ++i) {
        children[i]->setPosition({x, y});
        y += children[i]->getGlobalBounds().height;
    }
}

void Folder::printFileNames() {
    for(int i=0; i<children.size(); ++i) {
        std::cout << children[i]->folder.getFileName() << std::endl;
    }
}

sf::Vector2f Folder::getPosition() const {
    return folder.getPosition();
}

void Folder::setPosition(const sf::Vector2f &pos) {
    folder.setPosition(pos);
}

void Folder::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    folder.addEventHandler(window, event);
    //if the folder is clicked, show children files
    if(MouseEvents::isClicked(folder, window)) {
        folder.enableState(IS_CLICKED);
        folder.enableState(IS_OPENED);
//        folder.enableState(IS_SELECTED);
        for (int i = 0; i < fileCount(); ++i) {
            children[i]->folder.changeToFileIcon();
            children[i]->folder.disableStates(HIDDEN);
            children[i]->folder.addEventHandler(window, event);
        }
    }
//    if(MouseEvents::isNotClicked(folder, window)) {
//        folder.disableStates(IS_OPENED);
//    }
    if(folder.checkState(IS_CLICKED)) {
        for(int i=0; i<fileCount(); ++i) {
            if(MouseEvents::isClicked(children[i]->folder, window)) {
                children[i]->folder.enableState(IS_SELECTED);
            } //ADDED
//            if(MouseEvents::isNotClicked(children[i]->folder, window)) {
//                children[i]->folder.disableStates(IS_SELECTED);
//            }
        }
    }
}

Folder *Folder::getSelected() const {
    for(int i=0; i<fileCount(); ++i) {
        if(children[i]->checkState(IS_SELECTED)) {
            return children[i];
        }
    }
}

void Folder::deselectFile() {
    for(int i=0; i<fileCount(); ++i) {
        children[i]->disableStates(IS_SELECTED);
    }
}

void Folder::hideAllFile() {
    for(int i=0; i<fileCount(); ++i) {
        children[i]->folder.enableState(HIDDEN);
    }
}

void Folder::update() {
    folder.update();
    for(int i=0; i<fileCount(); ++i) {
        children[i]->folder.update();
    }
//    if(!checkState(IS_OPENED)) {
//        for(int i=0; i<fileCount(); ++i) {
//            children[i]->folder.enableState(HIDDEN);
//        }
//    }
}

void Folder::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(this->folder);
    if(checkState(IS_CLICKED)) {
        if(!children.empty()) {
            for(int i=0; i<children.size(); ++i) {
                target.draw(children[i]->folder);
            }
        }
    }
}

/*
int Folder::getSize() const {
    return files.size();
}

void Folder::addFile(const File& file) {
    //check if file already exists
    if(!fileExists(file.getFileName())) {
        files.push_back(file.getFileName());
    }
    else {std::cout << "File already exists in folder.";}
}

void Folder::deleteFile(const File &file) {
    if(fileExists(file.getFileName())) {
        int index = 0;
        auto iter = files.begin();
        while(iter != files.end()) {
            ++index;
            ++iter;
        }
        files.erase(files.begin()+index);
    }
}

bool Folder::fileExists(const std::string &fileName) {
    if(!files.empty()) {
        auto iter = files.begin();
        while(iter != files.end()) {
            if(*iter==fileName) {
                return true;
            }
            ++iter;
        }
        return false;
    }
}*/
