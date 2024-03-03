#include "node.hpp"

class LinkedList {
private:
    Node* head; // Pointer to the first node in the list
    int size;   // Number of nodes in the list

public:
    LinkedList();
    ~LinkedList();

    void insert(int value); // Automatically insert values in ascending order
    bool remove(int value); // Remove a node by its value
    int search(int value); // Search for an element and return its position

    std::string to_string() const; // Converts the list to a string representation
};