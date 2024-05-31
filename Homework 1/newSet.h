//
//  newSet.h
//  HW1
//

#ifndef newSet_H
#define newSet_H
#include <string>

using ItemType = std::string;
const int DEFAULT_MAX_ITEMS = 180;  // Default capacity

class Set
{
public:
    Set();                              // default constructor
    Set(int max);                       // parameter constructor
    Set(const Set& other);              // copy constructor
    Set& operator=(const Set& other);   // assignment operator
    ~Set();                             // destructor

    
    bool empty() const;
    int size() const;
    bool insert(const ItemType& value);
    bool erase(const ItemType& value);
    bool contains(const ItemType& value) const;
    bool get(int i, ItemType& value) const;
    void swap(Set& other);

private:
    ItemType* m_items;     // Pointer to dynamic array
    int m_size;            // Current size of the set
    int m_capacity;        // Maximum capacity of the set

};

#endif // NEWSET_H
