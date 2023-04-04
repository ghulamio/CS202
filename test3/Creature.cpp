// In this homework, you will simulate the behavior of a group of simple-minded and greedy creatures. 
// The simulation will start with a number of creatures and food that spawn at various locations. 
// Each creature will know the location of the food with the best quality, and they all will march towards it. 
// The first creature to arrive at the location with food will consume it. 
// At different times during the simulation, we will introduce additional food supplies to the region. 
// The creatures will race and fight against each other to survive by consuming the food resources scattered around. 

// The creatures will have 4 properties: A unique integer ID, an integer that represents their health, and 𝑥 and 𝑦 coordinates of their location.
//  At each time tick, each creature first will look to fight other creatures. 
// If there are other creatures within a 2 unit distance radius (Euclidean distance between creatures <2) with less than or equal health, it will kill all of them. 
// Then it will look for food. However, since they are greedy, they will only consume the food with the best quality and ignore the rest. 
//' Because of that, if its distance to the best food is less than 1, then it will consume the food, otherwise it will not consume anything. 
// If it consumes food, its health will increase based on the quality of the food. 
// So, if a creature with 10 health, consumes a food with 8 quality, its health will become 18.
// Then, it will move in the direction of the food with the best quality that is currently available.
//  If there are multiple foods with the same quality, creatures should prefer the one with the lowest food ID. 
// If there are no food supplies available, creatures will not move. 
// If they move, the distance covered in a single time tick will depend on the current health of the creature. 
// If the health of the creature is less than or equal to 10, then its survival instincts will kick-in and it will move 1 unit distance. 
// If it is healthy, i.e. its health is greater than 10, then it will only move 10/h unit distance where h is the current health of the creature. 
// Lastly, it will lose 1 health. If its health becomes 0, it will die. Dead creatures do not move, and they do not interact with other creatures and food supplies

#include "Creature.h"

Creature::Creature(int id, double x, double y, int health) {
    this->id = id;
    this->x = x;
    this->y = y;
    this->health = health;
}

int Creature::getId() const {
    return id;
}

double Creature::getX() const {
    return x;
}

double Creature::getY() const {
    return y;
}

int Creature::getHealth() const {
    return health;
}

void Creature::setHealth(int health) {
    this->health = health;
}

void Creature::move(double dx, double dy) {
    x += dx;
    y += dy;
}

void Creature::attack(Creature& other) {
    other.setHealth(0);
}

bool Creature::isAlive() const {
    return health > 0;
}