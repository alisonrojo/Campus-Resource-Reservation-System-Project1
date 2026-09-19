#include <iostream>
#include <string>
#include <limits>
#include "../include/ReservationManager.h"

using namespace std;
int main() {

    ReservationManager manager;
    int choice = 0;
    do {
        cout << "\n Campus Resource Reservation System" << endl;
        cout << "-------------------------------------" << endl;
        cout << "1. Create Reservation" << endl;
        cout << "2. Cancel Reservation" << endl;
        cout << "3. Display Active Reservations" << endl;
        cout << "4. Exit" << endl;
        cout  << "5. Display Cancellation History\n";

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
        else if (choice == 2) { 
            string reservationID;

            cout << "Enter reservation ID to cancel:";
            cin >> reservationID;

            manager.cancelReservation(reservationID);
        }

        else if (choice == 3) {
            manager.displayReservations();
        }

        else if (choice == 4){
            cout << "Goodbye. \n";
        }

        else if (choice == 5){
            manager.displayCancellationHistory();
        }

        else{
            cout << "Choose an option from 1 through 5. \n";
        }

     } while (choice != 4);

    





    return 0;
}
