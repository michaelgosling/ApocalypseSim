// City.cpp - Class file for City.h
//
// Created by Michael Gosling on 11/30/18.
// Last updated by Michael Gosling on 12/07/18.
//

#include "City.h"
#include <vector>
#include <random>
#include <algorithm>

/**
 * Default Constructor
 */
City::City() = default;

/**
 * Destructor. Delete's or nulls everything in grid.
 */
City::~City() {
    for (auto &i : grid) {
        for (auto &j : i)
            delete[] j;
        *i = nullptr;
    }
}

/**
 * Returns the organism at X, Y
 * @param x X Co-ordinate Integer
 * @param y Y Co-ordinate Integer
 * @return Organism
 */
Organism *City::getOrganism(int x, int y) {
    return grid[x][y];
}

/**
 * Sets an organism to a spot on the grid
 * @param organism Organism to set the location of
 * @param x X Co-ordinate Integer
 * @param y Y Co-ordinate Integer
 */
void City::setOrganism(Organism *organism, int x, int y) {
    grid[x][y] = organism;
}

/**
 * Move everything in the city.
 */
void City::move() {
    vector<Organism *> humans;
    vector<Organism *> zombies;

    // vector to hold organisms
    vector<Organism *> organisms;

    // sort human and zombies into their appropriate vectors
    for (auto &row : grid) {
        for (auto &org : row) {
            if (org != nullptr) {
                if (org->getSpecies() == Species::ZOMBIE) zombies.push_back(org);
                if (org->getSpecies() == Species::HUMAN) humans.push_back(org);
            }
        }
    }

    // shuffle zombies and humans vectors to discourage "bias of movement"
    random_device rd;
    shuffle(humans.begin(), humans.end(), default_random_engine(rd()));
    shuffle(zombies.begin(), zombies.end(), default_random_engine(rd()));

    // load humans into organism vector first, then zombies
    for (auto &human : humans)
        organisms.push_back(human);

    for (auto &zombie : zombies)
        organisms.push_back(zombie);

    // call move on all of them that haven't moved
    for (auto &org : organisms)
        if (!org->getMoved()) org->move();

    // clear and shrink to fit all 3 vectors so it frees the memory
    organisms.clear();
    humans.clear();
    zombies.clear();
    organisms.shrink_to_fit();
    humans.shrink_to_fit();
    zombies.shrink_to_fit();
}

/**
 * Output the city as a grid
 * @param output Output Stream
 * @param city City to output
 * @return ostream
 */
ostream &operator<<(ostream &output, City &city) {
    for (auto &i : city.grid) {
        for (auto &j : i) {
            if (j == nullptr)
                output << " - ";
            else
                output << " " << j->getSpeciesString() << " ";
        }
        output << endl;
    }
    return output;
}
