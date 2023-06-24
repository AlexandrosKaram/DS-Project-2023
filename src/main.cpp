//Include header files
#include "../header/funcs.h"
#include "../header/Pair.h"

//Include libraries
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

int main(int argc, char *argv[]) {
	formatFile(argv[1], "formatted.txt");   // format the text file
	
	int QsetSize;   // size of the Q set
	Pair* Qset = createSet(QsetSize);   // set of random pairs that will be searched in the data structures

	for (int i=2 ; i<argc ; i++) {
		std::string ds = argv[i];
		if (ds == "1") {
			array("formatted.txt", Qset, QsetSize);   // call Array
		} else if (ds == "2") {
			sortedArray("formatted.txt", Qset, QsetSize);   // call Sorted Array
		} else if (ds == "3") {
			binarySearchTree("formatted.txt", Qset, QsetSize);   // call Binary Search Tree
		} else if (ds == "4") {
			avlTree("formatted.txt", Qset, QsetSize);   // call AVL tree
		} else if (ds == "5") {
			hashTable("formatted.txt", Qset, QsetSize);   // call Hashtable
		}
	}
	
	return 0;
}
