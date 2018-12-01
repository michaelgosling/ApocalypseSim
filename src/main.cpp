#include <iostream>
#include <vector>
#include "City.h"
#include "GameSpecs.h"
#include "Human.h"
#include "Zombie.h"

void displayGrid();

vector<Organism> organisms;
City city;

int humanCount;
int zombieCount;

int main() {

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
            Human *human = new Human(&city, 1, 1);
            human->setPosition(x, y);
            city.setOrganism(human, x, y);
            humanCount++;
        } else {
            Zombie *zombie = new Zombie(&city, 1, 1);
            zombie->setPosition(x, y);
            city.setOrganism(zombie, x, y);
            zombieCount++;
        }
        organisms.insert(organisms.end(), *city.getOrganism(x, y));
    }


    // display grid
    displayGrid();

    return 0;
}

void displayGrid(){
    for (int i = 0; i < GRIDSIZE; i++){
        for (int j = 0; j < GRIDSIZE; j++){
            if (city.getOrganism(i, j) == nullptr)
                cout << ' ' << '-' << ' ';
            else
                cout << ' ' << city.getOrganism(i, j)->getSpecies() << ' ';
        }
        cout << endl;
    }

    cout << "Number of Zombies: " << zombieCount << endl;
    cout << "Number of Humans: " << humanCount << endl;

}