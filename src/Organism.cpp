// Organism.cpp - Class file for Organism.h
//
// Created by Michael Gosling on 11/30/18.
// Last Updated by Michael Gosling on 12/03/18.
//

#include "Organism.h"

/// Constructors
Organism::Organism() = default;
Organism::Organism(City *city, int width, int height) {
    this->city = city;
    this->width = width;
    this->height = height;
}

/// Destructors
Organism::~Organism() {}

/// Routines
void Organism::setPosition(int x, int y) {
    this->x = x;
    this->y = y;
}

/**
 * Returns the objects species property
 * @return char representing species
 */
char Organism::getSpecies() {
    return this->species;
}

/**
 * Returns the 'moved' property
 * @return bool representing whether it moved or not
 */
bool Organism::didMove() {
    return moved;
}

/**
 * Sets moved to false;
 */
void Organism::newTurn() {
    moved = false;
}
