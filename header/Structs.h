# pragma once

// include libraries
#include <iostream>

typedef struct Pair {
    std::string word1;   // first word of the pair
    std::string word2;   // second word of the pair
    int apps;   // number of appearances
} pair ;

// overloads
// bool operators
bool operator==(const pair& p1, const pair& p2);

bool operator>(const pair& p1, const pair& p2);

bool operator>=(const pair& p1, const pair& p2);

bool operator<(const pair& p1, const pair& p2);

bool operator<=(const pair& p1, const pair& p2);