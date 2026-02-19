#include <cmath>
#include <iostream>

// Method 1: Absolute Epsilon (not ideal, does not scale for very large/small numbers)
bool approximatelyEqualAbs(double a, double b, double absEps) { return std::abs(a - b) <= absEps; }

// Method 2: Knuth's Relative Epsilon (does not work if a and b are very close to 0.0)
bool approximatelyEqualRel(double a, double b, double relEps) {
    return (std::abs(a - b) <= (std::max(std::abs(a), std::abs(b)) * relEps));
}

// Method 3: Hybrid Approach (works best!)
bool approximatelyEqualAbsRel(double a, double b, double absEps, double relEps) {
    // Check if the numbers are really close (needed for near-zero values)
    if (std::abs(a - b) <= absEps)
        return true;

    // Otherwise, fall back to Knuth's algorithm
    return approximatelyEqualRel(a, b, relEps);
}

int main() {
    // Because floating point numbers cannot store all values precisely,
    // math operations result in tiny rounding errors!
    constexpr double a{0.1 + 0.2};
    constexpr double b{0.3};

    if (a == b) {
        std::cout << "'0.1 + 0.2' and '0.3' is equal.\n";
    } else { // else statement will execute...
        std::cout << "'0.1 + 0.2' and '0.3' is not equal.\n";
    }

    constexpr double absEps{1e-12};
    constexpr double relEps{1e-8};

#pragma region ABSOLUTE_EPSILON
    if (approximatelyEqualAbs(a, b, absEps)) {
        std::cout << "'0.1 + 0.2' and '0.3' is equal.\n";
    } else { // else statement will execute...
        std::cout << "'0.1 + 0.2' and '0.3' is not equal.\n";
    }
#pragma endregion

#pragma region KNUTH_RELATIVE
    if (approximatelyEqualRel(a, b, relEps)) {
        std::cout << "'0.1 + 0.2' and '0.3' is equal.\n";
    } else { // else statement will execute...
        std::cout << "'0.1 + 0.2' and '0.3' is not equal.\n";
    }

    if (approximatelyEqualRel(1e-7, -1e-7, relEps)) {
        std::cout << "Knuth works for numbers extremely close to 0.0\n";
    } else {
        std::cout << "Knuth does not work for numbers extremely close to 0.0\n";
    }
#pragma endregion

#pragma region HYBRID_APPROACH
    if (approximatelyEqualAbsRel(a, b, absEps, relEps)) {
        std::cout << "'0.1 + 0.2' and '0.3' is equal.\n";
    } else { // else statement will execute...
        std::cout << "'0.1 + 0.2' and '0.3' is not equal.\n";
    }

    if (approximatelyEqualAbsRel(1e-7, -1e-7, absEps, relEps)) {
        std::cout << "Hybrid works for numbers extremely close to 0.0\n";
    } else {
        std::cout << "Hybrid does not work for numbers extremely close to 0.0\n";
    }
#pragma endregion
    return 0;
}
