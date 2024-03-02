#include "LinkedList.hpp"
#include <iostream>
#include <cassert>
#include <string>

// Test adding elements to the LinkedList
void testAdd() {
    LinkedList list;
    list.add(1, 0); // Add 1 at position 0
    list.add(2, 1); // Add 2 at position 1
    
    // Verify by checking if returned strings contain expected values
    assert(list.get(0).find("value: 1") != std::string::npos);
    assert(list.get(1).find("value: 2") != std::string::npos);
    
    std::cout << "testAdd passed.\n";
}

// Test removing elements from the LinkedList
void testRemove() {
    LinkedList list;
    list.add(3, 0); // Setup list
    list.add(4, 1); // Add another element
    int val = list.remove(0); // Remove first element
    assert(val == 3); // Verify the value removed is correct
    
    // Verify the first element is now what used to be the second
    assert(list.get(0).find("value: 4") != std::string::npos);
    
    std::cout << "testRemove passed.\n";
}

// Test getting elements from the LinkedList without removing
void testGet() {
    LinkedList list;
    list.add(5, 0);
    list.add(6, 1);
    
    // Verify by checking if returned strings contain expected values
    assert(list.get(0).find("value: 5") != std::string::npos);
    assert(list.get(1).find("value: 6") != std::string::npos);
    
    std::cout << "testGet passed.\n";
}

int main() {
    testAdd();
    testRemove();
    testGet();

    std::cout << "All tests passed.\n";
    return 0;
}
