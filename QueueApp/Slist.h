// FILE: Slist.h
// Austin Lamb, Transy U
// CS 2444, Fall 2017
//
//     Interface: singly linked list
//
#ifndef    SLIST_H
#define    SLIST_H

// (uncomment for inclusion of extra credit functions)
//#define P4A
//#define P4B

// set up the data type to be held in the list
#include <string>
using namespace std;
typedef string DataType;

class Slist {
public:
// public member functions:    
    
///// constructor, destructor /////
    
    Slist (void);
         // postcondition: empty list set up, all class invariants hold                    

    ~Slist (void);
         // postcondition: all dynamically allocated storage is deleted                                    

///// mutators /////
                                        
    void insert (const DataType& newItem);
         // precondition: cursor pts at node that will precede new node
         // postcondition: node with newItem follows cursor node
         
    bool remove (void);
         // precondition: cursor pts at node that precedes the victim
         // postcondition: victim removed and deleted
         
    bool move (void);
         // postcondition: cursor pts one node further down the list
         
    void moveToBack (void);
         // postcondition: cursor pts at last node in the list
         
    void moveToFront (void);
         // postcondition: cursor pts at first node in the list

#ifdef P4A
    bool append (const Slist& other);
         // postcondition: other list is appended to end of this list;
         //                   cursor position in this list NOT preserved
         
    bool rotate (unsigned n);
         // postcondition: nodes have been rotated from front of this list to the back
         //                   n times; order among rotated nodes is preserved
#endif
#ifdef P4B
    bool truncate (const DataType& item);
         // postcondition: nodes that were at 1st occurrence of item and beyond are gone
         
    bool reverse (void);
         // postcondition: list is backwards, relative to its state at entry
#endif

///// accessors /////
    
    bool get (DataType& item) const;
         // precondition: cursor precedes item to retrieve
         // postcondition: item holds data value from node following cursor node
         
    void printDEBUG (void) const;
         // postcondition: data values contained in list are printed to screen


private:
// private data type: Node

    struct Node {
         DataType    data;
         Node        *next;
    };

// state variables:

    Node *head, *tail, *cursor;

};
#endif
