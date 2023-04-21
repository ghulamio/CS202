#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

#include"Food.h"

Food::Food() {
  origin.moveToOrigin();
  foodId = Food::getUniqueID();
  
  srand(time(NULL));
  quality = rand() % 10 + 1; // quality is between 1 and 10 inclusive 
}

Food::Food(int id, double x, double y, int newQuality, int newSpawnTime) {
  origin.moveTo(x, y);
  foodId = id;
  quality = newQuality;
  spawnTime = newSpawnTime;
}

Food::Food(const Food& other) {
  origin = other.origin;
  quality = other.quality;
  foodId = other.foodId;
  spawnTime = other.spawnTime;
}

Food::~Food() {}

int Food::getFoodId() const {
  return foodId;
}

int Food::getFoodQuality() const {
  return quality;
}

Point2D& Food::getCoordinate() const {
  return const_cast<Point2D&>(origin);
}

int Food::getSpawnTime() const {
  return spawnTime;
}
