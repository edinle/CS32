//
//  Set.cpp
//  P2
//

#include "Set.h"
#include <iostream>

Set::Set() : m_size(0), m_head(nullptr) {         // default constructor
    m_head = new Node();                          // Create a dummy node
    m_head->m_next = m_head;                      // Point it to itself to be circular
    m_head->m_prev = m_head;
}

Set::Set(const Set& other) : m_size(0), m_head(nullptr) {           // copy constructor
    m_head = new Node(); // Create a dummy node
    m_head->m_next = m_head; // Point it to itself
    m_head->m_prev = m_head; // circular

    // Copy elements from 'other' set to this set
    Node* current = other.m_head->m_next;
    while (current != other.m_head) {
        insert(current->value); // Insert each element from 'other' into this set
        current = current->m_next;
    }
}

Set& Set::operator=(const Set& other) {                 // assignment operator
    if (this != &other) {
        Set temp(other);
        swap(temp);
    }
    return *this;
}

Set::~Set() {                               // destructor
    Node* current = m_head->m_next;         // Start from the node after the dummy head node
    while (current != m_head) {             // Traverse the list until the dummy head node is reached again
        Node* m_next = current->m_next;     // Store the next node in a temporary pointer
        delete current;                     // delete current node and move onto next one
        current = m_next;                   // move onto next node
    }
    delete m_head;                          // delete dummy node
}

bool Set::empty() const {
    if (m_size == 0) {      // if the linked list is empty, return true
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
    
    // Check if the value is already present in the set
    if (contains(value)) {
        return false; // The value is already in the set
    }

    // Create a new node to hold the value
    Node* newNode = new Node(value);

    // Find the correct position to insert the new node while maintaining the sorted order
    Node* current = m_head->m_next;
    while (current != m_head && current->value < value) {
        current = current->m_next;
    }

    // Update pointers to insert the new node
    newNode->m_next = current;
    newNode->m_prev = current->m_prev;
    current->m_prev->m_next = newNode;
    current->m_prev = newNode;

    m_size++; // Increment the size of the set

    return true; // Value inserted successfully

}

bool Set::erase(const ItemType& value) {
    // Remove the value from the set if present.  Return true if the
    // value was removed; otherwise, leave the set unchanged and
    // return false.
    
    // Start from the first node in the list
    Node* current = m_head->m_next;
    
    // Traverse the list until the dummy node is reached
    while (current != m_head) {
        // Check if the current node's value matches the target value
        if (current->value == value) {
            // Remove the current node from the list
            current->m_prev->m_next = current->m_next;
            current->m_next->m_prev = current->m_prev;
            delete current; // Free memory associated with the node
            // Decrement the size of the set
            m_size--;
            return true; // Value removed successfully
        }
        // Move to the next node
        current = current->m_next;
    }
    return false; // Value not found in the set
}

bool Set::contains(const ItemType &value) const {
    // Return true if the value is in the set, otherwise false.
    Node* current = m_head->m_next; // start from the first node
    while (current != m_head) { // go through the list until the dummy node is reached
        if (current->value == value) { // if the current node value is the target value
            return true; // return true
        }
        current = current->m_next; // move to the next node
    }
    return false; // value not in set
}


bool Set::get(int pos, ItemType& value) const {
    // If 0 <= i < size(), copy into value the item in the set that is
    // strictly less than exactly i items in the set and return true.
    // Otherwise, leave value unchanged and return false.
    
    // Check if the position is within the valid range
        if (pos < 0 || pos >= m_size) {
            return false; // Invalid position
        }
        
        // Start from the last node in the list
        Node* current = m_head->m_prev;
        
        // Traverse the list backwards to find the node at the specified position
        for (int i = 0; i < pos; ++i) {
            current = current->m_prev;
        }
        
        // Copy the value from the found node
        value = current->value;
        
        return true; // Value retrieved successfully
}

void Set::swap(Set& other) {
    std::swap(m_head, other.m_head);
    std::swap(m_size, other.m_size);
}

void unite(const Set& s1, const Set& s2, Set& result) {
    // Check if result is one of the input sets
    if (&result == &s1 || &result == &s2) {
        // Create a temporary set to store the union result
        Set temp;
        
        // Iterate through each element in s1 and insert into temp
        for (int i = 0; i < s1.size(); ++i) {
            ItemType value;
            if (s1.get(i, value)) {
                temp.insert(value);
            }
        }

        // Iterate through each element in s2 and insert into temp
        for (int i = 0; i < s2.size(); ++i) {
            ItemType value;
            if (s2.get(i, value)) {
                temp.insert(value);
            }
        }

        // Swap the contents of temp with result
        result.swap(temp);
    } else {
        // If result is not one of the input sets, proceed normally
        result.clear();

        // Iterate through each element in s1 and insert into result
        for (int i = 0; i < s1.size(); ++i) {
            ItemType value;
            if (s1.get(i, value)) {
                result.insert(value);
            }
        }

        // Iterate through each element in s2 and insert into result
        for (int i = 0; i < s2.size(); ++i) {
            ItemType value;
            if (s2.get(i, value)) {
                result.insert(value);
            }
        }
    }
}





void inOnlyOne(const Set& s1, const Set& s2, Set& result) {
    // Create a temporary set to hold the result
    Set tempResult;

    // Iterate through each element in s1
    for (int i = 0; i < s1.size(); ++i) {
        ItemType value;
        if (s1.get(i, value)) {
            // If the element is not present in s2, add it to the temporary result
            if (!s2.contains(value)) {
                tempResult.insert(value);
            }
        }
    }

    // Iterate through each element in s2
    for (int i = 0; i < s2.size(); ++i) {
        ItemType value;
        if (s2.get(i, value)) {
            // If the element is not present in s1, add it to the temporary result
            if (!s1.contains(value)) {
                tempResult.insert(value);
            }
        }
    }

    // Copy the contents of the temporary set back to the result set
    result = tempResult;
}


void Set::print() const {
    Node* current = m_head->m_next;
    while (current != m_head) {
        std::cout << current->value << std::endl;
        current = current->m_next;
    }
    std::cout << std::endl;
}

void Set::clear() {
    Node* current = m_head->m_next;
    while (current != m_head) {
        Node* next = current->m_next;
        delete current;
        current = next;
    }
    m_head->m_next = m_head;
    m_head->m_prev = m_head;
    m_size = 0;
}
