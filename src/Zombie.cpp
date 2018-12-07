// Zombie.cpp - Class file for Zombie.h
//
// Created by Michael Gosling on 11/30/18.
// Last Updated by Michael Gosling on 12/07/18.
//

#include <stdlib.h>
#include <time.h>
#include "Zombie.h"
#include "Human.h"

/** Default Constructor */
Zombie::Zombie() {
    this->species = Species::ZOMBIE;
}

/** Constructor */
Zombie::Zombie(City *city) : Organism(city) {
    this->species = Species::ZOMBIE;
}

/** Destructor */
Zombie::~Zombie() = default;

/**
 * Generates new X and Y co-ordinates based on the direction given
 * @param move NORTH, SOUTH, EAST, WEST, NORTH_EAST, NORTH_WEST, SOUTH_EAST, SOUTH_WEST
 * @return int array with a new x and y
 */
int *Zombie::generateNewPosition(int move) {
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
        case NORTH_EAST:
            newX++;
            newY--;
            break;
        case SOUTH_EAST:
            newX++;
            newY++;
            break;
        case NORTH_WEST:
            newX--;
            newY--;
            break;
        case SOUTH_WEST:
            newX--;
            newY++;
            break;
        default:
            break;
    }

    return new int[2]{newX, newY};
}

/**
 * Zombie checks for food, eats food if it finds one. Otherwise finds a direction to move and does it.
 */
void Zombie::move() {
    // find humans and store the moves into a vector
    vector<int> moves = findHumans();

    // if there's people to eat, reset starve timer
    if (!moves.empty())
        this->starveCounter = 0;
    else {
        // increment starve timer if no people eaten
        this->starveCounter++;

        // check for valid moves and add them to moves array
        if (y - 1 >= 0 && city->getOrganism(x, y - 1) == nullptr)
            moves.push_back(NORTH);
        if (y + 1 < GRID_HEIGHT && city->getOrganism(x, y + 1) == nullptr)
            moves.push_back(SOUTH);
        if (x + 1 < GRID_WIDTH && city->getOrganism(x + 1, y) == nullptr)
            moves.push_back(EAST);
        if (x - 1 >= 0 && city->getOrganism(x - 1, y) == nullptr)
            moves.push_back(WEST);
    }

    // if there's a valid move, decide on a random one
    if (!moves.empty()) {
        // seed random with current time and then grab a random move
        srand((unsigned int) time(nullptr));
        int move = moves.at(rand() % moves.size());

        // Set previous location to null
        city->setOrganism(nullptr, this->x, this->y);

        // get new co-ordinates
        int *newLoc;
        newLoc = generateNewPosition(move);

        // set this position to the new co-ordinates
        this->setPosition(newLoc[0], newLoc[1]);

        // add this to the city at the new co-ordinates
        city->setOrganism(this, x, y);
    }

    // set moved to true, run starve method, and increment the infect counter
    this->moved = true;
    this->starve();
    this->infectCounter++;
}

/**
 * Generates a vector of human locations around the zombie
 * @return vector<int> of directions near the zombie
 */
vector<int> Zombie::findHumans() {
    // create a new vector the list of possible humans
    vector<int> humans;

    // Check for food!
    // we do this by making sure the direction isn't out of bounds, and dynamically casting getOrganism
    // to a human. If it comes back as a null pointer we know it's either not a human or it's an empty space.
    // if it doesn't come back null, and it's inside the bounds, we push it back to the vector
    if (y - 1 >= 0 && dynamic_cast<Human *>(city->getOrganism(x, y - 1)) != nullptr)
        humans.push_back(NORTH);
    if (y + 1 < GRID_HEIGHT && dynamic_cast<Human *>(city->getOrganism(x, y + 1)) != nullptr)
        humans.push_back(SOUTH);
    if (x + 1 < GRID_WIDTH && dynamic_cast<Human *>(city->getOrganism(x + 1, y)) != nullptr)
        humans.push_back(EAST);
    if (x - 1 >= 0 && dynamic_cast<Human *>(city->getOrganism(x - 1, y)) != nullptr)
        humans.push_back(WEST);
    if (y - 1 >= 0 && x + 1 < GRID_WIDTH && dynamic_cast<Human *>(city->getOrganism(x + 1, y - 1)) != nullptr)
        humans.push_back(NORTH_EAST);
    if (y + 1 < GRID_HEIGHT && x + 1 < GRID_WIDTH && dynamic_cast<Human *>(city->getOrganism(x + 1, y + 1)) != nullptr)
        humans.push_back(SOUTH_EAST);
    if (y - 1 >= 0 && x - 1 >= 0 && dynamic_cast<Human *>(city->getOrganism(x - 1, y - 1)) != nullptr)
        humans.push_back(NORTH_WEST);
    if (y + 1 < GRID_HEIGHT && x - 1 >= 0 && dynamic_cast<Human *>(city->getOrganism(x - 1, y + 1)) != nullptr)
        humans.push_back(SOUTH_WEST);

    // return the vector of human locations
    return humans;
}

/**
 * Create a new zombie if the time is right
 */
void Zombie::breed() {
    // if the infect counter is above or equal to the zombie breed threshold, execute this
    if (this->infectCounter >= ZOMBIE_BREED) {
        // fill a vector with locations of humans adjacent
        vector<int> humans = findHumans();

        // if there's humans to convert
        if (!humans.empty()) {
            // get a random human from the vector
            srand((unsigned int) time(nullptr));
            int infectTarget = humans.at(rand() % humans.size());

            // create a new zombie
            auto *zombie = new Zombie(city);

            // generate a new position for the zombie
            int *newLoc;
            newLoc = generateNewPosition(infectTarget);

            // assign new location to the new zombie
            zombie->setPosition(newLoc[0], newLoc[1]);

            // set the new zombie to the given location
            city->setOrganism(zombie, newLoc[0], newLoc[1]);
        }
    }
}

/**
 * Convert zombie to human if it's starved
 */
void Zombie::starve() {
    if (this->starveCounter >= ZOMBIE_STARVE) {
        auto *human = new Human(city);
        human->setPosition(x, y);
        city->setOrganism(human, x, y);
        delete this;
    }
}

