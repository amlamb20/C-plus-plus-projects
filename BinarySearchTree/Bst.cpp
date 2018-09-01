// FILE: Bst.cpp
// Austin Lamb, Transylvania University
// CS 2444, Fall 2017
//
//	Implementation: Bst Class
//
#include "Bst.h"

// constructor
Bst::Bst (void) {
	wholeTreeRoot = 0;
}

// destructor
Bst::~Bst (void) {
	kill (wholeTreeRoot);
}

// put (pubWrapper)
bool Bst::put (const ValueType& newItem) {
	return put (wholeTreeRoot, newItem);
}

// put
//	put a new item in the BST
bool Bst::put (Node*& root, const ValueType& newItem) {
	
// BASE CASES:
	// if root is 0, create a new Node
	if (root == 0) {
		root = new Node;
		root -> data = newItem;

		root -> left = 0;
		root -> right = 0;

		return true;
	}

	// if item is equal to root, return false
	if (newItem == root -> data) {
		return false;
	}

// RECURSIVE CASES:
	// Compare value to root, move accordingly
	if (newItem < root -> data) {
		return put (root -> left, newItem);
	}
		
		else {
			return put (root -> right, newItem);
		}

}
		
		
// get (pubWrapper)
bool Bst::get (const KeyType& searchKey, ValueType& foundItem) const {
	return get (wholeTreeRoot, searchKey, foundItem);
}

// get
//	get an item from the BST
bool Bst::get (Node *root, const KeyType& searchKey, ValueType& foundItem) const {


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
void Bst::kill (Node *root) {

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

// Comment next line out to turn Debugging off.
#define DB
void Bst::printNode (Node *pRoot) const {
#ifndef DB
	//cout << pRoot -> data << ' ';
#else
	cout << endl << "data: " << pRoot -> data;
	cout << endl << "\tleft: ";
	if (pRoot -> left) {
		cout << pRoot -> left -> data;
	}
	else {
		cout << "[EXTERNAL]";
	}

	cout << endl << "\tright: ";
	if (pRoot -> right) {
		cout << pRoot -> right -> data;
	}
	else {
		cout << "[EXTERNAL]";
	}
	cout << endl;
#endif
}

// printDEBUG
//	do some debugging, print out the entire tree of nodes
void Bst::printDEBUG (void) const {
	preOrder (wholeTreeRoot);
}

// preOrder
//	print out the Node as soon as it is visited, then approach
//	it's child nodes
void Bst::preOrder (Node *root) const {

	if (root == 0) {
		return;
	}

	printNode (root);

	preOrder (root -> left);
	preOrder (root -> right);
}




