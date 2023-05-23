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
	formatFile("small-file.txt", "output.txt"); // Custom function that formats the file

	std::ifstream file;
	file.open("output.txt");

	srand(time(0)); // Change the random value each time program is executed using the current time.
	int random = rand() % 5000 + 2000; // Random number between 2000 and 5000, will be used as the number of pairs.

	Array test(random); // Create an unordered array with random rows and two columns.

	std::string word;
	int row=0;

	file >> word; // Get first word
	test.setWord1(row, word); // Include first word
	while (row < test.getRows()-1) {
		file >> word; // Get next word
		test.setWord2(row, word); // Include next word
		test.setWord1(++row, word); // Use next word as first word in the next pair
	}
	file >> word; // Get last word
	test.setWord2(row, word); // Include last word

	// For testing reasons only - Print data
	for (int i=0;i<test.getRows();i++) {
		std::cout << "[" << test.getWord1(i) << ", " << test.getWord2(i) << ", " << test.getAppearances(i) << "]";
		std::cout << std::endl;
	}
	
		
	file.close();

	return 0;
}