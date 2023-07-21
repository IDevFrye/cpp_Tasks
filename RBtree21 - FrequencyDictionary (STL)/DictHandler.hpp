#ifndef RBTREE_DICT_H
#define RBTREE_DICT_H
#include <iosfwd>
#include <string>
#include "FreqDictionary.hpp"

namespace kostin
{
  void readFromFile(FreqDictionary& dict, std::istream& is);
  void invalidCMD(std::istream& is, std::ostream& os);
  void deleteCMD(std::ostream& os);
  void emptyCMD(std::ostream& os, std::string type);
  void enterCMD(std::ostream& os, std::string type);
  void saveCMD(std::ostream& os, bool success);
}

#endif
