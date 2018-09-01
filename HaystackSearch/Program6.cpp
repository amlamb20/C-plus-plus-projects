// FILE: Program6.cpp
// Austin Lamb, Transylvania University
// CS 2444, Fall 2017
//
//	Find the figurative needle in a haystack using recursive searching methods!
//	Read in contents of a Haystack into a grid and write the solved matrix to a file.
//
#include <iostream>
#include <fstream>
#include "Haystack.h"
using namespace std;

////
///	Main Program
//
int main (void) {
	ifstream inFile ("inHayStack.txt");
	Haystack hayStack, hayStackBackUp;

	// Read in contents of the Haystack into a grid.
	hayStack.read (inFile);
	hayStackBackUp = hayStack;
	
	cout << endl << "Here's the haystack:" << endl;
	hayStackBackUp.print ();
	cout << endl;

	if (hayStack.findNeedle()) {
	
		// Write the solved Haystack to an output file.
		ofstream outFile;
		outFile.open("outHaystack.txt");
		hayStack.print(outFile);
		outFile.close();

		cout << "Found a needle!" << endl;
		hayStack.print ();

	}
	else {
		cout << "No needle found!" << endl;
	}
	
	cout << endl << endl << "Done." << endl;

}



