# pragma once

//Include libraries
#include <string>
#include "Pair.h"
#include "File.h"

void formatFile(std::string inputFilename, std::string outputFilename); // Removes punctuation and convert all characters to lowercase

Pair* createSet(File filename, size_t& setSize);   // creates Q set with random pairs