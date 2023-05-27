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

	std::ifstream file;
	file.open("formated.txt");

	srand(time(0));   // change the random value each time program is executed using the current time
	int random = rand() % 5000 + 2000;   // random number between 2000 and 5000, will be used as the number of pairs

	Array test(random); // create an unordered array with random rows and two columns

	std::string word;
	int N = test.getRows();   // number of rows

	file >> word;	// read word from the file
	test.setWord1(0, word);   // include first word
	for (int i=0 ; i<N-1 ; i++) {
		file >> word;
		test.setWord2(i, word);   // use word as second in this pair and first in next pair
		test.setWord1(i+1, word); 
	}
	file >> word;
	test.setWord2(N-1, word);   // include last word

	// for testing reasons only - print data
	for (int i=0 ; i<test.getRows() ; i++) {
		test.setAppearances(i, test.timesExists(i));
		std::cout << "[" << test.getWord1(i) << ", " << test.getWord2(i) << ", " << test.getAppearances(i) << "]";
		std::cout << std::endl;
	}
	
		
	file.close();

	return 0;
}