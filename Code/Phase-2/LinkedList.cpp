#include "LinkedList.h"
#include <iostream>
using namespace std;

Node::Node(Internship i) : data(std::move(i)), next(nullptr) {}

LinkedList::LinkedList() : head(nullptr), tail(nullptr), count(0) {}

LinkedList::~LinkedList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void LinkedList::insert(const Internship& i) {
    Node* newNode = new Node(i);

    if (head == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    count++;
}

void LinkedList::display() const {
    for (Node* temp = head; temp != nullptr; temp = temp->next) {
        temp->data.display();   // display() must be marked const in Internship
    }
}

vector<Internship> LinkedList::getAllInternships() const {
    vector<Internship> internships;
    internships.reserve(count);  // one allocation instead of repeated regrowth

    for (Node* temp = head; temp != nullptr; temp = temp->next) {
        internships.push_back(temp->data);
    }
    return internships;
}