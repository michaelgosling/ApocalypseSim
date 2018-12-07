// Human.cpp - Class file for Human.h
//
// Created by Michael Gosling on 11/30/18.
// Last Updated by Michael Gosling on 12/07/18.
//

#include "Human.h"

/** Default Constructor */
Human::Human() {
    this->species = Species::HUMAN;
}

/** Constructor */
Human::Human(City *city) : Organism(city) {
    this->species = Species::HUMAN;
}

/** Destructor */
Human::~Human() = default;

/**
 * Generates new X and Y co-ordinates based on the direction given
 * @param move NORTH, SOUTH, EAST, WEST
 * @return int array with a new x and y
 */
int *Human::generateNewPosition(int move) {
    // generate new x and y co-ordinates based on move
    int newX = this->x;
    int newY = this->y;
    switch (move) {
        case NORTH:
            newY--;
            break;
        case SOUTH:
            newY++;
            break;
        case EAST:
            newX++;
            break;
        case WEST:
            newX--;
            break;
        default:
            break;
    }

    // return int array with new coords
    return new int[2]{newX, newY};
}

/** Move routine for Human */
void Human::move() {
    vector<int> moves;

    // check if moves are possible and add them to the vector if so
    if (y - 1 >= 0 && city->getOrganism(x, y - 1) == nullptr)
        moves.push_back(NORTH);
    if (y + 1 < GRID_HEIGHT && city->getOrganism(x, y + 1) == nullptr)
        moves.push_back(SOUTH);
    if (x - 1 >= 0 && city->getOrganism(x - 1, y) == nullptr)
        moves.push_back(WEST);
    if (x + 1 < GRID_WIDTH && city->getOrganism(x + 1, y) == nullptr)
        moves.push_back(EAST);

    // if there are moves to make
    if (!moves.empty()) {
        // set previous position to null
        city->setOrganism(nullptr, x, y);

        // get a random move
        int move = moves.at(rand() % moves.size());

        // get a new location based on the decided move
        int *newLoc;
        newLoc = generateNewPosition(move);

        // set to new position
        this->setPosition(newLoc[0], newLoc[1]);

        // set this human to new location on the city grid
        city->setOrganism(this, x, y);
    }

    // set moved to true
    this->moved = true;
}

/**
 * Creates a new human in an adjacent square if the time is right
 */
void Human::breed() {
    if (this->breedCounter >= 3) {
        // vector to store target directions
        vector<int> targets;

        // store all possible targets into the targets vector
        if (y - 1 >= 0 && city->getOrganism(x, y - 1) == nullptr)
            targets.push_back(NORTH);
        if (y + 1 < GRID_HEIGHT && city->getOrganism(x, y + 1) == nullptr)
            targets.push_back(SOUTH);
        if (x + 1 < GRID_WIDTH && city->getOrganism(x + 1, y) == nullptr)
            targets.push_back(EAST);
        if (x - 1 >= 0 && city->getOrganism(x - 1, y) == nullptr)
            targets.push_back(WEST);

        //get random move from vector
        if (!targets.empty()) {
            int target = targets.at(rand() % targets.size());

            // create a new human
            auto *human = new Human(city);

            // generate a new x and y location using the decided target
            int *newLoc;
            newLoc = generateNewPosition(target);

            // set the new human's position to the generated location
            human->setPosition(newLoc[0], newLoc[1]);

            // set the location in the city to the new humans location
            city->setOrganism(human, newLoc[0], newLoc[1]);
        }

        // counter resets whether it breeds or not
        this->breedCounter = 0;
    } else
        this->breedCounter++; // increment counter if not breeding time
}
