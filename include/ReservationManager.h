// Reservation Manager header file
#ifndef RESERVATION_MANAGER_H
#define RESERVATION_MANAGER_H
#include <vector>
#include <fstream>
#include <string>
#include "Resource.h"
#include "Reservation.h"
#include "LinkedList.h"
#include "WaitingList.h"
#include "CancellationHistory.h"
using namespace std;



void loadResources();
void displayAllResources();
void SearchResources();

void loadReservations(LinkedList& active, int& nextID);
void createReservation(LinkedList& active, WaitingList& waiting, int& nextID);
void cancelReservation(LinkedList& active, WaitingList& waiting,
                       CancellationHistory& history, int& nextID);
void undoCancellation(LinkedList& active, CancellationHistory& history);
void sortResources();
void generateReport(LinkedList& active, WaitingList& waiting, CancellationHistory& history);


#endif

