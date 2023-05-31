// include header files
#include "../header/Array.h"
// include libraries
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

Array::Array() {};   // empty constructor

Array::Array(int size) {   // constructor that creates an array with specific size
    this->size = size; 
    data = new pair[size];   // allocate memory for the array
    for (int i=0 ; i < size ; i++) {
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

int Array::getSize() {   // getter for number of rows
    return size;
}

int Array:: timesExists(int i) {   // returns number of appearances of the pair
    auto startSearching = std::chrono::high_resolution_clock::now();   // track start time of searching an individual pair
    int cnt = 0;   // counter
    for (int j=0 ; j < this->getSize() ; j++) {   // loop through the rows
        if (data[i] == data[j]) cnt++;   // check if pairs are the same and increase counter
    }
    auto endSearching = std::chrono::high_resolution_clock::now();   // track end time of searching an individual pair
    std::chrono::duration<double> duration = endSearching - startSearching;   // calculate duration of searching an individual pair
    this->searchingTime += duration.count();   // add duration of an individual pair
    return cnt;
}

void Array:: createPairs(File formated) {
    auto startConstructing = std::chrono::high_resolution_clock::now();   // track start time of constructing

    std::ifstream file;
	file.open(formated.getName());

    int size = formated.getPairCount();   // size of array
    std::string word;
	
    file >> word;	// read word from the file
	this->setWord1(0, word);   // include first word
	for (int i=0 ; i<size-1 ; i++) {
		file >> word;
		this->setWord2(i, word);   // use word as second in this pair and first in next pair
		this->setWord1(i+1, word); 
	}
	file >> word;
	this->setWord2(size-1, word);   // include last word

    auto endConstructing = std::chrono::high_resolution_clock::now();   // track end time of constructing
    std::chrono::duration<double> duration = endConstructing - startConstructing;   // calculate duration of constructing
    this->constructingTime = duration.count();   // assign duration

	// for testing reasons only - print data
	// for (int i=0 ; i < size ; i++) {
	// 	this->setAppearances(i, this->timesExists(i));
	// 	std::cout << "[" << this->getWord1(i) << ", " << this->getWord2(i) << ", " << this->getAppearances(i) << "]";
	// 	std::cout << std::endl;
	// }
		
	file.close();

    std::cout << "Time to create pairs for Array: " << this->constructingTime << " seconds." << std::endl;   // testing reasons only
};

void Array:: searchPairs(pair* pairs, size_t setSize) {   // search pairs from Q set
    auto startSearching = std::chrono::high_resolution_clock::now();   // track start time of searching 
    for (int i=0 ; i<setSize ; i++) {
        int cnt = 0;
        for (int j=0 ; j<size ; j++) {
            if (pairs[i] == data[j]) cnt++;
        }
        pairs[i].apps = cnt;
    }
    auto endSearching = std::chrono::high_resolution_clock::now();   // track end time of searching 
    std::chrono::duration<double> duration = endSearching - startSearching;   // calculate duration of searching 
    searchingTime = duration.count();

    std::cout << "Time to search pairs for Array: " << this->searchingTime << " seconds." << std::endl;   // testing reasons only
}