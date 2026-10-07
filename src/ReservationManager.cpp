#include "../include/ReservationManager.h"
#include <iostream>
#include <vector>
#include <cctype> //using tolower()
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
//search for a reservation by reservation ID
void ReservationManager::searchReservation(string reservationID) {
    Reservation foundReservation;

    if (reservations.find(reservationID, foundReservation)) {
        cout << "\nReservation Found:" << endl;

        cout << "Reservation ID: "
             << foundReservation.getReservationID() << endl;

        cout << "Student ID: "
             << foundReservation.getStudentID() << endl;

        cout << "Student Name: "
             << foundReservation.getStudentName() << endl;

        cout << "Resource ID: "
             << foundReservation.getResourceID() << endl;

        cout << "Reservation Date: "
             << foundReservation.getReservationDate() << endl;
       
    }
    else {
         cout << "\nReservation not found." << endl;
    }
}
void ReservationManager::displayCancellationHistory() const {
    cancellationHistory.displayHistory();
}
// to help with the case-insensitive requirement we can floor the characters
// by removing the upper case before sorting
static string toLower(const string& text) {

    string result = text;
    for (size_t i = 0; i < result.size(); i++){
        result[i] = (char)tolower((unsigned char) result[i]);

    }
    return result;
}
static void swapReservations(Reservation& a, Reservation& b){
    Reservation temp = a;
    a = b;
    b = temp;

}
static void quickSortByStudentName(vector<Reservation>& items, int low, int high) {
    if(low >= high) return;

    int mid = low +(high - low) / 2;
    swapReservations(items[mid], items[high]);  // setting the middle pivot to the end
    string pivot = toLower(items[high].getStudentName());

    int boundary = low; // everything to the left of the pivot 
    for(int i = low; i < high; i++){
        if(toLower(items[i].getStudentName()) < pivot) {
            swapReservations(items[i], items[boundary]);
            boundary++;
        }
    }
    swapReservations(items[boundary], items[high]);

    quickSortByStudentName(items, low, boundary - 1);
    quickSortByStudentName(items, boundary + 1, high);

}

void ReservationManager::displaySortedByStudentName() const {
    vector<Reservation> sorted;
    reservations.toVector(sorted);

    if (sorted.empty()) {
        cout << "No reservation to sort. \n";
        return;
    }

    quickSortByStudentName(sorted, 0, (int)sorted.size() - 1);

    cout << "\nReservations sorted by student name (A-Z): \n";
    for (size_t i = 0; i < sorted.size(); i++){
        cout << "Reservation ID: " << sorted[i].getReservationID() << endl;
        cout << "Student ID: " << sorted[i].getStudentID() << endl;
        cout << "Student Name: " << sorted[i].getStudentName() << endl;
        cout << "Resource ID: " << sorted[i].getResourceID() << endl;
        cout << "Reservation Date:" << sorted[i].getReservationDate() << endl << endl;
    }
}

