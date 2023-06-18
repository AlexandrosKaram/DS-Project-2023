#pragma once

#include <iostream>
#include "Pair.h"
#include "File.h"

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
    virtual void createPairs(File formatted);
    virtual void searchPairs(Pair* Qset, int QsetSize);
    void showResults(File formatted, Pair* Qset, int QsetSize);
};
