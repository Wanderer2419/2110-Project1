// Resource header file
#ifndef RESOURCE_H
#define RESOURCE_H
#include <string>
#include <vector>

class Resource {
    private:
        std::string Resource_ID;
        std::string Resource_Name;
        std::string Resource_Type;
        std::string Status;
    public:
        // Constructor
        Resource(std::string ID, std::string name, std::string type, std::string status);

        std::string getResourceID();

        std::string getResourceName();

        std::string getResourceType();
        std::string getAvailabilityStatus();        
};
#endif
