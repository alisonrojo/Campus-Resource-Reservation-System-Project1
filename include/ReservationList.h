#ifndef RESERVATIONLIST_H
#define RESERVATIONLIST_H

#include "Reservation.h"
#include <string>
#include <vector>

using std::string;

class ReservationList {
private:
    struct Node {
        Reservation reservation;
        Node* next;

        Node(Reservation r) {
            reservation = r;
            next = nullptr;
        }
    };

    //points to first node
    Node* head;

public:
    //constructor
    ReservationList();
    //destructor
    ~ReservationList();
    //add reservation to list
    void insert(Reservation reservation);
    //remove reservation
    bool remove(string reservationID);
    //search for reserID
    bool search(string reservationID);
    //display all reser
    void display();
    bool find(const string& reservationID, Reservation& outputReservation) const;
    
    bool isBooked(const string& resourceID, const string& date) const;

    //copies every reservation into a vector (used for sorting)
    void toVector(std::vector<Reservation>& out) const;
};

#endif

