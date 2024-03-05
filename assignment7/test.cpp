#include "dumbhash.hpp"
#include "smarthash.hpp"

#include <iostream>
#include <cassert> // For assert()

void testDumbHashTable() {
    DumbHashTable dumbTable(10); // Assuming a capacity of 10 for simplicity

    // Test adding elements
    dumbTable.add("test");
    dumbTable.add("data");
    assert(dumbTable.getSize() == 2);
    assert(dumbTable.search("test"));
    assert(dumbTable.search("data"));

    // Test overwriting an element
    dumbTable.add("test"); // This should overwrite
    assert(dumbTable.getSize() == 2); // Size should remain the same

    // Test removing an element
    assert(dumbTable.remove("test"));
    assert(!dumbTable.search("test"));
    assert(dumbTable.getSize() == 1);

    std::cout << "Dumb hash table tests passed.\n";
}

void testSmartHashTable() {
    SmartHashTable smartTable(10); // Create a hash table with 10 buckets

    // Add keys to the table
    smartTable.add("test"); // Add first key
    smartTable.add("data"); // Add second key, different from the first

    // Add keys that will cause a collision
    smartTable.add("a"); // ASCII sum % 10 = 7
    smartTable.add("k"); // ASCII sum % 10 = 7, should cause a collision

    // Check the table size and search functionality
    assert(smartTable.getSize() == 4); // Should be 4 items in the table
    assert(smartTable.search("test")); // "test" should be found
    assert(smartTable.search("data")); // "data" should be found
    assert(smartTable.search("a")); // "a" should be found
    assert(smartTable.search("k")); // "k" should be found

    // Test removing items
    assert(smartTable.remove("test")); // Remove "test"
    assert(!smartTable.search("test")); // "test" should not be found now
    assert(smartTable.getSize() == 3); // Size should be 3 after removal

    // Test removing an item that doesn't exist
    assert(!smartTable.remove("nonexistent")); // Should fail, as "nonexistent" isn't in the table

    // Test collision count
    assert(smartTable.getCollisionCount() == 1); // There should be 1 collision recorded

    std::cout << "Smart hash table tests passed.\n";
}


int main() {
    testDumbHashTable();
    testSmartHashTable();
    return 0;
}
