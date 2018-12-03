#include <iostream>
#include <vector>
#include "City.h"
#include "GameSpecs.h"
#include "Human.h"
#include "Zombie.h"

void displayGrid();
void setup();
void refreshMoves();
void move();

vector<Organism*> organisms;
City city;

int humanCount;
int zombieCount;
bool running = false;
int iteration = 1;

int main() {

    // setup
    setup();
    while (running){
        // display grid
        displayGrid();
        cin.get();
        refreshMoves();
        iteration++;
        move();

    }
    return 0;
}

void move() {
    for (auto &organism : organisms)
        organism->move();
}

void refreshMoves(){

}

void setup(){
    running = true;
    humanCount = 0;
    zombieCount = 0;

    // fill organisms vector
    for (int i = 1; i <= HUMAN_STARTCOUNT + ZOMBIE_STARTCOUNT; i++) {
        int x, y;
        do {
            x = rand() % (GRIDSIZE+1) - 1;
            y = rand() % (GRIDSIZE+1) - 1;
        } while (city.getOrganism(x, y) != nullptr);

        if (humanCount < HUMAN_STARTCOUNT) {
            auto *human = new Human(&city, 1, 1);
            human->setPosition(x, y);
            city.setOrganism(human, x, y);
            humanCount++;
        } else {
            auto *zombie = new Zombie(&city, 1, 1);
            zombie->setPosition(x, y);
            city.setOrganism(zombie, x, y);
            zombieCount++;
        }
        organisms.insert(organisms.end(), city.getOrganism(x, y));
    }
}

void displayGrid(){
    for (int i = 0; i < GRIDSIZE; i++){
        for (int j = 0; j < GRIDSIZE; j++){
            if (city.getOrganism(i, j) == nullptr)
                cout << ' ' << '-' << ' ';
            else if (city.getOrganism(i, j)->getSpecies() == 'H')
                cout << "\033[3" << HUMAN_COLOR << "m H \033[0m";
            else
                cout << "\033[3" << ZOMBIE_COLOR << "m Z \033[0m";
        }
        cout << endl;
    }
    cout << "Zombies: " << zombieCount << " | Humans: " << humanCount << " | Iteration: " << iteration << endl;
}