#include <iostream>

int get_number() {
    std::cout << "Enter a number: ";
    int y{};
    std::cin >> y; // can only execute at runtime

    return y; // this return expression is a runtime expression
}

// The return value of a non-constexpr function is a runtime expression
// even when the return value is a constant expression.
int five() {
    return 5; // this return expression is a constant expression
}

int main() {
    // Literals can be used in constant expressions
    5;              // constant expression
    1.2;            // constant expression
    "Hello world!"; // constant expression

    // Most operators that have constant expression operands
    // can be used in constant expressions.
    5 + 6;           // constant expression
    1.2 * 3.4;       // constant expression
    8 - 5.6;         // constant expression
    sizeof(int) + 1; // constant expression (sizeof known at compile-time)

    // The return values of non-constexpr functions can only be used
    // in runtime expressions.
    get_number(); // runtime expression
    five();       // runtime expression (even though return is constant)

    // Operators without constant expression operands can only be
    // used in runtime expressions.
    std::cout << 5; // runtime expression (std::cout -> not constant expr)
}
