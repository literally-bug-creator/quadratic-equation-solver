#include <catch2/catch_test_macros.hpp>

#include "../include/solution.hpp"
#include "tools.cpp"

TEST_CASE( "make_solution(rand, rand, rand, rand) in cycle", "[public]" ) {
    for ( int i = 0; i < TESTS_AMOUNT; i++ ) {
        SolutionType type = random_solution_type();
        Number first_root = random_number();
        Number second_root = random_number();
        Error error = random_error();

        Solution solution =
            make_solution( type, first_root, second_root, error );

        REQUIRE( solution.type == type );
        REQUIRE( solution.x1.value == first_root.value );
        REQUIRE( solution.x1.error.code == first_root.error.code );
        REQUIRE( solution.x1.error.message == first_root.error.message );
        REQUIRE( solution.x2.value == second_root.value );
        REQUIRE( solution.x2.error.code == second_root.error.code );
        REQUIRE( solution.x2.error.message == second_root.error.message );
        REQUIRE( solution.error.code == error.code );
        REQUIRE( solution.error.message == error.message );
    }
}

TEST_CASE( "get_solution_type(rand) in cycle", "[public]" ) {
    for ( int i = 0; i < TESTS_AMOUNT; i++ ) {
        Solution solution = random_solution();

        SolutionType type = get_solution_type( solution );

        REQUIRE( type == solution.type );
    }
}

TEST_CASE( "get_first_root(rand) in cycle", "[public]" ) {
    for ( int i = 0; i < TESTS_AMOUNT; i++ ) {
        Solution solution = random_solution();

        Number root = get_first_root( solution );

        REQUIRE( root.value == solution.x1.value );
        REQUIRE( root.error.code == solution.x1.error.code );
        REQUIRE( root.error.message == solution.x1.error.message );
    }
}

TEST_CASE( "get_second_root(rand) in cycle", "[public]" ) {
    for ( int i = 0; i < TESTS_AMOUNT; i++ ) {
        Solution solution = random_solution();

        Number root = get_second_root( solution );

        REQUIRE( root.value == solution.x2.value );
        REQUIRE( root.error.code == solution.x2.error.code );
        REQUIRE( root.error.message == solution.x2.error.message );
    }
}

TEST_CASE( "get_error(rand) in cycle", "[public][solution]" ) {
    for ( int i = 0; i < TESTS_AMOUNT; i++ ) {
        Solution solution = random_solution();

        Error error = get_error( solution );

        REQUIRE( error.code == solution.error.code );
        REQUIRE( error.message == solution.error.message );
    }
}

TEST_CASE( "get_solution(0, 0, 0)", "[public][solution]" ) {
    Number a = make_number( 0 );
    Number b = make_number( 0 );
    Number c = make_number( 0 );
    NumberKit kit = make_number_kit( a, b, c );

    Solution solution = get_solution( kit );

    REQUIRE( solution.type == INF_ROOTS );
    REQUIRE( solution.error.code == OK );
}

TEST_CASE( "get_solution(0, 0, 10)", "[public][solution]" ) {
    Number a = make_number( 0 );
    Number b = make_number( 0 );
    Number c = make_number( 10 );
    NumberKit kit = make_number_kit( a, b, c );

    Solution solution = get_solution( kit );

    REQUIRE( solution.type == NO_ROOTS );
    REQUIRE( solution.error.code == OK );
}

TEST_CASE( "get_solution(0, 2, -4)", "[public][solution]" ) {
    Number a = make_number( 0 );
    Number b = make_number( 2 );
    Number c = make_number( -4 );
    NumberKit kit = make_number_kit( a, b, c );

    Solution solution = get_solution( kit );

    REQUIRE( solution.type == SolutionType::SINGLE_ROOT );
    REQUIRE( solution.error.code == OK );
    REQUIRE( solution.x1.value == 2 );
    REQUIRE( solution.x1.is_null == false );
    REQUIRE( solution.x1.error.code == OK );
}

TEST_CASE( "get_solution(1, 1, 1)", "[public][solution]" ) {
    Number a = make_number( 1 );
    Number b = make_number( 1 );
    Number c = make_number( 1 );
    NumberKit kit = make_number_kit( a, b, c );

    Solution solution = get_solution( kit );

    REQUIRE( solution.type == NO_ROOTS );
    REQUIRE( solution.error.code == SOLUTION_ERROR );
    REQUIRE( solution.x1.is_null == true );
    REQUIRE( solution.x2.is_null == true );
}

TEST_CASE( "get_solution(1, 0, 1)", "[public][solution]" ) {
    Number a = make_number( 1 );
    Number b = make_number( 0 );
    Number c = make_number( 1 );
    NumberKit kit = make_number_kit( a, b, c );

    Solution solution = get_solution( kit );

    REQUIRE( solution.type == NO_ROOTS );
    REQUIRE( solution.error.code == SOLUTION_ERROR );
    REQUIRE( solution.x1.is_null == true );
    REQUIRE( solution.x2.is_null == true );
}

TEST_CASE( "get_solution(2, 2, 5)", "[public][solution]" ) {
    Number a = make_number( 2 );
    Number b = make_number( 2 );
    Number c = make_number( 5 );
    NumberKit kit = make_number_kit( a, b, c );

    Solution solution = get_solution( kit );

    REQUIRE( solution.type == NO_ROOTS );
    REQUIRE( solution.error.code == SOLUTION_ERROR );
    REQUIRE( solution.x1.is_null == true );
    REQUIRE( solution.x2.is_null == true );
}

TEST_CASE( "get_solution(3, 4, 5)", "[public][solution]" ) {
    Number a = make_number( 3 );
    Number b = make_number( 4 );
    Number c = make_number( 5 );
    NumberKit kit = make_number_kit( a, b, c );

    Solution solution = get_solution( kit );

    REQUIRE( solution.type == NO_ROOTS );
    REQUIRE( solution.error.code == SOLUTION_ERROR );
    REQUIRE( solution.x1.is_null == true );
    REQUIRE( solution.x2.is_null == true );
}

TEST_CASE( "get_solution(1, 2, 1)", "[public][solution]" ) {
    Number a = make_number( 1 );
    Number b = make_number( 2 );
    Number c = make_number( 1 );
    NumberKit kit = make_number_kit( a, b, c );

    Solution solution = get_solution( kit );

    REQUIRE( solution.type == SolutionType::SINGLE_ROOT );
    REQUIRE( solution.error.code == OK );
    REQUIRE( solution.x1.value == -1 );
    REQUIRE( solution.x1.is_null == false );
    REQUIRE( solution.x2.is_null == true );
}

TEST_CASE( "get_solution(4, -12, 9)", "[public][solution]" ) {
    Number a = make_number( 4 );
    Number b = make_number( -12 );
    Number c = make_number( 9 );
    NumberKit kit = make_number_kit( a, b, c );

    Solution solution = get_solution( kit );

    REQUIRE( solution.type == SolutionType::SINGLE_ROOT );
    REQUIRE( solution.error.code == OK );
    REQUIRE( solution.x1.value == 1.5 );
    REQUIRE( solution.x1.is_null == false );
    REQUIRE( solution.x2.is_null == true );
}

TEST_CASE( "get_solution(0, 4, -8)", "[public][solution]" ) {
    Number a = make_number( 0 );
    Number b = make_number( 4 );
    Number c = make_number( -8 );
    NumberKit kit = make_number_kit( a, b, c );

    Solution solution = get_solution( kit );

    REQUIRE( solution.type == SolutionType::SINGLE_ROOT );
    REQUIRE( solution.error.code == OK );
    REQUIRE( solution.x1.value == 2 );
    REQUIRE( solution.x1.is_null == false );
    REQUIRE( solution.x2.is_null == true );
}

TEST_CASE( "get_solution(0, -3, 9)", "[public][solution]" ) {
    Number a = make_number( 0 );
    Number b = make_number( -3 );
    Number c = make_number( 9 );
    NumberKit kit = make_number_kit( a, b, c );

    Solution solution = get_solution( kit );

    REQUIRE( solution.type == SolutionType::SINGLE_ROOT );
    REQUIRE( solution.error.code == OK );
    REQUIRE( solution.x1.value == 3 );
    REQUIRE( solution.x1.is_null == false );
    REQUIRE( solution.x2.is_null == true );
}

TEST_CASE( "get_solution(0, 5, 0)", "[public][solution]" ) {
    Number a = make_number( 0 );
    Number b = make_number( 5 );
    Number c = make_number( 0 );
    NumberKit kit = make_number_kit( a, b, c );

    Solution solution = get_solution( kit );

    REQUIRE( solution.type == SolutionType::SINGLE_ROOT );
    REQUIRE( solution.error.code == OK );
    REQUIRE( solution.x1.value == 0 );
    REQUIRE( solution.x1.is_null == false );
    REQUIRE( solution.x2.is_null == true );
}

TEST_CASE( "get_solution(1, -3, 2)", "[public][solution]" ) {
    Number a = make_number( 1 );
    Number b = make_number( -3 );
    Number c = make_number( 2 );
    NumberKit kit = make_number_kit( a, b, c );

    Solution solution = get_solution( kit );

    REQUIRE( solution.type == TWO_ROOTS );
    REQUIRE( solution.error.code == OK );
    REQUIRE( solution.x1.value == 2 );
    REQUIRE( solution.x1.is_null == false );
    REQUIRE( solution.x2.value == 1 );
    REQUIRE( solution.x2.is_null == false );
}

TEST_CASE( "get_solution(1, -5, 6)", "[public][solution]" ) {
    Number a = make_number( 1 );
    Number b = make_number( -5 );
    Number c = make_number( 6 );
    NumberKit kit = make_number_kit( a, b, c );

    Solution solution = get_solution( kit );

    REQUIRE( solution.type == TWO_ROOTS );
    REQUIRE( solution.error.code == OK );
    REQUIRE( solution.x1.value == 3 );
    REQUIRE( solution.x1.is_null == false );
    REQUIRE( solution.x2.value == 2 );
    REQUIRE( solution.x2.is_null == false );
}

TEST_CASE( "get_solution(2, -7, 3)", "[public][solution]" ) {
    Number a = make_number( 2 );
    Number b = make_number( -7 );
    Number c = make_number( 3 );
    NumberKit kit = make_number_kit( a, b, c );

    Solution solution = get_solution( kit );

    REQUIRE( solution.type == TWO_ROOTS );
    REQUIRE( solution.error.code == OK );
    REQUIRE( solution.x1.value == 3 );
    REQUIRE( solution.x1.is_null == false );
    REQUIRE( solution.x2.value == 0.5 );
    REQUIRE( solution.x2.is_null == false );
}

TEST_CASE( "get_solution(1, 0, -4)", "[public][solution]" ) {
    Number a = make_number( 1 );
    Number b = make_number( 0 );
    Number c = make_number( -4 );
    NumberKit kit = make_number_kit( a, b, c );

    Solution solution = get_solution( kit );

    REQUIRE( solution.type == TWO_ROOTS );
    REQUIRE( solution.error.code == OK );
    REQUIRE( solution.x1.value == 2 );
    REQUIRE( solution.x1.is_null == false );
    REQUIRE( solution.x2.value == -2 );
    REQUIRE( solution.x2.is_null == false );
}

TEST_CASE( "get_solution(error_number_kit)", "[public][solution]" ) {
    Number a = make_number( 1 );
    Number b = make_number( -3 );
    Number c = make_number( 2 );
    Error error = make_error( INVALID_INPUT, "" );
    NumberKit kit = make_number_kit( a, b, c, error );

    Solution solution = get_solution( kit );

    REQUIRE( solution.type == NO_ROOTS );
    REQUIRE( solution.error.code == SOLUTION_ERROR );
    REQUIRE( solution.x1.is_null == true );
    REQUIRE( solution.x2.is_null == true );
}
