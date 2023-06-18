#include <iostream>
#include "Pair.h"
#include "File.h"
#include "Array.h"

class SortedArray : public Array {
    protected:
    void addPair(Pair* tempPair);
    int binarySearchPair(Pair* tempPair);
    void movePairs(int i);

    public:
    void createPairs(File formatted);
    void searchPairs(Pair *Qset, int QsetSize);
};