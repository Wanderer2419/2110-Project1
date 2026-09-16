// Resources implementation
#include "Resource.h"
#include <fstream>

// Constructor
Resource::Resource(int ID, std::string name, std::string type, bool status) {
            Resource_ID = ID;
            Resource_Name = name;
            Resource_Type = type;
            Status = status;
        }

// Getters
int Resource::getResourceID() {
    return Resource_ID;
}

std::string Resource::getResourceName() {
    return Resource_Name;
}

std::string Resource::getResourceType() {
    return Resource_Type;
}

bool Resource::getAvailabilityStatus() {
    return Status;
}

// Functions
void displayResource() {
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
}

