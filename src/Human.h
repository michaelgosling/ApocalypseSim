// Human.h - Header file for Human.cpp
//
// Created by Michael Gosling on 11/30/18.
//

#ifndef APOCALYPSESIM_HUMAN_H
#define APOCALYPSESIM_HUMAN_H

#include "Organism.h"

class Human : public Organism
{
private:
    int stepCount;
public:
    Human();
    Human( City *city, int width, int height );
    virtual ~Human();

    int* breed() override;

    void move() override;
};


#endif //APOCALYPSESIM_HUMAN_H
