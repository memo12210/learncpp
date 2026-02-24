#include <print>
#include <string_view>

// Unnamed namespaces are the modern C++ replacement
// for `static` functions and variables.
namespace {
    // Variables/functions inside the unnamed namespace are forced
    // to have internal linkage.
    int someValue{100};
    void someFunction() { std::println("{}", someValue); }
} // namespace

// An inline namespace is used primarily for versioning code.
namespace V1 {
    std::string_view foo() { return "v1"; }
} // namespace V1

inline namespace V2 {
    std::string_view foo() { return "v2"; }
} // namespace V2

int main() {
    someFunction(); // no namespace needed

    std::println("{}", V1::foo()); // calls the V1 version
    std::println("{}", V2::foo()); // calls the V2 version

    std::println("{}", foo()); // calls the inline version (V2)

    return 0;
}
