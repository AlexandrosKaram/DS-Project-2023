#pragma once

#include <iostream>
#include "Pair.h"
#include "Array.h"

class SortedArray : public Array {
    protected:
    void handlePair(Pair* tempPair);
    int binarySearchPair(Pair tempPair);

    public:
    void createPairs(std::string filename);
    void searchPairs(Pair *Qset, int QsetSize);
};