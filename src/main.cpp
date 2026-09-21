#include <iostream>
#include <string>
#include <limits>
#include "../include/ReservationManager.h"
#include "Resource.h"
#include "WaitingList.h"

using namespace std;
int main() {

    ReservationManager manager;
    WaitingList WaitList;
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
        cout << "7. Add Student to Waiting List\n";
        cout << "8. Remove First Waiting Student\n";
        cout << "9. Display Waiting List" << endl;
        cout << "10. Exit" << endl;
        

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

        // functionality to add a student to a waiting list
        // includes error handling to prevent the program from crashing
        else if (choice == 7) {
            

            string studentName;
            string resourceID;

                // Remove the newline left by reading the menu number.
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            //safely exit the program if no input
            cout << "Enter student name: ";
            if (!getline(cin, studentName)) {
                break;
            }
            // same for resource ID
            cout << "Enter resource ID: ";
            if (!getline(cin, resourceID)) {
                break;
            }

            // if either field is empty then it will trigger because of the or operator
            if (studentName.empty() || resourceID.empty()) {
                cout << "Name and resource ID cannot be blank.\n";
            }
            // otherwise we can add the information the user inputs
            else {
                WaitList.AddStudent(studentName + " | " + resourceID);
                cout << "Student added to waiting list.\n";
            }
            }
    else if (choice == 8) {
        WaitList.RemoveStudent();
    }

    else if (choice == 9) {
        //waiting list function
        WaitList.Display();
    }

    else if (choice == 10) {
        cout << "Goodbye!" << endl;
    }
    
    else {
            cout << "Choose an option from 1 through 10. \n";
    }

     } while (choice != 10);

    return 0;
}
