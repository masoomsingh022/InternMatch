#include "LinkedList.h"
#include <iostream>
using namespace std;

Node::Node(Internship i):data(i){
    next = nullptr;
}

LinkedList::LinkedList(){
    head = nullptr;
}

void LinkedList::insert(Internship i){
    Node* newNode = new Node(i);

    if(head == nullptr){
        head = newNode;
    }
    else{
        Node* temp = head;

        while(temp->next != nullptr){
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

void LinkedList::display(){
    Node* temp = head;

    while(temp != nullptr){
        temp->data.display();
        temp = temp->next;
    }
}
