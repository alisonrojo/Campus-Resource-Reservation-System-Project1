#include "WaitingList.h"
#include <iostream>
using namespace std;

void WaitingList::AddStudent(string student) {
  WaitingList.push(student);
}

void WaitingList::RemoveStudent() {
  WaitingList.pop();
}

void WaitingList::Display() {
  queue<string> list = WaitingList;
  while (!list.empty()) {
    cout << list.front() << endl;
    list.pop();
  }
}
