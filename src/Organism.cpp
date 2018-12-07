// Organism.cpp - Class file for Organism.h
//
// Created by Michael Gosling on 11/30/18.
// Last Updated by Michael Gosling on 12/03/18.
//

#include "Organism.h"
#include "GameSpecs.h"

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
    output << " " << organism->getSpeciesString() << " ";
    return output;
}

std::string Organism::getSpeciesString() {
    // create a new string, append different values depending on the species
    std::string outputString;

    if (Species::ZOMBIE == this->getSpecies()) {
        outputString.append("\033[1;");
        outputString.append(to_string(ZOMBIE_COLOR));
        outputString.append("m");
        outputString.append("Z");
        outputString.append("\033[0;");
        outputString.append(to_string(RESET_COLOR));
        outputString.append("m");
    } else {
        outputString.append("\033[1;");
        outputString.append(to_string(HUMAN_COLOR));
        outputString.append("m");
        outputString.append("H");
        outputString.append("\033[0;");
        outputString.append(to_string(RESET_COLOR));
        outputString.append("m");
    }
    // return string
    return outputString;
}
