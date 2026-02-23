// Internal global variables definitions:
static int g_a;    // defines non-initialized internal global variable (zero initialized by default)
static int g_b{1}; // defines initialized internal global variable

const int g_c{2};     // defines initialized internal global const variable
constexpr int g_d{3}; // defines initialized internal global constexpr variable

// Internal function definitions:
static int foo() { return 100; }; // defines internal function
