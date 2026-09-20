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
    //check for duplicate bookings using id and date
    if (reservations.isBooked(reservation.getResourceID(),reservation.getReservationDate())) 
    {

    //output the message to the user
    cout << "This resource is already booked for that date.\n";

    return;
    }

    //add reser. to linked list
    reservations.insert(reservation);

    cout << "Reservation created successfully." << endl;
}

//cancel a reservation
void ReservationManager::cancelReservation(string reservationID) {

   //alternate solution to connect cancellationHistory()

   Reservation canceledReservation;

   if(!reservations.find(reservationID, canceledReservation)){

    cout << "Reservation not found. \n";
    return;

}


// save a copy before deleting the active-list node
cancellationHistory.push(canceledReservation);

if (!reservations.remove(reservationID)){

    // since the reservation wasnt removed we undo the history push
    cancellationHistory.pop();
    cout << "Reservation could not be cancelled. \n";

    return;
}
cout << "Reservation cancelled successfully. \n";

} //ending of cancelReservation()

// only restores the newest cancellation
// failed checks will result in the booking be left in history
void ReservationManager::undoLastCancellation() {
    Reservation canceled;

    // Read the newest cancellation without removing it.
    if (!cancellationHistory.peek(canceled)) {
        cout << "No cancellation to undo.\n";
        return;
    }

    // Prevent restoring a reservation ID that is already active.
    if (reservations.search(canceled.getReservationID())) {
        cout << "Cannot undo: reservation ID is already in use.\n";
        return;
    }

    // Prevent two bookings for the same resource and date.
    if (reservations.isBooked(
            canceled.getResourceID(),
            canceled.getReservationDate())) {
        cout << "Cannot undo: resource is booked for that date.\n";
        return;
    }

    // Restore first. Remove the history entry only afterward.
    reservations.insert(canceled);
    cancellationHistory.pop();

    cout << "Cancellation undone successfully.\n";
}


//Display all active reservations
void ReservationManager::displayReservations() {
    reservations.display();
}

void ReservationManager::displayCancellationHistory() const {
    cancellationHistory.displayHistory();
}
//check if resource ID is valid

