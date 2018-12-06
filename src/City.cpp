// City.cpp - Class file for City.h
//
// Created by Michael Gosling on 11/30/18.
//

#include "City.h"

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
    // move humans
    for (auto &row : grid) {
        for (auto &org : row) {
            if (org != nullptr) {
                if (org->getSpecies() == Species::HUMAN && !org->getMoved()) org->move();
            }
        }
    }

    // move zombies
    for (auto &row : grid) {
        for (auto &org : row) {
            if (org != nullptr) {
                if (org->getSpecies() == Species::ZOMBIE && !org->getMoved()) org->move();
            }
        }
    }
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
                output << " " << ((Species::ZOMBIE == j->getSpecies()) ? 'Z' : 'H') << " ";
        }
        output << endl;
    }
    return output;
}
