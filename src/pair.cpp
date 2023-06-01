// include header files
#include "../header/pair.h"
// include libraries
#include <iostream>

bool operator==(const pair& p1, const pair& p2) {
    return (p1.word1 == p2.word1) && (p1.word2 == p2.word2);
}

bool operator>(const pair& p1, const pair& p2) {
    return (p1.word1 > p2.word1) || (p1.word1 == p2.word1 && p1.word2 > p2.word2);
}

bool operator>=(const pair& p1, const pair& p2) {
    return (p1.word1 > p2.word1) || (p1.word1 == p2.word1 && p1.word2 >= p2.word2);
}

bool operator<(const pair& p1, const pair& p2) {
    return (p1.word1 < p2.word1) || (p1.word1 == p2.word1 && p1.word2 < p2.word2);
}

bool operator<=(const pair& p1, const pair& p2) {
    return (p1.word1 < p2.word1) || (p1.word1 == p2.word1 && p1.word2 <= p2.word2);
}

std::ostream& operator<<(std::ostream& os, pair& p) {
    os << "[" << "{" << p.word1 << ", " << p.word2 << "} " << "apps: " << p.apps << "]";
    return os;
}