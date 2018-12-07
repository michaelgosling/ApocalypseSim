#include <iostream>
#include <vector>
#include <random>
#include <functional>
#include "City.h"
#include "Human.h"
#include "Zombie.h"

/** Fields */
City *city;
int currentIteration = 1;
bool running = false;

/** Stuff for random number gen */
random_device rd;
default_random_engine xGenerator(rd());
default_random_engine yGenerator(rd());
uniform_int_distribution<int> xDistribution(1, GRID_WIDTH);
uniform_int_distribution<int> yDistribution(1, GRID_HEIGHT);
auto randomX = bind(xDistribution, xGenerator);
auto randomY = bind(yDistribution, yGenerator);

/** Prototypes */
int getCount(Species species);
void displayGrid();
void refreshMoves();
void breedOrganisms();

/**
 * Setup the simulation
 */
void setup() {
    // create a new city and reseed the random variable with the current time
    city = new City;

    for (auto j = 0; j < HUMAN_STARTCOUNT + ZOMBIE_STARTCOUNT; j++) {
        // initialize x and y variables
        int x = 0;
        int y = 0;
        // assign a random number in range to x and y, repeat until we find one without an organism on it
        do {
            x = randomX();
            y = randomY();
        } while (city->getOrganism(x, y) != nullptr);

        // if we haven't surpassed the human start count, make it a human
        if (j < HUMAN_STARTCOUNT) {
            auto *human = new Human(city);
            human->setPosition(x, y);
            city->setOrganism(human, x, y);
        } else { // otherwise make it a zombie
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
    // perform initial setup
    setup();
    // create a start point and a difference variable for the timer
    auto start = clock();
    double diff;

    // loop until we reach max iterations. for each loop we:
    // 1. Display the grid
    // 2. Refresh moves
    // 3. calculate the difference in time until it hits the threshold
    // 4. grab the current time and assign it to the start variable
    // 5. call the city's move method, and call the breeding method
    while (running) {
        displayGrid();
        refreshMoves();
        do {
            diff = (clock() - start) / (double) (CLOCKS_PER_SEC);
        } while (diff <= ITERATION_DELAY);
        start = clock();
        city->move();
        breedOrganisms();
        if (getCount(Species::HUMAN) <= 0 || getCount(Species::ZOMBIE) <= 0)
            running = false;
    }
    return 0;
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

/**
 * Set moved on all organisms in the city to false
 */
void refreshMoves() {
    for (int row = 0; row < GRID_HEIGHT; row++) {
        for (int col = 0; col < GRID_WIDTH; col++)
            if (city->getOrganism(row, col) != nullptr) city->getOrganism(row, col)->setMoved(false);
    }
}

/**
 * Calls breed on every organism in the city
 */
void breedOrganisms() {
    // vector to hold organisms
    vector<Organism *> organisms;

    // zombies go at start, humans go at end.
    for (int row = 0; row < GRID_HEIGHT; row++) {
        for (int col = 0; col < GRID_WIDTH; col++) {
            if (city->getOrganism(row, col) != nullptr) {
                if (city->getOrganism(row, col)->getSpecies() == Species::HUMAN)
                    organisms.push_back(city->getOrganism(row, col));
                if (city->getOrganism(row, col)->getSpecies() == Species::ZOMBIE)
                    organisms.insert(organisms.begin(), city->getOrganism(row, col));
            }
        }
    }

    // call breed on all of them
    for (auto &org : organisms)
        org->breed();

    // clear and shrink to fit the vector to free space
    organisms.clear();
    organisms.shrink_to_fit();
}