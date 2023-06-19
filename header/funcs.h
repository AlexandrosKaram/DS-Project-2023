# pragma once

//Include libraries
#include <string>
#include "Pair.h"

void formatFile(std::string inputFilename, std::string outputFilename); // Removes punctuation and convert all characters to lowercase

Pair* createSet(int& QsetSize);   // creates Q set with random pairs
