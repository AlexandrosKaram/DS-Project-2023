# pragma once

// include libraries
#include <iostream>

class Pair {
    public:
    std::string word1, word2;
    int apps;
    // constructor
    Pair();
    // destructor
    ~Pair();
};

// overloads
bool operator==(Pair& p1, Pair& p2);
bool operator>(Pair& p1, Pair& p2);
bool operator>=(Pair& p1, Pair& p2);
bool operator<(Pair& p1, Pair& p2);
bool operator<=(Pair& p1, Pair& p2);

std::ostream& operator<<(std::ostream& os, Pair& p);
