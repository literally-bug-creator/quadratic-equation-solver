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

TEST_CASE( "solve_equation(no_roots_coeffs)", "[solution]" ) {
    Error expected_error = Errors::OK;
    Coefficients coeffs = Coefficients(
        ZERO_NUMBER, ZERO_NUMBER, random_number_ne_zero(), expected_error );

    Solution solution = solve_equation( coeffs );
    Error real_error = get_error( solution );

    REQUIRE( has_no_roots( solution ) );
    REQUIRE( expected_error.code == real_error.code );
    REQUIRE( expected_error.message == real_error.message );
    REQUIRE( get_first_root( solution ).value == ZERO_DOUBLE );
    REQUIRE( get_second_root( solution ).value == ZERO_DOUBLE );
    REQUIRE( get_solution_type( solution ) == SolutionType::NO_ROOTS );
}

TEST_CASE( "solve_equation(inf_roots_coeffs)", "[solution]" ) {
    Error expected_error = Errors::OK;
    Coefficients coeffs =
        Coefficients( ZERO_NUMBER, ZERO_NUMBER, ZERO_NUMBER, expected_error );

    Solution solution = solve_equation( coeffs );
    Error real_error = get_error( solution );

    REQUIRE( has_inf_roots( solution ) );
    REQUIRE( expected_error.code == real_error.code );
    REQUIRE( expected_error.message == real_error.message );
    REQUIRE( get_first_root( solution ).value == ZERO_DOUBLE );
    REQUIRE( get_second_root( solution ).value == ZERO_DOUBLE );
    REQUIRE( get_solution_type( solution ) == SolutionType::INF_ROOTS );
}

TEST_CASE( "solve_equation(single_root_coeffs, b_not_equal_zero)",
           "[solution]" ) {
    for ( int i = 0; i < RAND_TESTS_AMOUNT; i++ ) {
        Error expected_error = Errors::OK;
        Coefficients coeffs = Coefficients( ZERO_NUMBER,
                                            random_number_ne_zero(),
                                            random_number(),
                                            expected_error );

        Solution solution = solve_equation( coeffs );
        Error real_error = get_error( solution );

        REQUIRE( has_single_root( solution ) );
        REQUIRE( expected_error.code == real_error.code );
        REQUIRE( expected_error.message == real_error.message );
        REQUIRE( get_solution_type( solution ) == SolutionType::SINGLE_ROOT );
    }
}

TEST_CASE( "solve_equation(single_root_coeffs, b_equal_zero)", "[solution]" ) {
    for ( int i = 0; i < RAND_TESTS_AMOUNT; i++ ) {
        ErrorCode expected_error_code = ErrorCode::OK;
        Coefficients coeffs = Coefficients(
            ZERO_NUMBER, ZERO_NUMBER, random_number(), Errors::OK );

        Solution solution = solve_equation( coeffs );
        Error real_error = get_error( solution );

        REQUIRE( has_no_roots( solution ) );
        REQUIRE( expected_error_code == real_error.code );
        REQUIRE( get_solution_type( solution ) == SolutionType::NO_ROOTS );
    }
}

TEST_CASE( "solve_equation(two_roots_coeffs)", "[solution]" ) {
    for ( int i = 0; i < RAND_TESTS_AMOUNT; i++ ) {
        Error expected_error = Errors::OK;
        Coefficients coeffs = random_two_roots_coefficients();

        Solution solution = solve_equation( coeffs );
        Error real_error = get_error( solution );

        REQUIRE( has_two_roots( solution ) );
        REQUIRE( expected_error.code == real_error.code );
        REQUIRE( get_solution_type( solution ) == SolutionType::TWO_ROOTS );
    }
}

TEST_CASE( "solve_equation(two_same_roots, 1, 4, 4)", "[solution]" ) {
    Number a = make_number( 1 );
    Number b = make_number( 4 );
    Number c = make_number( 4 );
    Error expected_error = Errors::OK;
    Coefficients coeffs = Coefficients( a, b, c, expected_error );

    Solution solution = solve_equation( coeffs );
    Error real_error = get_error( solution );

    REQUIRE( has_two_same_roots( solution ) );
    REQUIRE( expected_error.code == real_error.code );
    REQUIRE( get_solution_type( solution ) == SolutionType::TWO_SAME_ROOTS );
}

TEST_CASE( "solve_equation(two_same_roots, 2, -8, 8)", "[solution]" ) {
    Number a = make_number( 2 );
    Number b = make_number( -8 );
    Number c = make_number( 8 );
    Error expected_error = Errors::OK;
    Coefficients coeffs = Coefficients( a, b, c, expected_error );

    Solution solution = solve_equation( coeffs );
    Error real_error = get_error( solution );

    REQUIRE( has_two_same_roots( solution ) );
    REQUIRE( expected_error.code == real_error.code );
    REQUIRE( get_solution_type( solution ) == SolutionType::TWO_SAME_ROOTS );
}

TEST_CASE( "solve_equation(two_same_roots, 3, 6, 3)", "[solution]" ) {
    Number a = make_number( 3 );
    Number b = make_number( 6 );
    Number c = make_number( 3 );
    Error expected_error = Errors::OK;
    Coefficients coeffs = Coefficients( a, b, c, expected_error );

    Solution solution = solve_equation( coeffs );
    Error real_error = get_error( solution );

    REQUIRE( has_two_same_roots( solution ) );
    REQUIRE( expected_error.code == real_error.code );
    REQUIRE( get_solution_type( solution ) == SolutionType::TWO_SAME_ROOTS );
}

TEST_CASE( "solve_equation(two_same_roots, -1, -6, -9)", "[solution]" ) {
    Number a = make_number( -1 );
    Number b = make_number( -6 );
    Number c = make_number( -9 );
    Error expected_error = Errors::OK;
    Coefficients coeffs = Coefficients( a, b, c, expected_error );

    Solution solution = solve_equation( coeffs );
    Error real_error = get_error( solution );

    REQUIRE( has_two_same_roots( solution ) );
    REQUIRE( expected_error.code == real_error.code );
    REQUIRE( get_solution_type( solution ) == SolutionType::TWO_SAME_ROOTS );
}
