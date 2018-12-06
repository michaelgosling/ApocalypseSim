// Zombie.cpp - Class file for Zombie.h
//
// Created by Michael Gosling on 11/30/18.
// Last Updated by Michael Gosling on 12/03/18.
//

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
 * Zombie checks for food, eats food if it finds one. Otherwise finds a direction to move and does it.
 */
void Zombie::move() {
    // moves vector
    vector<int> moves;

    // Check for food.
    if (y - 1 >= 0 && dynamic_cast<Human *>(city->getOrganism(x, y - 1)) != nullptr)
        moves.push_back(NORTH);
    if (y + 1 < GRID_HEIGHT && dynamic_cast<Human *>(city->getOrganism(x, y + 1)) != nullptr)
        moves.push_back(SOUTH);
    if (x + 1 < GRID_WIDTH && dynamic_cast<Human *>(city->getOrganism(x + 1, y)) != nullptr)
        moves.push_back(EAST);
    if (x - 1 >= 0 && dynamic_cast<Human *>(city->getOrganism(x - 1, y)) != nullptr)
        moves.push_back(WEST);
    if (y - 1 >= 0 && x + 1 < GRID_WIDTH && dynamic_cast<Human *>(city->getOrganism(x + 1, y - 1)) != nullptr)
        moves.push_back(NORTH_EAST);
    if (y + 1 < GRID_HEIGHT && x + 1 < GRID_WIDTH && dynamic_cast<Human *>(city->getOrganism(x + 1, y + 1)) != nullptr)
        moves.push_back(SOUTH_EAST);
    if (y - 1 >= 0 && x - 1 >= 0 && dynamic_cast<Human *>(city->getOrganism(x - 1, y - 1)) != nullptr)
        moves.push_back(NORTH_WEST);
    if (y + 1 < GRID_HEIGHT && x - 1 >= 0 && dynamic_cast<Human *>(city->getOrganism(x - 1, y + 1)) != nullptr)
        moves.push_back(SOUTH_WEST);

    // if there's people to eat, reset starve timer
    if (!moves.empty())
        this->starveTimer = 0;
    else {
        // increment starve timer if no people eaten
        this->starveTimer++;

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
        int move = moves.at(rand() % moves.size());

        // Set previous location to null
        city->setOrganism(nullptr, this->x, this->y);

        // set new position of this zombie
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

        // set this position to the new co-ordinates
        this->setPosition(newX, newY);

        // add this to the city at the new co-ordinate
        city->setOrganism(this, x, y);
    }

    // set moved to true and run starve method
    this->moved = true;
    this->starve();
}

/**
 * Create a new zombie if the time is right
 */
void Zombie::breed() {
    // TODO: Breeding code
}

/**
 * Convert zombie back to human if it's starved
 */
void Zombie::starve() {
    if (this->starveTimer >= ZOMBIE_STARVE) {
        // TODO: Starve code
    }
}

