#include "CMDmap.hpp"
#include <functional>
#include <map>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <fstream>
#include <string>

kostin::CMDmap::CMDmap() :
  dictionary(), mergedDict()
{}

void kostin::CMDmap::help()
{
  std::cout << "\nAvailable commands:\n\n";
  std::cout << " help                  display available commands\n";
  std::cout << " openFrom              open file to make dictionary\n";
  std::cout << " closeFrom             close current file\n";
  std::cout << " searchWord            check for existence of word\n";
  std::cout << " findWord              find word with its frequency\n";
  std::cout << " deleteWord            delete word from dictionary\n";
  std::cout << " countWords            display total number of unique words\n";
  std::cout << " printWordList         output of all words\n";
  std::cout << " printFreqWordList     output of all words with their frequency\n";
  std::cout << " mostFrequentWord      display most frequent word\n";
  std::cout << " leastFrequentWord     display least frequent word\n";
  std::cout << " printSortedDictKeys   outputs dictionary sorted by keys\n";
  std::cout << " printSortedDictInfo   outputs dictionary sorted by frequency\n";
  std::cout << " dictToFile            writing dictionary to a file\n";
  std::cout << " mergeFiles            merges data from two files into one\n";
  std::cout << " printMergedFreqDict   outputs frequency of words in merged dictionary\n";
  std::cout << " exit                  finish the program\n\n";
}

void kostin::CMDmap::openFrom()
{
  dictionary = FreqDictionary{ };
  kostin::enterCMD(std::cout, "file");
  std::string filename;
  std::cin >> filename;
  std::ifstream is0(filename);
  if (!is0)
  {
    throw std::invalid_argument{ "Can't open file \"" + filename + "\"\n" };
  }
  kostin::readFromFile(dictionary, is0);
  is0.close();
  std::cout << "File " << filename << " opened\n" << std::endl;
}

void kostin::CMDmap::closeFrom()
{
  kostin::enterCMD(std::cout, "file");
  std::string filename;
  std::cin >> filename;
  std::cout << "Do you want to save dictionary to this file? (y/n) \n";
  std::string answer;
  std::cin >> answer;
  if (answer == "y")
  {
    std::ofstream out(filename);
    for (auto& p : dictionary.dict_)
    {
      out << p.first << " " << p.second << std::endl;
    }
    out.close();
    kostin::saveCMD(std::cout, true);
  }
  else if (answer == "n")
  {
    kostin::saveCMD(std::cout, false);
  }
}

void kostin::CMDmap::searchWord()
{
  kostin::enterCMD(std::cout, "word");
  std::string word = "";
  std::cin >> word;
  if (!dictionary.isEmpty() && dictionary.searchWord(word))
  {
    std::cout << "'" << word << "' exists in this dictionary\n\n";
  }
  else if (!dictionary.isEmpty() && !dictionary.searchWord(word))
  {
    std::cout << "'" << word << "' doesn't exist in this dictionary\n\n";
  }
  else
  {
    kostin::emptyCMD(std::cout, "dict");
  }
}

void kostin::CMDmap::findWord()
{
  std::cout << "Enter the word: ";
  std::string word = "";
  std::cin >> word;
  if (!dictionary.isEmpty() && dictionary.searchWord(word))
  {
    std::cout << word << ": " << dictionary.dict_[word] << std::endl << std::endl;
  }
  else if (!dictionary.isEmpty() && !dictionary.searchWord(word))
  {
    kostin::emptyCMD(std::cout, "word");
  }
  else
  {
    kostin::emptyCMD(std::cout, "dict");
  }
}

void kostin::CMDmap::deleteWord()
{
  kostin::enterCMD(std::cout, "word");
  std::string word;
  std::cin >> word;
  if (dictionary.searchWord(word))
  {
    dictionary.deleteWord(word);
    std::cout << std::endl;
  }
  else
  {
    kostin::emptyCMD(std::cout, "word");
  }
}

void kostin::CMDmap::countWords()
{
  std::cout << "Dictionary contains: " << dictionary.countWords() << " unique word(s)\n\n";
}

void kostin::CMDmap::printWordList()
{
  for (const auto& iter : dictionary.dict_)
  {
    std::cout << iter.first << std::endl;
  }
  std::cout << std::endl;
}

void kostin::CMDmap::printFreqWordList()
{
  for (const auto& iter : dictionary.dict_)
  {
    std::cout << iter.first << ": " << iter.second << std::endl;
  }
  std::cout << std::endl;
}

void kostin::CMDmap::mostFrequentWord()
{
  auto maxFreq = std::max_element(dictionary.dict_.begin(),
                                   dictionary.dict_.end(),
                                   [](const auto& a, const auto& b)
                                   {
                                     return a.second < b.second;
                                   }
                                 );
  std::cout << "The most frequent word: " << maxFreq->first << "\nIts frequency: " << maxFreq->second << std::endl << std::endl;
}

void kostin::CMDmap::leastFrequentWord()
{
  auto minFreq = std::min_element(dictionary.dict_.begin(),
                                   dictionary.dict_.end(),
                                   [](const auto& a, const auto& b)
                                   {
                                     return a.second < b.second;
                                   }
                                 );
  std::cout << "The least frequent word: " << minFreq->first << "\nIts frequency: " << minFreq->second << std::endl << std::endl;
}

void kostin::CMDmap::printSortedDictKeys()
{
  std::map<std::string, int> sortedDictByKeys(dictionary.dict_.begin(), dictionary.dict_.end());
  for (const auto& iter : sortedDictByKeys)
  {
    std::cout << iter.first << ": " << iter.second << std::endl;
  }
  std::cout << std::endl;
}

void kostin::CMDmap::printSortedDictInfo()
{
  std::vector<std::pair<std::string, int>> sortedDictByFreq(dictionary.dict_.begin(), dictionary.dict_.end());
  std::sort(sortedDictByFreq.begin(),
             sortedDictByFreq.end(),
             [](const auto& a, const auto& b)
             {
               return a.second < b.second;
             }
           );
  for (const auto& iter : sortedDictByFreq)
  {
    std::cout << iter.first << ": " << iter.second << std::endl;
  }
  std::cout << std::endl;
}

void kostin::CMDmap::dictToFile()
{
  kostin::enterCMD(std::cout, "file");
  std::string filename;
  std::cin >> filename;
  std::ofstream out(filename);
  for (auto& p : dictionary.dict_)
  {
    out << std::endl << p.first << " " << p.second << std::endl;
  }
  out.close();
  kostin::saveCMD(std::cout, true);
}

void kostin::CMDmap::mergeFiles()
{
  kostin::enterCMD(std::cout, "file");
  std::string filename1;
  std::cin >> filename1;
  std::ifstream is1(filename1);
  if (!is1)
  {
    throw std::invalid_argument{ "Can't open file \"" + filename1 + "\"" };
  }
  readFromFile(mergedDict, is1);
  is1.close();
  kostin::enterCMD(std::cout, "file");
  std::string filename2;
  std::cin >> filename2;
  std::ifstream is2(filename2);
  if (!is2)
  {
    throw std::invalid_argument{ "Can't open file \"" + filename2 + "\"" };
  }
  readFromFile(mergedDict, is2);
  is2.close();
  kostin::enterCMD(std::cout, "file");
  std::string filename3;
  std::cin >> filename3;
  std::ofstream out(filename3);
  for (auto& p : mergedDict.dict_)
  {
    out << p.first << " " << p.second << std::endl;
  }
  out.close();
  std::cout << "Files were successful merged.\n\n";
}

void kostin::CMDmap::printMergedFreqDict()
{
  for (const auto& iter : mergedDict.dict_)
  {
    std::cout << iter.first << ": " << iter.second << std::endl;
  }
  std::cout << std::endl;
}

void kostin::CMDmap::exitProgram()
{
  exit(0);
}
