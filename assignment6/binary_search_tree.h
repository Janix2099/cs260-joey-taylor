#include "binary_node.h"
#include <iostream>

class BinarySearchTree {
    BinaryNode *root;

    void in_order_traversal(BinaryNode* node);

    BinaryNode *locate_parent(int proposed_value);

public:
    BinarySearchTree();
    void add(int new_value);
    int remove(int old_value);
    bool search(int proposed_value);

    void in_order_traversal();
};