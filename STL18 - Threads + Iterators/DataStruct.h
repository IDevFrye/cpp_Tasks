#ifndef T2_DATASTRUCT_H
#define T2_DATASTRUCT_H

#include <string>
#include <iosfwd>

namespace kostin
{
  struct DataStruct
  {
    unsigned long long key1;
    unsigned long long key2;
    std::string key3;
  };

  std::istream& operator>>(std::istream& in, DataStruct& dest);
  std::ostream& operator<<(std::ostream& out, const DataStruct& src);
  bool operator<(const DataStruct& left, const DataStruct& right);
}

#endif