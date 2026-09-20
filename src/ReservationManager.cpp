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

   /* bool removed = reservations.remove(reservationID);

    if (removed) {
        cout << "Reservation cancelled successfully." << endl;
    }
    else {
        cout << "Reservation not found." << endl;
    }*/

   //alternate solution to connect cancellationHistory()

   Reservation canceledReservation;

   if(!reservations.find(reservationID, canceledReservation)){

    cout << "Reservation not found. \n";
    return;

}

cancellationHistory.push(canceledReservation);

if (!reservations.remove(reservationID)){

    cancellationHistory.pop();
    cout << "Reservation could not be cancelled. \n";

    return;
}
cout << "Reservation cancelled successfully. \n";

} //ending of cancelReservation()


//Display all active reservations
void ReservationManager::displayReservations() {
    reservations.display();
}

void ReservationManager::displayCancellationHistory() const {
    cancellationHistory.displayHistory();
}
//check if resource ID is valid

