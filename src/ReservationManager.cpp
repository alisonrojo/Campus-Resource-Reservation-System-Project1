#include "../include/ReservationManager.h"
#include <iostream>
using namespace std;

//constructor
ReservationManager::ReservationManager() {
}
//check if reservation ID already exists
bool ReservationManager::reservationExists(string reservationID) {
    return reservations.search(reservationID);
}

//creating a new reservation
void ReservationManager::createReservation(Reservation reservation) {
    //check for duplicate ID
    if (reservationExists(reservation.getReservationID())) {
        cout << "Reservation ID already exists." << endl;
        return;
    }

    //add reser. to linked list
    reservations.insert(reservation);

    cout << "Reservation created successfully." << endl;
}

//cancel a reservation
void ReservationManager::cancelReservation(string reservationID) {
    //try to remove from linked list
    bool removed = reservations.remove(reservationID);

    if (removed) {
        cout << "Reservation cancelled successfully." << endl;
    }
    else {
        cout << "Reservation not found." << endl;
    }
}

//Display all active reservations
void ReservationManager::displayReservations() {
    reservations.display();
}

//check if resource ID is valid
bool ReservationManager::validResource (string resourceID) {
    rokayeturn false;
}
