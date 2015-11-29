// linkedList.cpp

#include "linkedList.hpp"


int main() {
  return 0;
}



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
}



// Get the length of the linked list
int ll_length(linkedList list) {
  return list->length;
}



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
}



// Access the item stored in the head node
int ll_getHeadNodeItem(linkedList list) {
  return list->head->item;
}



// Access the item stored in the tail node
int ll_getTailNodeItem(linkedList list) {
  return list->tail->item;
}



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

}



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
}





// Check to see if the linked list is sorted in ascending order
// Lowest to highest
bool ll_isSortedAscending(linkedList list) {

  // If the list has zero or one nodes
  if (list->length == 0 || list->length == 1) {
    return true;
  }

  currentNode = currentNode->next;

  while (currentNode != NULL) {
    if (currentNode->item >= currentNode->previous->item) {
      currentNode = currentNode->next;
    }
    else {
      return false;
    }
  }

  return true;
}



// Check to see if the linked list is sorted in descending order
// Highest to lowest
bool ll_isSortedDescending(linkedList list) {

  // If the list has zero or one nodes
  if (list->length == 0 || list->length == 1) {
    return true;
  }

  node currentNode = list->head;

  currentNode = currentNode->previous;

  while (currentNode != NULL) {
    if (currentNode->item >= currentNode->next->item) {
      currentNode = currentNode->previous;
    }
    else {
      return false;
    }
  }

  return true;
}



// Insert node in list
// Assumes that list is sorted from least to greatest value
void ll_insertNodeAscending(linkedList list, int data) {
  node newNode = (node)malloc(sizeof(node_t));
  assert(newNode != NULL);

  newNode->item = data;

  // If the linked list is empty
  if (list->length == 0) {
    newNode->previous = NULL;
    newNode->next = NULL;
    list->head = newNode;
    list->tail = newNode;
    list->length++;
  }
  else {
    node currentNode, nextNode;

    currentNode = list->tail;
    nextNode = currentNode->next;

    while (currentNode != NULL) {
      if (currentNode == list->tail && newNode->item <= currentNode->item) {
        // insert node at tail of list
        ll_insertNodeTail(list, data);
        break;
      }
      else if (currentNode == list->head && newNode->item > currentNode->item) {
        // insert node at end of list
        ll_insertNodeHead(list, data);
        break;
      }
      // If insertion is in the middle of the linked list
      else if (newNode->item >= currentNode->item && newNode->item <= nextNode->item) {
        newNode->previous = currentNode;
        newNode->next = nextNode;
        currentNode->next = newNode;
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
}




// Insert node in list
// Assumes that list is sorted from least to greatest value
void ll_insertNodeDescending(linkedList list, int data) {
  node newNode = (node)malloc(sizeof(node_t));
  assert(newNode != NULL);

  newNode->item = data;

  // If the linked list is empty
  if (list->length == 0) {
    newNode->previous = NULL;
    newNode->next = NULL;
    list->head = newNode;
    list->tail = newNode;
    list->length++;
  }
  else {
    node previousNode, currentNode;

    currentNode = list->head;
    previousNode = currentNode->previous;

    while (currentNode != NULL) {
      if (currentNode == list->tail && newNode->item <= currentNode->item) {
        // Insert node at tail of list
        ll_insertNodeTail(list, data);
        break;
      }
      else if (currentNode == list->head && newNode->item > currentNode->item) {
        // Insert node at end of list
        ll_insertNodeHead(list, data);
        break;
      }
      // If insertion is in the middle of the linked list
      else if (newNode->item <= currentNode->item && newNode->item >= previousNode->item) {
        newNode->next = currentNode;
        newNode->previous = previousNode;
        currentNode->previous = newNode;
        previousNode->next = newNode;
        list->length++;
        break;
      }
      else {
        currentNode = previousNode;
        previousNode = currentNode->previous;
      }
    }
  }
}




// Locate the first node that contains "data" (tail to head)
node ll_findNodeAscending(linkedList list, int data) {
  node currentNode = list->tail;

  while (currentNode != NULL) {
    if (currentNode->item == data) {
      return currentNode;
    }
    else {
      currentNode = currentNode->next;
    }
  }

  return NULL;
}

// Locate the first node that contains "data" (head to tail)
node ll_findNodeDescending(linkedList list, int data) {
  node currentNode = list->head;

  while (currentNode != NULL) {
    if (currentNode->item == data) {
      return currentNode;
    }
    else {
      currentNode = currentNode->previous;
    }
  }

  return NULL;
}






// Print linked list in ascending order (i.e. tail to head)
void ll_printAscending(linkedList list) {
  node nodeToPrint = list->tail;

  while (nodeToPrint != NULL) {
    printf("%i ", nodeToPrint->item);
    nodeToPrint = nodeToPrint->next;
  }
  printf("\n");
}

// Print linked list in descending order (i.e. head to tail)
void ll_printDescending(linkedList list) {
  node nodeToPrint = list->head;

  while (nodeToPrint != NULL) {
    printf("%i ", nodeToPrint->item);
    nodeToPrint = nodeToPrint->previous;
  }
  printf("\n");
}








// Remove head node
void ll_removeNodeHead(linkedList list) {

  if (list->length == 0) {
    return;
  }

  node nodeToDelete = list->head;

  list->head = list->head->previous;
  list->head->next = NULL;

  free(nodeToDelete);

  list->length--;
}



// Remove tail node
void ll_removeNodeTail(linkedList list) {

  if (list->length == 0) {
    return;
  }

  node nodeToDelete = list->tail;

  list->tail = list->tail->next;
  list->tail->previous = NULL;

  free(nodeToDelete);

  list->length--;
}



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
}



void ll_removeLinkedList(linkedList list) {

  // Create temporary nodes current and next
  node current, next;

  // Assign the current node to the head o the list
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

}

// That's all folks!
