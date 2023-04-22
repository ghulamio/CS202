/**
* Author : Ghulam Ahmed
* ID: 22101001
* Section : 2
* Homework : 3
* Description : Homework 3 - Heaps and Priority Queues
*/

#include<iostream>
#include <cmath>

#include"Creature.h"
#include"Food.h"

using namespace std;

Creature::Creature(int id, double x, double y, int health) {
  this -> id  = id;
  point.moveTo(x, y);
  this -> health = health;
}

Creature::Creature(const Creature& copy) {
  id = copy.id;
  point = copy.point;
  health = copy.health;
}

const Point2D& Creature::getPoint() const {
  return point;
}

const int Creature::getHealth() const {
  return health;
}

bool Creature::isNotHealthier(const Creature& creature) const {
  return health <= creature.health;
}

bool Creature::isAlive() const {
  return health > 0;
}

void Creature::regainHealth(int h) {
  health += h;
}

void Creature::decrementHealth(){
  health --;
}

void Creature::killCreature() {
  health = 0;
}

void Creature::advance(Point2D& v, Point2D& p) {
  if (isAlive()) {
    double xDistance = v.getX();
    double yDistance = v.getY();
    if (xDistance != 0) {
      xDistance = v.getX() > 0 ? 1 : -1;
    }
    if (yDistance != 0) {
      yDistance = v.getY() > 0 ? 1 : -1;
    }

    double hypotenuseP = point.hypotenuse(p);
    double moveSpeed = health <= 10 ? 1 : 10.0 / health;
    double moveX = ((moveSpeed / hypotenuseP) * xDistance * abs(point.getX() - p.getX()));
    double moveY = ((moveSpeed / hypotenuseP) * yDistance * abs(point.getY() - p.getY()));

    point.moveTo(point.getX() + moveX, point.getY() + moveY);  
  }
}

ostream& operator<<(ostream& o, Creature& c) {
  o << "Creature " << c.id << ": " << c.point;
  return o;
}