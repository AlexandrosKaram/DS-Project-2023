# pragma once

//Include libraries
#include <string>
#include "Pair.h"
#include "File.h"

void formatFile(std::string inputFilename, std::string outputFilename); // Removes punctuation and convert all characters to lowercase

Pair* createSet(File filename, int& QsetSize);   // creates Q set with random pairs

int countPairs(std::string filename);