// include header files
#include "../header/Array.h"
// include libraries
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

Array::Array() {};   // empty constructor

Array::Array(int rows) {   // constructor that creates an array with specific number of rows
    this->time = 0;
    this->rows = rows; 
    data = new pair[rows];   // allocate memory for the array
    for (int i=0 ; i < rows ; i++) {
        data[i].apps = 0;   // initialize appearances as 0
    }
}

Array::~Array() {   // destructor
    delete[] data;   // deallocate memory
}

void Array::setWord1(int i, std::string word1) {   // setter for first word
    data[i].word1 = word1;   
}

void Array::setWord2(int i, std::string word2) {   // setter for second word
    data[i].word2 = word2;   
}
 
void Array::setAppearances(int i, int n) {   // setter for appearances
    data[i].apps = n; 
}

std::string Array::getWord1(int i) {   // getter for first word
    return data[i].word1;
}

std::string Array::getWord2(int i) {   // getter for second word
    return data[i].word2;
}

int Array::getAppearances(int i) {   // getter for appearances
    return data[i].apps;
}

int Array::getRows() {   // getter for number of rows
    return rows;
}

int Array:: timesExists(int i) {   // returns number of appearances of the pair
    int cnt = 0;   // counter
    for (int j=0 ; j < this->getRows() ; j++) {   // loop through the rows
        if (data[i] == data[j]) cnt++;   // check if pairs are the same and increase counter
    }
    return cnt;
}

void Array:: createPairs(std::string fileName, int random) {
    clock_t start = clock();   // track start time

    std::ifstream file;
	file.open(fileName);

	std::string word;
	int N = this->getRows();   // number of rows
	file.seekg(N,std::ios::beg);   // start from a random (N) position indicator
	file >> word;	// read word from the file
	this->setWord1(0, word);   // include first word
	for (int i=0 ; i<N-1 ; i++) {
		file >> word;
		this->setWord2(i, word);   // use word as second in this pair and first in next pair
		this->setWord1(i+1, word); 
	}
	file >> word;
	this->setWord2(N-1, word);   // include last word

	// for testing reasons only - print data
	for (int i=0 ; i < N ; i++) {
		this->setAppearances(i, this->timesExists(i));
		std::cout << "[" << this->getWord1(i) << ", " << this->getWord2(i) << ", " << this->getAppearances(i) << "]";
		std::cout << std::endl;
	}
		
	file.close();

    clock_t end = clock();   // track end time
    this->time = double(end - start)/CLOCKS_PER_SEC;   // calculate elapsed time
    std::cout << "Time to create pairs: " << this->time << " seconds." << std::endl;   // testing reasons only
};