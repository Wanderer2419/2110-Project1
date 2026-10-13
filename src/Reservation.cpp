// Reservation implementation file
#include "Reservation.h"
#include <iostream>
using namespace std;

// Constructor
Reservation::Reservation(string ReservationID, string StudentID, string name, string ResourceID, string date) {
	Reservation_ID = ReservationID;
	Student_ID = StudentID;
	Student_Name = name;
	Resource_ID = ResourceID;
	Reservation_Date = date;
}

string Reservation::getReservationID() {
	return Reservation_ID;
}
string Reservation::getStudentID() {
	return Student_ID;
}
string Reservation::getStudentName() {
	return Student_Name;
}
string Reservation::getResourceID() {
	return Resource_ID;
}
string Reservation::getReservationDate() {
	return Reservation_Date;
}

// Display Reservation function
void Reservation::DisplayReservation() {
	//301|1001|Alice Smith|R101|09/15/2026
	cout << "Reservation ID: " << Reservation_ID << "|" << "Student ID: " << Student_ID << "|" 
	     << "Student Name: " << Student_Name << "|" << "Resources ID: " << Resource_ID 
		 << "|" << "Reservation Date: " << Reservation_Date << endl;
}
