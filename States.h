//
// Created by Kelly Lwin on 3/9/2023.
//

#ifndef SFML_TEMPLATE_STATES_H
#define SFML_TEMPLATE_STATES_H
#include <iostream>
#include <SFML\Graphics.hpp>
#include <iostream>
#include <SFML\Graphics.hpp>

enum stateEnum
{
    HIDDEN,
    HIGHLIGHTED,
    DISABLED,
    IS_FOLDER, //FOR FILE TREE
    IS_CLICKED,
    IS_OPENED,
    IS_SELECTED, //FOR RECYCLE BIN
    LASTSTATE
};

class States {
private:
    std::map<stateEnum, bool> map;
    void load();
    void enableAllStates();
    void disableAllStates();
public:
    States();
    bool checkState(stateEnum state) const;
    void enableState(stateEnum state);
    void disableStates(stateEnum state);
    void setState(stateEnum state, bool value);
    void toggleState(stateEnum states);
};
#endif //SFML_TEMPLATE_STATES_H
