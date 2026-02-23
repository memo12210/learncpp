#include <print>

int main(int argc, char **argv) { // argc and argv enters scope here
    int i{5};                     // i enters scope here
    double d{4.0};                // d enters scope here
    std::println("{}, {}", i, d);
} // argc, argv, i and d go out of scope here
