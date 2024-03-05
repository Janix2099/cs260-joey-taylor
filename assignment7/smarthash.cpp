#include "smarthash.hpp"
#include <iostream>
#include <sstream>
#include <list>
#include <algorithm>

// Initializes hash table with specified capacity.
SmartHashTable::SmartHashTable(int initialCapacity) : capacity(initialCapacity), size(0), collisionCount(0) {
    storage = new std::list<std::string>[capacity];
}

// Cleans up allocated storage.
SmartHashTable::~SmartHashTable() {
    delete[] storage;
}

// Hash function: Sums ASCII values of characters and finds modulo capacity.
int SmartHashTable::hash(std::string key) {
    int hashValue = 0;
    for (char ch : key) hashValue += static_cast<int>(ch);
    return hashValue % capacity;
}

// Adds a key to the table, increments collision count if bucket is already occupied.
bool SmartHashTable::add(std::string key) {
    int index = hash(key);
    if (!storage[index].empty()) collisionCount++;
    storage[index].push_back(key);
    size++;
    return true;
}

// Removes a key if it exists, adjusting size.
bool SmartHashTable::remove(std::string key) {
    int index = hash(key);
    auto it = std::find(storage[index].begin(), storage[index].end(), key);
    if (it != storage[index].end()) {
        storage[index].erase(it);
        size--;
        return true;
    }
    return false;
}

// Checks if a key exists in the table.
bool SmartHashTable::search(std::string key) {
    int index = hash(key);
    return std::find(storage[index].begin(), storage[index].end(), key) != storage[index].end();
}

// Generates a string representation of the hash table.
std::string SmartHashTable::toString() {
    std::stringstream ss;
    for (int i = 0; i < capacity; i++) {
        ss << i << ":";
        for (auto& key : storage[i]) ss << " " << key;
        ss << std::endl;
    }
    return ss.str();
}

// Returns the number of items in the table.
int SmartHashTable::getSize() {
    return size;
}

// Returns the total number of collisions encountered.
int SmartHashTable::getCollisionCount() {
    return collisionCount;
}
