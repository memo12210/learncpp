#include <cstdint>
#include <iostream>

int main() {
#pragma region FIXED_WITH_INTEGERS
    std::cout << "Range of int8_t is: [" << INT8_MIN << ", " << INT8_MAX << "]\n";
    std::cout << "Range of uint8_t is: [0, " << UINT8_MAX << "]\n";
    std::cout << "Range of int16_t is: [" << INT16_MIN << ", " << INT16_MAX << "]\n";
    std::cout << "Range of uint16_t is: [0, " << UINT16_MAX << "]\n";
    std::cout << "Range of int32_t is: [" << INT32_MIN << ", " << INT32_MAX << "]\n";
    std::cout << "Range of uint32_t is: [0, " << UINT32_MAX << "]\n";
    std::cout << "Range of int64_t is: [" << INT64_MIN << ", " << INT64_MAX << "]\n";
    std::cout << "Range of uint64_t is: [0, " << UINT64_MAX << "]\n";
    std::cout << '\n';
#pragma endregion

#pragma region FAST_AND_LEAST
    // Generally avoid using fast and least types.
    std::cout << "The fastest type that is at least 32 bits is: " << typeid(std::int_fast32_t).name() << '\n';
    std::cout << "The smallest type that is at least 32 bits is: " << typeid(std::int_least32_t).name() << '\n';
    std::cout << '\n';
#pragma endregion

#pragma region SIZE_T
    switch (sizeof(std::size_t)) {
        case 4:
            std::cout << "This program runs on a 32-bit system.\n";
            break;
        case 8:
            std::cout << "This program runs on a 64-bit system.\n";
            break;
        default:
            std::cout << "Size of size_t is: " << sizeof(size_t) << " bytes.\n";
            break;
    }
#pragma endregion
    return 0;
}