# pragma once

//Include libraries
#include <string>
#include "Structs.h"
#include "File.h"

void formatFile(std::string inputFilename, std::string outputFilename); // Removes punctuation and convert all characters to lowercase

pair* createSet(File file, size_t& setSize);   // creates Q set with random pairs