#include "LinkedList.h"
#include <iostream>
using namespace std;

Node::Node(Internship i) : data(i) {
    next = nullptr;
}

LinkedList::LinkedList() {
    head = nullptr;
}

// Inserts a new Internship at the end of the list. O(n) due to tail traversal.
void LinkedList::insert(Internship i) {
    Node* newNode = new Node(i);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Traverses and prints all stored internships. O(n).
void LinkedList::display() {
    Node* temp = head;
    while (temp != nullptr) {
        temp->data.display();
        temp = temp->next;
    }
}
