// Queue.cpp

#include "Queue.hpp"
#include <stdexcept> // For std::out_of_range

Queue::Queue(): front(nullptr), rear(nullptr), size(0) {}

void Queue::enqueue(int new_value) 
// Enqueue is at best linear,  have to traverse the entire list to get to the end. Ergo O(n)
{
    Node* new_node = new Node();
    new_node->id = size; 
    new_node->value = new_value;
    if (rear == nullptr) {
        front = rear = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }
    size++;
}

int Queue::dequeue()
//dequeue is constant. Ergo O(1)  
 {
    if (front == nullptr) {
        throw std::out_of_range("Queue is empty");
    }
    Node* temp = front;
    int value = front->value;
    front = front->next;
    if (front == nullptr) {
        rear = nullptr;
    }
    delete temp;
    size--;
    return value;
}

std::string Queue::peek() 
//dequeue is constant. Ergo O(1)  
const {
    if (front == nullptr) {
        throw std::out_of_range("Queue is empty");
    }
    return front->to_string();
}
