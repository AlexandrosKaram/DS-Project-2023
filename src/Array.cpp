// include header files
#include "../header/Array.h"
// include libraries
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

Array::Array() {};   // empty constructor

Array::Array(int rows) {   // constructor that creates an array with specific number of rows
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
    auto startSearching = std::chrono::high_resolution_clock::now();   // track start time of searching an individual pair
    int cnt = 0;   // counter
    for (int j=0 ; j < this->getRows() ; j++) {   // loop through the rows
        if (data[i] == data[j]) cnt++;   // check if pairs are the same and increase counter
    }
    auto endSearching = std::chrono::high_resolution_clock::now();   // track end time of searching an individual pair
    std::chrono::duration<double> duration = endSearching - startSearching;   // calculate duration of searching an individual pair
    this->searchingTime += duration.count();   // add duration of an individual pair
    return cnt;
}

void Array:: createPairs(std::string fileName, int random) {
    auto startConstructing = std::chrono::high_resolution_clock::now();   // track start time of constructing

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

    auto endConstructing = std::chrono::high_resolution_clock::now();   // track end time of constructing
    std::chrono::duration<double> duration = endConstructing - startConstructing;   // calculate duration of constructing
    this->constructingTime = duration.count();   // assign duration

	// for testing reasons only - print data
	for (int i=0 ; i < N ; i++) {
		this->setAppearances(i, this->timesExists(i));
		std::cout << "[" << this->getWord1(i) << ", " << this->getWord2(i) << ", " << this->getAppearances(i) << "]";
		std::cout << std::endl;
	}
		
	file.close();

    std::cout << "Time to create pairs: " << this->constructingTime << " seconds." << std::endl;   // testing reasons only
    std::cout << "Time to search pairs: " << this->searchingTime << " seconds." << std::endl;   // testing reasons only
};