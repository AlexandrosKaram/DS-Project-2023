# pragma once

// include header files
#include "Array.h"

// declare SortedArray class
class SortedArray: public Array {   // derived class of Array
    private:
    // helper functions
    int partition(Pair* arr, int low, int high);  // Helper function for partition step
    void quicksort(Pair* arr, int low, int high);  // Quicksort function
    void swapPairs(Pair& a, Pair& b);   // swaps two pairs
    int binarySearchPair(Pair& key, int low, int high);   // function to binary search the key

    public:
    // constructors - destructors
    SortedArray();   // default constructor
    SortedArray(int size);   // constructor
    ~SortedArray();   // destructor
    
    // methods
    void createPairs(File formated);   // create the pairs
    void quicksortArray();  // quicksort the array
    void searchPairs(Pair* pairs, size_t setSize);   // search the pairs
};
