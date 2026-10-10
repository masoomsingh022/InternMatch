```cpp
// Include the LinkedList header file
#include "LinkedList.h"
#include <iostream>
using namespace std;

// Constructor to initialize a node with internship data
Node::Node(Internship i) : data(i) {
    // Initialize the next pointer to nullptr
    next = nullptr;
}

// Constructor to initialize an empty linked list
LinkedList::LinkedList() {
    // Initially, the head points to no node
    head = nullptr;
}

// Function to insert an internship at the end of the linked list
void LinkedList::insert(Internship i) {
    // Create a new node containing the internship data
    Node* newNode = new Node(i);

    // If the linked list is empty, make the new node the first node
    if (head == nullptr) {
        head = newNode;
        return;
    }

    // Start traversing the list from the head node
    Node* temp = head;

    // Move to the last node of the linked list
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    // Connect the last node to the new node
    temp->next = newNode;
}

// Function to display all internships stored in the linked list
void LinkedList::display() {
    // Start traversal from the first node
    Node* temp = head;

    // Traverse the list until the end is reached
    while (temp != nullptr) {
        // Display the internship data of the current node
        temp->data.display();

        // Move to the next node
        temp = temp->next;
    }
}
```
