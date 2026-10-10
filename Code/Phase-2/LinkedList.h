```cpp
// Include the Internship header file from Phase-1
#include "../Phase-1/Internship.h"

// Structure representing a node of the linked list
struct Node {
    Internship data;  // Stores internship information
    Node* next;       // Pointer to the next node

    // Constructor to initialize a node with internship data
    Node(Internship i);
};

// Class to implement a linked list of internships
class LinkedList {
private:
    Node* head;  // Pointer to the first node of the linked list

public:
    // Constructor to initialize the linked list
    LinkedList();

    // Function to insert an internship into the linked list
    void insert(Internship i);

    // Function to display all internships in the linked list
    void display();
};
```
