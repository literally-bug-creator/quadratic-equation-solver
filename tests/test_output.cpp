#include <catch2/catch_test_macros.hpp>

#include <sstream>
#include <string>

#include "../include/output.hpp"
#include "../src/output/output_constants.cpp"
#include "tools.cpp"

TEST_CASE( "output(any, error_solution)", "[public][output]" ) {
    std::ostringstream out;
    std::string error_message = random_string( MAX_INT );
    Error error = make_error( SOLUTION_ERROR, error_message );
    Number x1 = random_number();
    Number x2 = random_number();
    Solution solution = make_solution( TWO_ROOTS, x1, x2, error );

    output( out, solution );

    REQUIRE( out.str() == ( error_message + "\n" ) );
}

TEST_CASE( "output(any, linear) in cycle", "[public][output]" ) {
    for ( int i = 0; i < TESTS_AMOUNT; i++ ) {
        std::ostringstream out;
        Solution solution = random_linear_solution();
        std::string expected_msg =
            OutputMessages::SINGLE_ROOT + to_string( solution.x1 ) + "\n";

        output( out, solution );

        REQUIRE( out.str() == expected_msg );
    }
}

TEST_CASE( "output(any, one_root) in cycle", "[public][output]" ) {
    for ( int i = 0; i < TESTS_AMOUNT; i++ ) {
        std::ostringstream out;
        Solution solution = random_single_root_solution();
        std::string expected_msg =
            OutputMessages::SINGLE_ROOT + to_string( solution.x1 ) + "\n";

        output( out, solution );

        REQUIRE( out.str() == expected_msg );
    }
}

TEST_CASE( "output(any, two_roots) in cycle", "[public][output]" ) {
    for ( int i = 0; i < TESTS_AMOUNT; i++ ) {
        std::ostringstream out;
        Solution solution = random_two_roots_solution();
        std::string first_root_msg =
            OutputMessages::FIRST_ROOT + to_string( solution.x1 ) + "\n";
        std::string second_root_msg =
            OutputMessages::SECOND_ROOT + to_string( solution.x2 ) + "\n";
        std::string expected_msg = first_root_msg + second_root_msg;

        output( out, solution );

        REQUIRE( out.str() == expected_msg );
    }
}

TEST_CASE( "output(any, no_roots) in cycle", "[public][output]" ) {
    for ( int i = 0; i < TESTS_AMOUNT; i++ ) {
        std::ostringstream out;
        Solution solution = random_no_roots_solution();
        std::string expected_msg = OutputMessages::NO_ROOTS + "\n";

        output( out, solution );

        REQUIRE( out.str() == expected_msg );
    }
}
