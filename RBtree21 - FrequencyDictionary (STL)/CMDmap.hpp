#ifndef CMDMAP_H
#define CMDMAP_H
#include <vector>
#include "DictHandler.hpp"
#include "FreqDictionary.hpp"

namespace kostin
{
  struct CMDmap
  {
  public:
    CMDmap();
    void help();
    void openFrom();
    void closeFrom();
    void searchWord();
    void findWord();
    void deleteWord();
    void countWords();
    void printWordList();
    void printFreqWordList();
    void mostFrequentWord();
    void leastFrequentWord();
    void printSortedDictKeys();
    void printSortedDictInfo();
    void dictToFile();
    void mergeFiles();
    void printMergedFreqDict();
    void exitProgram();
  private:
    FreqDictionary dictionary;
    FreqDictionary mergedDict;
  };
}

#endif
