#ifndef HASH_DUMB_HPP
#define HASH_DUMB_HPP

#include <string>

class DumbHashTable {
public:
    DumbHashTable(int initialCapacity);
    ~DumbHashTable();

    bool add(std::string key);
    bool remove(std::string key);
    bool search(std::string key);
    std::string toString();
    int getSize();
    int getCollisionCount();

private:
    int hash(std::string key);
    int capacity;
    int size;
    int collisionCount;
    std::string* storage;
};

#endif // HASH_DUMB_HPP
