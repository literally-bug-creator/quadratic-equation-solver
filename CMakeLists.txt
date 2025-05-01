cmake_minimum_required(VERSION 3.14)
project(quadratic-equation-solver)

include(FetchContent)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.8.1
)
FetchContent_MakeAvailable(Catch2)

add_executable(tests
    tests/test_error.cpp
    tests/test_number.cpp
    tests/test_number_kit.cpp
)

target_compile_options(tests PRIVATE --coverage -O0 -g)
target_link_options(tests PRIVATE --coverage)

target_link_libraries(tests Catch2::Catch2WithMain)
