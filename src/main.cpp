#include <iostream>
#include <string>
#include <limits>
#include "../include/ReservationManager.h"
#include "Resource.h"
#include "WaitingList.h"

using namespace std;
int main() {

    ReservationManager manager;
    int choice = 0;
    do {
        cout << "\n Campus Resource Reservation System" << endl;
        cout << "-------------------------------------" << endl;
        cout << "1. View Resources" << endl;
        cout << "2. Create Reservation" << endl;
        cout << "3. Cancel Reservation" << endl;
        cout << "4. Display Active Reservations" << endl;
        cout  << "5. Display Cancellation History" << endl;
        cout << "6. Undo Latest Cancellation" << endl;
        cout << "7. Display Waiting List" << endl;
        cout << "8. Exit" << endl;
        

        cout << "Enter your choice: ";

        //adding some error handling to reduce risk of a failed program.

        if(!(cin >> choice)) {
            if (cin.eof()) {
                break;
            }

            cin.clear();

            //clearing any unread characters in the buffer from limits in the header
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

            cout << "Enter a numeric menu option. \n";
            continue;
        }

        if (choice == 1) {
            Resource fileResources;

            fileResources.ReadFile();
            fileResources.DisplayResources();
        }

        else if (choice == 2) {
            string reservationID;
            string studentID;
            string studentName;
            string resourceID;
            string reservationDate;

            cout << "Enter reservation ID: ";
            cin >> reservationID;

            cout << "Enter student ID: ";
            cin >> studentID;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter student name: ";
            getline(cin, studentName);

            cout << "Enter resource ID: ";
            cin >> resourceID;

            cout << "Enter reservation date: ";
            cin >> reservationDate;
        
            //replaced semicolons with commas for syntax
            Reservation reservation(
                reservationID,
                studentID,
                studentName,
                resourceID,
                reservationDate
            );
            //adding the rest of do while loop functionality
        

            manager.createReservation(reservation);
         }
        else if (choice == 3) { 
            string reservationID;

            cout << "Enter reservation ID to cancel:";
            cin >> reservationID;

            manager.cancelReservation(reservationID);
        }

        else if (choice == 4) {
            manager.displayReservations();
        }

        else if (choice == 5){
            manager.displayCancellationHistory();
        }

        else if (choice == 6){
            manager.undoLastCancellation();
        }

        else if (choice == 7) {
        //waiting list function
        }

        else if (choice == 8) {
            cout << "Goodbye!" << endl;
        }
        
        else {
            cout << "Choose an option from 1 through 7. \n";
        }

     } while (choice != 8);

    





    return 0;
}
