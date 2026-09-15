// standard reservation header that describes a booking
#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>
using std::string; //helps us avoid confusing the compiler with keywords

class Reservation{
private:
    string reservation_ID;
    string student_ID;
    string student_Name;
    string resource_ID;
    string reservation_Date;
public:
    Reservation();
    //creating a constructor
    Reservation(string reservation_ID,
    string student_ID,
    string student_Name,
    string resource_ID,
    string reservation_Date);

    string getReservationID();
    string getStudentID();
    string getStudentName();
    string getResourceID();
    string getReservationDate();

};


#endif
