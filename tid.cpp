#include <string>
#include <stdexcept>
#include "tid.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <sstream>

bool validateTurkishId(std::string tid){
    /*
        Validates the given Turkish Id number.
        The number must be 11 characters in length and
        all of the characters must be a number [0, 9]
    */

    if(tid.length() != 11){
        throw std::invalid_argument("Given id must be 11 characters long.");
    }

    // Check if all numbers are between range [0, 9]
    for(int index = 0 ; index < tid.length(); index++){
        int currentNumber = getNumberByPosition(tid, index);
        if(currentNumber < 0 || currentNumber > 9){
            throw std::invalid_argument("All characters must be a number.");
        }
    }

    // First digit must be greater than 0
    if(!getNumberByPosition(tid, 0)){
        return false;
    }
    
    int sumOfOddIndexes = oddSum(tid);
    int sumOfEvenIndexes = evenSum(tid);
    int d10 = getNumberByPosition(tid, 9);
    int n = sumOfOddIndexes * 7 + - sumOfEvenIndexes;

    if(n < 0){
        n = n + 10;
    }

    if(d10 != n % 10){
        return false;
    }

    if((d10 + sumOfOddIndexes + sumOfEvenIndexes) % 10 != getNumberByPosition(tid, 10)){
        return false;
    }

    return true;
}


int getNumberByPosition(std::string tid, int pos){
    /*
        Returns the number at the given position
        in the given string as integer.
    */

    // Subtract '0' to get the actual value instead of ascii number
    return tid.at(pos) - '0';
}

int oddSum(std::string tid){
    // Returns (d1 + d3 + d5 + d7 + d9)
    int sum = 0;
    for(int index = 0 ; index < 9; index += 2){
        sum += getNumberByPosition(tid, index);
    }
    return sum;
}

int evenSum(std::string tid){
    // Returns (d2 + d4 + d6 + d8)
    int sum = 0;
    for(int index = 1 ; index < 8; index += 2){
        sum += getNumberByPosition(tid, index);
    }
    return sum;
}

void validateFromFile(std::string fileName){
    /*
        Validates a batch of turkish ids from a file.
        File should consist of turkish ids seperated by a single comma ( , )
    */

    std::string fileContent;

    // Read from the file stream
    std::ifstream fileStream(fileName);

    if(!fileStream.good()){
        throw std::invalid_argument("File was not found");
    }

    // Read file content into a string
    while(fileStream.good()){
        std::string currentLine;
        getline (fileStream, currentLine);
        fileContent.append(currentLine);
    }

    // Close the file
    fileStream.close();

    // Make sure the file content doesn't include any white space
	fileContent.erase(std::remove_if(fileContent.begin(), fileContent.end(), ::isspace), fileContent.end());

    // Split the file content by comma
    std::vector<std::string> tids;
    std::stringstream ss(fileContent);
    while (ss.good()) {
        std::string substr; 
        getline(ss, substr, ',');
        tids.push_back(substr);
    }
    
    std::cout << "Validating from: " << fileName << std::endl;
    // Iterate over ids and validate each of them
    for (size_t i = 0; i < tids.size(); i++){
        std::cout << "\t" << tids[i] << "\t-->\t" 
            << (validateTurkishId(tids[i]) ? "\xE2\x9C\x85VALID" : "\xE2\x9D\x8CINVALID") 
            << std::endl;
    }
}