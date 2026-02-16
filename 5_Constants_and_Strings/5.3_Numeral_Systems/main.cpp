#include <format> // C++20
#include <iostream>
#include <print> // C++23

int main() {
    // C++20, {:b} formats the argument as binary digits.
    // C++20, {:#b} formats the argument as 0b-prefixed binary digits.
    std::cout << std::format("{:b}\n", 0b1010); // prints "1010"
    std::cout << std::format("{:#b}\n", 0b1010); // prints "0b1010"

    // C++23, format/print two arguments (same as above)
    std::println("{:b} {:#b}", 0b1010, 0b1010); // prints "1010 0b1010"

    return 0;
}
