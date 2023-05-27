# pragma once

// include header files
#include "Structs.h"
// include libraries
#include <string>

class Array {
    protected:
    pair *data;   // array of pairs
    int rows;   // number of pairs

    public:
    // constructors - destructors
    Array();   // default constructor
    Array(int rows);   // constructor
    ~Array();   // destructor
    
    // setters - getters
    void setWord1(int i, std::string word1);   // setter for first word
    void setWord2(int i, std::string word2);   // setter for second word
    void setAppearances(int i, int n);   // setter for appearances
    std::string getWord1(int i);   // getter for first word
    std::string getWord2(int i);   // getter for second word
    
    // methods
    void createPairs(std::string fileName, int random); // add random continuous pairs to the array
    int getAppearances(int i);   // getter for appearances
    int getRows();   // getter for number of rows
    virtual int timesExists(int i);   // returns number of appearances of the pair
};
