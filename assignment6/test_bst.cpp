#include "binary_search_tree.h"
#include <iostream>
#include <vector>

int main() {
    BinarySearchTree bst;

    // Add Elements Test
    std::vector<int> valuesToAdd = {10, 5, 15, 3, 7, 13, 17};
    for (int value : valuesToAdd) {
        bst.add(value);
    }
    std::cout << "After adding elements: ";
    bst.in_order_traversal(); // Expected order: 3 5 7 10 13 15 17

    // Remove Leaf Node Test
    bst.remove(3);
    std::cout << "After removing leaf node (3): ";
    bst.in_order_traversal(); // Expected order: 5 7 10 13 15 17

    // Remove Node with One Child Test
    bst.remove(15);
    std::cout << "After removing node with one child (15): ";
    bst.in_order_traversal(); // Expected order: 5 7 10 13 17

    // Remove Node with Two Children Test
    bst.remove(10);
    std::cout << "After removing node with two children (10): ";
    bst.in_order_traversal(); // Expected order: 5 7 13 17

    // Traversal Order Test
    std::cout << "Final in-order traversal: ";
    bst.in_order_traversal(); // Expected sequence: 5 7 13 17

    return 0;
}
