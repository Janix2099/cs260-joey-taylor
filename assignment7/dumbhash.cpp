#include "dumbhash.hpp"
#include <iostream>
#include <sstream>

DumbHashTable::DumbHashTable(int initialCapacity) : capacity(initialCapacity), size(0), collisionCount(0) {
    storage = new std::string[capacity];
}

DumbHashTable::~DumbHashTable() {
    delete[] storage;
}

int DumbHashTable::hash(std::string key) {
    int hashValue = 0;
    for (char ch : key) {
        hashValue += static_cast<int>(ch);
    }
    return hashValue % capacity;
}

bool DumbHashTable::add(std::string key) {
    int index = hash(key);
    if (storage[index].empty()) {
        size++; // Increment size only if it's a new insertion
    } else {
        collisionCount++; // Increment collision count on overwrite
    }
    storage[index] = key;
    return true;
}

bool DumbHashTable::remove(std::string key) {
    int index = hash(key);
    if (storage[index] == key) {
        storage[index].clear(); // Effectively deletes the value
        size--; // Decrement size since we're removing an element
        return true;
    }
    return false;
}

bool DumbHashTable::search(std::string key) {
    int index = hash(key);
    return storage[index] == key;
}

std::string DumbHashTable::toString() {
    std::stringstream ss;
    for (int i = 0; i < capacity; i++) {
        if (!storage[i].empty()) {
            ss << i << ": " << storage[i] << std::endl;
        }
    }
    return ss.str();
}

int DumbHashTable::getSize() {
    return size;
}

int DumbHashTable::getCollisionCount() {
    return collisionCount;
}