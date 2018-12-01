cmake_minimum_required(VERSION 3.12)
project(ApocalypseSim)

set(CMAKE_CXX_STANDARD 14)

add_executable(ApocalypseSim src/main.cpp src/Zombie.cpp src/Zombie.h src/Organism.cpp src/Organism.h src/Human.cpp src/Human.h src/GameSpecs.h src/City.cpp src/City.h)