#include "DictHandler.hpp"
#include <iostream>
#include <regex>

void kostin::readFromFile(FreqDictionary& dict, std::istream& is)
{
  auto word_regex = std::regex{ "[a-zA-Z]+" };
  std::string line;
  int i = 1;
  while (!is.eof())
  {
    std::getline(is, line);
    auto words_begin = std::sregex_iterator{ line.begin(), line.end(), word_regex };
    auto words_end = std::sregex_iterator{ };
    for (auto itr = words_begin; itr != words_end; ++itr)
    {
      auto word = itr->str();
      for (char& c : word)
      {
        c = std::tolower(c);
      }
      dict.insertWord(word, i);
    }
    ++i;
  }
}

void kostin::invalidCMD(std::istream& is, std::ostream& os)
{
  if (is.peek() == ' ')
  {
    is.ignore(std::numeric_limits< std::streamsize >::max(), '\n');
  }
  os << "<INVALID COMMAND>\n";
}

void kostin::enterCMD(std::ostream& os, std::string type)
{
  if (type == "word")
  {
    os << "Enter the word: ";
  }
  else if (type == "file")
  {
    os << "Enter the filename: ";
  }
}

void kostin::deleteCMD(std::ostream& os)
{
  os << "Word deleted.\n";
}

void kostin::emptyCMD(std::ostream& os, std::string type)
{
  if (type == "word")
  {
    os << "No such word in this dictionary!\n\n";
  }
  else if (type == "dict")
  {
    os << "Dictionary is empty!\n\n";
  }
}

void kostin::saveCMD(std::ostream& os, bool success)
{
  if (success)
  {
    os << "Dictionary was successfully saved!\n\n";
  }
  else
  {
    os << "Dictionary wasn't saved!\n\n";
  }
}
