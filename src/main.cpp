//Include header files
#include "../header/funcs.h"
#include "../header/Array.h"
#include "../header/Avl.h"
#include "../header/BinaryTree.h"
#include "../header/HashTable.h"
#include "../header/SortedArray.h"
#include "../header/funcs.h"
#include "../header/pair.h"
#include "../header/File.h"
#include <time.h>

//Include libraries
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

int main() {
	formatFile("small-file.txt", "formated.txt");   // custom function that formats the file
	File formated("formated.txt");   // object of class File
	// count number of pairs in the file and save it 
	formated.setPairCount(formated.countPairs());   
	size_t size = formated.getPairCount();

	size_t setSize;   // size of the Q set
	pair* setQ = createSet(formated, setSize);   // create set with the words we need to search in the data structures

	Array array(size);   // create new object of array class
	// calculate and print results for the array data structure
	array.createPairs(formated); 
	array.searchPairs(setQ, setSize);   

	SortedArray sortedArray(size);   // create new object of SortedArray class
	// calculate and print results for the sorted array data structure
	sortedArray.createPairs(formated);
	sortedArray.searchPairs(setQ, setSize);

	return 0;
}