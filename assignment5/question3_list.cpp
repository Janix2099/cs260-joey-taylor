#include "Node.hpp" 
#include "LinkedList.hpp" 
#include <stdexcept> 
#include <iostream>  

// Constructor
LinkedList::LinkedList() : head(nullptr), size(0) {}

// Automatically insert values in ascending order
void LinkedList::insert(int value) {
    Node* newNode = new Node{value, nullptr};

    // Special case for the head or if the new value is less than the head's data
    if (head == nullptr || value < head->data) {
        newNode->next = head;
        head = newNode;
    } else {
        // Find the insertion point
        Node* current = head;
        while (current->next != nullptr && current->next->data < value) {
            current = current->next;
        }
        // Insert the new node
        newNode->next = current->next;
        current->next = newNode;
    }
    size++;
}

// Search for an element and return its position (Linear)
int LinkedList::search(int value) {
    Node* current = head;
    int position = 0;
    while (current != nullptr) {
        if (current->data == value) {
            return position; // Element found
        }
        current = current->next;
        position++;
    }
    return -1; // Element not found
}

// Remove a node by its data and return true
bool LinkedList::remove(int value) {
    if (head == nullptr) return false; // List is empty

    // Special case for head
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
        return true;
    }

    // Find the node before the one to remove
    Node* current = head;
    while (current->next != nullptr && current->next->data != value) {
        current = current->next;
    }

    // Value not found
    if (current->next == nullptr) return false;

    // Remove the node
    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
    size--;
    return true;
}

// Destructor to clear list
LinkedList::~LinkedList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
