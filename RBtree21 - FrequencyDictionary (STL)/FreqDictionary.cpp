#include "FreqDictionary.hpp"
#include <iomanip>
#include <iterator>
#include <iostream>

kostin::FreqDictionary::FreqDictionary(FreqDictionary&& other) noexcept :
  dict_()
{
  std::swap(dict_, other.dict_);
}

void kostin::FreqDictionary::insertWord(std::string key, int value)
{
  dict_[key] += value;
}

void kostin::FreqDictionary::deleteWord(std::string key)
{
  auto it = dict_.find(key);
  if (it != dict_.end())
  {
    dict_.erase(key);
    std::cout << "Word deleted.\n";
  }
  else
  {
    std::cout << key << ": invalid word (there is no such word in the dictionary).\n";
  }
}

size_t kostin::FreqDictionary::countWords()
{
  return dict_.size();
}

bool kostin::FreqDictionary::searchWord(std::string key)
{
  auto it = dict_.find(key);
  bool exist;
  (it != dict_.end()) ? exist = true : exist = false;
  return exist;
}

bool kostin::FreqDictionary::isEmpty() noexcept
{
  return dict_.empty();
}

kostin::FreqDictionary& kostin::FreqDictionary::operator=(FreqDictionary&& other) noexcept
{
  if (this != &other)
  {
    std::swap(dict_, other.dict_);
  }
  return *this;
}

std::ostream& kostin::operator<<(std::ostream& stream, const FreqDictionary& elem)
{
  for (std::pair< std::string, int > pair : elem.dict_)
  {
    stream << pair.first << ": " << pair.second << '\n';
  }
  return stream;
}
