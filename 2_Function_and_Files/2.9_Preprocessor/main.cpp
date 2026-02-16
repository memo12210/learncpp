#include <iostream> // Every line that starts with `#` is a directive.

// Executing `g++ -E main.cpp > main.i` will allow us to
// view the translation unit of this code.
int main() {
    int i;
    std::cout << "Hello there!\n";
    return 0;
}
