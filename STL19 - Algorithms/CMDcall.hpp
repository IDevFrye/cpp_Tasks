#ifndef CMDCALL_H
#define CMDCALL_H

#include <string>
#include <iterator>
#include <iosfwd>
#include "Polygon.hpp"
namespace kostin
{
  struct CMDcall
  {
  public:
    CMDcall(std::vector< Polygon > polygon, std::istream& in, std::ostream& out);
    void doArea();
    void doMax();
    void doMin();
    void doCount();
    void doPerms();
    void doIntersections();
    void invalidCMD(std::ostream& os);
    void emptyMessage(std::ostream& os);
  private:
    std::vector< Polygon > shapes_;
    std::istream& in_;
    std::ostream& out_;
  };
}

#endif
