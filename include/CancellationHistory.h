//important to keep in mind the lifo structure of a stack

#ifndef CANCELLATIONHISTORY_H
#define CANCELLATIONHISTORY_H

#include "Reservation.h"
class CancellationHistory{
private:
    struct Node{
        // each node ehre will store a canceled reservation and a link to an 'older' cancellation
        Reservation reservation;
        Node* next;
    };
    // node top points us to the newest cancellation
    Node* top;

public:
CancellationHistory();
~CancellationHistory();

//To prevent stacks from owning the same nodes

CancellationHistory(const CancellationHistory&) = delete;
CancellationHistory& operator=(const CancellationHistory&) = delete;

// using various standard stack methods to operate the cancellation menu

bool isEmpty() const;
void push(const Reservation& reservation);
bool peek(Reservation& outputReservation) const;
// returns false if empty otherwise we remove the newest cancellation
bool pop();
// this will display cancellations in order from newest to oldest
void displayHistory() const;

//remove all nodes and empty our stack
void clear();

};



#endif