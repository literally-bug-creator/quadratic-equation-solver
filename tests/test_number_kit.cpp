#include <catch2/catch_test_macros.hpp>

#include "../src/number_kit.cpp"
#include "tools.cpp"

TEST_CASE( "make_number_kit(rand, rand, rand) in cycle", "[public]" ) {
    for (int i = 0; i < RAND_TESTS_AMOUNT; i++){
        Number a = random_number();
        Number c = random_number();
        Number b = random_number();
        NumberKit kit = make_number_kit( a, b, c );

        REQUIRE( kit.error.code == OK );
        REQUIRE( is_equal( kit.a, a ) );
        REQUIRE( is_equal( kit.b, b ) );
        REQUIRE( is_equal( kit.c, c ) );
    }
}

TEST_CASE( "make_number_kit(rand, rand, rand, error) in cycle", "[public]" ) {
    for (int i = 0; i < RAND_TESTS_AMOUNT; i++){
        Number a = random_number();
        Number c = random_number();
        Number b = random_number();
        Error error = random_error();
        NumberKit kit = make_number_kit( a, b, c, error );

        REQUIRE( kit.error.code == error.code );
        REQUIRE( kit.error.message == error.message );
        REQUIRE( is_equal( kit.a, a ) );
        REQUIRE( is_equal( kit.b, b ) );
        REQUIRE( is_equal( kit.c, c ) );
    }
}

TEST_CASE( "make_number_kit(rand, rand, rand, error) in cycle", "[public]" ) {
    for (int i = 0; i < RAND_TESTS_AMOUNT; i++){
        Number a = random_number();
        Number c = random_number();
        Number b = random_number();
        Error error = random_error();
        NumberKit kit = make_number_kit( a, b, c, error );

        REQUIRE( kit.error.code == error.code );
        REQUIRE( kit.error.message == error.message );
        REQUIRE( is_equal( kit.a, a ) );
        REQUIRE( is_equal( kit.b, b ) );
        REQUIRE( is_equal( kit.c, c ) );
    }
}

TEST_CASE( "get_a(rand) in cycle", "[public]" ) {
    for (int i = 0; i < RAND_TESTS_AMOUNT; i++){
        Number a = random_number();
        Number c = random_number();
        Number b = random_number();
        Error error = random_error();
        NumberKit kit = make_number_kit( a, b, c, error );
        Number kit_a = get_a( kit );

        REQUIRE( kit.error.code == error.code );
        REQUIRE( kit.error.message == error.message );
        REQUIRE( is_equal( kit_a, a ) );
        REQUIRE( is_equal( kit.b, b ) );
        REQUIRE( is_equal( kit.c, c ) );
    }
}

TEST_CASE( "get_b(rand) in cycle", "[public]" ) {
    for (int i = 0; i < RAND_TESTS_AMOUNT; i++){
        Number a = random_number();
        Number c = random_number();
        Number b = random_number();
        Error error = random_error();
        NumberKit kit = make_number_kit( a, b, c, error );
        Number kit_b = get_b( kit );

        REQUIRE( kit.error.code == error.code );
        REQUIRE( kit.error.message == error.message );
        REQUIRE( is_equal( kit.a, a ) );
        REQUIRE( is_equal( kit_b, b ) );
        REQUIRE( is_equal( kit.c, c ) );
    }
}

TEST_CASE( "get_c(rand) in cycle", "[public]" ) {
    for (int i = 0; i < RAND_TESTS_AMOUNT; i++){
        Number a = random_number();
        Number c = random_number();
        Number b = random_number();
        Error error = random_error();
        NumberKit kit = make_number_kit( a, b, c, error );
        Number kit_c = get_c( kit );

        REQUIRE( kit.error.code == error.code );
        REQUIRE( kit.error.message == error.message );
        REQUIRE( is_equal( kit.a, a ) );
        REQUIRE( is_equal( kit.b, b ) );
        REQUIRE( is_equal( kit_c, c ) );
    }
}

TEST_CASE( "get_error(rand) in cycle", "[public]" ) {
    for (int i = 0; i < RAND_TESTS_AMOUNT; i++){
        Number a = random_number();
        Number c = random_number();
        Number b = random_number();
        Error error = random_error();
        NumberKit kit = make_number_kit( a, b, c, error );
        Error kit_error = get_error( kit );

        REQUIRE( kit_error.code == error.code );
        REQUIRE( kit_error.message == error.message );
        REQUIRE( is_equal( kit.a, a ) );
        REQUIRE( is_equal( kit.b, b ) );
        REQUIRE( is_equal( kit.c, c ) );
    }
}
