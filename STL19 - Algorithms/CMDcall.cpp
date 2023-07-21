#include "CMDcall.hpp"
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <iostream>
#include "Commands.hpp"

kostin::CMDcall::CMDcall(std::vector< Polygon > polygon, std::istream& in, std::ostream& out) :
  shapes_(polygon),
  in_(in),
  out_(out)
{}

void kostin::CMDcall::doArea()
{
  std::string option = "";
  std::cin >> option;
  int num = 0;
  try
  {
    num = std::stoi(option);
  }
  catch (const std::invalid_argument& e)
  {
    num = -1;
  }
  if (option == "ODD")
  {
    getAreaOdd(shapes_);
  }
  else if (option == "EVEN")
  {
    getAreaEven(shapes_);
  }
  else if (option == "MEAN" && shapes_.size() != 0)
  {
    getAreaMean(shapes_);
  }
  else if (num > 2)
  {
    getAreaNumOfVertexes(num, shapes_);
  }
  else
  {
    invalidCMD(std::cout);
  }
}

void kostin::CMDcall::doMax()
{
  std::string option = "";
  std::cin >> option;
  if (option == "AREA" && shapes_.size() != 0)
  {
    getMaxArea(shapes_);
  }
  else if (option == "VERTEXES" && shapes_.size() != 0)
  {
    getMaxVertexes(shapes_);
  }
  else
  {
    invalidCMD(std::cout);
  }
}

void kostin::CMDcall::doMin()
{
  std::string option = "";
  std::cin >> option;
  if (option == "AREA" && shapes_.size() != 0)
  {
    getMinArea(shapes_);
  }
  else if (option == "VERTEXES" && shapes_.size() != 0)
  {
    getMinVertexes(shapes_);
  }
  else
  {
    invalidCMD(std::cout);
  }
}

void kostin::CMDcall::doCount()
{
  std::string option = "";
  std::cin >> option;
  int num = 0;
  try
  {
    num = std::stoi(option);
  }
  catch (const std::invalid_argument& e)
  {
    num = -1;
  }
  if (option == "EVEN")
  {
    countEven(shapes_);
  }
  else if (option == "ODD")
  {
    countOdd(shapes_);
  }
  else if (num > 2)
  {
    countVertexes(num, shapes_);
  }
  else
  {
    invalidCMD(std::cout);
  }
}

void kostin::CMDcall::doPerms()
{
  Polygon polyg;
  std::cin >> polyg;
  if (!polyg.points.empty())
  {
    getPerms(polyg, shapes_);
  }
  else
  {
    invalidCMD(std::cout);
  }
}

void kostin::CMDcall::doIntersections()
{
  Polygon polyg;
  std::cin >> polyg;
  if (!polyg.points.empty())
  {
    getIntersections(polyg, shapes_);
  }
  else
  {
    invalidCMD(std::cout);
  }
}

void kostin::CMDcall::invalidCMD(std::ostream& os)
{
  os << "<INVALID COMMAND>\n";
}

void kostin::CMDcall::emptyMessage(std::ostream& os)
{
  os << "<EMPTY>\n";
}
