#include <print>

constexpr double gravity{9.8};

void non_constexpr_if() {
    // Even though the condition is compile-time constant,
    // it is evaluated at runtime.
    if (gravity == 9.8) {
        std::println("earth gravity");
    } else {
        // Even though the condition is never false,
        // this else statement is included in the executable.
        std::println("not earth gravity");
    }
}

void constexpr_if() {
    // This if statement is now evaluated at compile-time.
    if constexpr (gravity == 9.8) {
        std::println("earth gravity");
    } else {
        // This line is effectively deleted by the compiler.
        // It will not exist in the final executable.
        std::println("not earth gravity");
    }
}

int main() {
    non_constexpr_if();
    constexpr_if();
    return 0;
}
