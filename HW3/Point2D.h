#ifndef _POINT2D_H
#define _POINT2D_H 

#include<iostream>
#include<string>
#include<cmath>

struct Point2D;
typedef Point2D Vector;

struct Point2D {

  double x;
  double y;
  Point2D();

  Point2D(const double startingX, const double startingY);
  Point2D(const Point2D& from);
  
  void moveTo(const double ToX, const double ToY);
  void moveTo(const Point2D& to);
  void moveToOrigin();
  bool equal(const Point2D& checkAgainst);
  double distanceFrom(const Point2D& from) const;
  Vector getVectorTo(Point2D& to);

  void operator=(Point2D& second);
  void operator=(const Point2D& second);
};


bool operator==(Point2D& first, Point2D& second);

bool operator!=(Point2D& first, Point2D& second);

std::ostream& operator<<(std::ostream& outstream, Point2D& p);

#endif