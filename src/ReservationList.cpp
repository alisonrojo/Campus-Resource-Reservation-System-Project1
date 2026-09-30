
#include "../include/ReservationList.h"
#include <iostream>

using namespace std;

//constructor
ReservationList::ReservationList() {
    head = nullptr;
}

//destructor
ReservationList::~ReservationList() {
    Node* current = head;

    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

//add a reservation 
void ReservationList::insert(Reservation reservation) {
    Node* newNode = new Node(reservation);

    //if list is empty
    if (head == nullptr) {
        head = newNode;
        return;
    }
    //move to end of list
    Node* current = head;

    while (current->next != nullptr) {
        current = current->next;
    }

    //add new node to end
    current->next = newNode;
}

//remove reservation using ID
bool ReservationList::remove(string reservationID) {

    //if list is empty
    if (head == nullptr) {
        return false;
    }

    //if reservation is the first node
    if (head->reservation.getReservationID() == reservationID) {
        Node* temp = head;
        head = head->next;
        delete temp;

        return true;
    }

    Node* current = head;

    //search for reser.
    while (current->next != nullptr &&
           current->next->reservation.getReservationID() != reservationID) {
        current = current->next;
    }

    //reser. not found
    if (current->next == nullptr) {
        return false;
    }

    //remove the node
    Node* temp = current->next;
    current->next = temp->next;
    delete temp;

    return true;
}

//search for a reser.
bool ReservationList::search(string reservationID) {
    Node* current = head;

    while (current != nullptr) {
        if (current->reservation.getReservationID() == reservationID) {
            return true;
        }
        current = current->next;
    }
    
    return false;
}

//display all reservations
void ReservationList::display() {
    Node* current = head;

    if (head == nullptr) {
        cout << "No active reservations." << endl;
        return;
    }

    cout << "\nActive Reservations:" << endl;

    while (current != nullptr) {
        cout << "Reservation ID: "
             << current->reservation.getReservationID() << endl;

        cout << "Student ID: "
             << current->reservation.getStudentID() << endl;

        cout << "Student Name: "
             << current->reservation.getStudentName() << endl;

        cout << "Resource ID: "
             << current->reservation.getResourceID() << endl;

        cout << "Reservation Date: "
             << current->reservation.getReservationDate() << endl;

        cout << endl;

        current = current->next;
    }

}
bool ReservationList::find(const string& reservationID, Reservation& outputReservation) const{
    const Node* current = head;

    while (current != nullptr) {
        if (current->reservation.getReservationID() == reservationID) {
            outputReservation = current->reservation;
            return true;
        }

        current = current->next;
    }
    return false;
}

//adding function to check for active bookings
//0(n) because it is possible to visit every active reservation
//must follow a mm/dd/yyyy date format

bool ReservationList::isBooked(const string& resourceID, const string& date) const {
    const Node* current = head;

    while(current != nullptr) {
        if(current->reservation.getResourceID() == resourceID && current->reservation.getReservationDate() == date){
            return true;
        }
        current = current->next;
    }
    return false;
}

void ReservationList::toVector(vector<Reservation>& out) const{
    const Node* current = head;
    while (current != nullptr){
        out.push_back(current->reservation);
        current = current->next;
    }
}
