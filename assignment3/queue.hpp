#include "node.hpp"

class Queue {
    Node* front;
    Node* rear;
    int size;

public:
    Queue();
    void enqueue(int new_value);
    int dequeue();
    string peek() const;
};
