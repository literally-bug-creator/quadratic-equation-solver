add_subdirectory(third-party/googletest)

include(GoogleTest)

file(GLOB_RECURSE TESTS_SRC_FILES ./tests/*.cpp)
add_executable(run_tests ${TESTS_SRC_FILES})
target_link_libraries(run_tests gtest gtest_main quadratic-equation-solver)
include_directories(include)

enable_testing()
include(GoogleTest)
gtest_discover_tests(run_tests)
