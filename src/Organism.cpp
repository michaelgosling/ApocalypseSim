// Organism.cpp - Class file for Organism.h
//
// Created by Michael Gosling on 11/30/18.
// Last Updated by Michael Gosling on 12/03/18.
//

#include "Organism.h"

/** Default Constructor */
Organism::Organism() = default;

/** Constructor */
Organism::Organism(City *city) {
    this->city = city;
}

/** Destructor */
Organism::~Organism() = default;

/**
 * Set position of organism
 * @param x X Co-ordinate Integer
 * @param y Y Co-ordinate Integer
 */
void Organism::setPosition(int x, int y) {
    this->x = x;
    this->y = y;
}

/**
 * Returns whether the organism moved or not
 * @return boolean representing moved or not
 */
bool Organism::getMoved() {
    return this->moved;
}

/**
 * Sets whether the organism has moved or not
 * @param val Boolean to set moved to
 */
void Organism::setMoved(bool val) {
    this->moved = val;
}

/**
 * Gets the species of the organism
 * @return Species enum value representing current species
 */
Species Organism::getSpecies() {
    return this->species;
}

/**
 * Output overloaded operator for organism
 * @param output Ostream
 * @param organism Organism to output
 * @return output stream
 */
ostream &operator<<(ostream &output, Organism *organism) {
    output << " " << ((Species::ZOMBIE == organism->getSpecies()) ? 'Z' : 'H') << " ";
    return output;
}
