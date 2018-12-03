// Zombie.h - Header file for Zombie.cpp
//
// Created by Michael Gosling on 11/30/18.
//


#ifndef APOCALYPSESIM_ZOMBIE_H
#define APOCALYPSESIM_ZOMBIE_H

#include "Organism.h"

class Zombie : public Organism
{
public:
    Zombie();
    Zombie( City *city, int width, int height );
    virtual ~Zombie();

    void move() override;
    int *breed() override;
};


#endif //APOCALYPSESIM_ZOMBIE_H
