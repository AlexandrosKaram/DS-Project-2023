//Include header files
#include "../header/funcs.h"
#include "../header/Array.h"
#include "../header/Avl.h"
#include "../header/BinaryTree.h"
#include "../header/HashTable.h"
#include "../header/SortedArray.h"
#include "../header/funcs.h"
#include "../header/Structs.h"
#include "../header/File.h"
#include <time.h>

//Include libraries
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

int main() {
	formatFile("small-file.txt", "formated.txt");   // custom function that formats the file
	File formated("formated.txt");
	formated.setPairCount(formated.countPairs());
	size_t size = formated.getPairCount();

	size_t setSize;
	pair* setQ = createSet(formated, setSize);   // create set with the words we need to search in the data structures

	Array array(size);
	array.createPairs(formated);
	array.searchPairs(setQ, setSize);

	// SortedArray sortedArray(random);   // create a sorted array with random pairs as lines
	// sortedArray.createPairs("formated.txt", random);   // add N random pairs to array

	return 0;
}