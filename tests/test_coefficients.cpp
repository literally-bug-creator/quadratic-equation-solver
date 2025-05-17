#include <catch2/catch_test_macros.hpp>

#include "../include/coefficients.hpp"
#include "../include/error.hpp"
#include "number.hpp"
#include "tools.cpp"

const int RAND_TESTS_AMOUNT = 1000;
const int ZERO_INT = 0;

TEST_CASE( "get_a(random_coeffs)", "[coefficients]" ) {
    for ( int i = 0; i < RAND_TESTS_AMOUNT; i++ ) {
        Number a = random_number();
        Number b = random_number();
        Number c = random_number();
        Error error = random_error();
        Coefficients coeffs = make_coefficients( a, b, c, error );


        Number res_a = get_a( coeffs );

        REQUIRE( res_a == a );
    }
}

TEST_CASE( "get_b(random_coeffs)", "[coefficients]" ) {
    for ( int i = 0; i < RAND_TESTS_AMOUNT; i++ ) {
        Number a = random_number();
        Number b = random_number();
        Number c = random_number();
        Error error = random_error();
        Coefficients coeffs = make_coefficients( a, b, c, error );

        Number res_b = get_b( coeffs );

        REQUIRE( res_b == b );
    }
}

TEST_CASE( "get_c(random_coeffs)", "[coefficients]" ) {
    for ( int i = 0; i < RAND_TESTS_AMOUNT; i++ ) {
        Number a = random_number();
        Number b = random_number();
        Number c = random_number();
        Error error = random_error();
        Coefficients coeffs = make_coefficients( a, b, c, error );

        Number res_c = get_c( coeffs );

        REQUIRE( res_c == c );
    }
}

TEST_CASE( "get_error(random_coeffs)", "[coefficients]" ) {
    for ( int i = 0; i < RAND_TESTS_AMOUNT; i++ ) {
        Number a = random_number();
        Number b = random_number();
        Number c = random_number();
        Error error = random_error();
        Coefficients coeffs = make_coefficients( a, b, c, error );

        Error res_error = get_error( coeffs );

        REQUIRE( get_error_code( res_error ) == get_error_code( error ) );
        REQUIRE( get_error_message( res_error ) == get_error_message( error ) );
    }
}
