// Human.h - Header file for Human.cpp
//
// Created by Michael Gosling on 11/30/18.
// Last Updated by Michael Gosling on 12/07/18.
//

#ifndef APOCALYPSESIM_HUMAN_H
#define APOCALYPSESIM_HUMAN_H

#include <vector>
#include "Organism.h"
#include "City.h"

using namespace std;

class Human : public Organism
{
private:
    int breedCounter = 0;
protected:
    int *generateNewPosition(int) override;
public:
    Human();

    Human(City *);
    virtual ~Human();

    void move() override;
    void breed() override;
};


#endif //APOCALYPSESIM_HUMAN_H
