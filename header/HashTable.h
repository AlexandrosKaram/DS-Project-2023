# pragma once

#include <iostream>
#include "Pair.h"

class hashEntry {
    public:
    Pair pair;
    unsigned long long int hashCode;
    bool occupied;
    // constructor
    hashEntry() {occupied = false;}
};

class HashTable {
    protected:
    hashEntry* data;
    int size, capacity;
    int hashFunction(hashEntry key, int capacity);
    double constTime, searchTime;
    // private helper methods
    void createPairs(std::string filename);
    void searchPairs(Pair* Qset, int QsetSize);
    // private methods
    void doubleSize();
    void handlePair(Pair tempPair);
    unsigned long long int createHashCode(Pair tempPair);
    int pow(int number,int power);

    public:
    // constructor - destructor
    HashTable();
    ~HashTable();
    // methods
    void showResults(std::string filename, Pair* Qset, int QsetSize);
};