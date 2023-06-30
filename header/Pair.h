# pragma once

#include <iostream>

struct Pair {
    std::string word1, word2;
    int apps;
};

// bool overloads
bool operator==(Pair& p1, Pair& p2);
bool operator>(Pair& p1, Pair& p2);
bool operator>=(Pair& p1, Pair& p2);
bool operator<(Pair& p1, Pair& p2);
bool operator<=(Pair& p1, Pair& p2);
// stream overloads
std::ostream& operator<<(std::ostream& os, Pair& p);
