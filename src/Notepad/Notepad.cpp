//
// Created by Kelly Lwin on 4/24/2023.
//

#include "Notepad.h"

void Notepad::showFileItems() {
    open.disableStates(HIDDEN);
    save.disableStates(HIDDEN);
    exit.disableStates(HIDDEN);
}

void Notepad::showEditItems() {
    font.disableStates(HIDDEN);
    color.disableStates(HIDDEN);
    size.disableStates(HIDDEN);
}

void Notepad::hideFileItems() {
    open.enableState(HIDDEN);
    save.enableState(HIDDEN);
    exit.enableState(HIDDEN);
}

void Notepad::hideEditTimes() {
    font.enableState(HIDDEN);
    color.enableState(HIDDEN);
    size.enableState(HIDDEN);
}

void Notepad::placePhonyButtons(const sf::Vector2f& pos) {
    fileButton.setPosition({pos.x+50, pos.y-10});
    editButton.setPosition({pos.x+250, pos.y-10});

    sf::Vector2f temp = fileButton.getPosition();
    open.setPosition({temp.x, temp.y+50});
    save.setPosition({temp.x, temp.y+100});
    exit.setPosition({temp.x, temp.y+150});

    temp = editButton.getPosition();
    font.setPosition({temp.x, temp.y+50});
    color.setPosition({temp.x, temp.y+100});
    size.setPosition({temp.x, temp.y+150});
}

void Notepad::setUpMenuBar() {
    file.setMenuTittle("File");
    edit.setMenuTittle("Edit");

    file.addMenuItem("Open");
    file.addMenuItem("Save");
    file.addMenuItem("Exit");

    edit.addMenuItem("Font");
    edit.addMenuItem("Text Color");
    edit.addMenuItem("Text Size");

    menuBar.creatMenu(file);
    menuBar.creatMenu(edit);

    menuBar.changeTextColor(sf::Color::Green);
}

Notepad::Notepad() {
    setPosition({150, 150});
    ti.textBox.setMarginColor(sf::Color::Transparent);

    setUpMenuBar();
    placePhonyButtons({300, 150});
    hideFileItems();
    hideEditTimes();
}

sf::Vector2f Notepad::getPosition() const {
    return ti.textBox.getPosition();
}

void Notepad::setPosition(const sf::Vector2f &pos) {
    ti.textBox.setPosition({(pos.x*2)+10, pos.y+50});
    ti.setBoxSize({700, 500});

    menuBar.setPosition({(pos.x*2)+30, pos.y-10});
}

std::string Notepad::getUserInput() {
    return ti.textBox.getString();
}

std::string Notepad::getFileName() {
    return fileNameString;
}

void Notepad::openFile(const std::string &fileName, const std::string &fileData) {
    ti.textBox.setString(fileData);
}

void Notepad::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    ti.addEventHandler(window, event);

    menuBar.addEventHandler(window, event);

    if(MouseEvents::isClicked(fileButton, window)) {
        showFileItems();
        hideEditTimes();
    }
    if(MouseEvents::isClicked(editButton, window)) {
        showEditItems();
        hideFileItems();
    }
    //other buttons
    if(MouseEvents::isClicked(font, window)) {
        ti.changeFont();
    }
    if(MouseEvents::isClicked(color, window)) {
        ti.changeTextColor();
    }
    if(MouseEvents::isClicked(size, window)) {
        ti.changeTextSize();
    }
}

void Notepad::update() {
    ti.update();

    menuBar.update();
}

void Notepad::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(this->ti);

    target.draw(this->menuBar);

    if(!open.checkState(HIDDEN)) {
        target.draw(this->open);
        target.draw(this->save);
        target.draw(this->exit);
    }

    if(!open.checkState(HIDDEN)) {
        target.draw(this->font);
        target.draw(this->color);
        target.draw(this->size);
    }
}


