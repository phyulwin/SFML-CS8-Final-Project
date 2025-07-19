//
// Created by Kelly Lwin on 4/28/2023.
//

#ifndef SFML_TEMPLATE_COMPUTERINTERFACE_H
#define SFML_TEMPLATE_COMPUTERINTERFACE_H
#include "../Apps.h"
#include "../App_Window.h"
//#include "../Notepad/Notepad.h"
#include "Computer.h"
#include "../MouseEvents.h"
#include "../HelperClass.h"

class ComputerInterface: public sf::Drawable, public States {
private:
    void createApp();
public:
    Button open, save, deleteButton;
    Apps computer;
    Computer myComputer;

    ComputerInterface();

    Folder* getSelectedFile() const;
    void deselectFile();
    void deleteFileFromFolder(const std::string& fileName);

    void saveFile(const std::string& folderName, const std::string& fileName, const std::string& fileData);

    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //SFML_TEMPLATE_COMPUTERINTERFACE_H
