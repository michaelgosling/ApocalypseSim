// Organism.h - Header file for Organism.cpp
//
// Created by Michael Gosling on 11/30/18.
//


#ifndef APOCALYPSESIM_ORGANISM_H
#define APOCALYPSESIM_ORGANISM_H

#include <iostream>
#include "City.h"

using namespace std;

class Organism
{
protected:
    int x;
    int y;
    int width;
    int height;
    char species;
    bool moved;
    City *city;

    enum { WEST, NORTH, EAST, SOUTH, NUM_DIRECTIONS };

public:
    Organism();
    Organism( City *city, int width, int height );
    virtual ~Organism();

    bool didMove();

    void newTurn();

    virtual void move() = 0;
    virtual int* breed() = 0;
    //virtual void spawn() = 0;
    char getSpecies();

    //virtual void getPosition() = 0;

    void setPosition( int x, int y );
    void endTurn();
    bool isTurn();

    //friend ostream& operator<<( ostream &output, Organism *organism );
};



#endif //APOCALYPSESIM_ORGANISM_H
