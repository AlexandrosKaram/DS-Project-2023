# pragma once

// include header files
#include "Array.h"
#include "Structs.h"
// include libraries
#include <iostream>

// declare SortedArray class
class SortedArray: public Array {   // derived class of Array
    public:
        // constructors - destructors
        SortedArray();
        SortedArray(int rows);
        ~SortedArray();
        // methods
        void quicksortArray();  // quick sort the array
        void swapPairs(pair& a, pair& b);   // swaps two pairs
        virtual int timesExists(int i);   // returns number of appearances
};
