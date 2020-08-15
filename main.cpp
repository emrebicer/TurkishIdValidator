#include <iostream>
#include <string>
#include "tid.h"


int main(){
    
    // Example usage of validating a single Turkish Id
    std::string exampleTurkishId = "10000000146";
    std::cout << "Validating: " << exampleTurkishId << std::endl;
    std::cout << "\t" << exampleTurkishId << "\t-->\t" 
        << (validateTurkishId(exampleTurkishId) ? "\xE2\x9C\x85VALID" : "\xE2\x9D\x8CINVALID") 
        << std::endl;

    // Example usage of validating several Turkish Id's from a file (must be comma seperated values)
    validateFromFile("exampleids.txt");

    return 0;
}