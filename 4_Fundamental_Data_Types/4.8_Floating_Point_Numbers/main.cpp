#include <iomanip>
#include <iostream>
#include <limits>

int main() {
    std::cout << "sizeof float is: " << sizeof(float) << " bytes.\n";
    std::cout << "sizeof double is: " << sizeof(double) << " bytes.\n";
    std::cout << "sizeof long double is: " << sizeof(long double) << " bytes.\n";
    std::cout << '\n';

    // Checking whether our floating-point types are IEEE 754 compatible.
    std::cout << std::boolalpha; // print bool as `true` or `false`
    std::cout << "float is IEEE 754: " << std::numeric_limits<float>::is_iec559 << '\n';
    std::cout << "double is IEEE 754: " << std::numeric_limits<double>::is_iec559 << '\n';
    std::cout << "long double is IEEE 754: " << std::numeric_limits<long double>::is_iec559 << '\n';
    std::cout << '\n';

    // Printing floating-point values (std::cout shows 6 significant digits by default):
    std::cout << 9.87654321f << '\n';
    std::cout << 987.654321f << '\n';
    std::cout << 987654.321f << '\n';
    std::cout << 9876543.21f << '\n';
    std::cout << 0.0000987654321f << '\n';
    std::cout << '\n';

    // Printing floating-point values with fixed precision:
    std::cout << std::setprecision(17); // show 17 digits of precision
    std::cout << 3.33333333333333333333333333333333333333f <<'\n'; // f suffix means float
    std::cout << 3.33333333333333333333333333333333333333 << '\n'; // no suffix means double
    std::cout << '\n';

    // Never assume that you're floating point numbers are exact!
    double d1{0.1};
    std::cout << std::setprecision(17); // show 17 digits of precision
    std::cout << d1 << '\n'; // will print 0.10000000000000001
    double d2{};
    for (int i = 0; i < 10; ++i) {
        d2 += 0.1;
    }
    std::cout << d2 << '\n'; // will print 0.99999999999999989
    std::cout << '\n';

    // Inf and NaN special values
    std::cout << 5.0 / 0.0 << '\n'; // will print positive inf
    std::cout << -5.0 / 0.0 << '\n'; // will print negative inf
    std::cout << 0.0 / 0.0 << '\n'; // will print NaN

    return 0;

}