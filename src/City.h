// City.h - Header file for City.cpp
//
// Created by Michael Gosling on 11/30/18.
//

#ifndef APOCALYPSESIM_CITY_H
#define APOCALYPSESIM_CITY_H


#include <iostream>
#include "GameSpecs.h"
#include "Organism.h"

using namespace std;


class City
{
protected:
    Organism *grid[GRID_HEIGHT][GRID_WIDTH];

public:
    City();
    virtual ~City();

    Organism *getOrganism(int, int);

    void setOrganism(Organism *, int, int);
    void move();

    friend ostream &operator<<(ostream &, City &);

};


#endif //APOCALYPSESIM_CITY_H
