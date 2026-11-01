#pragma once
#include <vector>
#include "Internship.h"
using namespace std;

class Node {
public:
    Internship data;
    Node* next;
    Node(Internship i);
};

class LinkedList {
private:
    Node* head;
    Node* tail;      
    size_t count;   

public:
    LinkedList();
    ~LinkedList();                              
    LinkedList(const LinkedList&) = delete;     
    LinkedList& operator=(const LinkedList&) = delete;

    void insert(const Internship& i);
    void display() const;
    vector<Internship> getAllInternships() const;
    size_t size() const { return count; }
};