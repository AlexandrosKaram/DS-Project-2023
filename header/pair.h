# pragma once

// include libraries
#include <iostream>

struct Pair {
    std::string word1, word2;
    int apps;
};

// overloads
bool operator==(Pair& p1, Pair& p2);
bool operator>(Pair& p1, Pair& p2);
bool operator>=(Pair& p1, Pair& p2);
bool operator<(Pair& p1, Pair& p2);
bool operator<=(Pair& p1, Pair& p2);

std::ostream& operator<<(std::ostream& os, Pair& p);
