// Internal global variables definitions:
#include <print>
static int g_a;    // defines non-initialized internal global variable (zero initialized by default)
static int g_b{1}; // defines initialized internal global variable

const int g_c{2};     // defines initialized internal global const variable
constexpr int g_d{3}; // defines initialized internal global constexpr variable

// Internal function definitions:
static int foo() { return 200; }; // defines internal function

// Notice that these variables are different from the ones from the a.cpp
int main() {
    std::println("{}, {}, {}, {}, {}", g_a, g_b, g_c, g_d, foo());
    return 0;
}
