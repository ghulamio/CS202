#ifndef _CREATURE_H
#define _CREATURE_H

#include<iostream>

#include"Point2D.h"
#include"Food.h"

using namespace std;

class Creature{
  public:
    Creature();
    ~Creature();
    Creature(int id, double x, double y, int health);
    Creature(const Creature&);

    const Point2D& getPoint() const;
    const int getHealth() const;
    double distanceBetween(const Creature&) const ;
    double distanceBetween(const Food&) const;
    bool isAlive() const;

    void regainHealth(int h);
    void decrementHealth();
    void killCreature();
    void advance(Point2D& v, Point2D& p);

  private:
    Point2D point;
    int id;
    int health;

  friend ostream& operator<<(ostream& o, Creature& c);
};

#endif