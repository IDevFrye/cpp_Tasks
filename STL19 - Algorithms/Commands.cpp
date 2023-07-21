#include "Commands.hpp"
#include <cmath>
#include <numeric>
#include <algorithm>
#include <iomanip>
#include <iostream>

void kostin::getPerms(Polygon& curPoly, std::vector< Polygon > figures)
{
  std::sort(curPoly.points.begin(), curPoly.points.end());
  size_t counter = std::count_if(figures.begin(),
                                  figures.end(),
                                  [&curPoly](Polygon& p)
                                  {
                                    std::sort(p.points.begin(), p.points.end());
                                    if (p.points.size() != curPoly.points.size())
                                    {
                                      return false;
                                    }
                                    return std::equal(p.points.begin(), p.points.end(),
                                                        curPoly.points.begin(), curPoly.points.end(),
                                                        [&curPoly, p](const Point& a, const Point& b)
                                                        {
                                                          return (a.x_ == b.x_ && a.y_ == b.y_) ||
                                                          (a.x_ == b.y_ && a.y_ == b.x_);
                                                        }
                                                      );
                                  }
                                );
  std::cout << counter << '\n';
}

void kostin::getIntersections(Polygon& curPoly, std::vector< Polygon > figures)
{
  size_t counter = 0;
  counter = std::count_if(figures.begin(),
                           figures.end(),
                           [&curPoly](const Polygon& otherpoly)
                           {
                             return std::any_of(otherpoly.points.begin(),
                                                 otherpoly.points.end(),
                                                 [&curPoly](Point point)
                                                 {
                                                   return isInPolygon(point, curPoly);
                                                 }
                             ) || std::any_of(curPoly.points.begin(),
                                               curPoly.points.end(),
                                               [&otherpoly](Point point)
                                               {
                                                 return isInPolygon(point, otherpoly);
                                               }
                                             );
                           }
                         );
  std::cout << counter << "\n";
}

void kostin::getAreaOdd(const std::vector< Polygon > figures)
{
  double areaSum = std::accumulate(figures.begin(),
                                    figures.end(),
                                    0.0,
                                    [](double acc, const Polygon& polygon)
                                    {
                                      if (polygon.points.size() % 2 == 1)
                                      {
                                        return acc + getPolygonArea(polygon);
                                      }
                                      else
                                      {
                                        return acc;
                                      }
                                    }
                                  );
  std::cout << std::fixed << std::setprecision(1) << areaSum << '\n';
}

void kostin::getAreaEven(const std::vector< Polygon > figures)
{
  double areaSum = std::accumulate(figures.begin(),
                                    figures.end(),
                                    0.0,
                                    [](double acc, const Polygon& polygon)
                                    {
                                      if (polygon.points.size() % 2 == 0)
                                      {
                                        return acc + getPolygonArea(polygon);
                                      }
                                      else
                                      {
                                        return acc;
                                      }
                                    }
                                  );
  std::cout << std::fixed << std::setprecision(1) << areaSum << '\n';
}

void kostin::getAreaMean(const std::vector< Polygon > figures)
{
  double areaSum = std::accumulate(figures.begin(),
                                    figures.end(),
                                    0.0,
                                    [](double acc, const Polygon& polygon)
                                    {
                                      return acc + getPolygonArea(polygon);
                                    }
                                  );
  if (areaSum != 0)
  {
    std::cout << std::fixed << std::setprecision(1) << areaSum / figures.size() << '\n';
  }
}

void kostin::getAreaNumOfVertexes(size_t polyVertexes, const std::vector< Polygon > figures)
{
  double areaSum = std::accumulate(figures.begin(),
                                    figures.end(),
                                    0.0,
                                    [&polyVertexes](double acc, const Polygon& polygon)
                                    {
                                      if (polygon.points.size() == polyVertexes)
                                      {
                                        return acc + getPolygonArea(polygon);
                                      }
                                      else
                                      {
                                        return acc;
                                      }
                                    }
                                  );
  std::cout << std::fixed << std::setprecision(1) << areaSum << '\n';
}

void kostin::getMaxArea(const std::vector< Polygon > figures)
{
  if (figures.size() != 0)
  {
    auto maxArea = std::max_element(figures.begin(),
                                     figures.end(),
                                     [](const Polygon& a, const Polygon& b)
                                     {
                                       return getPolygonArea(a) < getPolygonArea(b);
                                     }
                                   );
    std::cout << std::fixed << std::setprecision(1) << getPolygonArea(*maxArea) << std::endl;
  }
}

void kostin::getMaxVertexes(const std::vector< Polygon > figures)
{
  if (figures.size() != 0)
  {
    auto maxVertexes = std::max_element(figures.begin(),
                                         figures.end(),
                                         [](const Polygon& a, const Polygon& b)
                                         {
                                           return a.points.size() < b.points.size();
                                         }
                                       );
    std::cout << std::fixed << std::setprecision(1) << maxVertexes->points.size() << std::endl;
  }
}

void kostin::getMinArea(const std::vector< Polygon > figures)
{
  if (figures.size() != 0)
  {
    auto minArea = std::min_element(figures.begin(),
                                     figures.end(),
                                     [](const Polygon& a, const Polygon& b)
                                     {
                                       return getPolygonArea(a) < getPolygonArea(b);
                                     }
                                   );
    std::cout << std::fixed << std::setprecision(1) << getPolygonArea(*minArea) << std::endl;
  }
}

void kostin::getMinVertexes(const std::vector< Polygon > figures)
{
  if (figures.size() != 0)
  {
    auto minVertexes = std::min_element(figures.begin(),
                                         figures.end(),
                                         [](const Polygon& a, const Polygon& b)
                                         {
                                           return a.points.size() < b.points.size();
                                         }
                                       );
    std::cout << std::fixed << std::setprecision(1) << minVertexes->points.size() << std::endl;
  }
}

void kostin::countEven(const std::vector< Polygon > figures)
{
  int count = std::count_if(figures.begin(),
                             figures.end(),
                             [](const Polygon& polygon)
                             {
                               return polygon.points.size() % 2 == 0;
                             }
                           );
  std::cout << std::fixed << std::setprecision(1) << count << '\n';
}

void kostin::countOdd(const std::vector< Polygon > figures)
{
  int count = std::count_if(figures.begin(),
                             figures.end(),
                             [](const Polygon& polygon)
                             {
                               return polygon.points.size() % 2 == 1;
                             }
                           );
  std::cout << std::fixed << std::setprecision(1) << count << '\n';
}

void kostin::countVertexes(size_t polyVertexes, const std::vector< Polygon > figures)
{
  int count = std::count_if(figures.begin(),
                             figures.end(),
                             [&polyVertexes](const Polygon& polygon)
                             {
                               return polygon.points.size() == polyVertexes;
                             }
                           );
  std::cout << std::fixed << std::setprecision(1) << count << '\n';
}
