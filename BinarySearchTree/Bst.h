// FILE: Bst.h
// Austin Lamb, Transylvania University
// CS 2444, Fall 2017
//
//	Declarations and functions for Binary Search Tree (BST) class.
//
#ifndef BST_H
#define BST_H

#include <iostream>
#include "DataType.h"
#include "Mp3.h"
using namespace std;

class Bst {

public:

	// functions
	Bst (void);
	~Bst (void);

	bool put (const ValueType& newItem);
	bool get (const KeyType& searchKey, ValueType& foundItem) const;
	void printDEBUG (void) const;

private:
	
	// structures
	struct Node {
		ValueType data;
		Node *left;
		Node *right;
	};

	// functions
	bool put (Node*& root, const ValueType& newItem);
	bool get (Node *root, const KeyType& searchKey, ValueType& foundItem) const;
	void printNode (Node *pRoot) const;
	void kill (Node *root);
	void preOrder (Node *root) const;

	// data
	Node* wholeTreeRoot;

};
#endif
