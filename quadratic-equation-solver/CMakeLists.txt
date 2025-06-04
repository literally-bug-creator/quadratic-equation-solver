file (GLOB_RECURSE SOURCES "src/*.cpp")
add_library(quadratic-equation-solver SHARED ${SOURCES})

target_include_directories(quadratic-equation-solver PUBLIC include)
