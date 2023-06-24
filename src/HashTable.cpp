#include "../header/HashTable.h"
#include <chrono>
#include <fstream>

HashTable:: HashTable() {
    size = 0;
    capacity = 512;
    data = new hashEntry[capacity];
}

HashTable:: ~HashTable() {
    delete[] data;
}

int HashTable:: pow(int number, int power) {
    int result = 1;

    for (int i=0 ; i<power ; i++) {
        result *= number ;
    }
    
    return result;
}

int HashTable:: hashFunction(hashEntry key, int capacity) {
    return key.hashCode % capacity;
}

void HashTable:: doubleSize() {
    int new_capacity = capacity*2;   // double current capacity
    hashEntry* temp = new hashEntry[new_capacity];

    // copy and rehash elements
    for (int i=0 ; i<capacity ; i++) {
        if (data[i].occupied) {
            int pos = hashFunction(data[i], new_capacity);
            bool placed = false;

            while (!placed) {    
                if (!(temp[pos].occupied)) {
                    temp[pos] = data[i]; 
                    temp[pos].occupied = true;
                    placed = true;
                } else {
                    pos++;
                    if (pos == new_capacity)
                        pos = 0;
                }
            }
        }
    }

    delete []data;
    data = temp;
    capacity = new_capacity;
}

unsigned long long int HashTable:: createHashCode(Pair tempPair) {
    std::string concat_word = tempPair.word1 + tempPair.word2;

    unsigned long long int hash = 0;
    int prime = 31;

    for (char c : concat_word) {    
        hash = hash * prime + int(c);
    }
    
    return hash;
}

void HashTable:: handlePair(Pair tempPair) {
    hashEntry* tempEntry = new hashEntry; 
    tempEntry->pair = tempPair;
    tempEntry->hashCode = createHashCode(tempPair);

    int pos = hashFunction(*tempEntry, capacity);

    while (true) {
        if (!(data[pos].occupied)){
            data[pos] = *tempEntry;
            data[pos].occupied = true;
            data[pos].pair.apps = 1;
            size++;
        
            return;
        } else if (data[pos].pair == tempEntry->pair) {
            data[pos].pair.apps++;
            
            return;
        } else {
            if (pos == capacity-1)
                pos = 0;
            else
                pos++;
        }
    }
}

void HashTable:: createPairs(std::string filename) {
    std::ifstream file;
    file.open(filename);

    if (file.is_open()) {
        auto startConstructing = std::chrono::high_resolution_clock::now();
        std::string word;
        Pair* tempPair = new Pair;

        // start creating the pairs
        file >> word;
        tempPair->word1 = word;
        int j = 0;
        while (file) {
            j++;
            if (size >= capacity*0.7) {
                doubleSize();
            }
            file >> word;
            tempPair->word2 = word;     
            
            handlePair(*tempPair);  
            
            delete tempPair;
            tempPair = new Pair;

            tempPair->word1 = word;
        }
        delete tempPair;

        auto endConstructing = std::chrono::high_resolution_clock::now();
        std::chrono::duration <double> duration = endConstructing - startConstructing;
        this->constTime = duration.count();   // assign duration

        file.close();

        std::ofstream output;
        output.open("results/HashTable.txt");
        output << "Time to create " << size << " pairs for Hashtable: " << constTime << " seconds." << std::endl;
    } else {
        std::cerr << "Error! failed to open file" << std::endl;
    }
}

void HashTable:: searchPairs(Pair* Qset, int QsetSize) {
    auto startSearching = std::chrono::high_resolution_clock::now();

    for (int i=0 ; i<QsetSize ; i++) {
        unsigned long long int code = createHashCode(Qset[i]);
        int pos = code % capacity;

        bool finished = false;
        while (!finished) {
            if (data[pos].hashCode == -1) {
                Qset[i].apps = 0;
                finished = true;
            } else if (data[pos].pair == Qset[i]) {
                Qset[i].apps = data[pos].pair.apps;
                finished = true;
            } else {
                if (pos == capacity-1)
                    pos = 0;
                else
                    pos++;
            }
        }
    }

    auto endSearching = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = endSearching - startSearching;   // calculate duration of searching 
    searchTime = duration.count();

    std::ofstream output;
    output.open("results/HashTable.txt", std::ios::app);   // append from previous pointer position
    output << "Time to search " << QsetSize << " pairs for Hashtable: " << searchTime << " seconds." << std::endl;   // print searching time

    output << std::endl << "Pairs and their number of appearances:" << std::endl;
    for (int i=0 ; i<QsetSize ; i++) {   
        output << Qset[i] << std::endl;   // print pairs and their appearances
    }
}

void HashTable:: showResults(std::string filename, Pair* Qset, int QsetSize) {
    createPairs(filename);
    searchPairs(Qset, QsetSize);
}
