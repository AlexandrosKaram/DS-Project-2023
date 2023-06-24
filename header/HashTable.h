# pragma once

#include <iostream>
#include "Pair.h"

class hashEntry {
    public:
    Pair pair;
    int hashCode;
    hashEntry() {hashCode = NULL;}
};

class HashTable {
    protected:
    hashEntry* data;
    int size, capacity;
    int hashFunction(hashEntry key);
    double constTime, searchTime;
    // private helper methods
    void createPairs(std::string filename);
    void searchPairs(Pair* Qset, int QsetSize);
    // private methods
    void doubleSize();
    void handlePair(Pair* tempPair);
    int createHashCode(Pair tempPair);

    public:
    // constructor - destructor
    HashTable();
    ~HashTable();
    // methods
    void showResults(std::string filename, Pair* Qset, int QsetSize);
};