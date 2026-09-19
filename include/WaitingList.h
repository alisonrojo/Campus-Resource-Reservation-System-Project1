#ifndef WAITING_LIST_H
#define WAITING_LIST_H
#include <iostream>
#include <queue>
#include <string>
using namespace std;

class WaitingList {
  private:
    queue<string> WaitingList;
  public:
    void AddStudent(string student);
    void RemoveStudent();
    void Display();
};

#endif
