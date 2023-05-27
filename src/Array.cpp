// include header files
#include "../header/Array.h"
// include libraries
#include <string>

Array::Array() {};   // empty constructor

Array::Array(int rows) {   // constructor that creates an array with specific number of rows
    this->rows = rows; 
    data = new pair[rows];   // allocate memory for the array
    for (int i=0 ; i < rows ; i++) {
        data[i].apps = 0;   // initialize appearances as 0
    }
}

Array::~Array() {   // destructor
    delete[] data;   // deallocate memory
}

void Array::setWord1(int i, std::string word1) {   // setter for first word
    data[i].word1 = word1;   
}

void Array::setWord2(int i, std::string word2) {   // setter for second word
    data[i].word2 = word2;   
}
 
void Array::setAppearances(int i, int n) {   // setter for appearances
    data[i].apps = n; 
}

std::string Array::getWord1(int i) {   // getter for first word
    return data[i].word1;
}

std::string Array::getWord2(int i) {   // getter for second word
    return data[i].word2;
}

int Array::getAppearances(int i) {   // getter for appearances
    return data[i].apps;
}

int Array::getRows() {   // getter for number of rows
    return rows;
}

int Array:: timesExists(int i) {   // returns number of appearances of the pair
    int cnt = 0;   // counter
    for (int j=0 ; j < this->getRows() ; j++) {   // loop through the rows
        if (data[i] == data[j]) cnt++;   // check if pairs are the same and increase counter
    }
    return cnt;
}