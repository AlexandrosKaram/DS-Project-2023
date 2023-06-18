//Include header files
#include "../header/funcs.h"
#include "../header/Array.h"
#include "../header/Avl.h"
#include "../header/BinaryTree.h"
#include "../header/HashTable.h"
// #include "../header/SortedArray.h"
#include "../header/funcs.h"
#include "../header/Pair.h"
#include "../header/File.h"
#include <time.h>

//Include libraries
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

int main(int argc, char *argv[]) {
	formatFile(argv[2], "formatted.txt");   // custom function that formats the file
	File formatted("formatted.txt");   // object of class File
	// count number of pairs in the file and save it 
	formatted.setPairCount(formatted.countPairs());   
	
	int QsetSize;   // size of the Q set
	Pair* Qset = createSet(formatted, QsetSize);   // create set with the words we need to search in the data structures

	if (argv[1] == "1"){ 
		Array array;   // create new object of array class
		// calculate and print results for the array data structure
		array.createPairs(formatted);
		array.searchPairs(Qset, QsetSize);   
	} else if (argv[1] == "2") {

	}

	return 0;
}