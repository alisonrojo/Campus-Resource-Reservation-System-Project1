#include "Resource.h"
#include <iostream>
using namespace std;

Resource::Resource() {
    ResourceID = " ";
    ResourceName = " ";
    ResourceType = " ";
    Availability = " ";
}

Resource::Resource(const string& rID, const string& rName, const string& rType, const string& rAvl) {
    ResourceID = rID;
    ResourceName = rName;
    ResourceType = rType;
    Availability = rAvl;
}

string Resource::getResourceID() const {
    return ResourceID;
}

string Resource::getResourceName() const {
    return ResourceName;
}

string Resource::getResourceType() const {
    return ResourceType;
}

string Resource::getAvailability() const {
    return Availability;
}

void Resource::ReadFile() {
    ifstream resources;
    file.open("resources.txt");
    while (getline(file, ResourceID, '|')) {
        getline(file, ResourceName, '|');
        getline(file, ResourceType, '|');
        getline(file, Availability);

        DisplayResources();
        cout << endl;
    }
 file.close()
}

void Resource::DisplayResources() const {
    cout << "Resource ID: " << ResourceID << endl;
    cout << "Resource Name: " << ResourceName << endl;
    cout << "Resource Type: " << ResourceType << endl;
    cout << "Availability: " << Availability << endl;
}

