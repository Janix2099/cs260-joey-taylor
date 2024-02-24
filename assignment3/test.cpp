#include <iostream>

#include "queue.hpp" 
// #include "node.cpp" // This will work to simplify our compliation, but is bad practice... use better command line or build system rules instead...
// THe outputs matched expectations =)

int main() {
    Queue myQueue;

    myQueue.enqueue(10);
    myQueue.enqueue(20);

    std::cout << "Front of queue: " << myQueue.peek() << std::endl;

    std::cout << "Dequeue: " << myQueue.dequeue() << std::endl;
    std::cout << "Now front of queue: " << myQueue.peek() << std::endl;

    myQueue.enqueue(30);
    std::cout << "After enqueueing 30, front of queue: " << myQueue.peek() << std::endl;

    return 0;
}
