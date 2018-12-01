// Organism.cpp - Class file for Organism.h
//
// Created by Michael Gosling on 11/30/18.
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

char Organism::getSpecies() {
    return this->species;
}