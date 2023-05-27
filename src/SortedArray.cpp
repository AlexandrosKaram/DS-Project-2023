// include header files
#include "../header/SortedArray.h"
#include "../header/Array.h"
// include libraries
#include <iostream>

SortedArray:: SortedArray() : Array() {};   // default constructor

SortedArray:: SortedArray(int rows) : Array(rows) {};   // construcot that creates an array with specific number of rows

SortedArray:: ~SortedArray() {};   // destructor

void SortedArray:: swapPairs(pair& a, pair& b) {
    pair temp = a;
    a = b;
    b = temp;
}

int SortedArray:: timesExists(int i) {   // returns number of appearances
    int cnt = 0;   // counter
    bool flag = true;
    // loop only through the pairs around, since array is sorted
    for (int j=i-1 ; j>=0 && flag ; j++) {
        if (isSamePair(i, j)) {
            cnt++;   // if pairs are the same increase counter
        } else {
            flag = false;   // stop looping
        }
    }
    flag = true;
    for (int j=i+1 ; j<rows ; j++) {
        if (isSamePair(i, j)) {
            cnt++;   // if pairs are the same increase counter
        } else {
            flag = false;
        }
    }

    return cnt;   // return counter
}