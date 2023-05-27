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
bool operator==(pair& p1, pair& p2) {
    return (p1.word1 == p2.word1) && (p1.word2 == p2.word2);
}

bool operator>(pair& p1, pair& p2) {
    return p1.word1 > p2.word1 ||
           p1.word1 == p2.word1 && p1.word2 > p2.word2;
}

bool operator>=(pair& p1, pair& p2) {
    return p1.word1 >= p2.word1 ||
           p1.word1 == p2.word1 && p1.word2 >= p2.word2;
}

bool operator<(pair& p1, pair& p2) {
    return p1.word1 < p2.word1 ||
           p1.word1 == p2.word1 && p1.word2 < p2.word2;
}

bool operator<=(pair& p1, pair& p2) {
    return p1.word1 <= p2.word1 ||
           p1.word1 == p2.word1 && p1.word2 <= p2.word2;
}