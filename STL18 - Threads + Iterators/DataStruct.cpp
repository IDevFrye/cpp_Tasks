#include "DataStruct.h"
#include <iomanip>
#include "IOStructs.h"
#include "fmtGuardIO.h"

std::istream& kostin::operator>>(std::istream& in, DataStruct& dest)
{
  std::istream::sentry sentry(in);
  if (!sentry)
  {
    return in;
  }
  DataStruct input;
  {
    using sep = DelimeterIO;
    using oct = OctUnsignedLongLongIO;
    using bin = BinUnsignedLongLongIO;
    using str = StringIO;
    in >> sep{ '(' };
    in >> sep{ ':' };
    for (int i = 0; i < 3; i++)
    {
      std::string label = "";
      in >> label;
      if (label == "key1")
      {
        in >> oct{ input.key1 };
        in >> sep{ ':' };
      }
      else if (label == "key2")
      {
        in >> bin{ input.key2 };
        in >> sep{ ':' };
      }
      else if (label == "key3")
      {
        in >> str{ input.key3 };
        in >> sep{ ':' };
      }
    }
    in >> sep{ ')' };
  }
  if (in)
  {
    dest = input;
  }
  return in;
}

std::ostream& kostin::operator<<(std::ostream& out, const DataStruct& src)
{
  std::ostream::sentry sentry(out);
  if (!sentry)
  {
    return out;
  }
  kostin::iofmtguard fmtguard(out);
  out << "(:";
  out << "key1 0" << std::oct << src.key1;
  out << ":key2 0b0" << std::dec << BinUnsignedLongLongIO{ const_cast< unsigned long long& >(src.key2) };
  out << ":key3 \"" << src.key3 << '\"';
  out << ":)";
  return out;
}

bool kostin::operator<(const DataStruct& left, const DataStruct& right)
{
  if (left.key1 == right.key1)
  {
    if (left.key2 == right.key2)
    {
      return left.key3 < right.key3;
    }
    return left.key2 < right.key2;
  }
  return left.key1 < right.key1;
}