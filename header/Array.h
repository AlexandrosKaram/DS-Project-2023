# pragma once

#include <string>

class Array {
    private:
        std::string **data; // 2D array
        int rows; // Number of pairs
        const int columns=3; // Two words and number of appearances
        // [ [word1, word2, 1] [word2, word3, 1] ... ]
    public:
        Array(); // Default constructor
        Array(int rows); // Constructor
        ~Array(); // Deconstructor
        void setWord1(int i, std::string word1); // Setter for first word
        void setWord2(int i, std::string word2); // Setter for second word
        void setAppearances(int i, int n); // Setter for appearances
        std::string getWord1(int i); // Getter for first word
        std::string getWord2(int i); // Getter for second word
        int getAppearances(int i); // Getter for appearances
        int getRows(); // Getter for number of rows
        bool samePair(int i, std::string word1, std::string word2); // Checks if a pair is the same
        int timesExists(int row, std::string word1, std::string word2); // Returns how many times a pair exists - serial serach
};