add_subdirectory(third-party/long-arithmetic)

file (GLOB_RECURSE SOURCES "src/*.cpp")
add_library(quadratic-equation-solver SHARED ${SOURCES})

target_link_libraries(quadratic-equation-solver PRIVATE long_arithmetic)
target_include_directories(quadratic-equation-solver PUBLIC include)
