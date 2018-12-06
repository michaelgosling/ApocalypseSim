// Organism.cpp - Class file for Organism.h
//
// Created by Michael Gosling on 11/30/18.
// Last Updated by Michael Gosling on 12/03/18.
//

#include "Organism.h"

Organism::Organism() {

}

Organism::Organism(City *city) {
    this->city = city;
}


Organism::~Organism() {

}

void Organism::setPosition(int x, int y) {

}

bool Organism::getMoved() {
    return false;
}

void Organism::setMoved(bool moved) {

}

bool Organism::getSpawned() {
    return false;
}

void Organism::setSpawned(bool spawned) {

}

int Organism::getSpawnCount() {
    return 0;
}

void Organism::setSpawnCount(int spawnCount) {

}

Species Organism::getSpecies() {
    return this->species;
}

ostream &operator<<(ostream &output, Organism *organism) {
    output << " " << ((Species::ZOMBIE == organism->getSpecies()) ? 'Z' : 'H') << " ";
    return output;
}
