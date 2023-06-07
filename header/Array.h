# pragma once

// include header files
#include "Pair.h"
#include "File.h"

class Array {
    protected:
    Pair *data;   // array of pairs
    size_t size;   // number of pairs
    double constructingTime;   // time to create pairs
    double searchingTime;   // time to search pairs

    public:
    // constructors - destructors
    Array();   // default constructor
    Array(int size);   // constructor
    ~Array();   // destructor
    
    // setters - getters
    int getSize();   // getter for size of array
   
    // methods
    virtual void createPairs(File formated); // add random continuous pairs to the array
    virtual void searchPairs(Pair* pairs, size_t setSize);   // linear search the pairs
};
