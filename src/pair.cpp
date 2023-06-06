// include header files
#include "../header/Pair.h"

Pair:: Pair() {
    word1 = NULL;
    word2 = NULL;
    apps = NULL;
};

Pair:: Pair(std::string word1, std::string word2) {
    this->word1 = word1;
    this->word2 = word2;
    apps = NULL;
}

Pair:: Pair(std::string word1, std::string word2, int apps) {
    this->word1 = word1;
    this->word2 = word2;
    this->apps = apps;
}

Pair:: ~Pair() {}

void Pair::setWord1(std::string word1) {this->word1 = word1;}

void Pair::setWord2(std::string word2) {this->word2 = word2;}

void Pair::setAppearances(int apps) {this->apps = apps;}

std::string Pair:: getWord1() {return word1;}

std::string Pair:: getWord2() {return word2;}

int Pair:: getAppearances() {return apps;}

// overloads
bool operator==(const Pair& p1, const Pair& p2) {
    return (p1.getWord1() == p2.getWord1()) && (p1.getWord2() == p2.getWord2());
}

bool operator>(const Pair& p1, const Pair& p2) {
    return (p1.getWord1() > p2.getWord1()) || (p1.getWord1() == p2.getWord1() && p1.getWord2() > p2.getWord2());
}

bool operator>=(const Pair& p1, const Pair& p2) {
    return (p1.getWord1() > p2.getWord1()) || (p1.getWord1() == p2.getWord1() && p1.getWord2() >= p2.getWord2());
}

bool operator<(const Pair& p1, const Pair& p2) {
    return (p1.getWord1() < p2.getWord1()) || (p1.getWord1() == p2.getWord1() && p1.getWord2() < p2.getWord2());
}

bool operator<=(const Pair& p1, const Pair& p2) {
    return (p1.getWord1() < p2.getWord1()) || (p1.getWord1() == p2.getWord1() && p1.getWord2() <= p2.getWord2());
}

// output
std::ostream& operator<<(std::ostream& os, Pair& p) {
    os << "[" << "{" << p.getWord1() << ", " << p.getWord2() << "} " << "apps: " << p.apps << "]";
    return os;
}