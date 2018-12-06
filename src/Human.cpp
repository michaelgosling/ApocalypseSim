// Human.cpp - Class file for Human.h
//
// Created by Michael Gosling on 11/30/18.
// Last Updated by Michael Gosling on 12/06/18.
//

#include "Human.h"

Human::Human() {
    this->species = Species::HUMAN;
}

Human::Human(City *city) : Organism(city) {
    this->species = Species::HUMAN;
}

Human::~Human() {

}

void Human::move() {

}

void Human::spawn() {

}
