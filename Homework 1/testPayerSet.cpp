#include "PayerSet.h"
#include <cassert>
#include <iostream>

int main() {
    PayerSet payers;

    // Test adding unique account numbers
    assert(payers.add(123456789)); // should be true
    assert(payers.add(987654321)); // should be true
    assert(payers.add(192837465)); // should be true
    assert(!payers.add(123456789)); // should be false, duplicate

    // Check size
    assert(payers.size() == 3); // 3 unique account numbers

    // Testing print function
    std::cout << "Payer Accounts:" << std::endl;
    payers.print(); // Expected output: 123456789, 987654321, 192837465 in any order

    std::cout << "All tests passed." << std::endl;
    return 0;
}
