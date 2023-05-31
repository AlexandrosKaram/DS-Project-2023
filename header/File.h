# pragma once

// include header files
// include libraries
# include <iostream>

class File {
    protected:
    int pairCount;
    std::string name;
    
    public:
    // constructors
    File();
    File(std::string name);
    // destructor
    ~File();
    // setters
    void setPairCount(int pairCount);
    void setName(std::string name);
    // getters
    int getPairCount();
    std::string getName();
    // methods
    int countPairs();
};