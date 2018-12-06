// Organism.h - Header file for Organism.cpp
//
// Created by Michael Gosling on 11/30/18.
// Last Updated by Michael Gosling on 12/06/18.
//


#ifndef APOCALYPSESIM_ORGANISM_H
#define APOCALYPSESIM_ORGANISM_H

#include <iostream>

using namespace std;

class City;

enum class Species {
    ZOMBIE, HUMAN
};

class Organism
{
protected:
    int x;
    int y;
    bool moved;
    Species species;
    City *city;
    enum {
        WEST, NORTH, EAST, SOUTH, NORTH_EAST, NORTH_WEST, SOUTH_EAST, SOUTH_WEST
    };

public:
    Organism();

    Organism(City *);
    virtual ~Organism();

    virtual void move() = 0;

    virtual void breed() = 0;

    void setPosition(int, int);
    bool getMoved();

    void setMoved(bool);
    Species getSpecies();

    friend ostream &operator<<(ostream &, Organism *);
};



#endif //APOCALYPSESIM_ORGANISM_H
