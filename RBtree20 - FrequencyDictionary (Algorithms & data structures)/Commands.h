#ifndef CROSS_REFERENCES_COMMANDS_H
#define CROSS_REFERENCES_COMMANDS_H

#include "TextProcessing.h"

#include <string>

void analyseText(const std::string& filename);

void ThreeMFWText(const std::string& filename);

void analyseFreq(const std::string& filename);

void printHelp();

void readCommand(std::string command);

#endif

