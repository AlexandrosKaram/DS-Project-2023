#include <iostream>
#include "Pair.h"
#include "File.h"

class Array {
    protected:
    int size, currentSize;
    Pair* data;
    double constTime, searchTime;

    public:
    // constructor - destructor
    Array();
    ~Array();
    // methods
    void doubleSize();
    void createPairs(File formatted, int totalPairs);
    void searchPairs(Pair* Qset);
};
