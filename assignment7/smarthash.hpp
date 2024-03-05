#ifndef HASH_SMART_HPP
#define HASH_SMART_HPP

#include <string>
#include <list>

class SmartHashTable {
public:
    SmartHashTable(int initialCapacity);
    ~SmartHashTable();

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
    std::list<std::string>* storage;
};

#endif // HASH_SMART_HPP
