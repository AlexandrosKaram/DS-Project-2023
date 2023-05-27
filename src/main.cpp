//Include header files
#include "../header/funcs.h"
#include "../header/Array.h"
#include "../header/Avl.h"
#include "../header/BinaryTree.h"
#include "../header/HashTable.h"
#include "../header/SortedArray.h"
#include <time.h>

//Include libraries
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

int main() {
	formatFile("small-file.txt", "formated.txt");   // custom function that formats the file

	srand(time(0));   // change the random value each time program is executed using the current time
	int random = rand() % 5000 + 2000;   // random number between 2000 and 5000, will be used as the number of pairs

	//Array array(random);   // create an array with random pairs as lines
	//test.createPairs("formated.txt", random);   // add N random pairs to array

	//SortedArray sortedArray(random);   // create a sorted array with random pairs as lines
	//sortedArray.createPairs("formated.txt", random);   // add N random pairs to array

	return 0;
}