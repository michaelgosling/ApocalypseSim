// GameSpecs.h - constants for game
//
// Created by Michael Gosling on 11/30/18.
//


#ifndef APOCALYPSESIM_GAMESPECS_H
#define APOCALYPSESIM_GAMESPECS_H

const int GRIDSIZE = 20; // size of the square grid
const int HUMAN_STARTCOUNT = 100; // inital Humans
const int ZOMBIE_STARTCOUNT = 5; //initial Zombie count
const int HUMAN_BREED = 3; // steps until an Human breeds
const int ZOMBIE_BREED = 8; // steps until an Zombie breeds
const int ZOMBIE_STARVE = 3; // steps until a Zombie starves and converts back
const char HUMAN_CH = 111;//79 "o"// ascii Human
const char SPACE_CH = 32; // " " ascii space
const char ZOMBIE_CH = 90;//90 "Z"// ascii zombie
const double PAUSE_SECONDS = .09; // pause between steps
const int ITERATIONS = 1000; // max number of steps

//Colors
//0 - Black
//1 - Red
//2 - Green
//3 - Brown/yellow
//4 - Blue
//5 - Purple
//6 - Cyan
//7 - Light grey/white
//9 - Default

const int HUMAN_COLOR = 6; // cyan
const int ZOMBIE_COLOR = 1; // bright yellow

#endif //APOCALYPSESIM_GAMESPECS_H
