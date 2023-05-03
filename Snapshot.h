//
// Created by Kelly Lwin on 3/9/2023.
//

#ifndef SFML_TEMPLATE_SNAPSHOT_H
#define SFML_TEMPLATE_SNAPSHOT_H
#include "States.h"

class Snapshot {
private:
    States objStates;
    std::string data;
public:
    // this function will return a snapshot of the object's current state
    virtual Snapshot* getSnapshot() = 0;

    // this function will apply a snapshot to the object.
    //This will revert the object back to the state that has been recorded in the snapshot
    virtual void applySnapshot(const Snapshot& snapshot) = 0;
};

#endif //SFML_TEMPLATE_SNAPSHOT_H
