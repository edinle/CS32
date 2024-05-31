//
//  Set.h
//  P2
//

#ifndef Set_h
#define Set_h

#include <string>
using ItemType = std::string;

class Set {
public:
    Set();                              // Default constructor
    Set(const Set& other);              // Copy constructor
    Set& operator=(const Set& other);   // Assignment operator
    ~Set();                             // Destructor
    
    bool empty() const;
    int size() const;
    bool insert(const ItemType& value);
    bool erase(const ItemType& value);
    bool contains(const ItemType& value) const;
    bool get(int pos, ItemType& value) const;
    void swap(Set& other);
    
    void print() const;
    void clear();
    
private:
    struct Node {
        ItemType value;
        Node* m_prev;
        Node* m_next;

        Node() : m_prev(nullptr), m_next(nullptr) {}
        Node(ItemType value) : value(value), m_prev(nullptr), m_next(nullptr) {}
    };

    Node* m_head;   // Pointer to the head of the list
    int m_size;     // Current size of the set
};

void unite(const Set& s1, const Set& s2, Set& result);
// combines two sets into a result where there are no duplicate numbers
// order does not matter but when using get(), must get largest item
void inOnlyOne(const Set& s1, const Set& s2, Set& result);
// result must contain only the numbers in each set that are not duplicated and appear only once in each set

#endif /* Set_h */
