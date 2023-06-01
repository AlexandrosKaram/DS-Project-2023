# pragma once

// include header files
#include "Array.h"
#include "Structs.h"
// include libraries

// declare SortedArray class
class SortedArray: public Array {   // derived class of Array
    private:
    int partition(pair* arr, int low, int high);  // Helper function for partition step
    void quicksort(pair* arr, int low, int high);  // Quicksort function
    
    public:
    // constructors - destructors
    SortedArray();   // default constructor
    SortedArray(int size);   // constructor
    ~SortedArray();   // destructor
    
    // methods
    void createPairs(std::string fileName, int random);
    void quicksortArray();  // quick sort the array
    void swapPairs(pair& a, pair& b);   // swaps two pairs
    int timesExists(int i);   // returns number of appearances
};
