#include "../Phase-1/Internship.h"

struct Node {
    Internship data;
    Node* next;

    Node(Internship i);
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList();
    void insert(Internship i);
    void display();
};
