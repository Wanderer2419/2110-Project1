// Main source code
#include <iostream>
#include "Resource.h"
#include "ReservationManager.h"
#include "Reservation.h"
#include <fstream>
#include <string>
#include "LinkedList.h"
#include "WaitingList.h"
#include "CancellationHistory.h"
#include <limits>
using namespace std;

int main() {
    // Front

    std::cout << "===== Campus Resource Reservation System =====" << std::endl;
    std::cout << "1.View Resources" << std::endl;
    std::cout << "2.Create Reservation" << std::endl;
    std::cout << "3.Cancel Reservation" << std::endl;
    std::cout << "4.View Waiting Lists" << std::endl;
    std::cout << "5.Undo Cancellation" << std::endl;
    std::cout << "6.Search Reservations" << std::endl;
    std::cout << "7.Sort Resources" << std::endl;
    std::cout << "8.Generate Report" << std::endl;
    std::cout << "9.Exit" << std::endl;
    LinkedList active;             
    WaitingList waiting;           
    CancellationHistory history;   
    int nextID = 301;             

    loadResources();
    loadReservations(active, nextID);

    int choice = 0;
    while(choice != 9) {
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch(choice) {
        case 1:
            
            displayAllResources();
            break;
        case 2:
            createReservation(active, waiting, nextID);
            break;
        case 3:
             cancelReservation(active, waiting, history, nextID);
            break;
        case 4:
            waiting.displayAll();
            break;
        case 5:
            undoCancellation(active, history);
            break;
        case 6:
            
            SearchResources();
            break;
        case 7:
            sortResources();
            break;
        case 8:
            generateReport(active, waiting, history);
            break;
        case 9:
            std::cout << "Exit" << std::endl;
            break;
        default:
            std::cout << "Not in option" << std::endl;
            break;
        }
    }
    return 0;
}
