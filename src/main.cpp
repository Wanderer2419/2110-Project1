// Main source code
#include <iostream>
#include "Resource.h"
#include <fstream>
#include <string>

int main() {

    std::ifstream inputFile;
    inputFile.open("resource.txt");
    if(! inputFile.is_open()) {
        std::cerr << "File could not open" << std::endl;
    }
    std::string line = "";
    while(std::getline(inputFile, line)) {
        std::cout << line << std::endl;
    }


    inputFile.close();

    


    return 0;
}
