#include "Polygon.hpp"
#include <iterator>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <string>
#include "Delimeter.hpp"

std::istream& kostin::operator>>(std::istream& in, Point& point)
{
  std::istream::sentry sentry(in);
  if (!sentry)
  {
    return in;
  }
  in >> DelimeterIO('(');
  in >> point.x_;
  in >> DelimeterIO(';');
  in >> point.y_;
  in >> DelimeterIO(')');
  return in;
}

bool kostin::operator<(const Point& left, const Point& right)
{
  if (left.x_ == right.x_)
  {
    return left.y_ < right.y_;
  }
  return left.x_ < right.x_;
}

std::istream& kostin::operator>>(std::istream& in, Polygon& polygon)
{
  std::istream::sentry sentry(in);
  if (!sentry)
  {
    return in;
  }

  size_t polyVertexes = 0;
  if (!(in >> polyVertexes) || polyVertexes < 3)
  {
    return (in.ignore(std::numeric_limits<std::streamsize>::max(), '\n'), in.setstate(std::ios::failbit), in);
  }

  Polygon polyInput;
  Point polyPoint{};
  std::string strPoint;
  std::string strCoordinates;
  std::getline(in, strPoint);
  strPoint.erase(0, 1);

  while (!strPoint.empty())
  {
    if (strPoint[0] != '(' || strPoint[strPoint.length() - 1] != ')')
    {
      in.setstate(std::ios::failbit);
      return in;
    }
    strCoordinates = strPoint.substr(1, strPoint.find(';') - 1);
    if (strCoordinates.empty() || std::find_if(strCoordinates.begin(),
      strCoordinates.end(),
      [](char symbol)
      {
        return !std::isdigit(symbol) && symbol != '-';
      }
    ) != strCoordinates.end())
    {
      in.setstate(std::ios::failbit);
      return in;
    }
      polyPoint.x_ = std::stoi(strCoordinates);
      strCoordinates = strPoint.substr(strPoint.find(';') + 1, strPoint.find(')') - strPoint.find(';') - 1);
      if (strCoordinates.empty() || std::find_if(strCoordinates.begin(),
        strCoordinates.end(),
        [](char c)
        {
          return !std::isdigit(c) && c != '-';
        }
      ) != strCoordinates.end())
      {
        in.setstate(std::ios::failbit);
        return in;
      }
        polyPoint.y_ = std::stoi(strCoordinates);
        polyInput.points.push_back(polyPoint);
        strPoint.erase(0, strPoint.find(')') + 2);
  }
  if (polyInput.points.size() != polyVertexes)
  {
    in.setstate(std::ios::failbit);
  }
  if (in)
  {
    polygon = polyInput;
  }
  return in;
}

bool kostin::isInPolygon(const Point& point, const Polygon& polygon)
{
  bool ytop = std::any_of(polygon.points.begin(),
    polygon.points.end(),
    [point](const Point polyPoint)
    {
      return (polyPoint.y_ >= point.y_);
    }
  );
  bool ybottom = std::any_of(polygon.points.begin(),
    polygon.points.end(),
    [point](const Point polyPoint)
    {
      return (polyPoint.y_ <= point.y_);
    }
  );
  bool xleft = std::any_of(polygon.points.begin(),
    polygon.points.end(),
    [point](const Point polyPoint)
    {
      return (polyPoint.x_ <= point.x_);
    }
  );
  bool xright = std::any_of(polygon.points.begin(),
    polygon.points.end(),
    [point](const Point polyPoint)
    {
      return (polyPoint.x_ >= point.x_);
    }
  );
  return ytop && ybottom && xleft && xright;
}

double kostin::getAreaOfTriangle(const Point& firstVertex, const Point& secondVertex, const Point& thirdVertex)
{
  double crossProduct = firstVertex.x_ * secondVertex.y_
    + secondVertex.x_ * thirdVertex.y_
    + thirdVertex.x_ * firstVertex.y_
    - firstVertex.y_ * secondVertex.x_
    - secondVertex.y_ * thirdVertex.x_
    - thirdVertex.y_ * firstVertex.x_;
  return 0.5 * std::abs(crossProduct);
}

double kostin::getPolygonArea(const Polygon& polygon)
{
  if (polygon.points.size() < 3)
  {
    return 0.0;
  }
  const Point& firstVertex = polygon.points[0];
  double sumOfAreas = std::accumulate(polygon.points.begin() + 1,
    polygon.points.end() - 1,
    0.0,
    [firstVertex, &polygon](double sum, const Point& secondVertex)
    {
      size_t index = &secondVertex - &polygon.points[0];
  const Point& thirdVertex = polygon.points[index + 1];
  return sum + getAreaOfTriangle(firstVertex, secondVertex, thirdVertex);
    }
  );
  return std::abs(sumOfAreas);
}
