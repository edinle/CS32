//
//  set.cpp
//  HW1
//

#include "newSet.h"
#include <string>
#include <iostream>

Set::Set() : m_size(0), m_capacity(DEFAULT_MAX_ITEMS) { // default constructor
    m_items = new ItemType[m_capacity];
}

Set::Set(int max) : m_size(0), m_capacity(max) {        // parameter constructor
    if (max < 0) {                                      // checks if parameter is negative
        std::cout << "no negative integers allowed" << std::endl;
        exit(1);
    }
    m_items = new ItemType[m_capacity];                 // Dynamically allocate an array with 'max' capacity
}

Set::Set(const Set& other)                              // copy constructor
: m_size(other.m_size), m_capacity(other.m_capacity) {
    m_items = new ItemType[other.m_capacity];
    for (int i = 0; i < m_size; ++i) {
        m_items[i] = other.m_items[i];
    }
}

Set& Set::operator=(const Set& other) {                 // assignment operator
    if (&other == this) {   // check if variable is being assigned to itself, if so, do nothing
        return *this;
    }
    
    delete [] m_items;
    m_size = other.size();
    m_capacity = other.m_capacity;
    m_items = new ItemType[m_capacity];
    for (int j = 0; j < m_size; j++) {
        m_items[j] = other.m_items[j];
    }
    return *this;
    
//    if (this != &other) {
//        Set temp(other);
//        swap(temp);
//    }
//    return *this;
}

Set::~Set() {               // destructor
    delete[] m_items;
}

bool Set::empty() const {
    if (m_size == 0) {
        return true;
    }
    return false;
}

int Set::size() const {
    return m_size;
}

bool Set::insert(const ItemType& value) {
    // Insert value into the set if it is not already present.  Return
    // true if the value is actually inserted.  Leave the set unchanged
    // and return false if value was not inserted (perhaps because it
    // was already in the set or because the set has a fixed capacity and
    // is full).
    
    // for (loop through array) {
    //      if (string not in array) {
    //          insert value into array sorted
    //          return true
    //      } else {
    //          return false
    //      }
    // }
    
    // Check if the value is already present in the set
    if (contains(value)) {
        return false; // The value is already in the set
    }
    
    // Check if the set has reached its capacity
    if (m_size >= m_capacity) {
        return false; // The set is full and cannot accept new items
    }
    
    // Insert the new item
    int i = 0;
    // loop through array backwards, if index within bounds & item greater than new value
    for (i = m_size-1; (i >= 0 && m_items[i] > value); i--) {
        m_items[i+1] = m_items[i];
    }
    m_items[i+1] = value;
    m_size++;
    return true;
}

bool Set::erase(const ItemType& value) {
    // Remove the value from the set if present.  Return true if the
    // value was removed; otherwise, leave the set unchanged and
    // return false.
    
    // for (loop through array) {
    //  if (value in array) {
    //      remove value from set
    //      return true
    //  } else {
    //      return false
    //  }
    // }
    
    for (int i = 0; i < m_size; i++) {
        if (m_items[i] == value) {
            // Once the value is found, shift all elements after it to the left
            for (int j = i; j < m_size - 1; j++) {
                m_items[j] = m_items[j + 1];
            }
            m_size--;   // decrease the size
            return true;    // return true if the value was removed
        }
    }
    return false; // otherwise, leave the set unchanged and return false
}

bool Set::contains(const ItemType &value) const {
    // Return true if the value is in the set, otherwise false.
    
    // if (value in set) {
    //     return true;
    // } else {
    //     return false;
    // }
    
    if (m_size == 0) {
        return false;
    }
    for (int i = 0; i < m_size; i++) {
        if (m_items[i] == value) {
            return true;
        }
    }
    return false;
}

bool Set::get(int i, ItemType& value) const {
    // If 0 <= i < size(), copy into value the item in the set that is
    // strictly less than exactly i items in the set and return true.
    // Otherwise, leave value unchanged and return false.
    
    // if (0 <= i && i < size()) {
    //      value = (item < i)
    //      return true
    // } else {
    //      return false
    // }
    
    if (0 <= i && i < m_size) {
        value = m_items[m_size-(i+1)];
        return true;
    }
    return false;
}

void Set::swap(Set& other) {
    std::swap(m_items, other.m_items);
    std::swap(m_size, other.m_size);
    std::swap(m_capacity, other.m_capacity);
}
