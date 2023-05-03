//
// Created by Kelly Lwin on 4/27/2023.
//

#ifndef SFML_TEMPLATE_NOTEPADINTERFACE_H
#define SFML_TEMPLATE_NOTEPADINTERFACE_H
#include "../Apps.h"
#include "../App_Window.h"
#include "../Notepad/Notepad.h"

#include "../MouseEvents.h"
#include "../HelperClass.h"

class NotepadInterface: public sf::Drawable, public States {
private:
    void createApp();
public:
    Apps notepad;
    Notepad notepadApp;

    NotepadInterface();
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //SFML_TEMPLATE_NOTEPADINTERFACE_H
