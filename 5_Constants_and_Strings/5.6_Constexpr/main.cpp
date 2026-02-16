#include <iostream>

constexpr int max(int x, int y) { return (x > y) ? x : y; }

int main() {
    constexpr double gravity{9.8}; // OK: 9.8 is a literal
    constexpr int sum{4 + 5};      // OK: 4 + 5 is a constant expression

    constexpr int m{max(5, 6)}; // OK: evaluated at compile time

    return 0;
}
