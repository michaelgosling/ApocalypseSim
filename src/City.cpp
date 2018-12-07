// City.cpp - Class file for City.h
//
// Created by Michael Gosling on 11/30/18.
// Last updated by Michael Gosling on 12/07/18.
//

#include "City.h"
#include <vector>

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
    // vector to hold organisms
    vector<Organism *> organisms;

    // zombies go to end of vector, humans go to beginning
    for (auto &row : grid) {
        for (auto &org : row) {
            if (org != nullptr) {
                if (org->getSpecies() == Species::ZOMBIE) organisms.push_back(org);
                if (org->getSpecies() == Species::HUMAN) organisms.insert(organisms.begin(), org);
            }
        }
    }

    // call move on all of them that haven't moved
    for (auto &org : organisms)
        if (!org->getMoved()) org->move();

    // clear vector and shrink to fit so it frees the memory
    organisms.clear();
    organisms.shrink_to_fit();
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
