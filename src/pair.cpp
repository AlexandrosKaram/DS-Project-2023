// include header files
#include "../header/Pair.h"

Pair:: Pair() {}

Pair:: ~Pair() {}

void Pair::setWord1(std::string word1) {this->word1 = word1;}

void Pair::setWord2(std::string word2) {this->word2 = word2;}

void Pair::setAppearances(int apps) {this->apps = apps;}

std::string Pair:: getWord1() {return word1;}

std::string Pair:: getWord2() {return word2;}

int Pair:: getAppearances() {return apps;}

// overloads
bool operator==(Pair& p1, Pair& p2) {
    return (p1.getWord1() == p2.getWord1()) && (p1.getWord2() == p2.getWord2());
}

bool operator>(Pair& p1, Pair& p2) {
    return (p1.getWord1() > p2.getWord1()) || (p1.getWord1() == p2.getWord1() && p1.getWord2() > p2.getWord2());
}

bool operator>=(Pair& p1, Pair& p2) {
    return (p1.getWord1() > p2.getWord1()) || (p1.getWord1() == p2.getWord1() && p1.getWord2() >= p2.getWord2());
}

bool operator<(Pair& p1, Pair& p2) {
    return (p1.getWord1() < p2.getWord1()) || (p1.getWord1() == p2.getWord1() && p1.getWord2() < p2.getWord2());
}

bool operator<=(Pair& p1, Pair& p2) {
    return (p1.getWord1() < p2.getWord1()) || (p1.getWord1() == p2.getWord1() && p1.getWord2() <= p2.getWord2());
}

// output
std::ostream& operator<<(std::ostream& os, Pair& p) {
    os << "[" << "{" << p.getWord1() << ", " << p.getWord2() << "} " << "apps: " << p.getAppearances() << "]";
    return os;
}
