#include <iostream>
#include "Pair.h"
#include "File.h"
#include "Array.h"

class SortedArray : public Array {
    protected:
    void addPair(Pair* tempPair);
    void binarySearchPair(Pair* tempPair);

    public:
    void createPairs(File formatted);
    void searchPairs(Pair *Qset, int QsetSize);
};