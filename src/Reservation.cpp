// cpp file matching the constructors in the header file
#include  "../include/Reservation.h"


Reservation::Reservation(){}

Reservation::Reservation(
    const string& inc_reservation_ID,
    const string& inc_student_ID,
    const string& inc_student_name,
    const string& inc_resource_ID,
    const string& inc_reservation_Date
) {
    reservation_ID = inc_reservation_ID;
    student_ID = inc_student_ID;
    student_Name = inc_student_name;
    resource_ID = inc_resource_ID;
    reservation_Date = inc_reservation_Date;
}

string Reservation::getReservationID() const{
    return reservation_ID;
}

string Reservation::getStudentID() const{
    return student_ID;
}

string Reservation::getStudentName() const {
    return student_Name;
}

string Reservation::getResourceID() const{
    return resource_ID;
}
string Reservation::getReservationDate() const{
    return reservation_Date;
}