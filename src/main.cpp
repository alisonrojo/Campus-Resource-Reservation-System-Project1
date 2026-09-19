#include <iostream>
#include <string>

using namespace std;
int main() {

    ReservationManager manager;
    int choice;
    do {
        cout << "\n Campus Resource Reservation System" << endl;
        cout << "-------------------------------------" << endl;
        cout << "1. Create Reservation" << endl;
        cout << "2. Cancel Reservation" << endl;
        cout << "3. Display Active Reservations" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

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

            cin.ignore();

            cout << "Enter student name: ";
            getline(cin, studentName);

            cout << "Enter resource ID: ";
            cin >> resourceID;

            cout << "Enter reservation date: ";
            cin >> reservationDate;

            Reservation reservation(
                reservationID;
                studentID;
                studentName;
                resourceID;
                reservationDate;
            );

            manager.createReservation(reservation);
         }
     }
    





    return 0;
}
