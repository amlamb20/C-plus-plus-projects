// FILE: Rbt.h
// Austin Lamb, Transylvania University
// CS 2444, Fall 2017
//
//	Declarations and functions for Red-Black Tree (RBT) class.
//
#ifndef RBT_H
#define RBT_H

#include <iostream>
#include "DataType.h"
#include "Mp3.h"
using namespace std;

class Rbt {

public:

	// functions
	Rbt (void);
	~Rbt (void);

	bool put (const ValueType& newItem);
	bool get (const KeyType& searchKey, ValueType& foundItem) const;
	void printDEBUG (void) const;

private:
	
	// structures
	struct Node {
		ValueType data;
		Node *left;
		Node *right;
		bool isRed;
	};

	// functions
	bool put (Node*& root, const ValueType& newItem);
	bool get (Node *root, const KeyType& searchKey, ValueType& foundItem) const;
	void printNode (Node *pRoot) const;
	void kill (Node *root);
	void preOrder (Node *root) const;
	void split (Node*& root);
	void rebalance (Node*& root);

	// data
	Node* wholeTreeRoot;

};
#endif
