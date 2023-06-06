// include header files
#include "../header/SortedArray.h"
#include "../header/Array.h"
// include libraries
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

SortedArray:: SortedArray() : Array() {};   // default constructor

SortedArray:: SortedArray(int size) : Array(size) {};   // constructor that creates an array with specific number of rows

SortedArray:: ~SortedArray() {};   // destructor

void SortedArray:: swapPairs(Pair& a, Pair& b) {
    Pair temp = a;
    a = b;
    b = temp;
}

// quicksort functions
int SortedArray:: partition(Pair* data, int low, int high) {
    Pair pivot = data[high];  // last element is the pivot
    int i = low-1;

    for (int j = low ; j <= high-1 ; j++) {
        if (data[j] <= pivot) {
            i++;
            swapPairs(data[i], data[j]);
        }
    }

    // place the pivot element in its correct position
    swapPairs(data[i+1], data[high]);

    return i+1;
}

void SortedArray:: quicksort(Pair* data, int low, int high) {
    if (low < high) {
        int pi = partition(data, low, high);

        // recursively sort the sub-arrays
        quicksort(data, low, pi-1);
        quicksort(data, pi+1, high);
    }
}

void SortedArray:: quicksortArray() {
    quicksort(data, 0, size - 1);
}

void SortedArray:: createPairs(File formated) {
    auto startConstructing = std::chrono::high_resolution_clock::now();   // track start time of constructing

    std::ifstream file;
	file.open(formated.getName());   // open file

    int size = formated.getPairCount();   // size of array
    std::string word;
	
    file >> word;	// read word from the file
	data[0].setWord1(word);   // include first word
	for (int i=0 ; i<size-1 ; i++) {
		file >> word;
		data[i].setWord2(word);   // use word as second in this Pair and first in next Pair
		data[i].setWord1(word); 
	}
	file >> word;
	data[size-1].setWord2(word);;   // include last word
    this->quicksortArray();   // quicksort the array

    auto endConstructing = std::chrono::high_resolution_clock::now();   // track end time of constructing
    std::chrono::duration<double> duration = endConstructing - startConstructing;   // calculate duration of constructing
    this->constructingTime = duration.count();   // assign duration

	
	file.close();

    std::ofstream output;
    output.open("results/SortedArray.txt", std::ios::out);

    output << "Time to create " << size << " pairs for Array: " << this->constructingTime << " seconds." << std::endl;
};

int SortedArray:: binarySearchPair(Pair& key, int low, int high) {
    int mid = (high + low)/2;

    if (low <= high) {
        if (data[mid] == key)
            return mid;
        else if (data[mid] > key)
            return binarySearchPair(key, low, mid-1);
        else 
            return binarySearchPair(key, mid+1, high);
    }
    return -1;
}

void SortedArray:: searchPairs(Pair* pairs, size_t setSize) {
    auto startSearching = std::chrono::high_resolution_clock::now();   // track start time of searching 
    
    for (int i=0 ; i<setSize ; i++) {   // loop through the set
        int cnt = 1;
        // look for one of the Pair's appearances with binary search
        int pos = binarySearchPair(pairs[i], 0, size);   
        bool flag = true;
        // pairs will be continuous since array is sorted so look for pairs around
        for (int j=pos+1 ; j<size && flag ; j++) {
            if (data[j] == pairs[i]){
                cnt++;   // increase counter every time Pair is found
            } else {
                flag = false;   // set flag to false and stop the loop
            }
        }
        // do the same backwards
        flag = true;
        for (int j=pos-1 ; j>=0 && flag ; j--) {
            if (data[j] == pairs[i]){
                cnt++;
            } else {
                flag = false;
            }
        }

        pairs[i].setAppearances(cnt);
    }
    
    auto endSearching = std::chrono::high_resolution_clock::now();   // track end time of searching 
    std::chrono::duration<double> duration = endSearching - startSearching;   // calculate duration of searching 
    searchingTime = duration.count();

    // open output file to print the results
    std::ofstream output;
    output.open("results/SortedArray.txt", std::ios::app);   // append from previous pointer position
    output << "Time to search " << setSize << " pairs for Array: " << this->searchingTime << " seconds." << std::endl;   // print searching time

    output << std::endl << "Pairs and their number of appearances:" << std::endl;
    for (int i=0 ; i<setSize ; i++) {   
        output << pairs[i] << std::endl;   // print pairs and their appearances
    }
}