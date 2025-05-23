cmake_minimum_required(VERSION 3.14)
project(quadratic-equation-solver)

include(FetchContent)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.8.1
)
FetchContent_MakeAvailable(Catch2)

add_library(quadratic_solver
    src/input/impl.cpp
    src/input/constants.cpp
    src/error.cpp
    src/number/impl.cpp
    src/number/constants.cpp
    src/coefficients/impl.cpp
    src/coefficients/constants.cpp
    src/solution.cpp
    src/solver/impl.cpp
    src/solver/constants.cpp
    src/output/impl.cpp
    src/output/constants.cpp
)

target_include_directories(quadratic_solver PUBLIC include)

add_executable(tests
    tests/test_error.cpp
    tests/test_number.cpp
    tests/test_coefficients.cpp
    tests/test_solution.cpp
)

target_compile_options(tests PRIVATE --coverage -O0 -g)
target_link_options(tests PRIVATE --coverage)

target_link_libraries(tests PRIVATE quadratic_solver Catch2::Catch2WithMain)
