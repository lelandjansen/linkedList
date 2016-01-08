// linkedList.cpp

#include "linkedList.hpp"





// Create new linked list
linkedList ll_create() {
  // Create new linked list "list" and allocate enough space in memory
  linkedList list = (linkedList)malloc(sizeof(linkedList_t));
  // Abort the program if the linked list could not be created
  assert(list != NULL);

  // Assign the list's tail and head to NULL
  list->tail = NULL;
  list->head = NULL;

  // Set the list's length to zero;
  list->length = 0;

  // Return a pointer to the new linked list
  return list;

} // End of ll_create





// Get the length of the linked list
int ll_length(linkedList list) {
  return list->length;
} // End of ll_length





// Check that the linked list's length is correct (helpful for debugging)
bool ll_checkLength(linkedList list) {

  // Initialize ascending and descending length counters
  int lengthCountAscending  = 0;
  int lengthCountDescending = 0;

  // Initialize a node "currentNode"
  node currentNode;


  // Traverse the link in ascending order

  // Start currentNode at the tail of the linked list
  currentNode = list->tail;
  // Loop through the entire linked list
  while (currentNode != NULL) {
    // Increment the ascending counter
    lengthCountAscending++;
    // Move currentNode to the next node
    currentNode = currentNode->next;
  }


  // Traverse the link in descending order

  // Start currentNode at the head of the linked list
  currentNode = list->head;
  // Loop through the entire linked list
  while (currentNode != NULL) {
    // Increment the descending counter
    lengthCountDescending++;
    // Move currentNode to the previous node
    currentNode = currentNode->previous;
  }

  // If the list's length, lengthCountAscending, and lengthCountDescending
  // are equivalent
  if (list->length == lengthCountAscending && list->length == lengthCountDescending) {
    // The list's length is correct
    return true;
  }
  // Otherwise
  else {
    // The list's length is incorrect
    return false;
  }

} // End of ll_checkLength





// Access the item stored in the head node
int ll_getHeadNodeItem(linkedList list) {
  return list->head->item;
} // End of ll_getHeadNodeItem





// Access the item stored in the tail node
int ll_getTailNodeItem(linkedList list) {
  return list->tail->item;
} // End of ll_getTailNodeItem





// Insert node at head of the linked list
void ll_insertNodeHead(linkedList list, int data) {
  // Create new node "newNode" and allocate enough space in memory
  node newNode = (node)malloc(sizeof(node_t));
  // Abort the program if the linked list could not be created
  assert(newNode != NULL);

  // Assign newNode's item to data
  newNode->item = data;

  // If the list does not have any nodes
  if (list->length == 0) {
    newNode->previous = NULL;
    newNode->next = NULL;
    list->head = newNode;
    list->tail = newNode;
  }
  // If the list has at least one node
  else {
    newNode->previous = list->head;
    newNode->next = NULL;
    list->head->next = newNode;
    list->head = newNode;
  }

  // Increment the list's length
  list->length++;

} // End of ll_insertNodeHead





// Insert node at tail of the linked list
void ll_insertNodeTail(linkedList list, int data) {
  // Create new node "newNode" and allocate enough space in memory
  node newNode = (node)malloc(sizeof(node_t));
  // Abort the program if the linked list could not be created
  assert(newNode != NULL);

  // Assign newNode's item to data
  newNode->item = data;

  // If the list does not have any nodes
  if (list->length == 0) {
    newNode->previous = NULL;
    newNode->next = NULL;
    list->head = newNode;
    list->tail = newNode;
  }
  // If the list has at least one node
  else {
    newNode->previous = NULL;
    newNode->next = list->tail;
    list->tail->previous = newNode;
    list->tail = newNode;
  }

  // Increment the list's length
  list->length++;

} // End of ll_insertNodeTail





// Check to see if the linked list is sorted in ascending order (low to high)
bool ll_isSortedAscending(linkedList list) {

  // If the list has zero or one nodes
  if (list->length == 0 || list->length == 1) {
    return true;
  }

  // Set the current node to the tail of the list
  node currentNode = list->tail;

  // Loop through the entire linked list
  while (currentNode != NULL) {
    // If the current node's item is greater than or equal to the next node's item
    if (currentNode->item >= currentNode->previous->item) {
      // Advance to the next node
      currentNode = currentNode->next;
    }
    else {
      return false;
    }
  }

  return true;

} // End of ll_isSortedAscending





// Check to see if the linked list is sorted in descending order (high to low)
bool ll_isSortedDescending(linkedList list) {

  // If the list has zero or one nodes
  if (list->length == 0 || list->length == 1) {
    return true;
  }

  // Set the current node to the head of the list
  node currentNode = list->head;

  // Loop through the entire linked list
  while (currentNode != NULL) {
    // If the current node's item is greater than or equal to the next node's item
    if (currentNode->item >= currentNode->next->item) {
      // Advance to the previous node
      currentNode = currentNode->previous;
    }
    else {
      return false;
    }
  }

  return true;

} // End of ll_isSortedDescending





// Insert node in list
// Assumes that list is sorted from least to greatest value
void ll_insertNodeAscending(linkedList list, int data) {

  // Create new node and allocate space
  node newNode = (node)malloc(sizeof(node_t));
  assert(newNode != NULL);

  // Assign data to the node's item
  newNode->item = data;

  // If the linked list is empty
  if (list->length == 0) {
    newNode->previous = NULL;
    newNode->next     = NULL;
    list->head        = newNode;
    list->tail        = newNode;
    list->length++;
  }
  else {
    node currentNode, nextNode;

    currentNode = list->tail;
    nextNode = currentNode->next;

    // Loop through the entire linked list
    while (currentNode != NULL) {
      // If the current node's item is less than or equal to the tail's item
      if (currentNode == list->tail && newNode->item <= currentNode->item) {
        // insert node at tail of list
        ll_insertNodeTail(list, data);
        break;
      }
      // If the current node's item is greater than the head's item
      else if (currentNode == list->head && newNode->item > currentNode->item) {
        // insert node at end of list
        ll_insertNodeHead(list, data);
        break;
      }
      // If insertion is in the middle of the linked list
      else if (newNode->item >= currentNode->item && newNode->item <= nextNode->item) {
        newNode->previous  = currentNode;
        newNode->next      = nextNode;
        currentNode->next  = newNode;
        nextNode->previous = newNode;
        list->length++;
        break;
      }
      else {
        currentNode = nextNode;
        nextNode = currentNode->next;
      }
    }
  }
} // End of ll_insertNodeAscending





// Insert node in list
// Assumes that list is sorted from least to greatest value
void ll_insertNodeDescending(linkedList list, int data) {
  node newNode = (node)malloc(sizeof(node_t));
  assert(newNode != NULL);

  newNode->item = data;

  // If the linked list is empty
  if (list->length == 0) {
    newNode->previous = NULL;
    newNode->next     = NULL;
    list->head        = newNode;
    list->tail        = newNode;
    list->length++;
  }
  else {
    node previousNode, currentNode;

    currentNode  = list->head;
    previousNode = currentNode->previous;

    while (currentNode != NULL) {
      // If the current node's item is less than or equal to the tail's item
      if (currentNode == list->tail && newNode->item <= currentNode->item) {
        // Insert node at tail of list
        ll_insertNodeTail(list, data);
        break;
      }
      // If the current node's item is greater than the head's item
      else if (currentNode == list->head && newNode->item > currentNode->item) {
        // Insert node at end of list
        ll_insertNodeHead(list, data);
        break;
      }
      // If insertion is in the middle of the linked list
      else if (newNode->item <= currentNode->item && newNode->item >= previousNode->item) {
        newNode->next         = currentNode;
        newNode->previous     = previousNode;
        currentNode->previous = newNode;
        previousNode->next    = newNode;
        list->length++;
        break;
      }
      else {
        currentNode  = previousNode;
        previousNode = currentNode->previous;
      }
    }
  }
} // End of ll_insertNodeDescending





// Locate the first node that contains "data" (tail to head)
node ll_findNodeAscending(linkedList list, int data) {

  // Start searching at the list's tail
  node currentNode = list->tail;

  // Loop through the the entire linked list
  while (currentNode != NULL) {
    // If the current node's item matches the desired data
    if (currentNode->item == data) {
      return currentNode;
    }
    else {
      // Otherwise, advance to the next node
      currentNode = currentNode->next;
    }
  }
  return NULL;
} // End of ll_indNodeAscending





// Locate the first node that contains "data" (head to tail)
node ll_findNodeDescending(linkedList list, int data) {

  // Start searching at the list's head
  node currentNode = list->head;

  // Loop through the entire linked list
  while (currentNode != NULL) {
    // If the current node's item matches the desired data
    if (currentNode->item == data) {
      return currentNode;
    }
    else {
      // Otherwise, advance to the previous node
      currentNode = currentNode->previous;
    }
  }
  return NULL;
} // End of ll_findNodeDescending





// Print linked list in ascending order (i.e. tail to head)
void ll_printAscending(linkedList list) {

  // Start printing the linked list at the tail
  node nodeToPrint = list->tail;

  // Loop through the entire linked list
  while (nodeToPrint != NULL) {
    printf("%i ", nodeToPrint->item);
    nodeToPrint = nodeToPrint->next;
  }
  printf("\n");
} // End of ll_printAscending





// Print linked list in descending order (i.e. head to tail)
void ll_printDescending(linkedList list) {

  // Start printing the linked list at the head
  node nodeToPrint = list->head;

  // Loop through the entire linked list
  while (nodeToPrint != NULL) {
    printf("%i ", nodeToPrint->item);
    nodeToPrint = nodeToPrint->previous;
  }
  printf("\n");
} // End of ll_printDescending





// Remove head node
void ll_removeNodeHead(linkedList list) {

  // If the linked list's length is zero, do nothing
  if (list->length == 0) {
    return;
  }

  // Set the head node as the node to delete
  node nodeToDelete = list->head;

  // Set the node just before the head node as the new head
  list->head = list->head->previous;
  list->head->next = NULL;

  // Free the memory used by the deleted node
  free(nodeToDelete);

  // Decrement the linked list's length by one
  list->length--;

} // End of ll_removeNodeHead





// Remove tail node
void ll_removeNodeTail(linkedList list) {

  // If the linked list's length is zero do nothing
  if (list->length == 0) {
    return;
  }

  // Set the node just after the tail node as the new tail
  node nodeToDelete = list->tail;

  // Set the node just after the tail node's
  list->tail = list->tail->next;
  list->tail->previous = NULL;

  // Free the memory used by the deleted node
  free(nodeToDelete);

  // Decrement the linked list's length by one
  list->length--;

} // End of ll_removeNodeTail





// Remove first node containing data starting from tail
void ll_removeNode(linkedList list, node nodeToDelete) {
  if (nodeToDelete->previous == NULL) {
    ll_removeNodeTail(list);
  }
  else if (nodeToDelete->next == NULL) {
    ll_removeNodeHead(list);
  }
  else {
    nodeToDelete->previous->next = nodeToDelete->next;
    nodeToDelete->next->previous = nodeToDelete->previous;

    free(nodeToDelete);

    list->length--;
  }
} // End of ll_removeNode





void ll_removeLinkedList(linkedList list) {

  // Create temporary nodes current and next
  node current, next;

  // Assign the current node to the head of the list
  current = list->head;

  // Loop through the entire linked list
  while (current != NULL) {
    // Assign the next node to the following node after current
    next = current->next;

    // Free the memory assigned to the current node
    free(current);

    // Make the current node the next node
    current = next;
  }

  // Free the memory assigned to the linked list
  free(list);

} // End of ll_remoeLinkedList





// That's all folks!
