#include "Resource.h"
#include <iostream>
using namespace std;

Resource::Resource() {
    ResourceID = " ";
    ResourceName = " ";
    ResourceType = " ";
    Availability = false;
}

Resource::Resource(const string& rID, const string& rName, const string& rType, bool rAvl) {
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

bool Resource::getAvailability() const {
    return Availability;
}

void Resource::DisplayResources() const {
    cout << "Resource ID: " << ResourceID << endl;
    cout << "Resource Name: " << ResourceName << endl;
    cout << "Resource Type: " << ResourceType << endl;
    cout << "Availability: ";
    if (Availability == true) {
        cout << "Available" << endl;
    }
    else {
        cout << "Not Available" << endl;
    }
}

