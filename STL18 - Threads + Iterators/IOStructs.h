#ifndef T2_INPUTSTRUCTS_H
#define T2_INPUTSTRUCTS_H

#include <string>

namespace kostin
{
  struct DelimeterIO
  {
    char exp;
  };

  struct LabelIO
  {
    std::string exp;
  };

  struct OctUnsignedLongLongIO
  {
    unsigned long long& ref_;
  };

  struct BinUnsignedLongLongIO
  {
    unsigned long long& ref;
  };

  struct StringIO
  {
    std::string& ref;
  };

  std::istream& operator>>(std::istream& in, DelimeterIO&& dest);
  std::istream& operator>>(std::istream& in, LabelIO&& dest);
  std::istream& operator>>(std::istream& in, OctUnsignedLongLongIO&& dest);
  std::istream& operator>>(std::istream& in, BinUnsignedLongLongIO&& dest);
  std::ostream& operator<<(std::ostream& out, const BinUnsignedLongLongIO& src);
  std::istream& operator>>(std::istream& in, StringIO&& dest);

}

#endif