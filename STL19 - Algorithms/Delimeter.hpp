#ifndef DELIMETER_H
#define DELIMETER_H

#include <iosfwd>

struct DelimeterIO
{
  explicit DelimeterIO(char exp);
  char exp;
};

std::istream& operator>>(std::istream& in, DelimeterIO&& dest);

#endif
