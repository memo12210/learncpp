#include <iostream>
#include <string>

int main() {
    // Usage of std::string:
    std::string str{"Mehmet"};
    std::cout << str << '\n';
    str = "Some long sentence"; // automatically reallocates memory

    // Input/Output:
    std::cout << "Pick 1 or 2: ";
    int choice{};
    std::cin >> choice; // if we type 2, the cin actually reads "2\n"

    // "\n" remains in the buffer from the previous input.
    std::cout << "Enter your name: ";
    std::string name{};
    std::getline(std::cin >> std::ws, name); // ignores the previous "\n"


    // String length
    std::cout << str << " has " << str.length() << " characters.\n"; // does not include null-terminator ('\0')

    // String literals
    using namespace std::string_literals;
    std::cout << "foo\n";  // no suffix is a C-style string literal
    std::cout << "bar\n"s; // s suffix is a std::string literal

    return 0;
}
