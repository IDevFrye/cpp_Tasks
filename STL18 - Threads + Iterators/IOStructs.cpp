#include "IOStructs.h"
#include <iostream>
#include <iomanip>

namespace kostin {
  std::istream& operator>>(std::istream& in, kostin::DelimeterIO&& dest)
  {
    std::istream::sentry sentry(in);
    if (!sentry)
    {
      return in;
    }
    char c = '0';
    in >> c;
    if (in && (c != dest.exp))
    {
      in.setstate(std::ios::failbit);
    }
    return in;
  }

  std::istream& operator>>(std::istream& in, LabelIO&& dest)
  {
    std::istream::sentry sentry(in);
    if (!sentry) {
      return in;
    }
    std::string data = "";
    if ((in >> StringIO{ data }) && (data != dest.exp)) {
      in.setstate(std::ios::failbit);
    }
    return in;
  }

  std::istream& operator>>(std::istream& in, kostin::OctUnsignedLongLongIO&& dest) {
    std::istream::sentry sentry(in);
    if (!sentry) {
      return in;
    }
    return in >> std::oct >> dest.ref_;
  }

  std::istream& operator>>(std::istream& in, kostin::BinUnsignedLongLongIO&& dest)
  {
    std::istream::sentry sentry(in);
    if (!sentry)
    {
      return in;
    }
    in >> DelimeterIO{ '0' };
    std::string binStr = "";
    char elem = in.peek();
    if (elem == 'b' || elem == 'B')
    {
      in >> DelimeterIO{ elem };
      while (in.peek() == '1' || in.peek() == '0')
      {
        binStr += in.get();
      }
    }
    else
    {
      return in;
    }
    unsigned long long ull = std::stoull(binStr, nullptr, 2);
    if (!in)
    {
      in.setstate(std::ios::failbit);
    }
    dest.ref = ull;
    return in;
  }

  std::ostream& operator<<(std::ostream& out, const BinUnsignedLongLongIO& src)
  {
    std::ostream::sentry sentry(out);
    if (!sentry)
    {
      return out;
    }
    if (src.ref == 0)
    {
      return out;
    }
    else
    {
      unsigned long long decNumb = src.ref;
      unsigned long long binNumb = 0;
      int degBin = 1;
      while (decNumb)
      {
        binNumb += (decNumb % 2) * degBin;
        degBin *= 10;
        decNumb /= 2;
      }
      out << binNumb;
      return out;
    }
  }

  std::istream& operator>>(std::istream& in, kostin::StringIO&& dest)
  {
    std::istream::sentry sentry(in);
    if (!sentry)
    {
      return in;
    }
    return std::getline(in >> kostin::DelimeterIO{ '"' }, dest.ref, '"');
  }
}