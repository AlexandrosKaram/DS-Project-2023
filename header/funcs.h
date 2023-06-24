# pragma once

//Include libraries
#include <string>
#include "Pair.h"

void formatFile(std::string inputFilename, std::string outputFilename); // Removes punctuation and convert all characters to lowercase

Pair* createSet(int& QsetSize);   // creates Q set with random pairs

void array(std::string filename, Pair* Qset, int QsetSize);

void sortedArray(std::string filename, Pair* Qset, int QsetSize);

void binarySearchTree(std::string filename, Pair* Qset, int QsetSize);

void avlTree(std::string filename, Pair* Qset, int QsetSize);

void hashTable(std::string filename, Pair* Qset, int QsetSize);