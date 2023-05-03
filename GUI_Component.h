//
// Created by Kelly Lwin on 3/9/2023.
//

#ifndef SFML_TEMPLATE_GUI_COMPONENT_H
#define SFML_TEMPLATE_GUI_COMPONENT_H
#include "States.h"
#include "Snapshot.h"
//#include "Keyboard_Shortcut.h"

class GUI_Component: public States,
public Snapshot, public sf::Drawable {

};

#endif //SFML_TEMPLATE_GUI_COMPONENT_H
