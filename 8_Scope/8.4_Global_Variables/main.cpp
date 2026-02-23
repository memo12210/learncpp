// Non-constant global variables
#include <print>

int g_a;    // defines non-initialized global variable (zero initialized by default)
int g_b{};  // defines explicitly value-initialized global variable
int g_c{1}; // defines explicitly initialized global variable

// Const global variables
const int g_d{2}; // defines initialized global const

// Constexpr global variables
constexpr int g_e{3}; // defines initialized global constexpr

int main() {
    g_c = 42;
    std::println("{}, {}, {}, {}, {}", g_a, g_b, g_c, g_d, g_e);
    return 0;
}
