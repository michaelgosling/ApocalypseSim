// Zombie.cpp - Class file for Zombie.h
//
// Created by Michael Gosling on 11/30/18.
//

#include "Zombie.h"

/// Constructors
Zombie::Zombie() {
    this->species = 'Z';
}
Zombie::Zombie(City *city, int width, int height) : Organism(city, width, height) {
    this->species = 'Z';
}

/// Destructors
Zombie::~Zombie() {}

/// Routines

void Zombie::move() {

}
