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
	formatFile(argv[1], "formatted.txt");   // custom function that formats the file
	std::cout << "File done formatting" << std::endl;
	File formatted("formatted.txt");   // object of class File
	// count number of pairs in the file and save it 
	formatted.setPairCount(formatted.countPairs());   
	int totalPairs = formatted.getPairCount();
	std::cout << "Finished counting " << totalPairs << "pairs." << std::endl; 

	int QsetSize;   // size of the Q set
	Pair* Qset = createSet(formatted, QsetSize);   // create set with the words we need to search in the data structures
	std::cout << "Set created normally" << std::endl;

	Array array;   // create new object of array class
	// calculate and print results for the array data structure
	array.createPairs(formatted, totalPairs); 
	std::cout << "End of pair creation" << std::endl;
	array.searchPairs(Qset, QsetSize);   
	std::cout << "End of pair searching" << std::endl;

	return 0;
}