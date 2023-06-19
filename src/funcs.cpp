// include header files
#include "../header/funcs.h"
#include "../header/Pair.h"
// include libraries
#include <fstream>
#include <string>
#include <cctype>
#include <time.h>

void formatFile(std::string inputFilename, std::string outputFilename) {
    // open input and output files
    std::ifstream inputFile;
    std::ofstream outputFile;
    inputFile.open(inputFilename);
    outputFile.open(outputFilename);
    
    if (inputFile.is_open()){   // make sure there are no errors in opening the file
        // remove punctuation from the text and convert all characters to lowercase
        std::string line;
        while (std::getline(inputFile, line)) {   // loop through each line of the file
            for (char c : line) {   // loop through each character of the line
                if (!std::ispunct(c)) {   // if the character is not punctuation, convert it to lowercase and print it
                    outputFile << (char) std:: tolower(c);
                } else {
                    outputFile << " ";
                }
            }
            outputFile << std::endl;
        }
    } else {
        outputFile << "Error in reading the test file!";
    }

    inputFile.close();
    outputFile.close();
}

Pair* createSet(File formated, int& QsetSize) {   // create Q set with random pairs
    QsetSize = 2000;   // size of the set

    std::ifstream f;
    f.open(formated.getName());
    // get size of the file by seeing in which byte the pointer is
    f.seekg(0, std::ios::end);
    int end = f.tellg();   

    Pair* pairs = new Pair[QsetSize];   // create Pair array of size N

    srand(time(nullptr));
    for (int i=0 ; i<QsetSize ; i++) {
        // get random position within the file
        int pos = rand() % end;  
        f.seekg(pos, std::ios::beg);

        std::string word;
        f >> word;   // get rid of word in case pointer is not in suitable position
    
        // create Pair and add it to the array
        f >> word;
        pairs[i].word1 = word;
        f >> word;
        pairs[i].word2 = word;
    }
    f.close();

    return pairs;
}

int countPairs(std::string filename) {
    std::ifstream f;
    f.open(filename);
    int cnt = 0;   // pairs counter

    if (f.is_open()) {
        std::string word;
        while (f >> word) cnt++;
        f.close();
    } else {
        std::cerr << "Error! Failed to open file..." << std::endl;
    }

    if (cnt>1)
        return cnt-1;   // pairs are equal to words-1
    return cnt;
}