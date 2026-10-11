#include "../include/WaitingList.h"
#include <iostream>
using namespace std;

void WaitingList::AddStudent(string student) {
  WaitingList.push(student);
}

void WaitingList::RemoveStudent() {

  // added confirmation output and error handling if the user tries to remove an empty waiting list
    if (WaitingList.empty()) {
        cout << "The waiting list is empty.\n";
        return;
    }

    WaitingList.pop();
    cout << "First student removed from the waiting list.\n";
}


void WaitingList::Display() {
  queue<string> list = WaitingList;
  while (!list.empty()) {
    cout << list.front() << endl;
    list.pop();
  }
}

int WaitingList::StudentsWaiting(string resourceID) {
  queue<string> w;
  w = WaitingList;
  string rID;
  int counter = 0;
  while (!w.empty()) {
    string q;
    int s;
    q = w.front();
    s = q.find('|');
    rID = q.substr(s+2);
    if (rID == resourceID) {
        counter += 1;
    }
    w.pop();
  }
  return counter;
}
