#include "ReservationManager.h"
#include <iostream>
using namespace std;

//constructor
ReservationManager::ReservationManager() {
    head = nullptr;
}
//check if reservation ID already exists
bool ReservationManager::reservationExists(string reservationID) {
    Node* current = head;

    while (current != nullptr) {
        if (current->reservation.getReservationID() == reservationID) {
            return true;
        }
        current = current->next;
    }
    return false;
}

//creating a new reservation
void ReservationManager::createReservation(Reservation reservation) {
    //check for duplicate ID
    if (reservationExists(reservation.getReservationID())) {
        cout << "Reservation ID already exists." << endl;
        return;
    }

    //create new node
    Node* newNode = new Node(reservation);

    //if the list is empty
    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        //add new node to end
        current->next = newNode;
    }

    cout << "Reservation created successfully." << endl;
}

//cancel a reservation
void ReservationManager::cancelReservation (string reservationID) {

    if (head == nullptr) {
        cout << "No reservations found." << endl;
        return;
    }

    if (head->reservation.getReservationID() == reservationID) {
        Node* temp = head;
        head = head->next;
        delete temp;

        cout << "Reservation cancelled successfully." << endl;
        return;
    }

    Node* current = head;

    //Search for the reservation
    while (current->next != nullptr &&
           current->next->reservation.getReservationID() != reservationID) {
        current = current->next;
    }

    //reser. not found
    if (current->next == nullptr) {
        cout << "Reservation not found." << endl;
        return;
    }

    //remove reser. from linked list
    Node* temp = current->next;
    current->next = temp->next;
    delete temp;

    cout << "Reservation cancelled successfully." << endl;
}

//Display all active reservations
void ReservationManager::displayReservations() {

    if (head == nullptr) {
        cout << "No active reservations." << endl;
        return;
    }

    Node* current = head;

    cout << "Active Reservations:" << endl;

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

//check if resource ID is valid
bool ReservationManager::validResource (string resourceID) {
    return false;
}
