#ifndef RESERVATIONMANAGER_H
#define RESERVATIONMANAGER_H

#include <string>
#include "Reservation.h"
#include "ReservationList.h"

using std::string;

class ReservationManager {
private:
    //linked list of active reser.
    ReservationList reservations;

public:
    ReservationManager(); //constructor

    //create new reservation
    void createReservation(Reservation reservation);
    //cancel reservation using ID
    void cancelReservation(string reservationID);
    //displaying all active reservation
    void displayReservations();

    //if reservation ID exists already
    bool reservationExists(string reservationID);
    //if a resource ID is valid
    bool validResource(string resourceID);
};

#endif
