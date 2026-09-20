#ifndef RESERVATIONMANAGER_H
#define RESERVATIONMANAGER_H

#include <string>
#include "Reservation.h"
#include "ReservationList.h"
#include "CancellationHistory.h"

using std::string;

class ReservationManager {
private:
    //node for linked list
    /*struct Node {
        Reservation reservation;
        Node* next;

        Node(Reservation r) {
            reservation = r;
            next = nullptr;     
        }*/
       CancellationHistory cancellationHistory;
       ReservationList reservations;
    

    //points to the first reservation in linked list
    //Node* head;

public:
    ReservationManager(); //constructor

    //create new reservation
    void createReservation(Reservation reservation);
    //cancel reservation using ID
    void cancelReservation(string reservationID);
    //displaying all active reservation
    void displayReservations();

    //if reservation ID exists alread
    bool reservationExists(string reservationID);
    //if a resource ID is valid
    bool validResource(string resourceID);

    void displayCancellationHistory() const;
};

#endif
