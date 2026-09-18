// Reservation Manager implementation file
#include "Resource.h"
#include "ReservationManager.h"
#include "Reservation.h"
#include <iostream>
#include <fstream>
#include <sstream>

std::vector<Resource> res; 

void loadResources() {

    std::ifstream inputFile;
    inputFile.open("data/resources.txt");
    std::string line = "";
    while(std::getline(inputFile, line)) {

        std::string id, name, type, availability;
        std::stringstream ss(line);
        std::getline(ss, id, '|');
        std::getline(ss, name, '|');
        std::getline(ss, type, '|');
        std::getline(ss, availability, '|');

        Resource resources(id, name, type, availability);
        res.push_back(resources);

    } 
    inputFile.close();
}

void displayAllResources() {
    for(auto& re: res) {
        std::cout << "Resource ID: " << re.getResourceID() << std::endl;
        std::cout << "Resource Name: " << re.getResourceName() << std::endl;
        std::cout << "Resource Type: " << re.getResourceType() << std::endl;
        std::cout << "Availability: " << re.getAvailabilityStatus() << std::endl;
        std::cout << "------------------------" << std::endl; 
    }
}

