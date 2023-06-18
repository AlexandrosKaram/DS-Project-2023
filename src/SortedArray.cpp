#include <iostream>
#include <chrono>
#include <fstream>
#include "../header/SortedArray.h"

// search pair and increase appearances if found
int SortedArray:: binarySearchPair(Pair tempPair) {
    int left = 0;
    int right = currentSize-1;

    while (left <= right) {
        int mid = left + (right-left)/2;

        if (data[mid] == tempPair) {
            return mid;
        } else if (data[mid] < tempPair) {
            left = mid+1;
        } else {
            right = mid-1;
        }
    }

    return -1;
}

void SortedArray:: shiftArray(int i) {
    if (currentSize+1 >= size)
        doubleSize();
    for (int j = currentSize ; j>i ; j--) {
        data[j] = data[j-1];
    }
    currentSize++;
}

void SortedArray:: handlePair(Pair* tempPair) {
    int index = binarySearchPair(*tempPair);
    if (index == -1) {
        bool placed = false;
        for (int i=0 ; i<currentSize && !(placed) ; i++) {
            if (*tempPair < data[i]) {
                shiftArray(i);
                data[i] = *tempPair;
                data[i].apps = 1;
                placed = true;
            } 
        }
        if (!(placed)) {
            if (currentSize >= size)
                doubleSize();
            data[currentSize] = *tempPair;
            data[currentSize].apps = 1;
            // std::cout << "data[ " << currentSize << "] = " << data[currentSize] << std::endl; 
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
            handlePair(tempPair);
            tempPair->word1 = word;
        }
        delete tempPair;

        auto endConstructing = std::chrono::high_resolution_clock::now();   // track end time of constructing
        std::chrono::duration<double> duration = endConstructing - startConstructing;   // calculate duration of constructing
        this->constTime = duration.count();   // assign duration

        file.close();
        std::ofstream output;
        output.open("results/SortedArray.txt", std::ios::out);
        output << "Time to create " << currentSize << " pairs for Sorted Array: " << this->constTime << " seconds." << std::endl;
    } else {
        std::cerr << "Error! file not found..." << std::endl;
    }
}

void SortedArray:: searchPairs(Pair *Qset, int QsetSize) {
    auto startSearching = std::chrono::high_resolution_clock::now();   // track start time of searching 
   
    for (int i=0 ; i<QsetSize ; i++) {
        int index = binarySearchPair(Qset[i]);
        Qset[i].apps = data[index].apps;
    }

    auto endSearching = std::chrono::high_resolution_clock::now();   // track end time of searching 
    std::chrono::duration<double> duration = endSearching - startSearching;   // calculate duration of searching 
    searchTime = duration.count();

    std::ofstream output;
    output.open("results/SortedArray.txt", std::ios::app);   // append from previous pointer position
    output << "Time to search " << QsetSize << " pairs for Sorted Array: " << this->searchTime << " seconds." << std::endl;   // print searching time

    output << std::endl << "Pairs and their number of appearances:" << std::endl;
    for (int i=0 ; i<QsetSize ; i++) {   
        output << Qset[i] << std::endl;   // print pairs and their appearances
    }

    delete[] data;
}