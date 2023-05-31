// include header files
# include "../header/File.h"
// include libraries
# include <iostream>
# include <fstream>

File:: File() {   // default constructor
    pairCount = 0;
    name = " ";
}

File:: File(std::string name) {   // constructor with name parameter
    pairCount = 0;
    this->name = name;
}

File:: ~File() {}   // destructor

void File:: setPairCount(int pairCount) {   // setter for pairCount
    this->pairCount = pairCount;
}

void File:: setName(std::string name) {   // setter for name
    this->name = name;
}

int File:: getPairCount() {   // getter for pairCount
    return pairCount;
}

std::string File:: getName() {   // getter for file name
    return name;
}

int File:: countPairs() {
    std::ifstream f;
    f.open(name);
    int cnt = 0;

    if (f.is_open()) {
        std::string word;
        while (f >> word) cnt++;
        f.close();
    } else {
        std::cout << "Failed to open file" << std::endl;
    }

    if (cnt>1)
        return cnt-1;   // if words are more than one, pairs are equal to words-1
    return cnt;
}