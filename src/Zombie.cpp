// Zombie.cpp - Class file for Zombie.h
//
// Created by Michael Gosling on 11/30/18.
// Last Updated by Michael Gosling on 12/03/18.
//

#include "Zombie.h"

Zombie::Zombie() {
    this->species = Species::ZOMBIE;
}

Zombie::Zombie(City *city) : Organism(city) {
    this->species = Species::ZOMBIE;
}

Zombie::~Zombie() {

}

void Zombie::move() {

}

void Zombie::spawn() {

}

int Zombie::getStarved() {
    return 0;
}

void Zombie::setStarved(int eat) {

}

void Zombie::starve() {

}

