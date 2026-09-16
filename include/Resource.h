// Resource header file
#ifndef RESOURCE_H
#define RESOURCE_H
#include <string>

class Resource {
    private:
        int Resource_ID;
        std::string Resource_Name;
        std::string Resource_Type;
        bool Status;
    public:
        // Constructor
        Resource(int ID, std::string name, std::string type, bool status);

        int getResourceID();

        std::string getResourceName();

        std::string getResourceType();
        bool getAvailabilityStatus();

        void displayResource();
        void displayAvailability();
        std::string Search_Resources();
        
};
#endif
