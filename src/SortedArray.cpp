#include <iostream>
#include <chrono>
#include <fstream>
#include "../header/SortedArray.h"

// search pair and increase appearances if found
int SortedArray:: binarySearchPair(Pair* tempPair) {
    int left = 0;
    int right = currentSize-1;

    while (left <= right) {
        int mid = left + (right-left)/2;

        if (data[mid] == *tempPair) {
            return mid;
        } else if (data[mid] < *tempPair) {
            left = mid+1;
        } else {
            right = mid-1;
        }
    }

    return -1;
}

void SortedArray:: movePairs(int i) {
    if (currentSize >= size+1) doubleSize();
    for (int j = currentSize+1 ; j<i ; j--) {
        data[j] = data[j-1];
    }
    currentSize++;
}

void SortedArray:: addPair(Pair* tempPair) {
    int index = binarySearchPair(tempPair);
    if (index == -1) {
        bool placed = false;
        for (int i=0 ; i<currentSize ; i++) {
            if (*tempPair > data[i]) {
                movePairs(i);
                data[i] = *tempPair;
                data[i].apps = 1;
                placed = true;
            } 
        }
        if (!(placed)) {
            if (currentSize >= size) doubleSize();
            data[currentSize] = *tempPair;
            data[currentSize].apps = 1;
            currentSize++;
        }
    } else {
        data[index].apps++;
    }
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

