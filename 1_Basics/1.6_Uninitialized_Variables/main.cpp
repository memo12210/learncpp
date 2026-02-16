#include <iostream>

// In GCC -> prints nothing
// In Clang -> prints some garbage value
int main() {
    int x; // uninitialized variable, contains garbage value
    std::cout << x; // undefined behavior, we don't know what it will print

    return 0;
}
