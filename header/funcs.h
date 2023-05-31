# pragma once

//Include libraries
#include <string>
#include "Structs.h"

void formatFile(std::string inputFilename, std::string outputFilename); // Removes punctuation and convert all characters to lowercase

pair* createSet(std::string file);