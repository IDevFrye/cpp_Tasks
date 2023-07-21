#ifndef CROSS_REFERENCES_TEXT_PROCESSING
#define CROSS_REFERENCES_TEXT_PROCESSING

#include "RedBlackTree.h"

#include <list>
#include <string>
#include <ios>

class TextHandler
{
public:
  TextHandler();

  ~TextHandler() = default;

  void analyse(const std::string& filename);

  void analyse(std::istream& is);

  void deleteWord(std::string& word);

  void insertWord(std::string& word, int val);
  
  void print3MFW(std::ostream& os);

  void print3MFW(const std::string& filename);

  void printFreqStat(std::ostream& os);

  void printFreqStat(const std::string& filename);

  void printStatistics(std::ostream& os);

  void printStatistics(const std::string& filename);

  bool isDictEmpty();

private:

  RBTree< std::string, int > dictionary;
};

#endif

