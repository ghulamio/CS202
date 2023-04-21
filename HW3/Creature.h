#ifndef __CREATURE_H
#define __CREATURE_H

#include<iostream>
#include"Point2D.h"
#include"Food.h"

class Creature{
  public:
    Creature();
    Creature(int id, double x, double y, int health);
    Creature(const Creature&);
    ~Creature();

    const Point2D& getCoordinate() const;
    const int getHealth() const;
    const int getCreatureId() const;

    double distanceFromCreature(const Creature&) const ;
    double distanceFromFood(const Food&) const;

    void increaseHealth(int increaseBy);
    void decrementHealth();
    void die();
    bool isAlive() const;
    void moveForGameLoop(Vector& v, Point2D& p);

  private:
    Point2D origin;
    int creatureId;
    int health;

  friend std::ostream& operator<<(std::ostream&, Creature&);
};

#endif