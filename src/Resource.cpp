// Resources implementation
#include "Resource.h"
#include <fstream>

// Constructor
Resource::Resource(std::string ID, std::string name, std::string type, std::string status) {
            Resource_ID = ID;
            Resource_Name = name;
            Resource_Type = type;
            Status = status;
        }

// Getters
std::string Resource::getResourceID() {
    return Resource_ID;
}

std::string Resource::getResourceName() {
    return Resource_Name;
}

std::string Resource::getResourceType() {
    return Resource_Type;
}

std::string Resource::getAvailabilityStatus() {
    return Status;
}


