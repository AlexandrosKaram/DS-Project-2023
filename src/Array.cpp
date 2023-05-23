#include "../header/Array.h"

#include <string>

Array::Array() {}; // Empty constructor

Array::Array(int rows) {
    this->rows = rows;
    data = new std::string*[rows]; // Allocate memory for the rows
    for (int i = 0;i < rows;i++) {
        data[i] = new std::string[3]; // Allocate memory for the three columns of each row
        data[i][2] = '0'; // Initialize appearances to zero.
    }
}

Array::~Array() {
    for (int i = 0;i < rows;i++) {
        delete[] data[3]; // Deallocate memory for the three columns of each row
    }
    delete[] data; // Deallocate memory for the rows
}

void Array::setWord1(int i, std::string word1) {
    data[i][0] = word1;
}

void Array::setWord2(int i, std::string word2) {
    data[i][1] = word2;
}

void Array::setAppearances(int i, int n) {
    data[i][2] = std::to_string(n); // Int to string
}

std::string Array::getWord1(int i) {
    return data[i][0];
}

std::string Array::getWord2(int i) {
    return data[i][1];
}

int Array::getAppearances(int i) {
    return stoi(data[i][2]); // String to int
}

int Array::getRows() {
    return rows;
}

bool Array::samePair(int i, std::string word1, std::string word2) {
    return (data[i][0]==word1 && data[i][1]==word2);
}

int Array::timesExists(int row, std::string word1, std::string word2) {
    int i=0, counter=0;
    while (i < row) {
        if (samePair(i, word1, word2)) {
            counter++;
        }
        i++;
    }
    return counter;
}