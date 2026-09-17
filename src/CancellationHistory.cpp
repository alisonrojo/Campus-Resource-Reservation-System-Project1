#include "../include/CancellationHistory.h"
#include <iostream>

CancellationHistory::CancellationHistory(){
    //no nodes for the clear stack
    top = nullptr;
}

CancellationHistory::~CancellationHistory(){
    
    clear();
}

bool CancellationHistory::isEmpty()const{

    //if there is no top then there are no saved cancellations
    return top == nullptr;
}

void CancellationHistory::push(const Reservation& reservation) {

    //here we create a node with it's own copy of a reservation and link it to the previous top
    Node* newNode = new Node{reservation, top};

    // newest cancellation becomes the newest entry
    top = newNode;
}

bool CancellationHistory::peek(Reservation& outputReservation) const{
    if (isEmpty()) {
        // leave output unchanged if empty
        return false;
    }

        
    outputReservation = top->reservation;
    return true;
}

bool CancellationHistory::pop() {
    if(isEmpty()) {
        return false;
        //no node to remove
    }
    // saving the nodes address so it can be deleted after moving to the top
    Node* oldTop = top;

    // the next oldest becomes the top
    top = top->next;

    //Release the memory from the node we removed
    delete oldTop;

    return true;
}

void CancellationHistory::displayHistory() const {

    if (isEmpty()){
        std::cout << "No cancellation history.\n";
        return;
    }
    //here the stack will be traversed with a separate pointer so the top stays unchanged
    const Node* current = top;

    while(current != nullptr) {

        const Reservation& reservation = current->reservation;
        //use all of our getter methods to get info
        std::cout
            << "Reservation ID: " << reservation.getReservationID() << '\n'
            << "Student ID: " << reservation.getStudentID() << '\n'
            << "Student Name: " << reservation.getStudentName() << '\n'
            << "Resource ID: " << reservation.getResourceID() << '\n'
            << "Reservation Date: " << reservation.getReservationDate() << '\n'
            << "\n\n";

            current = current->next;
    }
}

void CancellationHistory::clear() {

    while (!isEmpty()){
        pop();
    }
}

