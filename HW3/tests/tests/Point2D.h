/**
* Author : Ghulam Ahmed
* ID: 22101001
* Section : 2
* Homework : 3
* Description : Homework 3 - Heaps and Priority Queues
*/

#ifndef _POINT2D_H
#define _POINT2D_H 

#include<iostream>
#include<string>
#include<cmath>

using namespace std;

class Point2D {
  public:
    Point2D();
    Point2D(const double x, const double y);
    Point2D(const Point2D& p);

    double getX() const;
    double getY() const;
    double hypotenuse(const Point2D& p) const;
    bool isEqualTo(const Point2D& p);
    Point2D getPointTo(Point2D& p);
    
    void moveTo(const double x, const double y);

  private:
    double x;
    double y;

  friend ostream& operator<<(ostream& o, Point2D& p);
};

#endif