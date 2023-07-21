#ifndef FREQDICTIONARY_H
#define FREQDICTIONARY_H
#include <map>
#include <list>
#include <string>

namespace kostin
{
  class FreqDictionary
  {
  public:
    friend struct CMDmap;
    friend struct CMDhandler;
    FreqDictionary() :
      dict_()
    {}
    ~FreqDictionary() = default;
    void insertWord(std::string key, int value);
    void deleteWord(std::string key);
    size_t countWords();
    bool searchWord(std::string key);
    bool isEmpty() noexcept;
    FreqDictionary(FreqDictionary&& other) noexcept;
    FreqDictionary& operator=(FreqDictionary&& other) noexcept;
    friend std::ostream& operator<<(std::ostream& stream, const FreqDictionary& table);
  private:
    std::map< std::string, int > dict_;
  };
}

#endif
