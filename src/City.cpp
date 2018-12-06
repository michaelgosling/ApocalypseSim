// City.cpp - Class file for City.h
//
// Created by Michael Gosling on 11/30/18.
//

#include "City.h"

City::City() {

}

City::~City() {

}

Organism *City::getOrganism(int x, int y) {
    return grid[x][y];
}

void City::setOrganism(Organism *organism, int x, int y) {
    grid[x][y] = organism;
}

void City::move() {

}

ostream &operator<<(ostream &output, City &city) {
    for (auto &i : city.grid) {
        for (auto &j : i) {
            if (j == nullptr)
                output << " - ";
            else
                output << *j;
        }
        output << endl;
    }
    return output;
}
