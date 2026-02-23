cmake_minimum_required(VERSION 4.0)
project(learncpp LANGUAGES CXX)

# Set C++ standard to C++23 and disable compiler extensions
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Disable C++ modules (for clangd in VSCode)
set(CMAKE_CXX_SCAN_FOR_MODULES OFF)

include(FetchContent)

# Add plog library for "3.4 - Debugging Tactics"
FetchContent_Declare(
        plog
        GIT_REPOSITORY https://github.com/SergiusTheBest/plog.git
        GIT_TAG 1.1.11
)
FetchContent_MakeAvailable(plog)

add_subdirectory("1_Basics")
add_subdirectory("2_Function_and_Files")
add_subdirectory("3_Debugging")
add_subdirectory("4_Fundamental_Data_Types")
add_subdirectory("5_Constants_and_Strings")
add_subdirectory("6_Operators")
add_subdirectory("7_Bit_Manipulation")
add_subdirectory("8_Scope")
