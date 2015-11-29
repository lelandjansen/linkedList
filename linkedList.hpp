// linkedList.hpp

#ifndef linkedList_hpp
#define linkedList_hpp

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "piArray.hpp"

// Single node in the linked list struct
typedef struct node_t {
    int item;
    struct node_t* previous;
    struct node_t* next;
} node_t;

typedef node_t* node;


// Linked list struct
typedef struct linkedList_t {
    node tail;
    node head;
    int length;
} linkedList_t;

typedef linkedList_t* linkedList;





// Functions



// Create new linked list
linkedList ll_create();



// Get the length of the linked list
int ll_length();

// Check that the linked list's length is correct (helpful for debugging)
bool ll_checkLength(linkedList list);




// Access the item stored in the head node
int ll_getHeadNodeItem(linkedList list);

// Access the item stored in the tail node
int ll_getTailNodeItem(linkedList list);


// Insert node at head of the linked list
void ll_insertNodeHead(linkedList list, int data);

// Insert node at the tail of the linked list
void ll_insertNodeTail(linkedList list, int data);

// Insert node to the linked list (tail to head)
void ll_insertNodeAscending(linkedList list, int data);

// Insert node to the linked list (head to tail)
void ll_insertNodeDescending(linkedList list, int data);



// Check to see if the linked list is sorted in ascending order
// Lowest to highest
bool ll_isSortedAscending(linkedList list);

// Check to see if the linked list is sorted in descending order
// Highest to lowest
bool ll_isSortedDescending(linkedList list);



// Locate the first node that contains "data" (tail to head)
node ll_findNodeAscending(linkedList list, int data);

// Locate the first node that contains "data" (head to tail)
node ll_findNodeDescending(linkedList list, int data);



// Print linked list in ascending order
void ll_printAscending(linkedList list);

// Print linked list in descending order
void ll_printDescending(linkedList list);



// Remove head node
void ll_removeNodeHead(linkedList list);

// Remove tail node
void ll_removeNodeTail(linkedList list);

// Remove first node containing data starting from tail
void ll_removeNode(linkedList list, node nodeToDelete);

// Destroy linked list
void ll_removeLinkedList(linkedList list);



#endif /* linkedList_hpp */
