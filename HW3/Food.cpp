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

int Food::getId() const {
  return id ;
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