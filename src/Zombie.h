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
    int starveTimer = 0;
    int infectTimer;

public:
    Zombie();

    Zombie(City *);
    virtual ~Zombie();

    void move() override;

    void breed() override;

    void starve();
};


#endif //APOCALYPSESIM_ZOMBIE_H
