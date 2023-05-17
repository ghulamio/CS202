/**
* Author : Ghulam Ahmed
* ID: 22101001
* Section : 2
* Homework : 3
* Description : Homework 3 - Heaps and Priority Queues
*/

#include"Food.h"

using namespace std;

Food::Food() {
  id  = 0;
  point.moveTo(0, 0);
  quality = 0;
  spawnTime = 0;
}

Food::~Food() {}

Food::Food(int id, double x, double y, int quality, int spawnTime) {
  this -> id  = id;
  point.moveTo(x, y);
  this -> quality = quality;
  this -> spawnTime = spawnTime;
}

int Food::getQuality() const {
  return quality;
}

int Food::getSpawnTime() const {
  return spawnTime;
}

Point2D& Food::getPoint() const {
  return const_cast<Point2D&>(point);
}