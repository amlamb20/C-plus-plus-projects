// FILE: Rbt.cpp
// Austin Lamb, Transylvania University
// CS 2444, Fall 2017
//
//	Implementation: Rbt Class
//
#include "Rbt.h"

// Comment next line out to turn Debugging off.
#define DB

// constructor
Rbt::Rbt (void) {
	wholeTreeRoot = 0;
}

// destructor
Rbt::~Rbt (void) {
	kill (wholeTreeRoot);
}

// put (pubWrapper)
bool Rbt::put (const ValueType& newItem) {
    
    bool rtnVal = put (wholeTreeRoot, newItem);
    wholeTreeRoot -> isRed = false;
    return rtnVal;

}

// put
//	put a new item in the RBT
bool Rbt::put (Node*& root, const ValueType& newItem) {

// BASE CASES:
	// if root is 0, create a new Node
	if (root == 0) {
		root = new Node;

		root -> isRed = 1;
		root -> data = newItem;
		root -> left = 0;
		root -> right = 0;

		return true;
	}

	// if item is equal to root, return false
	if (newItem == root -> data) {
		return false;
	}

	// if a red box is full, split
	if ((root -> left) && (root -> left -> isRed == 1) && 
		(root -> right) && (root -> right -> isRed == 1)) {

			split (root);
		
	}

// RECURSIVE CASES:
	// Compare value to root, move accordingly.

	bool retVal;

	if (newItem < root -> data) {
			retVal = put (root -> left, newItem);
	}
		
		else {
			retVal = put (root -> right, newItem);
		}

	// See if the tree needs rebalancing.
	rebalance (root);

	return retVal;
	
}

// split
//	split the tree, sending middle node1 back to parent and making children black nodes
void Rbt::split (Node*& root) {
	root -> isRed = 1;
	root -> left -> isRed = 0;
	root -> right -> isRed = 0;

	#ifdef DB
	cout << endl << "Split a node." << endl;
	#endif

}

// rebalance
//	rebalance the tree if there are two red childen in a row.
void Rbt::rebalance (Node*& root) {

	Node *temp;

	// CASE 1 (root -> left -> left):
	if  ((root -> left) && (root -> left -> isRed) && 
		(root -> left -> left) && (root -> left -> left -> isRed)) {

		temp = root;
		root = temp -> left;
		temp -> left = root -> right;
		root -> right = temp;

		root -> isRed = 0;
		root -> right -> isRed = 1;

		#ifdef DB
		cout << endl << "Rebalanced a case 1 node." << endl;
		#endif

		return;

	}

	// CASE 2 (root -> left -> right):
	if	((root -> left) && (root -> left -> isRed) && 
		(root -> left -> right) && (root -> left -> right -> isRed)) {

		temp = root;
		root = temp -> left -> right;
		temp -> left -> right = root -> left;
		root -> left = temp -> left;
		temp -> left = root -> right;
		root -> right = temp;

		root -> isRed = 0;
		root -> right -> isRed = 1;

		#ifdef DB
		cout << endl << "Rebalanced a case 2 node." << endl;
		#endif

		return;

	}

	// CASE 3 (root -> right -> left):
	if	((root -> right) && (root -> right -> isRed) && 
		(root -> right -> left) && (root -> right -> left -> isRed)) {

		temp = root;
		root = temp -> right -> left;
		temp -> right -> left = root -> right;
		root -> right = temp -> right;
		temp -> right = root -> left;
		root -> left = temp;

		root -> isRed = 0;
		root -> left -> isRed = 1;

		#ifdef DB
		cout << endl << "Rebalanced a case 3 node." << endl;
		#endif

		return;

	}

	// CASE 4 (root -> right -> right):
	if	((root -> right) && (root -> right -> isRed == 1) &&
		(root -> right -> right) && (root -> right -> right -> isRed == 1)) {

		temp = root;
		root = temp -> right;
		temp -> right = root -> left;
		root -> left = temp;

		root -> isRed = 0;
		root -> left -> isRed = 1;

		#ifdef DB
		cout << endl << "Rebalanced a case 4 node." << endl;
		#endif

		return;

	}
}

// get (pubWrapper)
bool Rbt::get (const KeyType& searchKey, ValueType& foundItem) const {
	return get (wholeTreeRoot, searchKey, foundItem);
}

// get
//	get an item from the Rbt
bool Rbt::get (Node *root, const KeyType& searchKey, ValueType& foundItem) const {


// BASE CASES:
	// if root is 0, return false
	if (root == 0) {
		return false;
	}
	
	// if item is found, return true
	if (searchKey == root -> data) {
		foundItem = root -> data;
		return true;
	}

// RECURSIVE CASES:
	// Compare value to root, move accordingly
	if (searchKey < root -> data) {
		return get (root -> left, searchKey, foundItem);
	}

		else {
			return get (root -> right, searchKey, foundItem);
	}
	
}

// kill
//	delete a Node from the list
void Rbt::kill (Node *root) {

// BASE CASES:
	if (!root) {
		return;
	}

// RECURSIVE CASES:
	kill (root -> left);
	kill (root -> right);

	delete root;

}

// printNode
//	print out a Node

void Rbt::printNode (Node *pRoot) const {
#ifndef DB
	//cout << pRoot -> data << ' ';
#else
	cout << endl << "data: " << pRoot -> data << ". ";
	
		// Node color:
			if (pRoot -> isRed) {
				cout << "[RED]";
			}
			else {
				cout << "[BLK]";
			}

	cout << endl << "\tleft: ";
	if (pRoot -> left) {
		cout << pRoot -> left -> data << ". ";

		// Node color:
			if (pRoot -> left -> isRed) {
				cout << "[RED]";
			}
			else {
				cout << "[BLK]";
			}
	}
	else {
		cout << "[EXTERNAL]";
	}

	cout << endl << "\tright: ";
	if (pRoot -> right) {
		cout << pRoot -> right -> data << ". ";

		// Node color:
			if (pRoot -> right -> isRed) {
				cout << "[RED]";
			}
			else {
				cout << "[BLK]";
			}

	}
	else {
		cout << "[EXTERNAL]";
	}

	cout << endl;

#endif
}

// printDEBUG
//	do some debugging, print out the entire tree of nodes
void Rbt::printDEBUG (void) const {
	preOrder (wholeTreeRoot);
}

// preOrder
//	print out the Node as soon as it is visited, then approach
//	it's child nodes
void Rbt::preOrder (Node *root) const {

	if (root == 0) {
		return;
	}

	printNode (root);

	preOrder (root -> left);
	preOrder (root -> right);
}

