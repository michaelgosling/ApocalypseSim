// Human.cpp - Class file for Human.h
//
// Created by Michael Gosling on 11/30/18.
// Last Updated by Michael Gosling on 12/06/18.
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

        // get new location
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

        // set to new position
        this->setPosition(newX, newY);

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
    // TODO: Breed code
    if (breedCounter >= 3) {
        vector<int> moves;

        //stores the valid moves into the vector
        if (y - 1 >= 0 && city->getOrganism(x, y - 1) == nullptr)
            moves.push_back(NORTH);
        if (y + 1 < GRID_HEIGHT && city->getOrganism(x, y + 1) == nullptr)
            moves.push_back(SOUTH);
        if (x + 1 < GRID_WIDTH && city->getOrganism(x + 1, y) == nullptr)
            moves.push_back(EAST);
        if (x - 1 >= 0 && city->getOrganism(x - 1, y) == nullptr)
            moves.push_back(WEST);

        //get random move from vector
        if (!moves.empty()) {
            int breedSpot = moves.at(rand() % moves.size());
            //creates a new human
            auto *human = new Human(city);

            //human's new position is set
            int newX = this->x;
            int newY = this->y;
            switch (breedSpot) {
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
            human->setPosition(newX, newY);

            //set the human in the city
            city->setOrganism(human, human->x, human->y);

            // set new human to moved so it doesn't move out of turn
            human->moved = true;

        }

        // counter resets whether it breeds or not
        this->breedCounter = 0;
    } else
        this->breedCounter++; // increment counter if not breeding time
}
