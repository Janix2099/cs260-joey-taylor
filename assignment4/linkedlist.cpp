// LinkedList.cpp
#include "LinkedList.hpp"
#include <stdexcept> // For std::out_of_range

// Constructor
LinkedList::LinkedList() : head(nullptr), size(0) {}

// Add a node at a specific position
void LinkedList::add(int value, int position) {
    // Check if position is valid
    if (position < 0 || position > size) {
        throw std::out_of_range("Position is out of range");
    }

    // Make new node
    Node* newNode = new Node();
    newNode->value = value;

    // If adding at start, adjust head
    if (position == 0) {
        newNode->next = head;
        head = newNode;
    } else {
        // Find node before the position
        Node* temp = head;
        for (int i = 0; i < position - 1; ++i) {
            temp = temp->next;
        }
        // Insert new node
        newNode->next = temp->next;
        temp->next = newNode;
    }
    // Increment list size
    size++;
}

// Remove a node and return its value
int LinkedList::remove(int position) {
    // Position check
    if (position < 0 || position >= size || head == nullptr) {
        throw std::out_of_range("Position is out of range");
    }

    Node* temp = head;
    int removedValue; // Value to return

    // Special case for head
    if (position == 0) {
        head = head->next;
        removedValue = temp->value;
        delete temp; // Free old head
    } else {
        // Find node before the one to remove
        for (int i = 0; i < position - 1; ++i) {
            temp = temp->next;
        }
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        removedValue = toDelete->value;
        delete toDelete; // Cleanup
    }
    // Decrement size
    size--;
    return removedValue;
}

// Get value at position without removing
std::string LinkedList::get(int position) const {
    // Position validation
    if (position < 0 || position >= size || head == nullptr) {
        throw std::out_of_range("Position is out of range");
    }

    // Traverse to position
    Node* temp = head;
    for (int i = 0; i < position; ++i) {
        temp = temp->next;
    }
    // Return node's string representation
    return temp->to_string();
}

// Destructor to clear list
LinkedList::~LinkedList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp; // Prevent memory leak
    }
}
