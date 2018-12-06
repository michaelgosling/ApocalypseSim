// Organism.h - Header file for Organism.cpp
//
// Created by Michael Gosling on 11/30/18.
// Last Updated by Michael Gosling on 12/03/18.
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
    int spawnCount;
    bool moved;
    bool spawned;
    Species species;
    City *city;
    enum {
        WEST, NORTH, EAST, SOUTH, NORTH_EAST, NORTH_WEST, SOUTH_EAST, SOUTH_WEST
    };

public:

    Organism();

    Organism(City *city);
    virtual ~Organism();

    virtual void move() = 0;

    virtual void spawn() = 0;

    void setPosition(int x, int y);

    bool getMoved();

    void setMoved(bool moved);

    bool getSpawned();

    void setSpawned(bool spawned);

    int getSpawnCount();

    void setSpawnCount(int spawnCount);

    Species getSpecies();

    friend ostream &operator<<(ostream &output, Organism *organism);
};



#endif //APOCALYPSESIM_ORGANISM_H
