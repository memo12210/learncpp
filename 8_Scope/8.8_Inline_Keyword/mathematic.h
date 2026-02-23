#ifndef MATHEMATIC_H
#define MATHEMATIC_H

#include <string_view>

// Inline variables
inline constexpr double pi{3.141592};
inline constexpr std::string_view info{"all about math."};

// Inline functions
inline double circumference(int radius) { return 2 * pi * radius; }
inline double area(int radius) { return pi * radius * radius; }

#endif
