// FILE: Queue.cpp
// Austin Lamb, Transy U
// CS 2444, Fall 2017
//
//	Implemenation: Queue Class
//	
//	CLASS INVARIANTS:
//		- Cursor in private Slist always points at empty head node.
//
#include "Queue.h"

//// constructor, destructor
Queue::Queue (void) {}
Queue::~Queue (void) {}

//// mutators ////

// put
//		Put new item at back of Queue
void Queue::put (const DataType& item) {
	s.moveToBack ();
	s.insert (item);
}

// get
//		Get item from the front of Queue
bool Queue::get (DataType& item) {
	s.moveToFront ();

		if (!s.get (item)) {
			return false;
		}
		
		s.remove ();
			return true;
}

// printDEBUG
//		Print the contents of the Queue
void Queue::printDEBUG (void) const {
	s.printDEBUG ();
}