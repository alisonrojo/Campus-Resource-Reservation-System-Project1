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
    Reservation(const string& inc_reservation_ID,
    const string& inc_student_ID,
    const string& inc_student_Name,
    const string& inc_resource_ID,
    const string& inc_reservation_Date);

    string getReservationID() const;
    string getStudentID() const;
    string getStudentName() const;
    string getResourceID() const;
    string getReservationDate() const;

};


#endif
