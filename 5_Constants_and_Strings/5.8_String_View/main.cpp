#include <iostream>
#include <string>
#include <string_view>

// Much better to use string_view for read-only purposes.
void print(std::string_view str) { std::cout << "prints " << str << '\n'; }

int main() {
    // string_view accepts ANYTHING (const char*, string, string_view)
    print("hello"); // const char*
    std::string str{"Foo"};
    print(str); // std::string

    // Assinging a new value to a string_view changes what it is looking at,
    // NOT the original string data.
    std::string name{"Alex"};
    std::string_view sv{name}; // sv now looks at "Alex".
    sv = "Mehmet";             // sv now looks at "Mehmet". `name` is still "Alex".

    // string_view literals:
    using namespace std::string_view_literals;
    std::cout << "cat\n"sv; // "cat\n" is a string_view

    // Unlike string, string_view fully supports constepxr:
    constexpr std::string_view greet{"Hello there!"}; // preferred for compile-time constants
}
