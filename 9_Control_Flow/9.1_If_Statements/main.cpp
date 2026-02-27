#include <print>

void ifelse(bool a, bool b, bool c) {
    if (a) // always evaluates
        std::println("a");
    else if (b) // only evaluates when prior if-statement condition is false
        std::println("b");
    else if (c) // only evaluates when prior if-statement condition is false
        std::println("c");
    std::println();
}

void ifif(bool a, bool b, bool c) {
    if (a) // always evaluates
        std::println("a");
    if (b) // always evaluates
        std::println("b");
    if (c) // always evaluates
        std::println("c");
    std::println();
}

int main() {
    ifelse(true, true, true);
    ifif(true, true, true);
    return 0;
}
