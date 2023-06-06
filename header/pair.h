# pragma once

// include libraries
#include <iostream>

class Pair {
    protected:
    std::string word1, word2;
    int apps;

    public:
    // constructors
    Pair();
    Pair(std::string, std::string);
    Pair(std::string, std::string, int);
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
bool operator==(const Pair& p1, const Pair& p2);
bool operator>(const Pair& p1, const Pair& p2);
bool operator>=(const Pair& p1, const Pair& p2);
bool operator<(const Pair& p1, const Pair& p2);
bool operator<=(const Pair& p1, const Pair& p2);

std::ostream& operator<<(std::ostream& os, Pair& p);