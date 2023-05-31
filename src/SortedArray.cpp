// // include header files
// #include "../header/SortedArray.h"
// #include "../header/Array.h"
// // include libraries
// #include <iostream>
// #include <fstream>
// #include <string>
// #include <chrono>

// SortedArray:: SortedArray() : Array() {};   // default constructor

// SortedArray:: SortedArray(int rows) : Array(rows) {};   // construcot that creates an array with specific number of rows

// SortedArray:: ~SortedArray() {};   // destructor

// void SortedArray:: swapPairs(pair& a, pair& b) {
//     pair temp = a;
//     a = b;
//     b = temp;
// }

// int SortedArray:: timesExists(int i) {   // returns number of appearances
//     auto startSearching = std::chrono::high_resolution_clock::now();   // track start time of searching an individual pair
//     int cnt = 1;   // counter
//     bool flag = true;
//     // loop only through the pairs around, since array is sorted
//     for (int j=i-1 ; j>=0 && flag ; j--) {
//         if (data[i] == data[j]) {
//             cnt++;   // if pairs are the same increase counter
//         } else {
//             flag = false;   // stop looping
//         }
//     }
//     flag = true;
//     for (int j=i+1 ; j<rows ; j++) {
//         if (data[i] == data[j]) {
//             cnt++;   // if pairs are the same increase counter
//         } else {
//             flag = false;
//         }
//     }
//     auto endSearching = std::chrono::high_resolution_clock::now();   // track end time of searching an individual pair
//     std::chrono::duration<double> duration = endSearching - startSearching;   // calculate duration of searching an individual pair
//     this->searchingTime += duration.count();   // add duration of an individual pair
//     return cnt;   // return counter
// }

// // quicksort functions
// int SortedArray:: partition(pair* data, int low, int high) {
//     pair pivot = data[high];  // last element is the pivot
//     int i = low-1;

//     for (int j = low ; j <= high-1 ; j++) {
//         if (data[j] <= pivot) {
//             i++;
//             swapPairs(data[i], data[j]);
//         }
//     }

//     // place the pivot element in its correct position
//     swapPairs(data[i+1], data[high]);

//     return i+1;
// }

// void SortedArray:: quicksort(pair* data, int low, int high) {
//     if (low < high) {
//         int pi = partition(data, low, high);

//         // recursively sort the sub-arrays
//         quicksort(data, low, pi-1);
//         quicksort(data, pi+1, high);
//     }
// }

// void SortedArray:: quicksortArray() {
//     quicksort(data, 0, rows - 1);
// }

// void SortedArray:: createPairs(std::string fileName, int random) {
//     auto startConstructing = std::chrono::high_resolution_clock::now();   // track start time of constructing

//     std::ifstream file;
// 	file.open(fileName);

// 	std::string word;
// 	int N = this->getRows();   // number of rows
// 	file.seekg(N,std::ios::beg);   // start from a random (N) position indicator
// 	file >> word;	// read word from the file
// 	this->setWord1(0, word);   // include first word
// 	for (int i=0 ; i<N-1 ; i++) {
// 		file >> word;
// 		this->setWord2(i, word);   // use word as second in this pair and first in next pair
// 		this->setWord1(i+1, word); 
// 	}
// 	file >> word;
// 	this->setWord2(N-1, word);   // include last word
//     this->quicksortArray();

//     auto endConstructing = std::chrono::high_resolution_clock::now();   // track end time of constructing
//     std::chrono::duration<double> duration = endConstructing - startConstructing;   // calculate duration of constructing
//     this->constructingTime = duration.count();   // assign duration

// 	// for testing reasons only - print data
// 	for (int i=0 ; i < N ; i++) {
// 		this->setAppearances(i, this->timesExists(i));
// 		std::cout << "[" << this->getWord1(i) << ", " << this->getWord2(i) << ", " << this->getAppearances(i) << "]";
// 		std::cout << std::endl;
// 	}
		
// 	file.close();

//     std::cout << "Time to create pairs for Sorted Array: " << this->constructingTime << " seconds." << std::endl;   // testing reasons only
//     std::cout << "Time to search pairs for Sorted Array: " << this->searchingTime << " seconds." << std::endl;   // testing reasons only
// };