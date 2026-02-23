#include <string_view>

int g_x{2};              // External by default
extern const int g_y{3}; // Explicitly made external using 'extern'

std::string_view sayHi() { return "hi"; } // Functions are external by default
