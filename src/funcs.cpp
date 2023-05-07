//Include header files
#include "../header/funcs.h"

//Include libraries
#include <fstream>
#include <string>
#include <cctype>

void formatFile(std::string inputFilename, std::string outputFilename) {
    std::ifstream inputFile;
    std::ofstream outputFile;
    inputFile.open(inputFilename);
    outputFile.open(outputFilename);
    if (!inputFile) {
        outputFile << "Error in reading the test file!";
    } else {
        //Remove punctuation from the text and convert all characters to lowercase
        std::string line;
        while (std::getline(inputFile, line)) { //Loop through each line of the file
            for (char c : line) { //Loop through each character of the line
                if (!std::ispunct(c)) { //If the character is not punctuation, convert it to lowercase and print it
                    c=std::tolower(c);
                    outputFile << c;
                }
            }
            outputFile << std::endl;
        }
    }
    inputFile.close();
    outputFile.close();
}