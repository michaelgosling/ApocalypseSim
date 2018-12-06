#include <iostream>
#include <vector>
#include "City.h"
#include "Human.h"
#include "Zombie.h"

City *city;
vector<Organism*> organisms;

int getCount(Species species);

void displayGrid();

void setup() {
    city = new City;

    for (auto j = 0; j < HUMAN_STARTCOUNT + ZOMBIE_STARTCOUNT; j++) {
        int x = 0;
        int y = 0;
        do {
            x = rand() % GRID_WIDTH;
            y = rand() % GRID_HEIGHT;
        } while (city->getOrganism(x, y) != nullptr);
        if (j < HUMAN_STARTCOUNT) {
            auto *human = new Human(city);
            human->setPosition(x, y);
            city->setOrganism(human, x, y);
        } else {
            auto *zombie = new Zombie(city);
            zombie->setPosition(x, y);
            city->setOrganism(zombie, x, y);
        }
        organisms.insert(organisms.end(), city->getOrganism(x, y));
    }

}

int main() {
    setup();
    displayGrid();
}

void displayGrid() {
    cout << *city;
    cout << "Humans: " << to_string(getCount(Species::HUMAN)) << " | Zombies: " << to_string(getCount(Species::ZOMBIE))
         << endl;

}

int getCount(Species species) {
    int count = 0;
    for (auto &org: organisms)
        if (org->getSpecies() == species) count++;

    return count;
}