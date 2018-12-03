// Zombie.cpp - Class file for Zombie.h
//
// Created by Michael Gosling on 11/30/18.
// Last Updated by Michael Gosling on 12/03/18.
//

#include "Zombie.h"
#include "Human.h"
#include "GameSpecs.h"

/// Constructors
Zombie::Zombie() {
    this->species = 'Z';
    this->hungerCounter = 0;
    this->stepCount = 0;
    this->canInfect = false;
}
Zombie::Zombie(City *city, int width, int height) : Organism(city, width, height) {
    this->species = 'Z';
    this->hungerCounter = 0;
    this->stepCount = 0;
    this->canInfect = false;
}

/// Destructors
Zombie::~Zombie() {}

/// Routines

/**
 * Move routine for a Zombie
 */
void Zombie::move() {
    // list of possible moves
    int moves[8][2]{{0,  -1},
                    {1,  -1},
                    {1,  0},
                    {1,  1},
                    {0,  1},
                    {-1, 1},
                    {-1, 0},
                    {-1, -1}};
    // variable to hold decided move
    int decidedMove[2] = {0, 0};

    // get first possible move
    for (auto pMove : moves) {
        if (city->getOrganism(x + pMove[0], y + pMove[1]) != nullptr) {
            if (city->getOrganism(x + pMove[0], y + pMove[1])->getSpecies() == 'H') {
                decidedMove[0] = pMove[0];
                decidedMove[1] = pMove[1];
                break;
            }
        }
    }

    // set new x and y to current x and y
    int newX = x;
    int newY = y;

    // if the decided move exists, commit it
    if (decidedMove[0] != 0 || decidedMove[1] != 0) {
        // increment x and y by the possible move
        newX += decidedMove[0];
        newY += decidedMove[1];

        // grab a reference to the human and tell it to die
        auto *human = (Human *) city->getOrganism(newX, newY);
        human->die();

        // reset hunger counter
        hungerCounter = 0;
    } else {
        // generate random direction
        int direction = rand() % 4;

        // use a switch to get new co-ordinate.
        switch (direction) {
            case NORTH:
                newY = (y - 1 < 0) ? y : y - 1;
                break;
            case SOUTH:
                newY = (y + 1 > 19) ? y : y + 1;
                break;
            case EAST:
                newX = (x + 1 > 19) ? x : x + 1;
                break;
            case WEST:
                newX = (x - 1 < 0) ? x : x - 1;
                break;
            default:
                break;
        }

        hungerCounter++;
    }

    // set the current space to null, set this to new position, then set the new position
    // in the city to the new co-ordinates
    if (newX != x || newY != y) {
        city->setOrganism(nullptr, x, y);
        this->setPosition(newX, newY);
        city->setOrganism(this, x, y);
    }

    // increment the step counter, if it's 8 or above make sure this zombie is ready
    // to infect
    stepCount++;
    if (stepCount >= 8)
        canInfect = true;

    // if the hunger counter is above the threshold for starving, set the appropriate bool
    if (hungerCounter >= ZOMBIE_STARVE)
        isStarved = true;

}

/**
 * Routine for the zombie to convert nearby player
 * @return
 */
int *Zombie::breed() {
    // TODO: Breed Routine
    return nullptr;
}
