#include <print>
#include <string_view>

#pragma region A_CPP_EXTERNALS
extern int g_x;       // Tells the compiler g_x is defined elsewhere
extern const int g_y; // Tells the compiler g_y is defined elsewhere

std::string_view sayHi(); // Forward declaration (no body, no 'extern' needed)
#pragma endregion

int main() {
    std::println("{}, {}, {}", g_x, g_y, sayHi());
    return 0;
}
