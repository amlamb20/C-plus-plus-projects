// FILE: Haystack.cpp
// Austin Lamb, Transylvania University
// CS 2444, Fall 2017
//
//	Implementation: Haystack Class
//		Definition: A cluster of H's, N',s and ?'s.
//		H = Hay, N = Needle, ? = Path.
//
#include "Haystack.h"

//// constructor, destructor
Haystack::Haystack (void) { }
Haystack::~Haystack (void) { }

//// mutators

// read
//	Read the contents of a grid array from an open file
bool Haystack::read (ifstream& input) {
	
	// read dimensions and check not 0
	input >> size;

	if (!size) {
		return false;
	}

	rows = size;
	cols = size;

	// set grid array to all 0's
	clean ();

	// convert input to 0's, 1's, and 2's
	// 0: Hay, 1: Path, 2: Needle
	char temp;
	for (int r = 1; r <= rows; ++r) {
		for (int c = 1; c <= cols; ++c) {
			input >> temp;

			grid[r][c] = (temp == HAYCHAR? 0 : (temp == PATHCHAR? 1 : 2));
		}
	}
	
	return true;
}

// clean
//	Turn a grid into 0's
void Haystack::clean (void) {
	for (int r = 0; r < MAXHEIGHT; ++r) {
		for (int c = 0; c < MAXWIDTH; ++c) {
			grid [r][c] = 0;
		}
	}
}

// clearSpace
//	Turn a path character into a blank space,
//	leading to the needle
bool Haystack::clearSpace (int r, int c) {

	// 0: HAY
	 // 1: PATH/DEAD END
	  // 2: NEEDLE
	   // 3: FINAL PATH
	    // 4: POTENTIAL PATH

	// base case 1: a needle char is found
	if (grid [r][c] == 2) {
		return true;
	}

	// base case 1: it is not a path char
	if (grid [r][c] != 1) {
		return false;
	}

////
//// RECURSIVE CASE --- Clear a path to the needle.
////

	// Set it to "4" -- this is a potential path to the needle.
	grid[r][c] = 4;

	if (clearSpace (r-1, c)) {  // up
		grid[r][c] = 3;
		return true;
	}

	if (clearSpace (r, c+1)) { // right
		grid[r][c] = 3;
		return true;
	}

	if (clearSpace (r+1, c)) { // down
		grid[r][c] = 3;
		return true;
		
	}

	if (clearSpace (r, c-1)) { // left
		grid[r][c] = 3;
		return true;
	}
		
		// set it back to "1" -- this path is a dead end.
		grid[r][c] = 1;
		return false;
}

// findNeedle
//	Search for a path to a needle (public wrapper)
bool Haystack::findNeedle (void) {

	if (clearSpace (1,1)) {
		return true;
		
	}

	else {
		return false;
	}

}

// assignment operator
//	Copy "other" Haystack to "this" Haystack
Haystack& Haystack::operator= (const Haystack& other) {
	if (this == &other) {
		return *this;
	}

	rows = other.rows;
	cols = other.cols;

	for (int r = 0; r < rows+2; ++r) {
		for (int c = 0; c < cols+2; ++c) {
			grid[r][c] = other.grid[r][c];
		}
	}
	
	return *this;

}

// print
//	Print the contents of a Haystack grid
void Haystack::print (void) const {
	for (int r = 1; r <= rows; ++r) {
		for (int c = 1; c <= cols; ++c) {
			cout << char (grid[r][c] == 0? HAYCHAR : 
					grid[r][c] == 1? PATHCHAR :
			     		grid[r][c] == 2? NEEDLECHAR : BLANKCHAR) << " ";
		}
	cout << endl;
	}
}

// print v2
//	Print the contents of a Haystack grid to an output file
void Haystack::print (ofstream& output) const {
	for (int r = 1; r <= rows; ++r) {
		for (int c = 1; c <= cols; ++c) {
			output << char (grid[r][c] == 0? HAYCHAR : 
					grid[r][c] == 1? PATHCHAR :
			     		grid[r][c] == 2? NEEDLECHAR : BLANKCHAR) << " ";
		}
	output << endl;
	}
}


