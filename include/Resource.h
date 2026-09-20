#ifndef RESOURCE_H
#define RESOURCE_H
#include <string>
using namespace std;

class Resource {
  private:
    string ResourceID;
    string ResourceName;
    string ResourceType;
    string Availability;
  public:
    Resource();
    Resource(const string& rID, const string& rName, const string& rType, string& rAvl);
    string getResourceID() const;
    string getResourceName() const;
    string getResourceType() const;
    string getAvailability() const;
    void ReadFile();
    void DisplayResources() const;
};

#endif
