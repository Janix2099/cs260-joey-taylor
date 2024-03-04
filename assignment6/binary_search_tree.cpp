#include "binary_search_tree.h"

// New values insertted left when less-than or right when greater-than-or-equal-to
BinarySearchTree::BinarySearchTree() {
    root = nullptr;
}

// Find the node that would be the parent of the proposed_value.
BinaryNode *BinarySearchTree::locate_parent(int proposed_value) {
    if(root == nullptr) {
        return nullptr;
    }

    BinaryNode *current = root;
    while(current->left != nullptr || current->right != nullptr) {
        if(proposed_value < current->value && current->left == nullptr) {
            break;
        } else if (proposed_value >= current->value && current->right == nullptr) {
            break;
        } else if(proposed_value < current->value) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    return current;
}

void BinarySearchTree::add(int new_value) {
    // create new node
    BinaryNode *new_node = new BinaryNode{new_value, nullptr, nullptr};

    if(root == nullptr) {
        //assign root to that node
        root = new_node;
    } else {
        // find where it goes
        BinaryNode *parent = locate_parent(new_value);
        //update parent pointer
        if(new_value < parent->value) {
            parent->left = new_node;
        } else {
            parent->right = new_node;
        }
    }
}

int BinarySearchTree::remove(int old_value) {
    BinaryNode *parent = nullptr;
    BinaryNode *current = root;
    
    // Find the node and its parent
    while (current != nullptr && current->value != old_value) {
        parent = current;
        if (old_value < current->value) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    
    if (current == nullptr) { // Value not found
        return -1; // Return an error code or handle as needed
    }
    
    // Case 1: Removing a leaf node
    if (current->left == nullptr && current->right == nullptr) {
        if (current != root) {
            if (parent->left == current) {
                parent->left = nullptr;
            } else {
                parent->right = nullptr;
            }
        } else {
            root = nullptr;
        }
    }
    // Case 2: Removing a node with two children
    else if (current->left && current->right) {
        BinaryNode *successor = current->right;
        BinaryNode *successorParent = current;
        
        while (successor->left != nullptr) {
            successorParent = successor;
            successor = successor->left;
        }
        
        current->value = successor->value; // Replace value
        
        if (successorParent != current) {
            successorParent->left = successor->right;
        } else {
            current->right = successor->right;
        }
        
        current = successor; // Node to be deleted is the successor
    }
    // Case 3: Removing a node with one child
    else {
        BinaryNode* child = (current->left) ? current->left : current->right;
        
        if (current != root) {
            if (current == parent->left) {
                parent->left = child;
            } else {
                parent->right = child;
            }
        } else {
            root = child;
        }
    }
    
    delete current; // Free the memory
    return 0; // Success
}

bool BinarySearchTree::search(int proposed_value) {
    BinaryNode *current = root;
    while (current != nullptr) {
        if (proposed_value < current->value) {
            current = current->left;
        } else if (proposed_value > current->value) {
            current = current->right;
        } else {
            return true; // Value found
        }
    }
    return false; // Value not found
}


void BinarySearchTree::in_order_traversal(BinaryNode* node) {
    if (node != nullptr) {
        in_order_traversal(node->left);
        std::cout << node->value << " ";
        in_order_traversal(node->right);
    }
}

void BinarySearchTree::in_order_traversal() {
    in_order_traversal(root);
    std::cout << std::endl;
}
