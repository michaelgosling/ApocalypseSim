// GameSpecs.h - constants for game
//
// Created by Michael Gosling on 11/30/18.
//

#ifndef APOCALYPSESIM_GAMESPECS_H
#define APOCALYPSESIM_GAMESPECS_H


const int GRID_HEIGHT = 20; // size of the square grid
const int GRID_WIDTH = 20; // size of the square grid
const int HUMAN_STARTCOUNT = 100; // initial Humans
const int ZOMBIE_STARTCOUNT = 5; //initial Zombie count
const int HUMAN_BREED = 3; // steps until a Human breeds
const int ZOMBIE_BREED = 8; // steps until a Zombie breeds
const int ZOMBIE_STARVE = 3; // steps until a Zombie starves and converts back
const double ITERATION_DELAY = 1.0; // amount of time to wait until continuing the loop


// ANSI Color works a little differently than Windows SetConsoleTextAttribute, so some modifications here
//          foreground background
//black        30         40
//red          31         41
//green        32         42
//yellow       33         43
//blue         34         44
//magenta      35         45
//cyan         36         46
//white        37         47
//
// **Additional Params:**
//reset             0  (everything back to normal)
//bold/bright       1  (often a brighter shade of the same colour)
//underline         4
//inverse           7  (swap foreground and background colours)
//bold/bright off  21
//underline off    24
//inverse off      27
// source: https://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal

const int HUMAN_COLOR = 34; // blue
const int ZOMBIE_COLOR = 31; // red
const int RESET_COLOR = 0; // reset

#endif //APOCALYPSESIM_GAMESPECS_H
