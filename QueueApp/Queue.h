// FILE: Queue.h
// Austin Lamb, Transy U
// CS 2444, Fall 2017
//
//	Interface: Queue Class
//
#ifndef QUEUE_H
#define QUEUE_H

#include <string>
#include "Slist.h"
using namespace std;
typedef string DataType;

class Queue {
public:

///// constructor, destructor /////
	Queue (void);
	~Queue (void);

// mutators

	void put (const DataType& item);
		// POSTCOND: <item> is put at the back of Queue.

	bool get (DataType& item);
		// POSTCOND: <item> contains item that was at front of Queue.

// accessors

	void printDEBUG (void) const;
		// POSTCOND: Queue contents are printed to the screen.

private:
//// private data
		Slist s;
};

#endif

