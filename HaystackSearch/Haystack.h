// FILE: Haystack.h
// Austin Lamb, Transylvania University
// CS 2444, Fall 2017
//
//	Declarations and functions for Haystack class
//
#ifndef HAYSTACK_H
#define HAYSTACK_H

#include <iostream>
#include <fstream>
using namespace std;

class Haystack {
	
public:

	//// public member functions

	Haystack (void);
	~Haystack (void);

	bool read (ifstream& input);	// mutators
	void clean (void);
	bool findNeedle (void);
	Haystack& operator= (const Haystack& other);

	void print (void) const;		// accessors
	void print (ofstream& output) const;
private:

	bool clearSpace (int r, int c);

		//// private data
		// constants
		enum {	MAXWIDTH = 100,
				MAXHEIGHT = 100,
				HAYCHAR = 'H',
				PATHCHAR = '?',
				NEEDLECHAR = 'N',
				BLANKCHAR = ' '
			};

		// variables
		int grid [MAXHEIGHT][MAXWIDTH];
		int size, rows, cols;

};

#endif
