#include <catch2/catch_test_macros.hpp>

#include "../include/solution.hpp"
#include "tools.cpp"

const int RAND_TESTS_AMOUNT = 1000;
const double ZERO_DOUBLE = 0;
const Number ZERO_NUMBER = Number( ZERO_DOUBLE, Errors::OK );

TEST_CASE( "get_error(random error & x1 & x2 & type)", "[solution]" ) {
    for ( int i = 0; i < RAND_TESTS_AMOUNT; i++ ) {
        SolutionType type = random_solution_type();
        Number x1 = random_number();
        Number x2 = random_number();
        Error expected_error = random_error();
        Solution solution = Solution( type, x1, x2, expected_error );

        Error real_error = get_error( solution );

        REQUIRE( expected_error.code == real_error.code );
        REQUIRE( expected_error.message == real_error.message );
    }
}

TEST_CASE( "get_solution_type(each_type, random error & values)",
           "[solution]" ) {
    for ( SolutionType expected_type : get_all_solution_types() ) {
        Error error = random_error();
        Number x1 = random_number();
        Number x2 = random_number();
        Solution solution = Solution( expected_type, x1, x2, error );

        SolutionType real_type = get_solution_type( solution );

        REQUIRE( expected_type == real_type );
    }
}

TEST_CASE( "get_first_root(random error & x1 & x2 & type)", "[solution]" ) {
    for ( int i = 0; i < RAND_TESTS_AMOUNT; i++ ) {
        SolutionType type = random_solution_type();
        Number expected_root = random_number();
        Number x2 = random_number();
        Error error = random_error();
        Solution solution = Solution( type, expected_root, x2, error );

        Number real_root = get_first_root( solution );

        REQUIRE( is_equal( expected_root, real_root ) );
    }
}

TEST_CASE( "get_second_root(random error & x1 & x2 & type)", "[solution]" ) {
    for ( int i = 0; i < RAND_TESTS_AMOUNT; i++ ) {
        SolutionType type = random_solution_type();
        Number x1 = random_number();
        Number expected_root = random_number();
        Error error = random_error();
        Solution solution = Solution( type, x1, expected_root, error );

        Number real_root = get_second_root( solution );

        REQUIRE( is_equal( expected_root, real_root ) );
    }
}

TEST_CASE( "has_no_roots(each type, random error & x1 & x2)", "[solution]" ) {
    for ( SolutionType type : get_all_solution_types() ) {
        Number x1 = random_number();
        Number x2 = random_number();
        Error error = random_error();
        Solution solution = Solution( type, x1, x2, error );

        bool real_has_no_roots = type == SolutionType::NO_ROOTS;

        REQUIRE( has_no_roots( solution ) == real_has_no_roots );
    }
}

TEST_CASE( "has_inf_roots(each type, random error & x1 & x2)", "[solution]" ) {
    for ( SolutionType type : get_all_solution_types() ) {
        Number x1 = random_number();
        Number x2 = random_number();
        Error error = random_error();
        Solution solution = Solution( type, x1, x2, error );

        bool real_has_inf_roots = type == SolutionType::INF_ROOTS;

        REQUIRE( has_inf_roots( solution ) == real_has_inf_roots );
    }
}

TEST_CASE( "has_single_root(each type, random error & x1 & x2)",
           "[solution]" ) {
    for ( SolutionType type : get_all_solution_types() ) {
        Number x1 = random_number();
        Number x2 = random_number();
        Error error = random_error();
        Solution solution = Solution( type, x1, x2, error );

        bool real_has_single_root = type == SolutionType::SINGLE_ROOT;

        REQUIRE( has_single_root( solution ) == real_has_single_root );
    }
}

TEST_CASE( "has_two_roots(each type, random error & x1 & x2)", "[solution]" ) {
    for ( SolutionType type : get_all_solution_types() ) {
        Number x1 = random_number();
        Number x2 = random_number();
        Error error = random_error();
        Solution solution = Solution( type, x1, x2, error );

        bool real_has_two_roots = type == SolutionType::TWO_ROOTS;

        REQUIRE( has_two_roots( solution ) == real_has_two_roots );
    }
}

TEST_CASE( "has_two_same_roots(each type, random error & x1 & x2)",
           "[solution]" ) {
    for ( SolutionType type : get_all_solution_types() ) {
        Number x1 = random_number();
        Number x2 = random_number();
        Error error = random_error();
        Solution solution = Solution( type, x1, x2, error );

        bool real_has_two_same_roots = type == SolutionType::TWO_SAME_ROOTS;

        REQUIRE( has_two_same_roots( solution ) == real_has_two_same_roots );
    }
}
