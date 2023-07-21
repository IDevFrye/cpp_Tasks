#include "Commands.h"
#include "TextProcessing.h"

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

void readCommand(std::string command) //чтение команды
{
  std::istringstream iss(command);
  std::string cmd;
  std::string filename;
  iss >> cmd;

  if (cmd == "help")
  {
    printHelp();
    std::cout << "\n> ";
  }
  else if (cmd == "analyse")
  {
    if (iss >> filename)
    {
      try
      {
        analyseText(filename);
        std::cout << "\n> ";
      }
      catch (const std::invalid_argument& e)
      {
        std::cerr << e.what() << '\n';
        std::cout << "\n> ";
      }
    }
  }
  else if (cmd == "exit")
  {
    exit(0);
  }
  else if (cmd == "3mfw")
  {
    if (iss >> filename)
    {
      try
      {
        ThreeMFWText(filename);
        std::cout << "\n> ";
      }
      catch (const std::invalid_argument& e)
      {
        std::cerr << e.what() << '\n';
        std::cout << "\n> ";
      }
    }
  }
  else if (cmd == "frequency")
  {
    if (iss >> filename)
    {
      try
      {
        analyseFreq(filename);
        std::cout << "\n> ";
      }
      catch (const std::invalid_argument& e)
      {
        std::cerr << e.what() << '\n';
        std::cout << "\n> ";
      }
    }
  }
}

void printHelp()
{
  std::cout << "\n.-----------------------------------------------------------------------------------------------.\n";
  std::cout << "|  AVAILABLE COMMANDS     |  DESCRIPTION                                                        |\n";
  std::cout << "|-----------------------------------------------------------------------------------------------|\n";
  std::cout << "|  help                   |  display this help message                                          |\n";
  std::cout << "|  analyse <filename>     |  print table of analysed text from <filename> (keys sorting)        |\n";
  std::cout << "|  3mfw <filename>        |  print 3 most frequent words                                        |\n";
  std::cout << "|  frequency <filename>   |  print table of analysed frequency from <filename> (values sorting) |\n";
  std::cout << "|  exit                   |  exit the program                                                   |\n";
  std::cout << "'-----------------------------------------------------------------------------------------------'\n";
}

void ThreeMFWText(const std::string& filename)
{
  TextHandler dict{ };
  dict.analyse(filename);
  std::cout << "\nChoose output options: \n";
  std::cout << "  -> terminal             analyse 3 most frequent words to terminal\n";
  std::cout << "  -> <filename>           analyse 3 most frequent words to file (warning: filename must include extension .txt)\n";
  std::cout << "\n>> ";
  std::string outfile;
  std::cin >> outfile;
  if (!std::cin)
  {
    throw std::invalid_argument{ "Reading input error" };
  }
  if (outfile == "terminal")
  {
    std::cout << "\n";
    dict.print3MFW(std::cout);
  }
  else
  {
    dict.print3MFW(outfile);
  }
}

void analyseText(const std::string& filename)
{
  TextHandler dict{ };
  dict.analyse(filename);
  std::cout << "\nChoose output options: \n";
  std::cout << "  -> terminal             analyse text to terminal\n";
  std::cout << "  -> <filename>           analyse text to file (warning: filename must include extension .txt)\n";
  std::cout << "\n>> ";
  std::string outfile;
  std::cin >> outfile;
  if (!std::cin)
  {
    throw std::invalid_argument{ "Reading input error" };
  }
  if (outfile == "terminal")
  {
    std::cout << "\n";
    dict.printStatistics(std::cout);
  }
  else
  {
    dict.printStatistics(outfile);
  }
  while (!dict.isDictEmpty())
  {
    std::cout << "Do you want to delete or insert word or nothing? (D/I/N)\n";
    auto answer1 = std::string{ };
    std::cin >> answer1;
    if (!std::cin)
    {
      throw std::invalid_argument{ "Reading input error" };
    }
    if (answer1 == "D")
    {
      std::cout << "\nEnter the word to delete: ";
      auto word = std::string{};
      std::cin >> word;
      dict.deleteWord(word);
      if (outfile == "terminal")
      {
        std::cout << "\n";
        dict.printStatistics(std::cout);
      }
      else
      {
        dict.printStatistics(outfile);
      }
    }
    else if (answer1 == "I")
    {
      std::cout << "\nEnter the word to insert: ";
      auto word1 = std::string{};
      std::cin >> word1;
      std::cout << "Enter the amount of words: ";
      int val;
      std::cin >> val;
      dict.insertWord(word1, val);
      if (outfile == "terminal")
      {
        std::cout << "\n";
        dict.printStatistics(std::cout);
      }
      else
      {
        dict.printStatistics(outfile);
      }
    }
    else if (answer1 == "N")
    {
      break;
    }
  }
}

void analyseFreq(const std::string& filename)
{
  TextHandler dict{ };
  dict.analyse(filename);
  std::cout << "\nChoose output options: \n";
  std::cout << "  -> terminal             analyse frequency of words to terminal\n";
  std::cout << "  -> <filename>           analyse frequency of words to file (warning: filename must include extension .txt)\n";
  std::cout << "\n>> ";
  std::string outfile;
  std::cin >> outfile;
  if (!std::cin)
  {
    throw std::invalid_argument{ "Reading input error" };
  }
  if (outfile == "terminal")
  {
    std::cout << "\n";
    dict.printFreqStat(std::cout);
  }
  else
  {
    dict.printFreqStat(outfile);
  }
}