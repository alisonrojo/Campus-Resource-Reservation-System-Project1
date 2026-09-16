#ifndef RESERVATIONMANAGER_H
#define RESERVATIONMANAGER_H

#include <string>
#include "Reservation.h"

using std::string;

class ReservationManager {
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
    bool validResourc(string resourceID);
};

#endif
