// City.cpp - Class file for City.h
//
// Created by Michael Gosling on 11/30/18.
//

#include "City.h"

/// Constructors
City::City() {
    for (auto row : grid ){
        for(int i = 0; i < GRID_HEIGHT; i++){
            row[i] = nullptr;
        }
    }
}

/// Destructors
City::~City() {
    // TODO: Destructor
}

/// Routines

/**
 * Returns the organism at location x,y
 * @param x Integer representing X location
 * @param y Integer representing Y location
 * @return Organism
 */
Organism *City::getOrganism(int x, int y) {
    return grid[x][y];
}

/**
 * Sets an organism to location x,y
 * @param organism Organism to set
 * @param x Integer representing X location
 * @param y Integer representing Y location
 */
void City::setOrganism(Organism *organism, int x, int y) {
        grid[x][y] = organism;
}

/**
 * Moves
 */
void City::move() {
    
}
