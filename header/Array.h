# pragma once

#include <string>

class Array {
    private:
        std::string **data;   // 2d array
        int rows;   // number of pairs
        const int columns=3;   // two words and number of appearances
        // [ [word1, word2, 1] [word2, word3, 1] ... ]
    public:
        Array();   // default constructor
        Array(int rows);   // constructor
        ~Array();   // destructor
        void setWord1(int i, std::string word1);   // setter for first word
        void setWord2(int i, std::string word2);   // setter for second word
        void setAppearances(int i, int n);   // setter for appearances
        std::string getWord1(int i);   // getter for first word
        std::string getWord2(int i);   // getter for second word
        int getAppearances(int i);   // getter for appearances
        int getRows();   // getter for number of rows
        bool samePair(int i, std::string word1, std::string word2);   // checks if a pair is the same
        int timesExists(int row, std::string word1, std::string word2);   // returns how many times a pair exists - serial serach
};