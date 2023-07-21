#include "RedBlackTree.h"
#include "TextProcessing.h"
#include "Commands.h"
#include "RedBlackTree.cpp"

#include <string>
#include <iostream>
#include <fstream>

void tableTest()
{
  TextHandler dict;
  std::cout << "\n=============TABLE TEST=============\n\n";
  try
  {
    dict.analyse("text0.txt");
    dict.printStatistics(std::cout);
    dict.printStatistics("out.txt");
  }
  catch (std::invalid_argument& e)
  {
    std::cerr << e.what() << '\n';
  }
  std::cout << "=============DELETE WORD FROM TABLE TEST=============\n\n";
  std::cout << "-> Deleting word \"advantages\":\n\n";
  try
  {
    std::string word = "advantages";
    dict.deleteWord(word);
    dict.printStatistics(std::cout);
    dict.printStatistics("out1.txt");
  }
  catch (std::invalid_argument& e)
  {
    std::cerr << e.what() << '\n';
  }

  std::cout << "-> Deleting word \"networks\":\n\n";
  try
  {
    std::string word = "networks";
    dict.deleteWord(word);
    dict.printStatistics(std::cout);
    dict.printStatistics("out2.txt");
  }
  catch (std::invalid_argument& e)
  {
    std::cerr << e.what() << '\n';
  }

  std::cout << "=============EXCEPTIONS TEST=============\n\n";
  try
  {
    dict.analyse("nofile.txt"); //нет такого файла
    dict.printStatistics(std::cout);
  }
  catch (std::invalid_argument& e)
  {
    std::cerr << e.what() << '\n';
  }
  try
  {
    dict.analyse("text.txt");
    dict.printStatistics("file"); //без расширения
  }
  catch (std::invalid_argument& e)
  {
    std::cerr << e.what() << '\n';
  }
  try
  {
    dict.analyse("text.txt");
    dict.printStatistics("/.txt"); //невозможно создать
  }
  catch (std::invalid_argument& e)
  {
    std::cerr << e.what() << '\n';
  }
}

int main()
{
  setlocale(LC_ALL, "ru");
  tableTest();
  std::cout << "\n=============USER CONSOLE=============\n";
  std::cout << "\n> ";
  std::string command;
  while (std::cin)
  {
    std::getline(std::cin, command);
    readCommand(command);
  }
  return 0;
}