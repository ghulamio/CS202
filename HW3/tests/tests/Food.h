/**
* Author : Ghulam Ahmed
* ID: 22101001
* Section : 2
* Homework : 3
* Description : Homework 3 - Heaps and Priority Queues
*/

#ifndef _FOOD_H
#define _FOOD_H

#include<iostream>

#include"Point2D.h"

class Food{
  public:
    Food();
    ~Food();
    Food(int id, double x, double y, int quality, int spawnTime);

    Point2D& getPoint() const;

    int getQuality() const;
    int getSpawnTime() const;

  private:
    Point2D point;
    int id ;
    int quality;
    int spawnTime;
};

#endif