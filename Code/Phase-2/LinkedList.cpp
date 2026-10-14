<<<<<<< HEAD
```cpp
// Include the LinkedList header file
=======

>>>>>>> 733ecb4 (Update Phase 2 internship matching)
#include "LinkedList.h"
#include <iostream>
#include <vector>
using namespace std;

<<<<<<< HEAD
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
=======
Node::Node(Internship i) : data(i) {
    next = nullptr;
}

LinkedList::LinkedList() {
    head = nullptr;
}

void LinkedList::insert(Internship i) {
    Node* newNode = new Node(i);

>>>>>>> 733ecb4 (Update Phase 2 internship matching)
    if (head == nullptr) {
        head = newNode;
        return;
    }

<<<<<<< HEAD
    // Start traversing the list from the head node
    Node* temp = head;

    // Move to the last node of the linked list
=======
    Node* temp = head;

>>>>>>> 733ecb4 (Update Phase 2 internship matching)
    while (temp->next != nullptr) {
        temp = temp->next;
    }

<<<<<<< HEAD
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
=======
    temp->next = newNode;
}

void LinkedList::display() {
    Node* temp = head;

    while (temp != nullptr) {
>>>>>>> 733ecb4 (Update Phase 2 internship matching)
        temp->data.display();

        // Move to the next node
        temp = temp->next;
    }
}
<<<<<<< HEAD
```
=======

vector<Internship> LinkedList::getAllInternships() {
    vector<Internship> result;
    Node* temp = head;

    while (temp != nullptr) {
        result.push_back(temp->data);
        temp = temp->next;
    }

    return result;
}
>>>>>>> 733ecb4 (Update Phase 2 internship matching)
