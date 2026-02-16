#define ENABLE_DEBUG
#include <iostream>

int get_user_input() {
#ifdef ENABLE_DEBUG
    // We use `cerr` since it is unbuffered (instant output)
    std::cerr << "get_user_input() called\n";
#endif

    std::cout << "Enter a number: ";
    int x{};
    std::cin >> x;
    return x;
}

int main() {
#ifdef ENABLE_DEBUG
    std::cerr << "main() called\n";
#endif
    int x{get_user_input()};
    std::cout << "You entered: " << x << '\n';
    return 0;
}
