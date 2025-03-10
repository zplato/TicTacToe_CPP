cmake_minimum_required(VERSION 3.10)

# Define the project name
project(TicTacToe_CPP)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set the dynamic runtime MDd for debug and MD for release
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MDd")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MD")

# Set the runtime library to /MD for both target executables
add_compile_options($<$<CONFIG:Debug>:/MDd>)
add_compile_options($<$<CONFIG:Release>:/MD>)

# Create TicTacToe_CPP as a library
add_library(TicTacToe_CPP_lib src/TicTacToe.cpp)

# Fetch GoogleTest (this will download and build GoogleTest)
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG main # or a newer release tag
)
FetchContent_MakeAvailable(googletest)

# Create a test executable
add_executable(TicTacToeTest test/test_Tic_Tac_Toe.cpp )

# Link the test executable with GoogleTest
target_link_libraries(TicTacToeTest gtest_main TicTacToe_CPP_lib)

# Add tests
enable_testing()
add_test(NAME TicTacToeTest COMMAND TicTacToeTest)

# Add the standalone executable
# add_executable(TicTacToe_Game src/TicTacToe.cpp) # Only if this has a main function