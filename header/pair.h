# pragma once

// include libraries
#include <iostream>

class Pair {
    protected:
    std::string word1, word2;
    int apps;

    public:
    // constructor
    Pair();
    // destructor
    ~Pair();
    // setters
    void setWord1(std::string);
    void setWord2(std::string);
    void setAppearances(int);
    // getters
    std::string getWord1();
    std::string getWord2();
    int getAppearances();
};

// overloads
bool operator==(Pair& p1, Pair& p2);
bool operator>(Pair& p1, Pair& p2);
bool operator>=(Pair& p1, Pair& p2);
bool operator<(Pair& p1, Pair& p2);
bool operator<=(Pair& p1, Pair& p2);

std::ostream& operator<<(std::ostream& os, Pair& p);
