// Main source code
#include <iostream>
#include "Resource.h"
#include "ReservationManager.h"
#include "Reservation.h"
#include <fstream>
#include <string>

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


    int choice = 0;
    while(choice != 9) {
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch(choice) {
        case 1:
            loadResources();
            displayAllResources();
            break;
        case 2:
            std::cout << "Need to work" << std::endl;
            break;
        case 3:
            std::cout << "Need to work" << std::endl;
            break;
        case 4:
            std::cout << "Need to work" << std::endl;
            break;
        case 5:
            std::cout << "Need to work" << std::endl;
            break;
        case 6:
            loadResources();
            SearchResources();
            break;
        case 7:
            std::cout << "Need to work" << std::endl;
            break;
        case 8:
            std::cout << "Need to work" << std::endl;
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
