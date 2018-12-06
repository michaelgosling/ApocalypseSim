#include <iostream>
#include <vector>
#include "City.h"
#include "Human.h"
#include "Zombie.h"

// fields
City *city;
int currentIteration = 1;
bool running = false;

// prototypes
int getCount(Species species);
void displayGrid();

void refreshMoves();

/**
 * Creates a new city and fills  with humans and zombies.
 * Sets running to true.
 */
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
    }

    running = true;
}

/**
 * Main
 * @return Exit Code
 */
int main() {
    setup();
    while (running) {
        displayGrid();
        cin.get();
        refreshMoves();
        city->move();
    }
}

/**
 * Displays city as grid and the current count of humans and zombies, as well as the current iteration
 */
void displayGrid() {
    cout << *city;
    cout << "Humans: " << to_string(getCount(Species::HUMAN)) << " | Zombies: " << to_string(getCount(Species::ZOMBIE))
         << " | Iteration: " << currentIteration++ << endl;

}

/**
 * Get current count of specified species
 * @param species Species you want to count
 * @return Integer representing current count of given species
 */
int getCount(Species species) {
    int count = 0;
    for (int row = 0; row < GRID_HEIGHT; row++) {
        for (int col = 0; col < GRID_WIDTH; col++)
            if (city->getOrganism(row, col) != nullptr)
                if (city->getOrganism(row, col)->getSpecies() == species) count++;
    }

    return count;
}

void refreshMoves() {
    for (int row = 0; row < GRID_HEIGHT; row++) {
        for (int col = 0; col < GRID_WIDTH; col++)
            if (city->getOrganism(row, col) != nullptr) city->getOrganism(row, col)->setMoved(false);
    }
}