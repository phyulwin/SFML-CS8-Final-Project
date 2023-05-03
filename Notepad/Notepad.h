//
// Created by Kelly Lwin on 4/24/2023.
//

#ifndef SFML_TEMPLATE_NOTEPAD_H
#define SFML_TEMPLATE_NOTEPAD_H
#include <iostream>
#include <SFML/Graphics.hpp>

#include "../TextInput/TextInput.h"
#include "../MenuBar/MenuBar.h"

#include "../MouseEvents.h"
#include "../HelperClass.h"

class Notepad: public sf::Drawable, public States {
public:
    //representative buttons
    PhonyButton fileButton, editButton;
    PhonyButton open, save, exit;
    PhonyButton font, color, size;

    void showFileItems();
    void showEditItems();
    void hideFileItems();
    void hideEditTimes();
private:
    MenuBar menuBar;
    Menu file;
    Menu edit;

    TextInput ti;
    //current file opened
    sf::Text fileName;
    std::string fileNameString;

    void setUpMenuBar();
    void placePhonyButtons(const sf::Vector2f& pos);
public:
    Notepad();
    sf::Vector2f getPosition() const;
    void setPosition(const sf::Vector2f& pos);

    std::string getUserInput();
    std::string getFileName();

    void openFile(const std::string& fileName, const std::string& fileData);

    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //SFML_TEMPLATE_NOTEPAD_H
