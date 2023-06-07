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
    data = new Pair[size];   // allocate memory for the array
}

Array::~Array() {   // destructor
    delete[] data;   // deallocate memory
}

int Array::getSize() {   // getter for number of rows
    return size;
}

void Array:: createPairs(File formated) {   // put all pairs of the file in an array
    auto startConstructing = std::chrono::high_resolution_clock::now();   // track start time of constructing

    std::ifstream file;
	file.open(formated.getName());   // open file

    std::string word;
	
    file >> word;	// read word from the file
	data[0].word1 = word;   // include first word
	for (int i=0 ; i<size-1 ; i++) {
		file >> word;
		data[i].word2 = word;   // use word as second in this Pair and first in next Pair
		data[i+1].word1 = word; 
	}
	file >> word;
	data[size-1].word2 = word;   // include last word

    auto endConstructing = std::chrono::high_resolution_clock::now();   // track end time of constructing
    std::chrono::duration<double> duration = endConstructing - startConstructing;   // calculate duration of constructing
    this->constructingTime = duration.count();   // assign duration
		
	file.close();

    std::ofstream output;
    output.open("results/Array.txt", std::ios::out);

    output << "Time to create " << size << " pairs for Array: " << this->constructingTime << " seconds." << std::endl;
};

void Array:: searchPairs(Pair* pairs, size_t setSize) {   // search pairs from Q set with linear search
    auto startSearching = std::chrono::high_resolution_clock::now();   // track start time of searching 
    
    for (int i=0 ; i<setSize ; i++) {   // loop through the set
        int cnt = 0;   // counter
        for (int j=0 ; j<size ; j++) {   // loop through the array
            if (pairs[i] == data[j]) cnt++;   // increase counter every time Pair is found
        }
        pairs[i].apps = cnt;   
    }
    
    auto endSearching = std::chrono::high_resolution_clock::now();   // track end time of searching 
    std::chrono::duration<double> duration = endSearching - startSearching;   // calculate duration of searching 
    searchingTime = duration.count();

    // open output file to print the results
    std::ofstream output;
    output.open("results/Array.txt", std::ios::app);   // append from previous pointer position
    output << "Time to search " << setSize << " pairs for Array: " << this->searchingTime << " seconds." << std::endl;   // print searching time

    output << std::endl << "Pairs and their number of appearances:" << std::endl;
    for (int i=0 ; i<setSize ; i++) {   
        output << pairs[i] << std::endl;   // print pairs and their appearances
    }
}