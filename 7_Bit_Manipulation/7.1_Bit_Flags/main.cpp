#include <bitset>
#include <iostream>

int main() {
#pragma region MANIPULATION_FUNCTIONS
    std::bitset<8> b1{0b0000'0101};
    b1.set(3);  // turn on bit 3
    b1.flip(4); // flip bit 4
    std::cout << "b1: " << b1 << '\n';
    std::cout << b1.test(3) << '\n'; // prints if bit[3] is set
#pragma endregion

#pragma region QUERY_FUNCTIONS
    std::bitset<8> b2{0b0000'1101};

    std::cout << b2.size() << "\n";  // prints no. of bits (8)
    std::cout << b2.count() << '\n'; // prints no. of bits set to 1 (3)

    std::cout << std::boolalpha;
    std::cout << b2.all() << '\n';  // prints if all bits are true (false)
    std::cout << b2.any() << '\n';  // prints if any bit is true (true)
    std::cout << b2.none() << '\n'; // prints if all bits are false (false)
#pragma endregion
    return 0;
}
