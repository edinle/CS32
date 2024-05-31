#include "Set.h"
#include <iostream>
#include <cassert>
#include <string>
using namespace std;

#ifndef TESTNUM
#define TESTNUM 1 // CHANGE TEST CASE HERE
#endif

#if TESTNUM == 1
// Testing the default constructor

int main() {
    Set a;
    string x;
    assert(a.size() == 0); // Check if the set is initially empty
    assert(a.empty()); // Check if the set is empty
    assert(!a.get(0, x)); // Try to get an item from an empty set

    cout << "test case 1 passed" << endl;
}

#elif TESTNUM == 2
// Testing the insert function

int main() {
    Set a;
    assert(a.insert("hi")); // Insert a string into the set
    assert(a.insert("test")); // Insert another string into the set
    assert(a.insert("")); // Insert an empty string into the set
    assert(a.insert("aa")); // Insert another string into the set
    assert(a.insert("zzz")); // Insert another string into the set
    assert(a.size() == 5); // Check if the size is correct after insertions

    assert(!a.insert("test")); // Try to insert a string that already exists
    string x = "hi";
    assert(!a.insert(x)); // Try to insert a string using a variable that already exists
    assert(a.size() == 5); // Check if the size remains unchanged

    // Check if all inserted strings are present in the set
    assert(a.contains("hi") && a.contains("test") && a.contains("aa") && a.contains("") && a.contains("zzz"));

    cout << "test case 2 passed" << endl;
}

#elif TESTNUM == 3
// Testing the erase function

int main() {
    Set a;
    assert(a.insert("hi")); // Insert a string into the set
    assert(a.insert("test")); // Insert another string into the set
    assert(a.insert("")); // Insert an empty string into the set
    assert(a.insert("aa")); // Insert another string into the set
    assert(a.size() == 4); // Check if the size is correct after insertions

    assert(a.erase("hi")); // Erase a string from the set
    assert(a.size() == 3); // Check if the size is correct after erasure
    assert(!a.erase("hi")); // Try to erase a string that does not exist
    assert(a.size() == 3); // Check if the size remains unchanged
    assert(a.erase("aa")); // Erase another string from the set
    assert(a.erase("")); // Erase an empty string from the set
    assert(a.erase("test")); // Erase another string from the set
    assert(a.size() == 0); // Check if the set is empty after all erasures
    assert(a.empty()); // Check if the set is empty
    assert(!a.erase("")); // Try to erase from an empty set

    // Check if all erased strings are not present in the set
    assert(!a.contains("hi") && !a.contains("test") && !a.contains("aa") && !a.contains(""));

    cout << "test case 3 passed" << endl;
}

#elif TESTNUM == 4
// Testing the get function

int main() {
    Set a;
    assert(a.insert("hi")); // Insert a string into the set
    assert(a.insert("test")); // Insert another string into the set
    assert(a.insert("")); // Insert an empty string into the set
    assert(a.insert("aa")); // Insert another string into the set
    assert(a.size() == 4); // Check if the size is correct after insertions

    string x;
    assert(a.get(0, x) && x == "test"); // Get the item at index 0 and compare with expected value
    assert(a.get(1, x) && x == "hi"); // Get the item at index 1 and compare with expected value
    assert(a.get(2, x) && x == "aa"); // Get the item at index 2 and compare with expected value
    assert(a.get(3, x) && x == ""); // Get the item at index 3 and compare with expected value
    assert(!a.get(4, x) && x == ""); // Try to get an item at an out-of-range index
    assert(a.size() == 4); // Check if the size remains unchanged

    assert(a.insert("zzz")); // Insert another string into the set
    assert(a.get(0, x) && x == "zzz"); // Get the new item at index 0 and compare with expected value
    assert(a.get(4, x) && x == ""); // Try to get an item at an out-of-range index
    assert(!a.get(-10, x) && x == ""); // Try to get an item at a negative index
    assert(a.size() == 5); // Check if the size is correct after insertion

    // Check if all inserted strings are present in the set
    assert(a.contains("hi") && a.contains("test") && a.contains("aa") && a.contains("") && a.contains("zzz"));

    cout << "test case 4 passed" << endl;
}

#elif TESTNUM == 5
// Testing the swap function

int main() {
    Set a;
    assert(a.insert("hi")); // Insert a string into the set
    assert(a.insert("test")); // Insert another string into the set
    assert(a.insert("")); // Insert an empty string into the set
    assert(a.insert("aa")); // Insert another string into the set
    assert(a.size() == 4); // Check if the size is correct after insertions

    Set b;
    assert(b.insert("math")); // Insert a string into another set
    assert(b.insert("physics")); // Insert another string into another set
    assert(b.insert("aa")); // Insert another string into another set

    a.swap(b); // Swap the contents of two sets

    assert(a.size() == 3 && b.size() == 4); // Check if the sizes are correct after swapping
    assert(a.contains("math") && a.contains("aa") && a.contains("physics")); // Check if the first set contains elements from the second set after swapping
    assert(b.contains("hi") && b.contains("test") && b.contains("aa") && b.contains("")); // Check if the second set contains elements from the first set after swapping

    Set c;
    b.swap(c); // Swap an empty set with another set
    assert(b.size() == 0 && c.size() == 4); // Check if the sizes are correct after swapping
    assert(!b.contains("hi") && !b.contains("test") && !b.contains("aa") && !b.contains("")); // Check if the first set is empty after swapping
    assert(c.contains("hi") && c.contains("test") && c.contains("aa") && c.contains("")); // Check if the second set contains elements from the first set after swapping

    Set d;
    d.swap(b); // Swap an empty set with another empty set
    assert(b.size() == 0 && d.size() == 0); // Check if both sets are empty after swapping

    cout << "test case 5 passed" << endl;
}

#elif TESTNUM == 6
// Testing the copy constructor

int main() {
    Set a;
    assert(a.insert("hi")); // Insert a string into the set
    assert(a.insert("test")); // Insert another string into the set
    assert(a.insert("")); // Insert an empty string into the set
    assert(a.insert("aa")); // Insert another string into the set
    assert(a.size() == 4); // Check if the size is correct after insertions

    Set b(a); // Create a copy of the set
    assert(a.size() == 4 && b.size() == 4); // Check if the sizes of both sets are correct
    assert(a.contains("hi") && a.contains("test") && a.contains("aa") && a.contains("")); // Check if the original set contains all inserted strings
    assert(b.contains("hi") && b.contains("test") && b.contains("aa") && b.contains("")); // Check if the copied set contains all inserted strings

    Set c;
    c.insert("car");
    c.insert("helicopter");
    Set d(c); // Create a copy of another set
    assert(c.size() == 2 && d.size() == 2); // Check if the sizes of both sets are correct
    c.erase("car"); // Modify the original set
    d.insert("bicycle"); // Modify the copied set
    assert(c.size() == 1 && d.size() == 3); // Check if the sizes of both sets are correct after modification

    Set e;
    Set f(e); // Create a copy of an empty set
    assert(f.size() == 0 && e.size() == 0); // Check if both sets are empty

    cout << "test case 6 passed" << endl;
}

#elif TESTNUM == 7
// Testing the assignment operator

int main() {
    Set a;
    assert(a.insert("hi")); // Insert a string into the set
    assert(a.insert("test")); // Insert another string into the set
    assert(a.insert("")); // Insert an empty string into the set
    assert(a.insert("aa")); // Insert another string into the set
    assert(a.size() == 4); // Check if the size is correct after insertions

    Set b;
    b = a; // Assign the contents of one set to another

    assert(a.size() == 4 && b.size() == 4); // Check if the sizes of both sets are correct
    assert(a.contains("hi") && a.contains("test") && a.contains("aa") && a.contains("")); // Check if the original set contains all inserted strings
    assert(b.contains("hi") && b.contains("test") && b.contains("aa") && b.contains("")); // Check if the assigned set contains all inserted strings

    Set c;
    b = c; // Assign an empty set to another set
    assert(b.size() == 0 && c.size() == 0); // Check if both sets are empty
    assert(!b.contains("hi") && !b.contains("test") && !b.contains("aa") && !b.contains("")); // Check if the assigned set is empty
    assert(!c.contains("hi") && !c.contains("test") && !c.contains("aa") && !c.contains("")); // Check if the original set is empty

    Set d;
    d = c; // Assign an empty set to another empty set
    assert(d.size() == 0 && c.size() == 0); // Check if both sets are empty

    cout << "test case 7 passed" << endl;
}

#elif TESTNUM == 8
// Testing the unite function

int main() {
    Set a;
    assert(a.insert("hi")); // Insert a string into the set
    assert(a.insert("test")); // Insert another string into the set
    assert(a.insert("")); // Insert an empty string into the set
    assert(a.insert("aa")); // Insert another string into the set
    assert(a.size() == 4); // Check if the size is correct after insertions

    Set b;
    assert(b.insert("math")); // Insert a string into another set
    assert(b.insert("physics")); // Insert another string into another set
    assert(b.insert("aa")); // Insert another string into another set

    Set c;
    unite(a, b, c); // Unite the contents of two sets into a third set
    assert(a.size() == 4 && b.size() == 3 && c.size() == 6); // Check if the sizes of all sets are correct after uniting
    assert(c.contains("hi") && c.contains("test") && c.contains("aa") && c.contains("") && c.contains("math") && c.contains("physics")); // Check if the united set contains all elements from both sets

    Set d;
    assert(d.insert("red")); // Insert a string into another set
    assert(d.insert("blue")); // Insert another string into another set
    assert(d.insert("green")); // Insert another string into another set
    unite(a, b, d); // Unite the contents of two sets into another set
    assert(a.size() == 4 && b.size() == 3 && d.size() == 6); // Check if the sizes of all sets are correct after uniting
    assert(d.contains("hi") && d.contains("test") && d.contains("aa") && d.contains("") && d.contains("math") && d.contains("physics")); // Check if the united set contains all elements from both sets

    Set e;
    assert(e.insert("dog")); // Insert a string into another set
    unite(d, e, d); // Unite the contents of a set with another set and overwrite the first set
    assert(d.size() == 7 && e.size() == 1); // Check if the sizes of both sets are correct after uniting
    assert(d.contains("hi") && d.contains("test") && d.contains("aa") && d.contains("") && d.contains("math") && d.contains("physics") && d.contains("dog")); // Check if the united set contains all elements from both sets

    Set f;
    unite(f, e, f); // Unite an empty set with another set
    assert(f.size() == 1 && f.contains("dog")); // Check if the united set contains all elements from the second set

    Set g(f);
    unite(g, f, g); // Unite a set with another set and overwrite the first set
    assert(g.size() == 1 && g.contains("dog")); // Check if the united set contains all elements from both sets

    cout << "test case 8 passed" << endl;
}

#elif TESTNUM == 9
// Testing the inonlyone function

int main() {
    Set a;
    assert(a.insert("hi")); // Insert a string into the set
    assert(a.insert("test")); // Insert another string into the set
    assert(a.insert("")); // Insert an empty string into the set
    assert(a.insert("aa")); // Insert another string into the set
    assert(a.size() == 4); // Check if the size is correct after insertions

    Set b;
    assert(b.insert("math")); // Insert a string into another set
    assert(b.insert("physics")); // Insert another string into another set
    assert(b.insert("aa")); // Insert another string into another set

    Set c;
    inOnlyOne(a, b, c); // Get elements that are only in one of the two sets
    assert(a.size() == 4 && b.size() == 3 && c.size() == 5); // Check if the sizes of all sets are correct
    assert(c.contains("hi") && c.contains("test") && c.contains("") && c.contains("math") && c.contains("physics")); // Check if the resulting set contains elements that are only in one of the original sets

    Set d;
    Set e;
    inOnlyOne(a, d, e); // Get elements that are only in one of the two sets
    for (int i = 0; i < a.size(); i++) {
        string x;
        a.get(i, x);
        assert(e.contains(x)); // Check if the resulting set contains elements that are only in one of the original sets
    }

    inOnlyOne(a, d, a); // Get elements that are only in one of the two sets and overwrite one of the original sets
    assert(a.contains("hi") && a.contains("test") && a.contains("") && a.contains("aa")); // Check if the original set contains elements that are only in one of the original sets

    cout << "test case 9 passed" << endl;
}

#elif TESTNUM == 10
// Additional test case 1

int main() {
    Set a;
    assert(a.insert("apple")); // Insert a string into the set
    assert(a.insert("banana")); // Insert another string into the set
    assert(a.insert("cherry")); // Insert another string into the set
    assert(a.size() == 3); // Check if the size is correct after insertions

    Set b;
    assert(b.insert("cherry")); // Insert a string into another set
    assert(b.insert("dates")); // Insert another string into another set
    assert(b.insert("fig")); // Insert another string into another set

    Set c;
    unite(a, b, c); // Unite the contents of two sets into a third set
    assert(a.size() == 3 && b.size() == 3 && c.size() == 5); // Check if the sizes of all sets are correct after uniting
    assert(c.contains("apple") && c.contains("banana") && c.contains("cherry") && c.contains("dates") && c.contains("fig")); // Check if the united set contains all elements from both sets

    cout << "test case 10 passed" << endl;
}
#endif
