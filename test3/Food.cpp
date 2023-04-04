// In this homework, you will simulate the behavior of a group of simple-minded and greedy creatures. 
// The simulation will start with a number of creatures and food that spawn at various locations. 
// Each creature will know the location of the food with the best quality, and they all will march towards it. 
// The first creature to arrive at the location with food will consume it. 
// At different times during the simulation, we will introduce additional food supplies to the region. 
// The creatures will race and fight against each other to survive by consuming the food resources scattered around. 
// In this simulation, the food resources will spontaneously spawn at certain locations at certain times. 
// Each food resource will have 4 properties: 𝑥 and 𝑦 coordinates of their location, a unique integer ID and their quality. 
// Here, the quality of the food will be denoted by an integer value. 


#include "Food.h"

Food::Food(int id, int spawnTime, double x, double y, int quality) {
    this->id = id;
    this->spawnTime = spawnTime;
    this->x = x;
    this->y = y;
    this->quality = quality;
}

int Food::getId() const {
    return id;
}

int Food::getSpawnTime() const {
    return spawnTime;
}

double Food::getX() const {
    return x;
}

double Food::getY() const {
    return y;
}

int Food::getQuality() const {
    return quality;
}