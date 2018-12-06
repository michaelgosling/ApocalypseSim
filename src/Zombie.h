// Zombie.h - Header file for Zombie.cpp
//
// Created by Michael Gosling on 11/30/18.
// Last Updated by Michael Gosling on 12/03/18.
//


#ifndef APOCALYPSESIM_ZOMBIE_H
#define APOCALYPSESIM_ZOMBIE_H

#include <vector>
#include "Organism.h"
#include "City.h"

using namespace std;

class Zombie : public Organism
{
protected:
    int starved;

public:
    Zombie();

    Zombie(City *city);
    virtual ~Zombie();

    void move() override;

    void spawn() override;

    int getStarved();

    void setStarved(int eat);

    void starve();

};


#endif //APOCALYPSESIM_ZOMBIE_H
