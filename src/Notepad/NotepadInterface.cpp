//
// Created by Kelly Lwin on 4/27/2023.
//

#include "NotepadInterface.h"

void NotepadInterface::createApp() {
    notepad.setAppName("Notepad");
    notepad.setAppIcon(NOTEPAD);
    notepad.setPosition({50, 200});
    notepad.setWindowPosition({300, 50});
}

NotepadInterface::NotepadInterface() {
    createApp();
    disableStates(HIDDEN);
}

void NotepadInterface::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    notepad.addEventHandler(window, event);
    if(notepad.appRunning) {
        notepadApp.addEventHandler(window, event);
        //if the exit button is clicked, stop the notepad app from running
        if(!notepadApp.exit.checkState(HIDDEN) && MouseEvents::isClicked(notepadApp.exit, window)) {
            notepad.appRunning = false;
        }
    }
}

void NotepadInterface::update() {
    notepad.update();
}

void NotepadInterface::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(notepad);
    if(notepad.appRunning) {
        target.draw(this->notepad.appWindow);
        target.draw(this->notepadApp);

        target.draw(notepadApp.fileButton);
        target.draw(notepadApp.editButton);
    }
}
