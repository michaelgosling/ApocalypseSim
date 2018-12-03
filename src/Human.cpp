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
int* Human::breed(){
    if(stepCount >= 3){
        stepCount = 0;
        if (city->getOrganism(x, y - 1) == nullptr)
            return new int[2] {x, y-1};
        else if (city->getOrganism(x + 1, y) == nullptr)
            return new int[2] {x+1, y};
        else if (city->getOrganism(x, y + 1) == nullptr)
            return new int[2] {x, y+1};
        else if (city->getOrganism(x - 1, y) == nullptr)
            return new int[2] {x-1, y};
        else
            return nullptr;
    } else {
        return nullptr;
    }

}

/**
 * Human attempts to move to an adjacent space
 */
void Human::move() {
    int direction = rand() % 4;
    int newX = x;
    int newY = y;

    // use a switch to get new co-ordinate.
    switch (direction) {
        case NORTH:
            newY = (y-1 < 0) ? y : y-1;
            break;
        case SOUTH:
            newY = (y+1 > 19) ? y : y+1;
            break;
        case EAST:
            newX = (x+1 > 19) ? x : x+1;
            break;
        case WEST:
            newX = (x-1 < 0) ? x : x-1;
            break;
        default:
            break;
    }

    if (city->getOrganism(newX, newY) == nullptr) {
        city->setOrganism(nullptr, x, y);
        this->setPosition(newX, newY);
        city->setOrganism(this, x, y);
    }

    moved = true;
    stepCount++;
}

