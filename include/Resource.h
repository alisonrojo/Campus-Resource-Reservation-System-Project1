#ifndef RESOURCE_H
#define RESOURCE_H
#include <string>
using namespace std;

class Resource {
  private:
    string ResourceID;
    string ResourceName;
    string ResourceType;
    bool Availability;
  public:
    Resource();
    Resource(const string& rID, const string& rName, const string& rType, bool rAvl);
    string getResourceID() const;
    string getResourceName() const;
    string getResourceType() const;
    bool getAvailability() const;
    void DisplayResources() const;
};

#endif
