// City.h - Header file for City.cpp
//
// Created by Michael Gosling on 11/30/18.
//

#ifndef APOCALYPSESIM_CITY_H
#define APOCALYPSESIM_CITY_H


#include <iostream>
#include "GameSpecs.h"

using namespace std;

class Organism;

class City
{
protected:
    Organism *grid[GRID_HEIGHT][GRID_WIDTH];

public:
    City();
    virtual ~City();

    Organism *getOrganism(int x, int y);

    void setOrganism(Organism *organism, int x, int y);

    void move();

    friend ostream &operator<<(ostream &output, City &city);

};


#endif //APOCALYPSESIM_CITY_H
