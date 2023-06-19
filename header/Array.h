#pragma once

#include <iostream>
#include "Pair.h"

class Array {
    protected:
    int size, currentSize;
    Pair* data;
    double constTime, searchTime;
    // helper functions
    virtual void handlePair(Pair* tempPair);

    public:
    // constructor - destructor
    Array();
    ~Array();
    // methods
    void doubleSize();
    virtual void createPairs(std::string filename);
    virtual void searchPairs(Pair* Qset, int QsetSize);
    void showResults(std::string filename, Pair* Qset, int QsetSize);
};
