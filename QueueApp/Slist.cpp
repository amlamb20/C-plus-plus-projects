// FILE: Slist.cpp
// Austin Lamb, Transylvania University
// CS 2444, Fall 2017
//
// Implementation: Singly Linked List
//
//	CLASS INVARIANTS:
//
//	* The head always points at the first node in the list.
//		* The head node always contains a garbage value in it's "data."
//		* The head node always exists until the list is desconstructed.
//	* The cursor always points at some node in the list.
//	* The tail always points at the last node in the list.
//		* The last node in the list must have a "next" of 0.
//
#include "Slist.h"
#include <iostream>
using namespace std;

//// public member functions

// constructor: Creates a new list.
Slist::Slist (void) {

	// Create the first node in the list. Point the head ptr at it.
	head = new Node;

	head -> next = 0;

	// Point the tail ptr and cursor ptr at the first node.
	tail = head;
	cursor = head;

}


// destructor: Delete an old list.
Slist::~Slist (void) {

	// Call "moveToFront" func, moves cursor ptr to front.
	moveToFront();

	// Call "remove" func in a while loop. Deletes all nodes.
	while (remove()) {}

	// delete first (head) node
	delete head;

}

// insert operation: Insert a new node in the list.
void Slist::insert (const DataType& newItem) {

	Node *temp;

	// allocate a new Node at temp, pass in the data
	temp = new Node;
	temp -> data = newItem;

	// put the Node in the list.
	if (cursor -> next == 0) {
		cursor -> next = temp;
		cursor -> next -> next = 0;
		tail = tail -> next;
	}

	else {
		temp -> next = cursor -> next;
		cursor -> next = temp;
	}

}

// remove operation: Remove a node from the list.
bool Slist::remove (void) {

	Node *victim;

	// set victim to Node after the one pointed at by cursor
	victim = cursor -> next;

	if (victim == 0) {
		return false;
	}

	// set cursor -> next to Node after victim Node.
	cursor -> next = cursor -> next -> next;
		delete victim;

	if (cursor -> next == 0) {
		tail = cursor;
	}

	return true;
}

// get operation: Retrieve a node from the list.
bool Slist::get (DataType& item) const {

	if (cursor -> next == 0) {
		return false;
	}

	item = cursor -> next -> data;
		return true;
}

// move operation: Move cursor one node down the list.
bool Slist::move (void) {

	if (cursor -> next == 0) {
		return false;
	}

	cursor = cursor -> next;
		return true;
}

// moveToFront: Move cursor to front of the list.
void Slist::moveToFront (void) {
	cursor = head;
}

// moveToBack: Move cursor to back of the list.
void Slist::moveToBack (void) {
	cursor = tail;
}

// printDEBUG
//    print the contents of the list to the screen
void Slist::printDEBUG (void) const {
	 for (Node *temp = head->next; temp; temp = temp->next) {
	       cout << temp -> data << ' ';
	   }
}

