#include <iostream>
#include <chrono>
#include <fstream>
#include "../header/SortedArray.h"

bool SortedArray:: binarySearchPair(Pair* tempPair) {
    int left = 0;
    int right = currentSize-1;

    while (left <= right) {
        int mid = left + (right-left)/2;

        if (data[mid] == *tempPair) {
            data[mid].apps++;
        } else if (data[mid] < *tempPair) {
            left = mid+1;
        } else {
            right = mid -1;
        }
    }
}

void SortedArray:: addPair(Pair* tempPair) {

}

void SortedArray:: createPairs(File formatted) {
    std::ifstream file;
    file.open(formatted.getName());

    if (file.is_open()) {
        auto startConstructing = std::chrono::high_resolution_clock::now();   // track start time of constructing
        std::string word;
        Pair* tempPair = new Pair;

        // start creating the pairs
        file >> word;
        tempPair->word1 = word;
        while (file) {
            file >> word;
            tempPair->word2 = word;
            addPair(tempPair);
            tempPair->word1 = word;
        }
        delete tempPair;

        auto endConstructing = std::chrono::high_resolution_clock::now();   // track end time of constructing
        std::chrono::duration<double> duration = endConstructing - startConstructing;   // calculate duration of constructing
        this->constTime = duration.count();   // assign duration

        file.close();
    } else {
        std::cerr << "Error! file not found..." << std::endl;
    }
}

