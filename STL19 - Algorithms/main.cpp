#include <fstream>
#include <iostream>
#include <map>
#include <functional>
#include "Polygon.hpp"
#include "CMDcall.hpp"

int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    std::cerr << "Wrong amount of arguments." << '\n';
    return 1;
  }

  std::ifstream in(argv[1]);

  if (!in)
  {
    std::cerr << "File cannot be opened." << '\n';
    return 2;
  }

  using kostin::Polygon;
  std::vector< Polygon > shapes;
  while (!in.eof())
  {
    in.clear();
    std::copy(
      std::istream_iterator< Polygon >(in),
      std::istream_iterator< Polygon >(),
      std::back_inserter(shapes)
    );
  }

  using kostin::CMDcall;
  CMDcall inputCMD(shapes, std::cin, std::cout);
  std::map < std::string, std::function< void()> > cmdMap
  {
    { "AREA", std::bind(&CMDcall::doArea, std::ref(inputCMD)) },
    { "MAX", std::bind(&CMDcall::doMax, std::ref(inputCMD)) },
    { "MIN", std::bind(&CMDcall::doMin, std::ref(inputCMD)) },
    { "COUNT", std::bind(&CMDcall::doCount, std::ref(inputCMD)) },
    { "PERMS", std::bind(&CMDcall::doPerms, std::ref(inputCMD)) },
    { "INTERSECTIONS", std::bind(&CMDcall::doIntersections, std::ref(inputCMD)) }
  };

  std::string cmd = "";
  std::cin >> cmd;

  while (!std::cin.eof())
  {
    auto it = cmdMap.find(cmd);
    if (it != cmdMap.end())
    {
      it->second();
    }
    else
    {
      inputCMD.invalidCMD(std::cout);
      std::cin.ignore(256, '\n');
    }
    std::cin.clear();
    std::cin >> cmd;
  }

  in.close();
  return 0;
}
