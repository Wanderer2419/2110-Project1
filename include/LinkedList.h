// Reservation Linked List header file
#include <iostream>
#include <string>
#include "Reservation.h"
using namespace std;

// Node structure for storing reservations
struct Node {
    string resID;
	Reservation resData;
    Node* next;

    Node(Reservation res);	// node Constructor
};

// LinkedList Class
class LinkedList {
	private:
		Node* head; // Pointer to the first node

	public:
		LinkedList();	// Basic Constructor
		~LinkedList();	// Linked List destructor

	    void pushFront(Reservation res);	// New head node insertion
	    void PushBack(Reservation res);		// New node at the end of the list

	    void display();		// Print all nodes in the list

	// Might need to change return type:
		void remove(string ID);	// Remove a node based on its reservation id
		void search(string ID);	// Search for a reservation
};
