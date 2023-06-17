#include "../header/Array.h"
#include "../header/Pair.h"
#include <chrono>
#include <fstream>

// constructor
Array:: Array() {
    size = 1000000;
    data = new Pair[1000000];   // create an array of 512 pairs
    currentSize = 0;
    constTime = 0;
    searchTime = 0;
}

// destructor
Array:: ~Array() {
    size = 0;
    currentSize = 0;
    delete []data;   // delete array and set size to 0
}

// methods

// double the array's size dynamically
void Array:: doubleSize() {
    // create new array with double the current size
    Pair* temp = new Pair[size*2];

    // copy all of the current array's pairs
    for (int i=0 ; i<currentSize ; i++) {
        temp[i] = data[i];
    }

    // delete old array and replace it with the new one
    delete []data;
    data = temp;
    size = 2*size;
}

// create the pairs from the text file
void Array:: createPairs(File formatted, int totalPairs) {
    std::ifstream file;
    file.open(formatted.getName());
    
    if (file.is_open()) {
        auto startConstructing = std::chrono::high_resolution_clock::now();   // track start time of constructing
        std::string word;
        Pair* tempPair = new Pair;

        // start creating the pairs
        file >> word;
        tempPair->word1 = word;
        while (currentSize < totalPairs-1) {
            file >> word;
            tempPair->word2 = word;

            addPair(tempPair);
            // if (!(currentSize % 10000)) {
            //     std::cerr << "Current size: " << currentSize << ", data[currentSize-1]: " << data[currentSize-1] << std::endl;
            // }
            tempPair->word1 = word;   
        }
        file >> word;
        tempPair->word2 = word;
        addPair(tempPair);
        delete tempPair;
        
        auto endConstructing = std::chrono::high_resolution_clock::now();   // track end time of constructing
        std::chrono::duration<double> duration = endConstructing - startConstructing;   // calculate duration of constructing
        this->constTime = duration.count();   // assign duration

        file.close();

        std::ofstream output;
        output.open("results/Array.txt", std::ios::out);
        output << "Time to create " << currentSize << " pairs for Array: " << this->constTime << " seconds." << std::endl;
    } else {
        std::cerr << "Error, file not found." << std::endl;
    }
}
 
// search pairs from Q set with linear search
void Array:: searchPairs(Pair* Qset, int QsetSize) {   // calculate Qset's size
    auto startSearching = std::chrono::high_resolution_clock::now();   // track start time of searching 

    for (int i=0 ; i<QsetSize ; i++) {
        for (int j=0 ; j<currentSize ; j++) 
            if (data[j] == Qset[i]) Qset[i].apps = data[j].apps;
    }

    auto endSearching = std::chrono::high_resolution_clock::now();   // track end time of searching 
    std::chrono::duration<double> duration = endSearching - startSearching;   // calculate duration of searching 
    searchTime = duration.count();

    std::ofstream output;
    output.open("results/Array.txt", std::ios::app);   // append from previous pointer position
    output << "Time to search " << QsetSize << " pairs for Array: " << this->searchTime << " seconds." << std::endl;   // print searching time

    output << std::endl << "Pairs and their number of appearances:" << std::endl;
    for (int i=0 ; i<QsetSize ; i++) {   
        output << Qset[i] << std::endl;   // print pairs and their appearances
    }

    delete[] data;
}

// add pair to data if not already contained
void Array:: addPair(Pair* tempPair) {
    bool alreadyExists = false;
    for (int i=0 ; i<currentSize && !(alreadyExists) ; i++) {
        if (data[i] == *tempPair) {
            alreadyExists = true;
            data[i].apps++;
        }
    }
    if (!alreadyExists) {
        if (currentSize >= size)
            doubleSize();
        data[currentSize] = *tempPair;
        data[currentSize].apps = 1;
        currentSize++;
    }
}