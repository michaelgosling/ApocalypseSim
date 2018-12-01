// Human.cpp - Class file for Human.h
//
// Created by Michael Gosling on 11/30/18.
//

#include "Human.h"

/// Constructors
Human::Human() {
    this->species = 'H';
}
Human::Human(City *city, int width, int height) : Organism(city, width, height) {
    this->species = 'H';
}

/// Destructors
Human::~Human() {
    // TODO: Destructor
}

/// Routines


/**
 * Attempts to add a new human to an empty adjacent space
 */
void Human::recruit(){
    // TODO: Recruit Routine
}


/**
 * Human attempts to move to an adjacent space
 */
void Human::move() {
    // TODO: Finish move routine
    int direction = rand() % 4;
    switch (direction) {
        case NORTH:
            //this->setPosition(x, y-1);
            break;
        case SOUTH:
            //this->setPosition(x, y+1);
            break;
        case EAST:
            //this->setPosition(x+1, y);
            break;
        case WEST:
            //this->setPosition(x-1, y);
            break;
    }
}

