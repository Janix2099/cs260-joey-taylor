#include "node.hpp"
#include <string>
#include <stdexcept>

class LinkedList {
private:
    Node* head; // Pointer to the first node in the list
    int size;   // Number of nodes in the list

public:
    LinkedList();
    ~LinkedList(); 

    void add(int value, int position); // Adds a node with the given value at the specified position
    int remove(int position); // Removes the node at the specified position and returns its value
    std::string get(int position) const; // Returns the value of the node at the specified position as a string
};