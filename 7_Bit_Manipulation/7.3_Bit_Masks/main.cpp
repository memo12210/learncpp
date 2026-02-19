#include <bitset>
#include <iostream>

int main() {
    constexpr std::uint8_t mask0{0b0000'0001}; // represents bit 0
    constexpr std::uint8_t mask1{0b0000'0010}; // represents bit 1
    constexpr std::uint8_t mask2{0b0000'0100}; // represents bit 2
    constexpr std::uint8_t mask3{0b0000'1000}; // represents bit 3
    constexpr std::uint8_t mask4{0b0001'0000}; // represents bit 4
    constexpr std::uint8_t mask5{0b0010'0000}; // represents bit 5
    constexpr std::uint8_t mask6{0b0100'0000}; // represents bit 6
    constexpr std::uint8_t mask7{0b1000'0000}; // represents bit 7

    std::uint8_t flags{0b0101'1011};
#pragma region TESTING_BITS
    std::cout << "bit 0 is " << (static_cast<bool>(flags & mask0) ? "on\n" : "off\n");
    std::cout << "bit 1 is " << (static_cast<bool>(flags & mask1) ? "on\n" : "off\n");
    std::cout << "bit 2 is " << (static_cast<bool>(flags & mask2) ? "on\n" : "off\n");
    std::cout << "after testing bits: " << std::bitset<8>{flags} << '\n';
#pragma endregion

#pragma region SETTING_BITS
    flags |= mask2;           // turn on bit 2
    flags |= (mask6 | mask7); // turn bits 6 and 7 on at the same time
    std::cout << "bit 2 is " << (static_cast<bool>(flags & mask2) ? "on\n" : "off\n");
    std::cout << "after setting bits: " << std::bitset<8>{flags} << '\n';
#pragma endregion

#pragma region RESETTING_BITS
    flags &= ~mask0;           // turn off bit 0
    flags &= ~(mask6 | mask7); // turn bits 6 and 7 off at the same time
    std::cout << "bit 0 is " << (static_cast<bool>(flags & mask0) ? "on\n" : "off\n");
    std::cout << "after resetting bits: " << std::bitset<8>{flags} << '\n';
#pragma endregion

#pragma region FLIPPING_BITS
    flags ^= ~mask0;           // toggle bit 0
    flags ^= ~(mask6 | mask7); // toggle bits 6 and 7 at the same time
    std::cout << "bit 0 is " << (static_cast<bool>(flags & mask0) ? "on\n" : "off\n");
    std::cout << "after flipping bits: " << std::bitset<8>{flags} << '\n';
#pragma endregion

#pragma region EXTRACTING_VALUES
    // Extracting color values from a 32-bit integer (stored as RRGGBBAA)
    constexpr std::uint32_t pixel{0x73F4B0CC};

    // Bit masks
    constexpr std::uint32_t redBits{0xFF000000};
    constexpr std::uint32_t greenBits{0x00FF0000};
    constexpr std::uint32_t blueBits{0x0000FF00};
    constexpr std::uint32_t alphaBits{0x000000FF};

    // Use Bitwise AND to isolate the pixels for our given color,
    // then right shift the value into the lower 8 bits
    const std::uint8_t red{static_cast<std::uint8_t>((pixel & redBits) >> 24)};
    const std::uint8_t green{static_cast<std::uint8_t>((pixel & greenBits) >> 16)};
    const std::uint8_t blue{static_cast<std::uint8_t>((pixel & blueBits) >> 8)};
    const std::uint8_t alpha{static_cast<std::uint8_t>(pixel & alphaBits)};

    std::cout << "Your color contains:\n";
    std::cout << std::hex;

    std::cout << static_cast<int>(red) << " red\n";
    std::cout << static_cast<int>(green) << " green\n";
    std::cout << static_cast<int>(blue) << " blue\n";
    std::cout << static_cast<int>(alpha) << " alpha\n";
#pragma endregion
    return 0;
}
