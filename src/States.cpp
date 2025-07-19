//
// Created by Kelly Lwin on 3/9/2023.
//

#include "States.h"
std::map<stateEnum, bool> map;

States::States()
{
    load();
}

void States::load() {
    for(int i = 0; i < LASTSTATE ;i++)
    {
        map[static_cast<stateEnum>(i)] = false;
    }
}

void States::enableAllStates()
{
    for(int i = 0; i < LASTSTATE ;i++)
    {
        map[static_cast<stateEnum>(i)] = true;
    }
}

void States::disableAllStates()
{
    for(int i = 0; i < LASTSTATE ;i++)
    {
        map[static_cast<stateEnum>(i)] = false;
    }
}

bool States::checkState(stateEnum state) const
{
    return map.at(state);
}

void States::enableState(stateEnum state)
{
    setState(state,true);
}

void States::disableStates(stateEnum state)
{
    setState(state,false);
}

void States::setState(stateEnum state, bool value)
{
    map.at(state) = value;
}

void States::toggleState(stateEnum state)
{
    setState(state, !map.at(state));
}