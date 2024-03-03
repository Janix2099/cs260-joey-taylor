#pragma once

#include <string>
#include "node.hpp"

// define the list class
class list {
    private:
        node *head;

    public:
        list();
        void insert(int data);
        std::string to_string();
};