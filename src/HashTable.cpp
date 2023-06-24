#include "../header/HashTable.h"
#include <chrono>
#include <fstream>
#include <cmath>  

HashTable:: HashTable() {
    size = 0;
    capacity = 512;
    data = new hashEntry[capacity];
}

HashTable:: ~HashTable() {
    size = 0;
    capacity = 0;
    delete[] data;
}

int HashTable:: hashFunction(hashEntry key) {
    return key.hashCode % capacity;
}

void HashTable:: doubleSize() {
    int new_capacity = capacity*2;   // double current capacity
    hashEntry* temp = new hashEntry[new_capacity];

    // copy elements
    for (int i=0 ; i<capacity ; i++) {
        if (data[i].hashCode) {
            temp[hashFunction(data[i])] = data[i];   // rehash the entries
        }
    }

    delete []data;
    data = temp;
    capacity = new_capacity;
}

int HashTable:: createHashCode(Pair tempPair) {
    int n = tempPair.word1.length() + tempPair.word2.length();
    int code = 0;
    for (int i=0 ; i<tempPair.word1.length() ; i++) {
        code += tempPair.word1[i] * pow(31, n-i);
    }
    for (int i=tempPair.word1.length() ; i<n ; i++) {
        code += tempPair.word2[i] * pow(31, n-i);
    }

    return code;
}

void HashTable:: handlePair(Pair* tempPair) {
    hashEntry* tempEntry = new hashEntry; 
    tempEntry->pair = *tempPair;
    tempEntry->hashCode = createHashCode(*tempPair);

    int pos = hashFunction(*tempEntry);
    
    while (true) {
        if (data[pos].hashCode == -1){
            data[pos] = *tempEntry;
            return;
        } else if (data[pos].pair == tempEntry->pair) {
            data[pos].pair.apps++;
            return;
        } else {
            if (pos == capacity-1)
                pos = 0;
            else
                pos++;
        }
    }
}

void HashTable:: createPairs(std::string filename) {
    std::fstream file;
    file.open(filename);

    if (file.is_open()) {
        auto startConstructing = std::chrono::high_resolution_clock::now();
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

        auto endConstructing = std::chrono::high_resolution_clock::now();
        std::chrono::duration <double> duration = endConstructing - startConstructing;
        this->constTime = duration.count();   // assign duration

        file.close();

        std::ofstream output;
        output.open("results/HashTable.txt");
        output << "Time to create " << size << " pairs for Hashtable: " << constTime << " seconds." << std::endl;
    } else {
        std::cerr << "Error! failed to open file" << std::endl;
    }
}

void HashTable:: searchPairs(Pair* Qset, int QsetSize) {
    auto startSearching = std::chrono::high_resolution_clock::now();

    for (int i=0 ; i<QsetSize ; i++) {
        int code = createHashCode(Qset[i]);
        int pos = code % capacity;

        bool finished = false;
        while (!finished) {
            if (!(data[pos].hashCode)) {
                Qset[i].apps = 0;
                finished = true;
            } else if (data[pos].pair == Qset[i]) {
                Qset[i].apps = data[pos].pair.apps;
                finished = true;
            } else {
                if (pos == capacity-1)
                    pos = 0;
                else
                    pos++;
            }
        }
    }

    auto endSearching = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = endSearching - startSearching;   // calculate duration of searching 
    searchTime = duration.count();

    std::ofstream output;
    output.open("results/HashTable.txt", std::ios::app);   // append from previous pointer position
    output << "Time to search " << QsetSize << " pairs for Hashtable: " << searchTime << " seconds." << std::endl;   // print searching time

    output << std::endl << "Pairs and their number of appearances:" << std::endl;
    for (int i=0 ; i<QsetSize ; i++) {   
        output << Qset[i] << std::endl;   // print pairs and their appearances
    }
}

void HashTable:: showResults(std::string filename, Pair* Qset, int QsetSize) {
    createPairs(filename);
    searchPairs(Qset, QsetSize);
}
