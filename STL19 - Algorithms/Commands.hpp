#ifndef COMMANDS_H
#define COMMANDS_H

#include <vector>
#include <iosfwd>
#include <map>
#include "Polygon.hpp"

namespace kostin
{
  void getPerms(Polygon& polygon, std::vector< Polygon > polygons);
  void getIntersections(Polygon& polygon, std::vector< Polygon > polygons);

  void getAreaOdd(const std::vector< Polygon > polygon);
  void getAreaEven(const std::vector< Polygon > polygon);
  void getAreaMean(const std::vector< Polygon > polygon);
  void getAreaNumOfVertexes(size_t number, const std::vector< Polygon > polygon);

  void getMaxArea(const std::vector< Polygon > polygon);
  void getMaxVertexes(const std::vector< Polygon > polygon);
  void getMinArea(const std::vector< Polygon > polygon);
  void getMinVertexes(const std::vector< Polygon > polygon);

  void countEven(const std::vector< Polygon > polygon);
  void countOdd(const std::vector< Polygon > polygon);
  void countVertexes(size_t number, const std::vector< Polygon > polygons);
}

#endif
