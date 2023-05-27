# pragma once

// include header files
#include "Array.h"
#include "Structs.h"
// include libraries
#include <iostream>

// declare SortedArray class
class SortedArray: public Array {   // derived class of Array
    private:
    int partition(pair* arr, int low, int high);  // Helper function for partition step
    void quicksort(pair* arr, int low, int high);  // Quicksort function
    
    public:
    // constructors - destructors
    SortedArray();
    SortedArray(int rows);
    ~SortedArray();
    
    // methods
    void createPairs(std::string fileName, int random);
    void quicksortArray();  // quick sort the array
    void swapPairs(pair& a, pair& b);   // swaps two pairs
    virtual int timesExists(int i);   // returns number of appearances
};
