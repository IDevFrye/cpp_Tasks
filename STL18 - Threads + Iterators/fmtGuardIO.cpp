#include "fmtGuardIO.h"

kostin::iofmtguard::iofmtguard(std::basic_ios< char >& s) :
  s_(s),
  fill_(s.fill()),
  fmt_(s.flags())
{}

kostin::iofmtguard::~iofmtguard()
{
  s_.fill(fill_);
  s_.flags(fmt_);
}