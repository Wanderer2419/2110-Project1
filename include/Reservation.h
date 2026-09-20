// Reservation header file
// Resource header file
#ifndef RESERVATION_H
#define RESERVATION_H
#include <string>
#include <vector>
using namespace std

class Reservation {
    private:
        string Reservation_ID;
        string Student_ID;
        string Student_Name;
        string Resource_ID;
		string Reservation_Date
    public:
        // Constructor
        Reservation(string ResrvationID, string StudentID, string name, string ResourceID, string date);

        string getReservationID();
		string getStudentID();
        string getStudentName();
        string getResourceID();
        string getReservationDate();

		// Display reservations
		void DisplayReservation();
};
#endif
