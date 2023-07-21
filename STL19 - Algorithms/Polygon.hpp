#ifndef POLYGON_H
#define POLYGON_H

#include <iosfwd>
#include <vector>

namespace kostin
{
  struct Point
  {
    int x_, y_;
  };

  struct Polygon
  {
    std::vector< Point > points;
  };

  std::istream& operator>>(std::istream& in, Polygon& polygon);
  std::istream& operator>>(std::istream& in, Point& point);
  bool operator<(const Point& left, const Point& right);

  bool isInPolygon(const Point& point, const Polygon& polygon);
  double getAreaOfTriangle(const Point& p1, const Point& p2, const Point& p3);
  double getPolygonArea(const Polygon& polygon);
}

#endif
