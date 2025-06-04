cmake_minimum_required(VERSION 3.14)
project(quadratic-equation-solver)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(quadratic-equation-solver)
# add_subdirectory(benchmark)

enable_testing()
add_subdirectory(tests)

set(CMAKE_CXX_FLAGS_DEBUG "-Wall -g")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -Wall -DNDEBUG")

message(STATUS "CMAKE_CXX_FLAGS_DEBUG: ${CMAKE_CXX_FLAGS_DEBUG}")
message(STATUS "CMAKE_CXX_FLAGS_RELEASE: ${CMAKE_CXX_FLAGS_RELEASE}")
message(STATUS "CURRENT ENVIRONMENT: ${CMAKE_BUILD_TYPE}")

add_executable(main main.cpp)
target_link_libraries(main quadratic-equation-solver)
