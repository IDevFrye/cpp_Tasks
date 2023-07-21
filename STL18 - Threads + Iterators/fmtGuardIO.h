#ifndef MAIN_CPP_IOFMTGUARD_H
#define MAIN_CPP_IOFMTGUARD_H

#include <ios>
namespace kostin
{
  class iofmtguard
  {
  public:
    explicit iofmtguard(std::basic_ios< char >& s);
    ~iofmtguard();
  private:
    std::basic_ios< char >& s_;
    char fill_;
    std::basic_ios< char >::fmtflags fmt_;
  };
}

#endif