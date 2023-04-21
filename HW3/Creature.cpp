#include<iostream>
#include <cmath>

#include"Creature.h"
#include"Food.h"


Creature::Creature() {}

Creature::Creature(int id, double x, double y, int newHealth) {
  creatureId = id;
  health = newHealth;
  origin.moveTo(x, y);
}

Creature::Creature(const Creature& copy) {
  origin = copy.origin;
  health = copy.health;
  creatureId = copy.creatureId;
}

Creature::~Creature() {}

const Point2D& Creature::getCoordinate() const {
  return origin;
}

const int Creature::getHealth() const {
  return health;
}

const int Creature::getCreatureId() const {
  return creatureId;
}

double Creature::distanceFromCreature(const Creature& creature) const {
  return origin.distanceFrom(creature.origin);
}

double Creature::distanceFromFood(const Food& food) const {
  return origin.distanceFrom(food.getCoordinate());
}

void Creature::increaseHealth(int increaseBy) {
  health += increaseBy;
}

void Creature::decrementHealth(){
  health --;
}

void Creature::die() {
  health = 0;
}

bool Creature::isAlive() const {
  return health > 0;
}

void Creature::moveForGameLoop(Vector& v, Point2D& p) {
  if (!isAlive()) return;

  double moveXDir = v.x;
  if (moveXDir != 0.) {
    moveXDir = v.x > 0 ? 1 : -1;
  }

  double moveYDir = v.y;
  if (moveYDir != 0) {
    moveYDir = v.y > 0 ? 1 : -1;
  }

  double d1;
  double d2 = origin.distanceFrom(p);

  if (health <= 10) {
    d1 = 1;
  } else {
    // d1 = (10.0 / static_cast<double>(health));
    d1 = 10.0 / health;
  }

  double x1 = moveXDir * ((d1 / d2) * std::abs(origin.x - p.x));
  double y1 = moveYDir * ((d1 / d2) * std::abs(origin.y - p.y));

  origin.moveTo(origin.x+x1, origin.y+y1);  
}

std::ostream& operator<<(std::ostream& outstream, Creature& creature) {
  outstream << "Creature " << creature.creatureId << ": " << creature.origin;
  return outstream;
}