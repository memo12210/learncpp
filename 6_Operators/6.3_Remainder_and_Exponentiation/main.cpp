#include <cassert> // for assert
#include <cmath>
#include <cstdint> // for std::int64_t
#include <iostream>
#include <limits> // for std::numeric_limits

// Demonstration of the remainder operator (%) to check if a given value is even or odd.
constexpr bool is_even(int x) { return (x % 2 == 0); }


// A safer (but slower) version of powint() that checks for overflow
// note: exp must be non-negative
// Returns std::numeric_limits<std::int64_t>::max() if overflow occurs
constexpr std::int64_t powint_safe(std::int64_t base, int exp) {
    assert(exp >= 0 && "powint_safe: exp parameter has negative value");

    // Handle 0 case
    if (base == 0)
        return (exp == 0) ? 1 : 0;

    std::int64_t result{1};

    // To make the range checks easier, we'll ensure base is positive
    // We'll flip the result at the end if needed
    bool negative_result{false};

    if (base < 0) {
        base = -base;
        negative_result = (exp & 1);
    }

    while (exp > 0) {
        if (exp & 1) // if exp is odd
        {
            // Check if result will overflow when multiplied by base
            if (result > std::numeric_limits<std::int64_t>::max() / base) {
                std::cerr << "powint_safe(): result overflowed\n";
                return std::numeric_limits<std::int64_t>::max();
            }

            result *= base;
        }

        exp /= 2;

        // If we're done, get out here
        if (exp <= 0)
            break;

        // The following only needs to execute if we're going to iterate again

        // Check if base will overflow when multiplied by base
        if (base > std::numeric_limits<std::int64_t>::max() / base) {
            std::cerr << "powint_safe(): base overflowed\n";
            return std::numeric_limits<std::int64_t>::max();
        }

        base *= base;
    }

    if (negative_result)
        return -result;

    return result;
}

int main() {
    std::cout << std::boolalpha; // for printing "true" or "false" on booleans
    std::cout << "4 is even: " << is_even(4) << '\n';

    double result{std::pow(3.0, 4.0)};

    std::cout << powint_safe(7, 12) << '\n';  // 7 to the 12th power
    std::cout << powint_safe(70, 12) << '\n'; // 70 to the 12th power (will return UINT64_MAX)

    return 0;
}
