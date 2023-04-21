#ifndef __FOOD_H
#define __FOOD_H


#include<iostream>
#include"Point2D.h"


class Food{

  // friend std::ostream& operator<<(std::ostream&, Food&);
  // friend std::ostream& operator<<(std::ostream&, const Food&);

  private:
  static int getUniqueID(){
    static int starting_id = 0;
    starting_id++;
    return starting_id;
  }

  private:
    Point2D origin;
    int foodId;
    int quality;
    int spawnTime;

  public:
    Food();
    Food(int id, double x, double y, int newQuantity, int newSpawnTime);
    Food(const Food&);
    ~Food();

    Point2D& getCoordinate() const;

    int getFoodId() const;
    int getFoodQuality() const;
    int getSpawnTime() const;
};


#endif