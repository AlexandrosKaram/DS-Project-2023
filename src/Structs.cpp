// include header files
#include "../header/Structs.h"
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