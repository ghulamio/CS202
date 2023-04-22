/**
* Author : Ghulam Ahmed
* ID: 22101001
* Section : 2
* Homework : 3
* Description : Homework 3 - Heaps and Priority Queues
*/

#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include"Point2D.h"

using namespace std;

Point2D::Point2D() {
  x = 0;
  y = 0;
}

Point2D::Point2D(const double x, const double y) {
    this -> x = x;
    this -> y = y;
}

Point2D::Point2D(const Point2D& p) {
  x = p.x;
  y = p.y;
}

double Point2D::getX() const {
  return x;
}

double Point2D::getY() const {
  return y;
}

double Point2D::hypotenuse(const Point2D& p) const{
  return sqrt(pow((x - p.x), 2.0) + pow((y - p.y), 2.0));
}

bool Point2D::isEqualTo(const Point2D& p) {
  return x == p.x && y == p.y;
}

Point2D Point2D::getPointTo(Point2D& p) {
  Point2D PY;
  PY.x = p.x - this->x;
  PY.y = p.y - this->y;
  return PY;
}

void Point2D::moveTo(const double x, const double y) {
  this -> x = x;
  this -> y = y;
}

ostream& operator<<(ostream& o, Point2D& p) {
  o << fixed << setprecision(2);
  o << p.x << ", " << p.y;
  return o;
}