#include "TextProcessing.h"
#include "RedBlackTree.h"
#include "RedBlackTree.cpp"

#include <iostream>
#include <fstream>
#include <regex>
#include <string>


std::string generateSpaces(size_t length);
std::string generateLine(size_t length);

TextHandler::TextHandler() :
  dictionary{ }
{}

void TextHandler::analyse(const std::string& filename) //анализ файла
{
  dictionary = RBTree< std::string, int >{ }; //создаЄм пустой словарь
  std::ifstream is(filename); //открываем поток дл€ чтени€ файла
  if (!is)
  {
    throw std::invalid_argument{ " -> Can't open file \"" + filename + "\" because the file doesn't exist." };
  }
  analyse(is);

  is.close();
}

void TextHandler::analyse(std::istream& is) //анализ потока
{
  dictionary = RBTree< std::string, int >{ }; //создаЄм пустой словарь

  auto word_regex = std::regex{ "[a-zA-Zа-€ј-я0-9]+" };
  std::string currline;
  while (!is.eof())
  {
    std::getline(is, currline);

    auto words_begin = std::sregex_iterator{ currline.begin(), currline.end(), word_regex };
    auto words_end = std::sregex_iterator{ };

    for (auto itr = words_begin; itr != words_end; ++itr)
    {
      auto word = itr->str(); //перевод в строковый тип
      for (char& c : word)
      {
        c = std::tolower(c); //понижение регистра
      }
      if (dictionary.containsNode(word))
      {
        dictionary[word]++;
      }
      else
      {
        dictionary.insertNode(word, 1);
      }
    }
  }
}

void TextHandler::deleteWord(std::string& word)
{
  if (dictionary.containsNode(word))
  {
    dictionary.deleteNode(word);
  }
  else
  {
    std::cout << word << ": invalid word (there is no such word in the dictionary).\n";
  }
}

void TextHandler::insertWord(std::string& word, int val)
{
  if (dictionary.containsNode(word))
  {
    dictionary.searchNode(word)->value += val;
  }
  else
  {
    dictionary.insertNode(word, val);
  }
}

void TextHandler::print3MFW(std::ostream& os)
{
  std::string word = "Word";
  auto coloumnswidth = word.length();
  auto max1 = dictionary.preend();
  int valm = max1.value();
  max1.value() = 0;
  for (auto itr = dictionary.begin(); itr != dictionary.end(); ++itr)
  {
    if (itr.value() > max1.value()) max1 = itr;
  }
  for (auto itr = dictionary.begin(); itr != dictionary.end(); ++itr)
  {
    coloumnswidth = std::max(itr.key().length(), coloumnswidth); //слово максимальной длины
  }
  const auto margin = size_t{ 2 };
  const auto margin2 = size_t{ 11 };
  const auto margin3 = size_t{ 9 };
  const auto margin4 = size_t{ 1 };
  size_t margin5;
  if (max1.value() <= 9) margin5 = size_t{ 0 };
  else if (max1.value() <= 99) margin5 = size_t{ 1 };
  else if (max1.value() <= 999) margin5 = size_t{ 2 };
  else if (max1.value() <= 9999) margin5 = size_t{ 3 };
  else if (max1.value() <= 99999) margin5 = size_t{ 4 };
  os << "." << generateLine(margin2 + coloumnswidth + margin + margin4) << ".\n";
  os << "|Word" << generateSpaces(coloumnswidth - word.length() + margin) << "| Frequency |\n";
  os << "|" << generateLine(margin2 + coloumnswidth + margin + margin4) << "|\n";
  os << "|" << max1.key() << generateSpaces(coloumnswidth - max1.key().length() + margin) << "| " << max1.value() << generateSpaces(margin3 - margin5) << "|\n";
  for (int i = 0; (max1.value() > 0) && (i < 2); max1.value()--)
  {
    for (auto itr = dictionary.begin(); (itr != dictionary.end()) && (i < 2); ++itr)
    {
      if ((itr.value() == max1.value()) && (itr.key() != max1.key()))
      {
        if (itr.value() <= 9) margin5 = size_t{ 0 };
        else if (itr.value() <= 99) margin5 = size_t{ 1 };
        else if (itr.value() <= 999) margin5 = size_t{ 2 };
        os << "|" << itr.key() << generateSpaces(coloumnswidth - itr.key().length() + margin) << "| " << itr.value() << generateSpaces(margin3 - margin5) << "|\n";
        i++;
      }
    }
  }
  os << "'" << generateLine(margin2 + coloumnswidth + margin + margin4) << "\'\n";
  max1.value() = valm;
  if (dictionary.isEmpty())
  {
    os << "Dictionary is empty!\n";
  }
}

void TextHandler::print3MFW(const std::string& filename)
{
  if (filename.length() <= 4 || filename.substr(filename.size() - 4) != ".txt") //проверка на расширение и название файла
  {
    throw std::invalid_argument(" -> Invalid output file extension. A file with the \".txt\" extension is expected.");
  }
  std::ofstream os(filename);
  if (!os)
  {
    throw std::invalid_argument{ " -> Invalid file's name \"" + filename + "\". Enter the valid file's name in the following request!" };
  }

  print3MFW(os);
  os.close();
}

void TextHandler::printFreqStat(std::ostream& os)
{
  std::string word = "Word";
  auto coloumnswidth = word.length();
  auto max1 = dictionary.preend();
  int valm = max1.value();
  max1.value() = 0;
  for (auto itr = dictionary.begin(); itr != dictionary.end(); ++itr)
  {
    if (itr.value() > max1.value()) max1 = itr;
  }
  for (auto itr = dictionary.begin(); itr != dictionary.end(); ++itr)
  {
    coloumnswidth = std::max(itr.key().length(), coloumnswidth); //слово максимальной длины
  }
  const auto margin = size_t{ 2 };
  const auto margin2 = size_t{ 11 };
  const auto margin3 = size_t{ 9 };
  const auto margin4 = size_t{ 1 };
  size_t margin5;
  os << "." << generateLine(margin2 + coloumnswidth + margin + margin4) << ".\n";
  os << "|Word" << generateSpaces(coloumnswidth - word.length() + margin) << "| Frequency |\n";
  os << "|" << generateLine(margin2 + coloumnswidth + margin + margin4) << "|\n";
  if (max1.value() <= 9) margin5 = size_t{ 0 };
  else if (max1.value() <= 99) margin5 = size_t{ 1 };
  else if (max1.value() <= 999) margin5 = size_t{ 2 };
  else if (max1.value() <= 9999) margin5 = size_t{ 3 };
  else if (max1.value() <= 99999) margin5 = size_t{ 4 };
  os << "|" << max1.key() << generateSpaces(coloumnswidth - max1.key().length() + margin) << "| " << max1.value() << generateSpaces(margin3 - margin5) << "|\n";
  for (max1; max1.value() > 0; max1.value()--)
  {
    for (auto itr = dictionary.begin(); itr != dictionary.end(); ++itr)
    {
      if ((itr.value() == max1.value()) && (itr.key() != max1.key()))
      {
        if (itr.value() <= 9) margin5 = size_t{ 0 };
        else if (itr.value() <= 99) margin5 = size_t{ 1 };
        else if (itr.value() <= 999) margin5 = size_t{ 2 };
        os << "|" << itr.key() << generateSpaces(coloumnswidth - itr.key().length() + margin) << "| " << itr.value() << generateSpaces(margin3 - margin5) << "|\n";
      }
    }
  }
  os << "'" << generateLine(margin2 + coloumnswidth + margin + margin4) << "\'\n";
  max1.value() = valm;
  if (dictionary.isEmpty())
  {
    os << "Dictionary is empty!\n";
  }
}

void TextHandler::printFreqStat(const std::string& filename)
{
  if (filename.length() <= 4 || filename.substr(filename.size() - 4) != ".txt") //проверка на расширение и название файла
  {
    throw std::invalid_argument(" -> Invalid output file extension. A file with the \".txt\" extension is expected.");
  }
  std::ofstream os(filename);
  if (!os)
  {
    throw std::invalid_argument{ " -> Invalid file's name \"" + filename + "\". Enter the valid file's name in the following request!" };
  }

  printFreqStat(os);
  os.close();
}

void TextHandler::printStatistics(std::ostream& os)
{
  std::string word = "Word";
  auto coloumnswidth = word.length();
  for (auto itr = dictionary.begin(); itr != dictionary.end(); ++itr)
  {
    coloumnswidth = std::max(itr.key().length(), coloumnswidth); //слово максимальной длины
  }
  const auto margin = size_t{ 2 };
  const auto margin2 = size_t{ 11 };
  const auto margin3 = size_t{ 9 };
  const auto margin4 = size_t{ 1 };
  size_t margin5;
  os << "." << generateLine(margin2 + coloumnswidth + margin + margin4) << ".\n";
  os << "|Word" << generateSpaces(coloumnswidth - word.length() + margin) << "| Frequency |\n";
  os << "|" << generateLine(margin2 + coloumnswidth + margin + margin4) << "|\n";
  for (auto itr = dictionary.begin(); itr != dictionary.end(); ++itr)
  {
    if (itr.value() <= 9) margin5 = size_t{ 0 };
    else if (itr.value() <= 99) margin5 = size_t{ 1 };
    else if (itr.value() <= 999) margin5 = size_t{ 2 };
    os << "|" << itr.key() << generateSpaces(coloumnswidth - itr.key().length() + margin) << "| " << itr.value() << generateSpaces(margin3 - margin5) << "|\n";
  }
  os << "'" << generateLine(margin2 + coloumnswidth + margin + margin4) << "\'\n";
  os << "\n";
  if (dictionary.isEmpty())
  {
    os << "Dictionary is empty!\n";
  }
}

void TextHandler::printStatistics(const std::string& filename)
{
  if (filename.length() <= 4 || filename.substr(filename.size() - 4) != ".txt") //проверка на расширение и название файла
  {
    throw std::invalid_argument(" -> Invalid output file extension. A file with the \".txt\" extension is expected.");
  }
  std::ofstream os(filename);
  if (!os)
  {
    throw std::invalid_argument{ " -> Invalid file's name \"" + filename + "\". Enter the valid file's name in the following request!" };
  }

  printStatistics(os);
  os.close();
}

bool TextHandler::isDictEmpty()
{
  if (dictionary.isEmpty())
  {
    return true;
  }
  return false;
}

std::string generateSpaces(size_t length)
{
  std::string spaces;
  for (size_t i = 0; i < length; ++i) {
    spaces += " ";
  }
  return spaces;
}

std::string generateLine(size_t length)
{
  std::string lines;
  for (size_t i = 0; i < length; ++i) {
    lines += "-";
  }
  return lines;
}
