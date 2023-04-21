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

Point2D::Point2D(const double startingX, const double startingY) {
    x = startingX;
    y = startingY;
}

Point2D::Point2D(const Point2D& from) {
  x = from.x;
  y = from.y;
}

void Point2D::moveTo(const double ToX, const double ToY) {
  x = ToX;
  y = ToY;
}

void Point2D::moveTo(const Point2D& to) {
  x = to.x;
  y = to.y;
}

void Point2D::moveToOrigin() {
  x = 0;
  y = 0;
}

bool Point2D::equal(const Point2D& checkAgainst) {
  return x == checkAgainst.x && y == checkAgainst.y;
}

double Point2D::distanceFrom(const Point2D& from) const{
  double sumOfSquares = pow(static_cast<double>(x - from.x), 2.0) + pow(static_cast<double>(y - from.y), 2.0);
  return pow(sumOfSquares, 0.5);
}

Vector Point2D::getVectorTo(Point2D& to) {
  Vector AB;
  AB.x = to.x - this->x;
  AB.y = to.y - this->y;
  return AB;
}

void Point2D::operator=(Point2D& second) {
  moveTo(second);   
}

void Point2D::operator=(const Point2D& second) {
  moveTo(second);
}

bool operator==(Point2D& first, Point2D& second) {
  return first.equal(second);  
}

bool operator!=(Point2D& first, Point2D& second) {
  return !first.equal(second);
}

std::ostream& operator<<(ostream& outstream, Point2D& p) {
  outstream << fixed << setprecision(2);
  outstream << p.x << ", " << p.y;
  return outstream;
}