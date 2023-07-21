#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <iterator>
#include <vector>
#include <functional>
#include "FreqDictionary.hpp"
#include "CMDmap.hpp"
#include "DictHandler.hpp"

int main()
{
  std::cout << "'help' - available commands\n" << "> ";
  using namespace kostin;
  std::vector< FreqDictionary > freqDict;
  CMDmap inputCMD;
  const std::map< std::string, std::function< void() > > cmdMap
  {
    { "help", std::bind(&CMDmap::help, std::ref(inputCMD)) },
    { "openFrom", std::bind(&CMDmap::openFrom, std::ref(inputCMD)) },
    { "closeFrom", std::bind(&CMDmap::closeFrom, std::ref(inputCMD)) },
    { "searchWord",std::bind(&CMDmap::searchWord, std::ref(inputCMD)) },
    { "findWord",std::bind(&CMDmap::findWord, std::ref(inputCMD)) },
    { "deleteWord",std::bind(&CMDmap::deleteWord, std::ref(inputCMD)) },
    { "countWords",std::bind(&CMDmap::countWords, std::ref(inputCMD)) },
    { "printWordList", std::bind(&CMDmap::printWordList, std::ref(inputCMD)) },
    { "printFreqWordList", std::bind(&CMDmap::printFreqWordList, std::ref(inputCMD)) },
    { "mostFrequentWord", std::bind(&CMDmap::mostFrequentWord, std::ref(inputCMD)) },
    { "leastFrequentWord", std::bind(&CMDmap::leastFrequentWord, std::ref(inputCMD)) },
    { "printSortedDictKeys", std::bind(&CMDmap::printSortedDictKeys, std::ref(inputCMD)) },
    { "printSortedDictInfo", std::bind(&CMDmap::printSortedDictInfo, std::ref(inputCMD)) },
    { "dictToFile", std::bind(&CMDmap::dictToFile, std::ref(inputCMD)) },
    { "mergeFiles", std::bind(&CMDmap::mergeFiles, std::ref(inputCMD)) },
    { "printMergedFreqDict", std::bind(&CMDmap::printMergedFreqDict, std::ref(inputCMD)) },
    { "exit", std::bind(&CMDmap::exitProgram, std::ref(inputCMD)) },
  };

  std::string cmd = "";
  std::cin >> cmd;
  while (!std::cin.eof())
  {
    try
    {
      auto it = cmdMap.find(cmd);
      if (it != cmdMap.end())
      {
        it->second();
      }
      else
      {
        kostin::invalidCMD(std::cin, std::cout);
        std::cin.ignore(std::numeric_limits< std::streamsize >::max(), '\n');
      }
      std::cin.clear();
      std::cout << "> ";
      std::cin >> cmd;
    }
    catch (const std::invalid_argument& arg)
    {
      std::cerr << arg.what() << "\n";
    }
  };
  return 0;
}
