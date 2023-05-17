/**
* Author : Ghulam Ahmed
* ID: 22101001
* Section : 2
* Homework : 3
* Description : Homework 3 - Heaps and Priority Queues
*/

#ifndef _CREATURE_H
#define _CREATURE_H

#include<iostream>

#include"Food.h"

using namespace std;

class Creature{
  public:
    Creature(int id, double x, double y, int health);
    Creature(const Creature&);

    const Point2D& getPoint() const;
    const int getHealth() const;
    bool isAlive() const;
    bool isNotHealthier(const Creature&) const;

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