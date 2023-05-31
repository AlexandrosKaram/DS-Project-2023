# pragma once

// include header files
#include "Structs.h"
#include "File.h"
// include libraries

class Array {
    protected:
    pair *data;   // array of pairs
    int size;   // number of pairs
    double constructingTime=0;   // time to create pairs
    double searchingTime=0;   // time to search pairs

    public:
    // constructors - destructors
    Array();   // default constructor
    Array(int size);   // constructor
    ~Array();   // destructor
    
    // setters - getters
    void setWord1(int i, std::string word1);   // setter for first word
    void setWord2(int i, std::string word2);   // setter for second word
    void setAppearances(int i, int n);   // setter for appearances
    std::string getWord1(int i);   // getter for first word
    std::string getWord2(int i);   // getter for second word
    int getSize();   // getter for size of array
    
    // methods
    void createPairs(File formated); // add random continuous pairs to the array
    int getAppearances(int i);   // getter for appearances
    virtual int timesExists(int i);   // returns number of appearances of the pair
    void searchPairs(pair* pairs, size_t setSize);
};
