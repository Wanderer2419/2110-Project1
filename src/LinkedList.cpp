// Reservation Linked List implementation
#include "LinkedList.h"
#include "Reservation.h"
#include "ReservationManager.h"
#include <iostream>

using namespace std;

// Node struct
Node::Node(Reservation res) {
	ResData = res;
	resID = res.getReservationID();
	next = nullptr;
}

// Linked List class
LinkedList::LinkedList() {	// basic constructor
	head = nullptr;
}
LinkedList::~LinkedList() {	// destructor
	Node* current = head;
	while (current != nullptr) {
		Node* nextNode = current->next;
		delete current;
		current = nextNode;
	}
}

// Adding to the linked list
void LinkedList::pushFront(Reservation res) {
	Node* newNode = new Node(res);
	newNode->next = head;
	head = newNode;
}
void LinkedList::pushBack(Reservation res) {
	Node* newNode = new Node(res);
	if (head == nullptr) {
		head = newNode;
		return;
	}
	Node* temp = head;
	while (temp->next != nullptr) {
		temp = temp->next;
	}
	temp->next = newNode;
}

// Display function
void LinkedList::display() {
	Node* temp = head;
	while (temp != nullptr) {
		cout << temp->data << " -> ";
		temp = temp->next;
	}
}



// Remove a node from the linked list
void LinkedList::remove(string ID) {
	// Check if the list is empty:
	if (head == nullptr) {
		cout << "Error: The list is empty"
		return;
	}

	// Check the head for the value:
	if (head->resID == ID) {
		Node* temp = head;
		head = head->next;
		delete temp;
		return;
	}

	Node* current = head;
	Node* previous = nullptr;

	// Search the rest of the list for the value:
	while (current != nullptr && current->resID != ID) {
		previous = current;
		current = current->next;
	}
	// No corresponding ID value found:
	if (current == nullptr) {
		cout << "Error: ID " << ID << " not found in the list"
		return;
	}
	// Found ID value:
	previou->next = current->next;
	delete current;
}

// Search function
void LinkedList::search(string ID) {
	// Check if the list is empty:
	if (head == nullptr) {
		cout << "Error: The list is empty"
		return;
	}

	Node* current = head;
	
	// Check the list for the value:
	while (current != nullptr && current->resID != ID) {
		current = current->next;
	}
	// No corresponding ID value found:
	if (current == nullptr) {
		cout << "Error: ID " << ID << " not found in the list"
		return;
	}
	// Found ID value:
	cout << "ID " << ID << " found in the list:" << endl;
	cout << "\tReservation ID = " << current->resData.getReservationID() << endl;
	cout << "\tStudent ID = " << current->resData.getStudentID() << endl;
	cout << "\tStudent Name = " << current->resData.getStudentName() << endl;
	cout << "\tResource ID = " << current->resData.getResourceID() << endl;
	cout << "\tReservation Date = " << current->resData.getReservationDate() << endl;
}
