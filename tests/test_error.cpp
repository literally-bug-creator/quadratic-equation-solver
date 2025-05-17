#include <catch2/catch_test_macros.hpp>

#include "../include/error.hpp"
#include "tools.cpp"

const int RAND_TESTS_AMOUNT = 1000;

TEST_CASE( "make_error(each_type, random)", "[error]" ) {
    for ( auto code : get_all_error_codes() ) {
        std::string msg = random_string( random_int( ZERO, MAX_INT ) );
        Error error = make_error( code, msg );

        REQUIRE( get_error_code( error ) == code );
        REQUIRE( get_error_message( error ) == msg );
    }
}

TEST_CASE( "get_error_code(random_error)", "[error]" ) {
    for ( int _ = 0; _ < RAND_TESTS_AMOUNT; _++ ) {
        ErrorCode code = random_error_code();
        std::string msg = random_string( random_int( ZERO, MAX_INT ) );
        Error error = make_error( code, msg );

        REQUIRE( get_error_code( error ) == code );
    }
}

TEST_CASE( "get_error_message(random_error)", "[error]" ) {
    for ( int _ = 0; _ < RAND_TESTS_AMOUNT; _++ ) {
        ErrorCode code = random_error_code();
        std::string msg = random_string( random_int( ZERO, MAX_INT ) );
        Error error = make_error( code, msg );

        REQUIRE( get_error_message( error ) == msg );
    }
}

TEST_CASE( "is_ok(each_type_errors)", "[error]" ) {
    for ( auto code : get_all_error_codes() ) {
        std::string msg = random_string( random_int( ZERO, MAX_INT ) );
        Error error = make_error( code, msg );

        REQUIRE( is_ok( error ) == ( code == ErrorCode::OK ) );
    }
}
