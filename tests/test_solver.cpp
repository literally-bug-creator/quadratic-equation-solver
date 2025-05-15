#include <catch2/catch_test_macros.hpp>

#include "../include/solver.hpp"
#include "coefficients.hpp"
#include "constants.hpp"
#include "solution.hpp"
#include "tools.cpp"

const int RAND_TESTS_AMOUNT = 1000;
const double ZERO_DOUBLE = 0;

TEST_CASE( "solve_equation(no_roots_coefficients)", "[solver]" ) {
    Coefficients coeffs = inf_roots_coefficients();
    SolutionType expected_type = SolutionType::NO_ROOTS;
    Error expected_error = Errors::OK;

    Solution solution = solve_equation( coeffs );

    REQUIRE( get_solution_type( solution ) == expected_type );
    REQUIRE( get_error( solution ).code == expected_error.code );
}

TEST_CASE( "solve_equation(inf_roots_coefficients)", "[solver]" ) {
    Coefficients coeffs = inf_roots_coefficients();
    SolutionType expected_type = SolutionType::INF_ROOTS;
    Error expected_error = Errors::OK;

    Solution solution = solve_equation( coeffs );

    REQUIRE( get_solution_type( solution ) == expected_type );
    REQUIRE( get_error( solution ).code == expected_error.code );
}

TEST_CASE( "solve_equation(single_root_coefficients)", "[solver]" ) {
    for ( int i = 0; i < RAND_TESTS_AMOUNT; i++ ) {
        Coefficients coeffs = random_single_root_coefficients();
        SolutionType expected_type = SolutionType::SINGLE_ROOT;
        Error expected_error = Errors::OK;

        Solution solution = solve_equation( coeffs );

        REQUIRE( get_solution_type( solution ) == expected_type );
        REQUIRE( get_error( solution ).code == expected_error.code );
    }
}

TEST_CASE( "solve_equation(two_roots_coefficients)", "[solver]" ) {
    for ( int i = 0; i < RAND_TESTS_AMOUNT; i++ ) {
        Coefficients coeffs = random_two_roots_coefficients();
        SolutionType expected_type = SolutionType::TWO_ROOTS;
        Error expected_error = Errors::OK;

        Solution solution = solve_equation( coeffs );

        REQUIRE( get_solution_type( solution ) == expected_type );
        REQUIRE( get_error( solution ).code == expected_error.code );
    }
}
